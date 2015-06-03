#include "scenery.h"
#include "player.h"
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QKeyEvent>


Scenary::Scenary(QWidget *parent)
{
    resize(800,600);
    this->setFocus();
    _Rows = 12;
    _Col = 20;

    _w_sz = width()/_Col;
    _h_sz = height()/_Rows;
    _x = _y = 0;

    RectColors.resize(_Rows);
    for(int r = 0; r < _Rows; r++) {
        RectColors[r].resize(_Col);
    }
    RectPos.resize(_Rows);
    for(int r = 0; r < _Rows; r++) {
        RectPos[r].resize(_Col);
    }

    define_Scenary(1);

    _p1 = new Player(this);
}

void Scenary::draw()
{
    repaint();

}

void Scenary::define_Scenary(int type)
{
    if(type ==1){

        //define cenario 1
        RectColors[0][0]=-1;
        RectColors[0][1]=-1;
        RectColors[0][2]=-1;
        RectColors[0][3]=-1;
        RectColors[0][4]=-1;
        RectColors[0][5]=-1;
        RectColors[0][6]=-1;
        RectColors[0][7]=-1;
        RectColors[0][8]=-1;
        RectColors[0][9]=-1;
        RectColors[0][10]=-1;
        RectColors[0][11]=-1;
        RectColors[0][12]=-1;
        RectColors[0][13]=-1;
        RectColors[0][14]=-1;
        RectColors[0][15]=-1;
        RectColors[0][16]=-1;
        RectColors[0][17]=-1;
        RectColors[0][18]=-1;
        RectColors[0][19]=-1;

        RectColors[1][0]=-1;
        RectColors[1][1]=1;
        RectColors[1][2]=1;
        RectColors[1][3]=1;
        RectColors[1][4]=1;
        RectColors[1][5]=1;
        RectColors[1][6]=1;
        RectColors[1][7]=1;
        RectColors[1][8]=1;
        RectColors[1][9]=1;
        RectColors[1][10]=1;
        RectColors[1][11]=1;
        RectColors[1][12]=1;
        RectColors[1][13]=1;
        RectColors[1][14]=1;
        RectColors[1][15]=1;
        RectColors[1][16]=1;
        RectColors[1][17]=1;
        RectColors[1][18]=1;
        RectColors[1][19]=-1;


        RectColors[2][0]=-1;
        RectColors[2][1]=0;
        RectColors[2][2]=1;
        RectColors[2][3]=1;
        RectColors[2][4]=1;
        RectColors[2][5]=1;
        RectColors[2][6]=1;
        RectColors[2][7]=1;
        RectColors[2][8]=1;
        RectColors[2][9]=1;
        RectColors[2][10]=1;
        RectColors[2][11]=1;
        RectColors[2][12]=1;
        RectColors[2][13]=1;
        RectColors[2][14]=1;
        RectColors[2][15]=1;
        RectColors[2][16]=1;
        RectColors[2][17]=1;
        RectColors[2][18]=1;
        RectColors[2][19]=-1;

        RectColors[3][0]=-1;
        RectColors[3][1]=0;
        RectColors[3][2]=0;
        RectColors[3][3]=1;
        RectColors[3][4]=1;
        RectColors[3][5]=1;
        RectColors[3][6]=1;
        RectColors[3][7]=1;
        RectColors[3][8]=1;
        RectColors[3][9]=1;
        RectColors[3][10]=1;
        RectColors[3][11]=1;
        RectColors[3][12]=1;
        RectColors[3][13]=1;
        RectColors[3][14]=1;
        RectColors[3][15]=1;
        RectColors[3][16]=1;
        RectColors[3][17]=1;
        RectColors[3][18]=1;
        RectColors[3][19]=-1;

        RectColors[4][0]=-1;
        RectColors[4][1]=0;
        RectColors[4][2]=0;
        RectColors[4][3]=0;
        RectColors[4][4]=1;
        RectColors[4][5]=1;
        RectColors[4][6]=1;
        RectColors[4][7]=1;
        RectColors[4][8]=1;
        RectColors[4][9]=1;
        RectColors[4][10]=1;
        RectColors[4][11]=1;
        RectColors[4][12]=1;
        RectColors[4][13]=1;
        RectColors[4][14]=1;
        RectColors[4][15]=1;
        RectColors[4][16]=1;
        RectColors[4][17]=1;
        RectColors[4][18]=1;
        RectColors[4][19]=-1;

        RectColors[5][0]=-1;
        RectColors[5][1]=0;
        RectColors[5][2]=0;
        RectColors[5][3]=0;
        RectColors[5][4]=0;
        RectColors[5][5]=0;
        RectColors[5][6]=0;
        RectColors[5][7]=1;
        RectColors[5][8]=1;
        RectColors[5][9]=1;
        RectColors[5][10]=1;
        RectColors[5][11]=1;
        RectColors[5][12]=1;
        RectColors[5][13]=1;
        RectColors[5][14]=1;
        RectColors[5][15]=1;
        RectColors[5][16]=1;
        RectColors[5][17]=1;
        RectColors[5][18]=1;
        RectColors[5][19]=-1;

        RectColors[6][0]=-1;
        RectColors[6][1]=0;
        RectColors[6][2]=0;
        RectColors[6][3]=0;
        RectColors[6][4]=0;
        RectColors[6][5]=0;
        RectColors[6][6]=0;
        RectColors[6][7]=1;
        RectColors[6][8]=1;
        RectColors[6][9]=1;
        RectColors[6][10]=1;
        RectColors[6][11]=1;
        RectColors[6][12]=1;
        RectColors[6][13]=1;
        RectColors[6][14]=1;
        RectColors[6][15]=1;
        RectColors[6][16]=1;
        RectColors[6][17]=1;
        RectColors[6][18]=1;
        RectColors[6][19]=-1;

        RectColors[7][0]=-1;
        RectColors[7][1]=0;
        RectColors[7][2]=0;
        RectColors[7][3]=0;
        RectColors[7][4]=1;
        RectColors[7][5]=1;
        RectColors[7][6]=1;
        RectColors[7][7]=1;
        RectColors[7][8]=1;
        RectColors[7][9]=1;
        RectColors[7][10]=1;
        RectColors[7][11]=1;
        RectColors[7][12]=1;
        RectColors[7][13]=1;
        RectColors[7][14]=1;
        RectColors[7][15]=1;
        RectColors[7][16]=1;
        RectColors[7][17]=1;
        RectColors[7][18]=1;
        RectColors[7][19]=-1;

        RectColors[8][0]=-1;
        RectColors[8][1]=0;
        RectColors[8][2]=0;
        RectColors[8][3]=1;
        RectColors[8][4]=1;
        RectColors[8][5]=1;
        RectColors[8][6]=1;
        RectColors[8][7]=1;
        RectColors[8][8]=1;
        RectColors[8][9]=1;
        RectColors[8][10]=1;
        RectColors[8][11]=1;
        RectColors[8][12]=1;
        RectColors[8][13]=1;
        RectColors[8][14]=1;
        RectColors[8][15]=1;
        RectColors[8][16]=1;
        RectColors[8][17]=1;
        RectColors[8][18]=1;
        RectColors[8][19]=-1;

        RectColors[9][0]=-1;
        RectColors[9][1]=0;
        RectColors[9][2]=1;
        RectColors[9][3]=1;
        RectColors[9][4]=1;
        RectColors[9][5]=1;
        RectColors[9][6]=1;
        RectColors[9][7]=1;
        RectColors[9][8]=1;
        RectColors[9][9]=1;
        RectColors[9][10]=1;
        RectColors[9][11]=1;
        RectColors[9][12]=1;
        RectColors[9][13]=1;
        RectColors[9][14]=1;
        RectColors[9][15]=1;
        RectColors[9][16]=1;
        RectColors[9][17]=1;
        RectColors[9][18]=1;
        RectColors[9][19]=-1;

        RectColors[10][0]=-1;
        RectColors[10][1]=1;
        RectColors[10][2]=1;
        RectColors[10][3]=1;
        RectColors[10][4]=1;
        RectColors[10][5]=1;
        RectColors[10][6]=1;
        RectColors[10][7]=1;
        RectColors[10][8]=1;
        RectColors[10][9]=1;
        RectColors[10][10]=1;
        RectColors[10][11]=1;
        RectColors[10][12]=1;
        RectColors[10][13]=1;
        RectColors[10][14]=1;
        RectColors[10][15]=1;
        RectColors[10][16]=1;
        RectColors[10][17]=1;
        RectColors[10][18]=1;
        RectColors[10][19]=-1;


        RectColors[11][0]=-1;
        RectColors[11][1]=-1;
        RectColors[11][2]=-1;
        RectColors[11][3]=-1;
        RectColors[11][4]=-1;
        RectColors[11][5]=-1;
        RectColors[11][6]=-1;
        RectColors[11][7]=-1;
        RectColors[11][8]=-1;
        RectColors[11][9]=-1;
        RectColors[11][10]=-1;
        RectColors[11][11]=-1;
        RectColors[11][12]=-1;
        RectColors[11][13]=-1;
        RectColors[11][14]=-1;
        RectColors[11][15]=-1;
        RectColors[11][16]=-1;
        RectColors[11][17]=-1;
        RectColors[11][18]=-1;
        RectColors[11][19]=-1;


        //        RectColors[12][0]=-1;
        //        RectColors[12][1]=1;
        //        RectColors[12][2]=1;
        //        RectColors[12][3]=1;
        //        RectColors[12][4]=1;
        //        RectColors[12][5]=0;
        //        RectColors[12][6]=0;
        //        RectColors[12][7]=0;
        //        RectColors[12][8]=0;
        //        RectColors[12][9]=0;
        //        RectColors[12][10]=0;
        //        RectColors[12][11]=0;
        //        RectColors[12][12]=0;
        //        RectColors[12][13]=0;
        //        RectColors[12][14]=1;
        //        RectColors[12][15]=1;
        //        RectColors[12][16]=1;
        //        RectColors[12][17]=1;
        //        RectColors[12][18]=-1;


        //        RectColors[13][0]=-1;
        //        RectColors[13][1]=0;
        //        RectColors[13][2]=0;
        //        RectColors[13][3]=0;
        //        RectColors[13][4]=0;
        //        RectColors[13][5]=0;
        //        RectColors[13][6]=0;
        //        RectColors[13][7]=0;
        //        RectColors[13][8]=0;
        //        RectColors[13][9]=0;
        //        RectColors[13][10]=0;
        //        RectColors[13][11]=0;
        //        RectColors[13][12]=0;
        //        RectColors[13][13]=0;
        //        RectColors[13][14]=0;
        //        RectColors[13][15]=0;
        //        RectColors[13][16]=0;
        //        RectColors[13][17]=0;
        //        RectColors[13][18]=-1;

        //        RectColors[14][0]=-1;
        //        RectColors[14][1]=-1;
        //        RectColors[14][2]=-1;
        //        RectColors[14][3]=-1;
        //        RectColors[14][4]=-1;
        //        RectColors[14][5]=-1;
        //        RectColors[14][6]=-1;
        //        RectColors[14][7]=-1;
        //        RectColors[14][8]=-1;
        //        RectColors[14][9]=-1;
        //        RectColors[14][10]=-1;
        //        RectColors[14][11]=-1;
        //        RectColors[14][12]=-1;
        //        RectColors[14][13]=-1;
        //        RectColors[14][14]=-1;
        //        RectColors[14][15]=-1;
        //        RectColors[14][16]=-1;
        //        RectColors[14][17]=-1;
        //        RectColors[14][18]=-1;

    }

}

