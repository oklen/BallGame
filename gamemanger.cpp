#include "gamemanger.h"

GameManger::GameManger(MainWindow *child):board{child},
    falls{std::vector<Ball*>()}
{
    board->show();
    timer.setInterval(10);
    connect(&timer,&QTimer::timeout,this,&GameManger::calMove);
    connect(board,&MainWindow::PushBall,[this](){
        pushTheBall = true;
    });
    //start();
    timer.start();
}

void GameManger::start()
{
    board->Reset();
    board->rd.setRound(who);
    board->rd.showTurns = true;
    QTimer::singleShot(2000,&board->rd,&rounder::close);
    QTimer::singleShot(2050,board,&MainWindow::doUpdate);
}

void GameManger::nextRound()
{
    switch(players[who].state){
    case Player::hitred:{
        int ban = 0;
        for(int i=0;i<Col_Order.size();++i){
            if(Col_Order[i].first->rank!=Ball::bai&&Col_Order[i].second->rank!=Ball::bai)
                continue;
            if(Col_Order[i].first->rank!=Ball::bai)
                Ball::swap(Col_Order[i].first->rank,Col_Order[i].second->rank);
            if(Col_Order[i].second->rank==Ball::hong) ban=1;
            else ban = std::min(ban,-Col_Order[i].second->rank);
        }
        if(ban>0)
        for(int i=0;i<falls.size();++i){
            if(falls[i]->rank==Ball::ball_color::hong)continue;
            ban = std::min(ban,-falls[i]->rank);
            falls[i]->restore();
            board->balls.push_back(falls[i]);
        }
        if(ban>0) players[who].state = Player::hitcolor;
        else if(ban<=0) {
            players[who].state =Player::failed;
            players[who?1:0].scores+=-ban;
        }
        break;
    }
    case Player::hitcolor:{
        int ban = 0;
        Ball* firstTouch = nullptr;
        for(int i=0;i<Col_Order.size();++i)
        {
            if(Col_Order[i].first->rank!=Ball::bai&&
                    Col_Order[i].second->rank!=Ball::bai)
            {
                int mx = std::max((int)Col_Order[i].first->rank,
                                  (int)Col_Order[i].second->rank);
                if(mx>firstTouch->rank);
                ban = std::min(ban,-mx);
                continue;
            }
            if(Col_Order[i].first->rank!=Ball::bai)
                Ball::swap(Col_Order[i].first->rank,Col_Order[i].second->rank);
            if(!firstTouch) firstTouch = Col_Order[i].second;
            if(firstTouch->rank<Col_Order[i].second->rank)
                ban = -firstTouch->rank;
        }
        if(ban==0)
        for(int i=0;i<falls.size();++i){
            if(falls[i]==firstTouch) {
                ban=falls[i]->rank;
                players[who].state = Player::hitred;
            }
        }
        if(players[who].state==Player::hitcolor){
            players[who].state = Player::failed;
        }
        break;
    }
    case Player::hitHuang:{
    break;

    }
    case Player::hitlv:{
    break;
    }
    case Player::hitzong:{
    break;
    }
    case Player::hitlan:{
    break;
    }
    case Player::hitfen:{
    break;
    }
    case Player::hithei:{
break;
    }
    case Player::failed:{
        who= (who==1?0:1);
        board->rd.setRound(who);
        players[who].state = Player::hitred;
        board->rd.showTurns = true;
        board->update();
        QTimer::singleShot(2000,&board->rd,&rounder::close);
        QTimer::singleShot(2050,board,&MainWindow::doUpdate);
        return;
    }
    };
    clearBalls();
    nextRound();
}

void GameManger::calScore()
{
    nextRound();
}

void GameManger::calFalls()
{
    for(int j=0;j<board->balls.size();++j)
    {
          for(int i=0;i<6;++i)
          {
            if(preciseDetectionCol(*board->holes[i],*board->balls[j]))
            {
                board->balls.erase(board->balls.begin()+j);
                falls.push_back(board->balls[i]);
                board->update();
                break;
            }
          }
    }
}

void GameManger::clearBalls()
{
    qDebug() << falls.size();
    falls.clear();
    Col_Order.clear();
}

void GameManger::calMove()
{
    bool needUpdate = false;
    int balls_cnt = board->balls.size();
    std::unordered_set<int> toskip;
    someOneMove = false;
    calFalls();
    for(int i=0;i<balls_cnt;++i){
        if(toskip.count(i)) continue;
        if(board->balls[i]->moving){
            someOneMove = true;
            board->balls[i]->save();
            board->balls[i]->Move(time_span);
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
                Vector2 Vix = (Uxi+Uxj-(Uxi-Uxj))*0.5;
                Vector2 Vjx = (Uxi+Uxj+(Uxi-Uxj))*0.5;
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
            pushTheBall = false;
            calScore();
        }
    }
}


bool GameManger::preciseDetectionCol(Ball &a, Ball &b) const
{
    double rvx = b.vx  - a.vx,rvy = b.vy - a.vy;
    double rx = b.x - a.x,ry = b.y - a.y;
    if(rvx*rx+rvy*ry>0) return false; //difTf
    double dtime = (abs(rvx*rx+rvy*ry)/(rvx*rvx+rvy*rvy));
//    qDebug() << dtime << rvx << rx << rvy*ry << rvx*rvx << (rx+rvx*dtime);
    //exit(0);


    dtime = std::fmin(dtime,time_span);
    if(a.r+b.r>std::sqrt((rx+rvx*dtime)*(rx+rvx*dtime)+(ry+rvy*dtime)*(ry+rvy*dtime)))
    {
        Col_Order.push_back(std::pair<Ball*,Ball*>{&a,&b});
        return true;
    }
    return false;
}
