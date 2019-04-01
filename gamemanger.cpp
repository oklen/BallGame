#include "gamemanger.h"

GameWorker::GameWorker(Board *child):board{child},
    falls{std::vector<Ball*>()},mainWindow(child)
{    
    timer.setInterval(10);
    QObject::connect(&timer,&QTimer::timeout,this,&GameWorker::calMove);
    mainWindow.show();
    connect(board,&Board::PushBall,[this](){
        pushTheBall = true;
    });

    connect(mainWindow.pauseMenu->quit,&ControlButton::mpress,[](){
       exit(0);
    });
}

void GameWorker::start()
{
    board->Reset();
    board->rd.setRound(who);
    board->rd.showTurns = true;
    QTimer::singleShot(2000,&board->rd,&rounder::close);
    QTimer::singleShot(2050,board,&Board::doUpdate);
    board->GameStarted = true;
    timer.start();
}

void GameWorker::calFalls()
{
    for(int j=0;j<board->balls.size();++j)
    {
        if(board->balls[j]->moving)
          for(int i=0;i<6;++i)
          {
            if(preciseDetectionCol(*board->holes[i],*board->balls[j]))
            {
                falls.push_back(board->balls[j]);
                board->balls[j]->moving =
                        board->balls[j]->vx =
                        board->balls[j]->vy = 0;
                board->balls.erase(board->balls.begin()+j);
                board->update();
                break;
            }
          }
    }
}

void GameWorker::MoveBackBall()
{
    if(!board->balls.empty()){
        for(int j=0;j<board->balls.size();++j)
        {
            if(board->balls[j]->rank == Ball::hong)
            {
                for(int i=0;i<falls.size();++i){
                    if(falls[i]->rank == Ball::hong) continue;
                    falls[i]->restore();
                    if(falls[i]->rank!=Ball::bai)
                    board->balls.push_back(falls[i]);
                    else {
                        board->balls.push_front(falls[i]);
                    }
                }
                break;
            }
        }
    }
}

void GameWorker::clearBalls()
{
    falls.clear();
    Col_Order.clear();
    board->update();
}

void GameWorker::calMove()
{
    if(!pushTheBall) return;
    bool needUpdate = false;
    std::unordered_set<int> toskip;
    someOneMove = false;
    calFalls();

    int balls_cnt = board->balls.size();
    if(board->club->tops.moving) {
        someOneMove = true;
//        qDebug()<<"tops mov!";
//        qDebug() << board->balls[0]->r << board->club->tops.r;
        if(preciseDetectionCol(*board->balls[0],board->club->tops))
        {
            board->balls[0]->vx = board->club->tops.vx;
            board->balls[0]->vy = board->club->tops.vy;
            board->club->tops.moving = board->club->showOn =false;
            board->balls[0]->moving = true;
        }else board->club->tops.Move(time_span);
        needUpdate = true;
    }

    for(int i=0;i<balls_cnt;++i){
        if(toskip.count(i)) continue;
        if(board->balls[i]->moving){
            someOneMove = true;
            board->balls[i]->save();
            board->balls[i]->Move(time_span);
//            qDebug()<<board->balls[i]->x;
            double nx = board->balls[i]->x,ny=  board->balls[i]->y,
                    nr = 2*board->balls[i]->r;
            if(nx<board->used_bound_width+nr/2||
                    nx+nr/2+board->used_bound_width>board->width())
            {
                board->balls[i]->setVx(-board->balls[i]->getVx()*Bound_loss);
                board->balls[i]->rollback();
                continue;
            }
            if(ny<board->used_bound_width+nr/2||
                    ny+nr/2+board->used_bound_width>board->height())
            {
                board->balls[i]->setVy(-board->balls[i]->getVy()*Bound_loss);
                board->balls[i]->rollback();
                continue;
            }
            for(int j=0;j<balls_cnt;++j){
                if(j==i||toskip.count(j)) continue;
                double dx = std::abs(board->balls[j]->x-nx),
                        dy = std::abs(board->balls[j]->y - ny);
                if(!preciseDetectionCol(
                            *board->balls[i],*board->balls[j])) continue;

                float vx = board->balls[i]->vx,vy= board->balls[i]->vy;

                //                xaxis=(pb2-pb1).unit(); // X-Axis轴
                //                a=xaxis.dot(ArrayVel[BallColNr1]); // X_Axis投影系数
                //                U1x=xaxis*a; // 计算在X_Axis轴上的速度
                //                U1y=ArrayVel[BallColNr1]-U1x; // 计算在垂直轴上的速度
                //                xaxis=(pb1-pb2).unit();
                //                b=xaxis.dot(ArrayVel[BallColNr2]);
                //                U2x=xaxis*b;
                //                U2y=ArrayVel[BallColNr2]-U2x;
                //                V1x=(U1x+U2x-(U1x-U2x))*0.5; // 计算新的速度
                //                V2x=(U1x+U2x-(U2x-U1x))*0.5;
                //                V1y=U1y;
                //                V2y=U2y;
                //                for (j=0;j<NrOfBalls;j++) // 更新所有球的位置
                //                ArrayPos[j]=OldPos[j]+ArrayVel[j]*BallTime;
                //                ArrayVel[BallColNr1]=V1x+V1y; // 设置新的速度
                //                ArrayVel[BallColNr2]=V2x+V2y;

                Vector2 vi(vx,vy),vj(board->balls[j]->vx,board->balls[j]->vy);
                Vector2 xaxis(board->balls[j]->x-board->balls[i]->x,board->balls[j]->y-
                              board->balls[i]->y);
                xaxis.united();
                float a = xaxis.dot(vi);
                Vector2 Uxi = xaxis*a,Uyi = vi - Uxi;
                xaxis.reserved();
                float b = xaxis.dot(vj);
                Vector2 Uxj = xaxis*b,Uyj = vj - Uxj;
                Vector2 Vix = (Uxi+Uxj-(Uxi-Uxj))*0.45;
                Vector2 Vjx = (Uxi+Uxj+(Uxi-Uxj))*0.45;
                Vix+=Uyi;
                Vjx+=Uyj;

                board->balls[i]->accelacte(Vix.x,Vix.y);
                board->balls[j]->accelacte(Vjx.x,Vjx.y);
                board->balls[i]->rollback();
                toskip.insert(j);
                break;
            }
            needUpdate = true;
        }
    }

    if(needUpdate) board->update();

    if(pushTheBall){
        if(!someOneMove){
//            qDebug() << "calScore";
            board->NoOneMove = true;
            pushTheBall = false;
            emit nextRound();
        }
        else board->NoOneMove = false;
    }
}


bool GameWorker::preciseDetectionCol(Ball &a, Ball &b) const
{
//    qDebug()<<"R:" <<a.r <<b.r;
    float dx = a.x - b.x,dy = a.y - b.y;
    if(sqrt(dx*dx+dy*dy)<a.r+b.r) return true;
    double rvx = b.vx  - a.vx,rvy = b.vy - a.vy;
    double rx = b.x - a.x,ry = b.y - a.y;
    if(rvx*rx+rvy*ry>0) return false; //difTf
    double dtime = (abs(rvx*rx+rvy*ry)/(rvx*rvx+rvy*rvy));


    dtime = std::fmin(dtime,time_span);
    if(a.r+b.r>std::sqrt((rx+rvx*dtime)*(rx+rvx*dtime)+(ry+rvy*dtime)*(ry+rvy*dtime)))
    {
        if(b.rank!=-1&&a.rank!=-1)
        Col_Order.push_back(std::pair<Ball*,Ball*>{&a,&b});
        return true;
    }
    return false;
}
