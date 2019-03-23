#include "widget.h"
#include "ui_widget.h"

bool MainWindow::eventFilter(QObject *who, QEvent *Event)
{
    if(who!=this) return true;

    if(Event->type()==QEvent::MouseButtonPress){
        QMouseEvent *event = dynamic_cast<QMouseEvent*>(Event);
            int i=0;
            int dx=abs(balls[i]->x - event->pos().x()),
                    dy = abs(balls[i]->y - event->pos().y());
            if(std::sqrt(dx*dx+dy*dy)<=balls[i]->r){
                balls[i]->selected = true;
                selectedIndex = i;
            }

    }else if(selectedIndex!=-1&&Event->type()==QEvent::MouseMove){
        QMouseEvent *event = dynamic_cast<QMouseEvent*>(Event);
        mousex = event->x();
        mousey = event->y();
        update();
    }else if(Event->type()==QEvent::MouseButtonRelease&&selectedIndex!=-1){
        balls[selectedIndex]->selected =false;
        selectedIndex = -1;
        update();
    }else return false;
    return true;
}

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    selectedIndex{-1}
{
    int Nhole_size = hole_size/rev_scale,Nbound_width=bound_width/rev_scale;
    setFixedSize(real_width/rev_scale,real_height/rev_scale);
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
    Reset();
    installEventFilter(this);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    mpainter.begin(this);
    for(int i=0;i<6;++i)
    {
        bounds[i]->draw(mpainter);
        holes[i]->draw(mpainter);
    }
    for(auto bb = balls.begin();bb!=balls.end();++bb)
        (*bb)->draw(mpainter);
    if(selectedIndex!=-1){
        QPen mpen = mpainter.pen();
        mpainter.setPen(vectpen);
//        qDebug() << balls[selectedIndex]->y << mousey;
        mpainter.drawLine(balls[selectedIndex]->x,balls[selectedIndex]->y,mousex,mousey);
        mpainter.setPen(mpen);
    }
    mpainter.end();
}

void MainWindow::Reset()
{
    for(int i=0;i<balls.size();++i)
        delete balls[i];
    int xPos[] = {800-100,800,800,800,real_width/2,real_width/4*3,real_width/10*9},
    yPos[] {real_height/2,real_height/2,real_height/2-292,real_height/2+292,real_height/2
    ,real_height/2,real_height/2};
    QColor Colors[] = {Qt::white,Qt::yellow,Qt::green,QColor(139,69,19),Qt::blue,
                      QColor(255,192,203),Qt::black};
    for(int i=0;i<7;++i)
        balls.push_back(new Ball(xPos[i]/rev_scale,yPos[i]/rev_scale,ball_radius,Colors[i]));
    for(int i=1;i<5;++i){
        for(int j=0;j<i;++j){
            balls.push_back(new Ball(balls[5]->x+ball_radius*2*(i+2),
                    balls[5]->y-ball_radius*((i-1)-j*2),ball_radius,Qt::red));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