void Scenary::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);

    painter.setPen(Qt::gray);
    _x = _y = 0;
    _w_sz = width()/_Col;
    _h_sz = height()/_Rows;

    for(int i=0;i<_Rows;i++){
        for(int j=0;j<_Col;j++){

            RectPos [i][j]= QPoint(_x,_y);
            if(RectColors[i][j]==0){
                painter.setBrush( Qt::white );
            }
            if(RectColors[i][j]==1){
                painter.setBrush( Qt::black );
            }
            if(RectColors[i][j]==-1){
                painter.setBrush( Qt::gray );
            }
            painter.drawRect(_x ,_y, _w_sz, _h_sz);
            //qDebug()<< RectPos [i][j];
            _x += _w_sz;
        }
        _y +=_h_sz;
        _x=0;
    }
    _p1->draw(painter);
}

void Scenary::keyPressEvent(QKeyEvent *event)
{
    QFrame::keyPressEvent(event);
    qDebug()<<"key event";
    switch (event->key()) {
    case Qt::Key_Up:
        _p1->setX(100);
        _p1->setY(100);
        repaint();
        qDebug()<<"up";
        break;
    case Qt::Key_Down:
        qDebug()<<"down";

        break;
    case Qt::Key_Left:
        qDebug()<<"left";

        break;
    case Qt::Key_Right:
        qDebug()<<"right";

        break;
    default:
        break;
    }
}

void Scenary::resizeEvent(QResizeEvent *event)
{
    QFrame::resizeEvent(event);

    //    //qDebug()<< width();
    //    //qDebug()<< height();

    _x = _y = 0;
    _w_sz = width()/_Col;
    _h_sz = height()/_Rows;
}
