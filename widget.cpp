#include "widget.h"
#include "ui_widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
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
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    mpainter.begin(this);
    for(int i=0;i<6;++i)
    {
        bounds[i]->draw(mpainter);
        holes[i]->draw(mpainter);
    }
    mpainter.end();
}

MainWindow::~MainWindow()
{
    delete ui;
}
