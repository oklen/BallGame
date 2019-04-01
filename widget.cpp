#include "widget.h"
#include "ui_widget.h"

//float MainWindow::rev_scale;
bool Board::eventFilter(QObject *who, QEvent *Event)
{
    if(who!=this) return true;

    if(Event->type()==QEvent::MouseButtonPress&&NoOneMove){
        QMouseEvent *event = dynamic_cast<QMouseEvent*>(Event);
            int i=0;
            int dx=abs(balls[i]->x - event->pos().x()),
                    dy = abs(balls[i]->y - event->pos().y());
            if(std::sqrt(dx*dx+dy*dy)<=balls[i]->r){
                balls[i]->selected = true;
                selectedIndex = i;
                club->setCenter(balls[i]->x,balls[i]->y);
                club->setTops(event->pos().x(),event->pos().y());
                club->showOn = true;
                shootline->beginAt = Vector2(balls[i]->x,balls[i]->y);
            }
    }
    else if(selectedIndex!=-1&&Event->type()==QEvent::MouseMove){
        QMouseEvent *event = dynamic_cast<QMouseEvent*>(Event);
        mousex = event->x();
        mousey = event->y();
        if(!club->isTooFar(mousex,mousey))
            club->setTops(mousex,mousey);
        shootline->dir = Vector2{mousex-shootline->beginAt.x,
    mousey-shootline->beginAt.y};
        shootline->dir.united();
        shootline->dir.reserved();
        shootline->CalABC(shootline->beginAt,club->getDir());
        shootline->showOn = true;

        shootline->colTest(balls);
        if(shootline->isMposEmpty()){
            shootline->colTest(bounds);
        }
        update();
    }
    else if(Event->type()==QEvent::MouseButtonRelease&&selectedIndex!=-1){
        balls[selectedIndex]->selected =false;
        club->tops.accelacte((balls[selectedIndex]->x-mousex)/40,
                             (balls[selectedIndex]->y-mousey)/40);
        selectedIndex = -1;
        shootline->showOn = false;

        update();
        emit PushBall();
    }else if(Event->type()==QEvent::MouseButtonRelease
             ||Event->type()==QEvent::MouseMove) return true;
    else return false;
    return true;
}

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    selectedIndex{-1},
    rd(width()/2-100,50,50),
    club(new Club(0,0,Qt::black)),
    shootline(new ShootLine)
{
//    ball_radius*=rev_scale;
    int Nhole_size = hole_size/rev_scale,Nbound_width=bound_width/rev_scale;
    setFixedSize(real_width/rev_scale,real_height/rev_scale);
    qDebug()<<Nhole_size<<Nbound_width<<width()<<height();
    bounds[0] = new Bound(Nhole_size,
                          0,
                          (width()-3*Nhole_size)/2,
                          Nbound_width);
    bounds[1] = new Bound(0,Nhole_size,
                          Nbound_width,
                          height()-2*Nhole_size);
    bounds[2] = new Bound(Nhole_size,
                          height()-Nbound_width,
                          (width()-3*Nhole_size)/2,
                          Nbound_width);
    bounds[3] = new Bound(width()-Nbound_width,
                          Nhole_size,
                          Nbound_width,
                          height()-2*Nhole_size);
    bounds[4] = new Bound(Nhole_size+(width()-3*Nhole_size)/2+Nhole_size,
                          0,
                          (width()-3*Nhole_size)/2,
                          Nbound_width);
    bounds[5] = new Bound(Nhole_size+(width()-3*Nhole_size)/2+Nhole_size,
                          height()-Nbound_width,
                          (width()-3*Nhole_size)/2,
                          Nbound_width);


    holes[0] = new Hole(Nhole_size/2,
                        Nhole_size/2,
                        Nhole_size/2);
    holes[1] = new Hole(Nhole_size/2,
                        bounds[1]->y+bounds[1]->yspan+Nhole_size/2,Nhole_size/2);
    holes[2] = new Hole(width()-Nhole_size/2,Nhole_size/2,Nhole_size/2);
    holes[3] = new Hole(width()-Nhole_size/2,
            bounds[1]->y+bounds[1]->yspan+Nhole_size/2,Nhole_size/2);
    holes[4] = new Hole(Nhole_size+(width()-3*Nhole_size)/2+Nhole_size/2,
                        Nhole_size/2-hole_shift,
                        Nhole_size/2);
    holes[5] = new Hole(Nhole_size+(width()-3*Nhole_size)/2+Nhole_size/2,
                        bounds[1]->y+bounds[1]->yspan+Nhole_size/2+hole_shift,
                        Nhole_size/2);
    ui->setupUi(this);
    vectpen.setColor(Qt::green);
    vectpen.setWidth(10);
    installEventFilter(this);
//    showFullScreen();
}

void Board::paintEvent(QPaintEvent *event)
{
    mpainter.begin(this);
    mpainter.setBrush(QColor(32,145,30));
    mpainter.drawRect(rect());

    for(int i=0;i<6;++i)
    {
        bounds[i]->draw(mpainter);
        holes[i]->draw(mpainter);
    }
    for(auto bb = balls.begin();bb!=balls.end();++bb)
        (*bb)->draw(mpainter);
    if(rd.showTurns) rd.draw(mpainter);
    club->draw(mpainter);
    shootline->draw(mpainter);

    mpainter.end();
}

void Board::Reset()
{
    for(int i=0;i<balls.size();++i)
        delete balls[i];
    int xPos[] = {800-100,800,800,800,real_width/2,real_width/4*3,real_width/10*9},
    yPos[] {real_height/2,real_height/2,real_height/2-292,real_height/2+292,real_height/2
    ,real_height/2,real_height/2};
    QColor Colors[] = {Qt::white,Qt::yellow,Qt::green,QColor(139,69,19),Qt::blue,
                      QColor(255,192,203),Qt::black};
    Ball::ball_color bcs[]={
        Ball::bai,Ball::huang,Ball::lv,Ball::zong,Ball::lan,Ball::fen,Ball::hei
    };

    for(int i=0;i<7;++i)
    {
        balls.push_back(new Ball(xPos[i]/rev_scale,yPos[i]/rev_scale,ball_radius,Colors[i]));
        balls[i]->rank = bcs[i];
    }

    for(int i=1;i<5;++i){
        for(int j=0;j<i;++j){
            balls.push_back(new Ball(balls[5]->x+(ball_radius+1)*2*(i+2),
                    balls[5]->y-(ball_radius+1)*((i-1)-j*2),ball_radius,Qt::red));
            balls.back()->rank = Ball::hong;
        }
    }

//    balls[0]->accelacte(10000,1);
    update();
}

Board::~Board()
{
    for(int i=0;i<balls.size();++i)
        delete balls[i];
    delete ui;
}

void Board::doUpdate()
{
    update();
}
