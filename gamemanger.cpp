#include "gamemanger.h"

GameManger::GameManger(MainWindow *child):board{child}
{
    board->show();
    timer.setInterval(10);
    connect(&timer,&QTimer::timeout,this,&GameManger::calMove);
    timer.start();
}

void GameManger::start()
{
    board->Reset();
}

void GameManger::calMove()
{
    bool needUpdate = false;
    int balls_cnt = board->balls.size();
    std::unordered_set<int> toskip;
    for(int i=0;i<balls_cnt;++i){
        if(toskip.count(i)) continue;
        if(board->balls[i]->moving){
            board->balls[i]->Move(time_span);
            int nx = board->balls[i]->x,ny=  board->balls[i]->y,
                    nr = 2*board->balls[i]->r;
            if(nx<board->used_bound_width+nr||
                    nx+nr+board->used_bound_width>board->width())
                board->balls[i]->setVx(-board->balls[i]->getVx());
            if(ny<board->used_bound_width+nr||
                    ny+nr+board->used_bound_width>board->height())
                board->balls[i]->setVy(-board->balls[i]->getVy());
            for(int j=0;j<balls_cnt;++j){
                if(i==j) continue;
                int dx = std::abs(board->balls[j]->x-nx),
                        dy = std::abs(board->balls[j]->y - ny);
                if(dx>nr||dy>nr||std::sqrt(dx*dx+dy*dy)>=nr) continue;
                float vx = board->balls[i]->vx,vy= board->balls[i]->vy;
                board->balls[i]->accelacte(board->balls[j]->vx,board->balls[j]->vy);
                board->balls[j]->accelacte(vx,vy);
//                board->balls[i]->x-=board->balls[j]->x-nx;
//                board->balls[j]->x+=board->balls[j]->x-nx;
//                board->balls[i]->y-=board->balls[j]->y-ny;
//                board->balls[j]->y+=board->balls[j]->y-ny;
                board->balls[i]->Move(time_span);
                toskip.insert(j);
                break;
            }
            needUpdate = true;
        }
    }
    if(needUpdate) board->update();
}
