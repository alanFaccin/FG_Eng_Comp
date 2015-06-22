#include "scenery.h"
#include "player.h"
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QKeyEvent>
#include <QApplication>
#include <QColor>
#include "missile.h"
#include <QMediaPlayer>
#include <QSound>
#include <QDebug>

#define preto 1
#define branco 0
#define cinza -1

int salto =5;
Qt::Key tecla_b;
Qt::Key tecla_p;
bool tst_fire = false;
float pos_x_atua_p1,pos_y_atua_p1,pos_x_atua_p2,pos_y_atua_p2;

QPoint _btn_1,_btn_2,_btn_3,_btn_4,_btn_5;
int _w_bt,_h_bt;
bool selected_level = false;




bool keyLeft = false,keyRight = false,keyUp = false,keyDown = false, KeySpace = false;
bool keyA = false,keyD = false,keyW = false,keyS = false;

//Missile _bu;


Scenary::Scenary(QWidget *parent)
{

    //time animation improved
    _counter = 0;
    _accumulator60 = 0;
    _max_fps = 60;
    _constant_dt = 1000 / _max_fps;
    _last_time_60fps = QDateTime::currentMSecsSinceEpoch();


    resize(800,600);

    this->setFocus();
    _Rows = 12;
    _Col = 20;

    _w_sz = width()/_Col;
    _h_sz = height()/_Rows;
    _x = _y = 0;

    _cont_t =0;

    RectColors.resize(_Rows);
    for(int r = 0; r < _Rows; r++) {
        RectColors[r].resize(_Col);
    }
    RectPos.resize(_Rows);
    for(int r = 0; r < _Rows; r++) {
        RectPos[r].resize(_Col);
    }

    define_Scenary(1);

    _p1 = new Player(this, Qt::white,700,300);
    _p2 = new Player(this, Qt::black,100,300);


    //play background music

    QMediaPlayer *_bg_music = new QMediaPlayer();
    //  _bg_music->setMedia(QUrl("qrc:/sounds/sounds/bg_music.mp3"));
    //qDebug()<<_bg_music->mediaStatus();
    //->play();
    // qDebug()<<_bg_music->mediaStatus();
    // sound colision
    _colision_music = new QMediaPlayer();
    _colision_music->setMedia(QUrl("qrc:/sounds/sounds/fire2.wav"));

    //qDebug()<<_colision_music->mediaStatus();


    // Start timer
    QTimer::singleShot(1000/_max_fps, this, SLOT(_tick()));
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
        RectColors[6][10]=-1;
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
    if(type ==2){

        //linha 1
        RectColors[0][0]=branco;
        RectColors[0][1]=branco;
        RectColors[0][2]=branco;
        RectColors[0][3]=branco;
        RectColors[0][4]=branco;
        RectColors[0][5]=branco;
        RectColors[0][6]=branco;
        RectColors[0][7]=branco;
        RectColors[0][8]=branco;
        RectColors[0][9]=branco;
        RectColors[0][10]=preto;
        RectColors[0][11]=preto;
        RectColors[0][12]=preto;
        RectColors[0][13]=preto;
        RectColors[0][14]=preto;
        RectColors[0][15]=preto;
        RectColors[0][16]=preto;
        RectColors[0][17]=preto;
        RectColors[0][18]=preto;
        RectColors[0][19]=preto;
        //linha 2
        RectColors[1][0]=branco;
        RectColors[1][1]=branco;
        RectColors[1][2]=branco;
        RectColors[1][3]=branco;
        RectColors[1][4]=branco;
        RectColors[1][5]=branco;
        RectColors[1][6]=branco;
        RectColors[1][7]=branco;
        RectColors[1][8]=branco;
        RectColors[1][9]=cinza;
        RectColors[1][10]=cinza;
        RectColors[1][11]=preto;
        RectColors[1][12]=preto;
        RectColors[1][13]=preto;
        RectColors[1][14]=preto;
        RectColors[1][15]=preto;
        RectColors[1][16]=preto;
        RectColors[1][17]=preto;
        RectColors[1][18]=preto;
        RectColors[1][19]=preto;


        RectColors[2][0]=branco;
        RectColors[2][1]=branco;
        RectColors[2][2]=branco;
        RectColors[2][3]=branco;
        RectColors[2][4]=branco;
        RectColors[2][5]=branco;
        RectColors[2][6]=branco;
        RectColors[2][7]=branco;
        RectColors[2][8]=branco;
        RectColors[2][9]=cinza;
        RectColors[2][10]=cinza;
        RectColors[2][11]=preto;
        RectColors[2][12]=preto;
        RectColors[2][13]=preto;
        RectColors[2][14]=preto;
        RectColors[2][15]=preto;
        RectColors[2][16]=preto;
        RectColors[2][17]=preto;
        RectColors[2][18]=preto;
        RectColors[2][19]=preto;

        RectColors[3][0]=branco;
        RectColors[3][1]=branco;
        RectColors[3][2]=branco;
        RectColors[3][3]=branco;
        RectColors[3][4]=branco;
        RectColors[3][5]=branco;
        RectColors[3][6]=branco;
        RectColors[3][7]=branco;
        RectColors[3][8]=branco;
        RectColors[3][9]=cinza;
        RectColors[3][10]=cinza;
        RectColors[3][11]=preto;
        RectColors[3][12]=preto;
        RectColors[3][13]=preto;
        RectColors[3][14]=preto;
        RectColors[3][15]=preto;
        RectColors[3][16]=preto;
        RectColors[3][17]=preto;
        RectColors[3][18]=preto;
        RectColors[3][19]=preto;

        RectColors[4][0]=branco;
        RectColors[4][1]=branco;
        RectColors[4][2]=branco;
        RectColors[4][3]=branco;
        RectColors[4][4]=branco;
        RectColors[4][5]=branco;
        RectColors[4][6]=branco;
        RectColors[4][7]=branco;
        RectColors[4][8]=branco;
        RectColors[4][9]=cinza;
        RectColors[4][10]=cinza;
        RectColors[4][11]=preto;
        RectColors[4][12]=preto;
        RectColors[4][13]=preto;
        RectColors[4][14]=preto;
        RectColors[4][15]=preto;
        RectColors[4][16]=preto;
        RectColors[4][17]=preto;
        RectColors[4][18]=preto;
        RectColors[4][19]=preto;

        RectColors[5][0]=branco;
        RectColors[5][1]=branco;
        RectColors[5][2]=branco;
        RectColors[5][3]=branco;
        RectColors[5][4]=branco;
        RectColors[5][5]=branco;
        RectColors[5][6]=branco;
        RectColors[5][7]=branco;
        RectColors[5][8]=branco;
        RectColors[5][9]=cinza;
        RectColors[5][10]=cinza;
        RectColors[5][11]=preto;
        RectColors[5][12]=preto;
        RectColors[5][13]=preto;
        RectColors[5][14]=preto;
        RectColors[5][15]=preto;
        RectColors[5][16]=preto;
        RectColors[5][17]=preto;
        RectColors[5][18]=preto;
        RectColors[5][19]=preto;

        RectColors[6][0]=branco;
        RectColors[6][1]=branco;
        RectColors[6][2]=branco;
        RectColors[6][3]=branco;
        RectColors[6][4]=branco;
        RectColors[6][5]=branco;
        RectColors[6][6]=branco;
        RectColors[6][7]=branco;
        RectColors[6][8]=branco;
        RectColors[6][9]=cinza;
        RectColors[6][10]=cinza;
        RectColors[6][11]=preto;
        RectColors[6][12]=preto;
        RectColors[6][13]=preto;
        RectColors[6][14]=preto;
        RectColors[6][15]=preto;
        RectColors[6][16]=preto;
        RectColors[6][17]=preto;
        RectColors[6][18]=preto;
        RectColors[6][19]=preto;

        RectColors[7][0]=branco;
        RectColors[7][1]=branco;
        RectColors[7][2]=branco;
        RectColors[7][3]=branco;
        RectColors[7][4]=branco;
        RectColors[7][5]=branco;
        RectColors[7][6]=branco;
        RectColors[7][7]=branco;
        RectColors[7][8]=branco;
        RectColors[7][9]=cinza;
        RectColors[7][10]=cinza;
        RectColors[7][11]=preto;
        RectColors[7][12]=preto;
        RectColors[7][13]=preto;
        RectColors[7][14]=preto;
        RectColors[7][15]=preto;
        RectColors[7][16]=preto;
        RectColors[7][17]=preto;
        RectColors[7][18]=preto;
        RectColors[7][19]=preto;

        RectColors[8][0]=branco;
        RectColors[8][1]=branco;
        RectColors[8][2]=branco;
        RectColors[8][3]=branco;
        RectColors[8][4]=branco;
        RectColors[8][5]=branco;
        RectColors[8][6]=branco;
        RectColors[8][7]=branco;
        RectColors[8][8]=branco;
        RectColors[8][9]=cinza;
        RectColors[8][10]=cinza;
        RectColors[8][11]=preto;
        RectColors[8][12]=preto;
        RectColors[8][13]=preto;
        RectColors[8][14]=preto;
        RectColors[8][15]=preto;
        RectColors[8][16]=preto;
        RectColors[8][17]=preto;
        RectColors[8][18]=preto;
        RectColors[8][19]=preto;

        RectColors[9][0]=branco;
        RectColors[9][1]=branco;
        RectColors[9][2]=branco;
        RectColors[9][3]=branco;
        RectColors[9][4]=branco;
        RectColors[9][5]=branco;
        RectColors[9][6]=branco;
        RectColors[9][7]=branco;
        RectColors[9][8]=branco;
        RectColors[9][9]=cinza;
        RectColors[9][10]=cinza;
        RectColors[9][11]=preto;
        RectColors[9][12]=preto;
        RectColors[9][13]=preto;
        RectColors[9][14]=preto;
        RectColors[9][15]=preto;
        RectColors[9][16]=preto;
        RectColors[9][17]=preto;
        RectColors[9][18]=preto;
        RectColors[9][19]=preto;

        RectColors[10][0]=branco;
        RectColors[10][1]=branco;
        RectColors[10][2]=branco;
        RectColors[10][3]=branco;
        RectColors[10][4]=branco;
        RectColors[10][5]=branco;
        RectColors[10][6]=branco;
        RectColors[10][7]=branco;
        RectColors[10][8]=branco;
        RectColors[10][9]=cinza;
        RectColors[10][10]=cinza;
        RectColors[10][11]=preto;
        RectColors[10][12]=preto;
        RectColors[10][13]=preto;
        RectColors[10][14]=preto;
        RectColors[10][15]=preto;
        RectColors[10][16]=preto;
        RectColors[10][17]=preto;
        RectColors[10][18]=preto;
        RectColors[10][19]=preto;


        RectColors[11][0]=branco;
        RectColors[11][1]=branco;
        RectColors[11][2]=branco;
        RectColors[11][3]=branco;
        RectColors[11][4]=branco;
        RectColors[11][5]=branco;
        RectColors[11][6]=branco;
        RectColors[11][7]=branco;
        RectColors[11][8]=branco;
        RectColors[11][9]=branco;
        RectColors[11][10]=preto;
        RectColors[11][11]=preto;
        RectColors[11][12]=preto;
        RectColors[11][13]=preto;
        RectColors[11][14]=preto;
        RectColors[11][15]=preto;
        RectColors[11][16]=preto;
        RectColors[11][17]=preto;
        RectColors[11][18]=preto;
        RectColors[11][19]=preto;
    }
    if(type ==3){

        //linha 1
        RectColors[0][0]=branco;
        RectColors[0][1]=branco;
        RectColors[0][2]=branco;
        RectColors[0][3]=branco;
        RectColors[0][4]=branco;
        RectColors[0][5]=branco;
        RectColors[0][6]=branco;
        RectColors[0][7]=branco;
        RectColors[0][8]=branco;
        RectColors[0][9]=branco;
        RectColors[0][10]=preto;
        RectColors[0][11]=preto;
        RectColors[0][12]=preto;
        RectColors[0][13]=preto;
        RectColors[0][14]=preto;
        RectColors[0][15]=preto;
        RectColors[0][16]=preto;
        RectColors[0][17]=preto;
        RectColors[0][18]=preto;
        RectColors[0][19]=preto;
        //linha 2
        RectColors[1][0]=branco;
        RectColors[1][1]=branco;
        RectColors[1][2]=branco;
        RectColors[1][3]=branco;
        RectColors[1][4]=branco;
        RectColors[1][5]=branco;
        RectColors[1][6]=branco;
        RectColors[1][7]=branco;
        RectColors[1][8]=branco;
        RectColors[1][9]=branco;
        RectColors[1][10]=preto;
        RectColors[1][11]=preto;
        RectColors[1][12]=preto;
        RectColors[1][13]=preto;
        RectColors[1][14]=preto;
        RectColors[1][15]=preto;
        RectColors[1][16]=preto;
        RectColors[1][17]=preto;
        RectColors[1][18]=preto;
        RectColors[1][19]=preto;


        RectColors[2][0]=branco;
        RectColors[2][1]=branco;
        RectColors[2][2]=cinza;
        RectColors[2][3]=cinza;
        RectColors[2][4]=branco;
        RectColors[2][5]=branco;
        RectColors[2][6]=branco;
        RectColors[2][7]=branco;
        RectColors[2][8]=branco;
        RectColors[2][9]=branco;
        RectColors[2][10]=preto;
        RectColors[2][11]=preto;
        RectColors[2][12]=preto;
        RectColors[2][13]=preto;
        RectColors[2][14]=preto;
        RectColors[2][15]=preto;
        RectColors[2][16]=cinza;
        RectColors[2][17]=cinza;
        RectColors[2][18]=preto;
        RectColors[2][19]=preto;

        RectColors[3][0]=branco;
        RectColors[3][1]=branco;
        RectColors[3][2]=cinza;
        RectColors[3][3]=cinza;
        RectColors[3][4]=branco;
        RectColors[3][5]=branco;
        RectColors[3][6]=branco;
        RectColors[3][7]=branco;
        RectColors[3][8]=branco;
        RectColors[3][9]=branco;
        RectColors[3][10]=preto;
        RectColors[3][11]=preto;
        RectColors[3][12]=preto;
        RectColors[3][13]=preto;
        RectColors[3][14]=preto;
        RectColors[3][15]=preto;
        RectColors[3][16]=cinza;
        RectColors[3][17]=cinza;
        RectColors[3][18]=preto;
        RectColors[3][19]=preto;

        RectColors[4][0]=branco;
        RectColors[4][1]=branco;
        RectColors[4][2]=cinza;
        RectColors[4][3]=cinza;
        RectColors[4][4]=branco;
        RectColors[4][5]=branco;
        RectColors[4][6]=branco;
        RectColors[4][7]=branco;
        RectColors[4][8]=cinza;
        RectColors[4][9]=cinza;
        RectColors[4][10]=cinza;
        RectColors[4][11]=cinza;
        RectColors[4][12]=preto;
        RectColors[4][13]=preto;
        RectColors[4][14]=preto;
        RectColors[4][15]=preto;
        RectColors[4][16]=cinza;
        RectColors[4][17]=cinza;
        RectColors[4][18]=preto;
        RectColors[4][19]=preto;

        RectColors[5][0]=branco;
        RectColors[5][1]=branco;
        RectColors[5][2]=branco;
        RectColors[5][3]=branco;
        RectColors[5][4]=branco;
        RectColors[5][5]=branco;
        RectColors[5][6]=branco;
        RectColors[5][7]=branco;
        RectColors[5][8]=cinza;
        RectColors[5][9]=cinza;
        RectColors[5][10]=cinza;
        RectColors[5][11]=cinza;
        RectColors[5][12]=preto;
        RectColors[5][13]=preto;
        RectColors[5][14]=preto;
        RectColors[5][15]=preto;
        RectColors[5][16]=preto;
        RectColors[5][17]=preto;
        RectColors[5][18]=preto;
        RectColors[5][19]=preto;

        RectColors[6][0]=branco;
        RectColors[6][1]=branco;
        RectColors[6][2]=branco;
        RectColors[6][3]=branco;
        RectColors[6][4]=branco;
        RectColors[6][5]=branco;
        RectColors[6][6]=branco;
        RectColors[6][7]=branco;
        RectColors[6][8]=cinza;
        RectColors[6][9]=cinza;
        RectColors[6][10]=cinza;
        RectColors[6][11]=cinza;
        RectColors[6][12]=preto;
        RectColors[6][13]=preto;
        RectColors[6][14]=preto;
        RectColors[6][15]=preto;
        RectColors[6][16]=preto;
        RectColors[6][17]=preto;
        RectColors[6][18]=preto;
        RectColors[6][19]=preto;

        RectColors[7][0]=branco;
        RectColors[7][1]=branco;
        RectColors[7][2]=cinza;
        RectColors[7][3]=cinza;
        RectColors[7][4]=branco;
        RectColors[7][5]=branco;
        RectColors[7][6]=branco;
        RectColors[7][7]=branco;
        RectColors[7][8]=cinza;
        RectColors[7][9]=cinza;
        RectColors[7][10]=cinza;
        RectColors[7][11]=cinza;
        RectColors[7][12]=preto;
        RectColors[7][13]=preto;
        RectColors[7][14]=preto;
        RectColors[7][15]=preto;
        RectColors[7][16]=cinza;
        RectColors[7][17]=cinza;
        RectColors[7][18]=preto;
        RectColors[7][19]=preto;

        RectColors[8][0]=branco;
        RectColors[8][1]=branco;
        RectColors[8][2]=cinza;
        RectColors[8][3]=cinza;
        RectColors[8][4]=branco;
        RectColors[8][5]=branco;
        RectColors[8][6]=branco;
        RectColors[8][7]=branco;
        RectColors[8][8]=branco;
        RectColors[8][9]=branco;
        RectColors[8][10]=preto;
        RectColors[8][11]=preto;
        RectColors[8][12]=preto;
        RectColors[8][13]=preto;
        RectColors[8][14]=preto;
        RectColors[8][15]=preto;
        RectColors[8][16]=cinza;
        RectColors[8][17]=cinza;
        RectColors[8][18]=preto;
        RectColors[8][19]=preto;

        RectColors[9][0]=branco;
        RectColors[9][1]=branco;
        RectColors[9][2]=cinza;
        RectColors[9][3]=cinza;
        RectColors[9][4]=branco;
        RectColors[9][5]=branco;
        RectColors[9][6]=branco;
        RectColors[9][7]=branco;
        RectColors[9][8]=branco;
        RectColors[9][9]=branco;
        RectColors[9][10]=preto;
        RectColors[9][11]=preto;
        RectColors[9][12]=preto;
        RectColors[9][13]=preto;
        RectColors[9][14]=preto;
        RectColors[9][15]=preto;
        RectColors[9][16]=cinza;
        RectColors[9][17]=cinza;
        RectColors[9][18]=preto;
        RectColors[9][19]=preto;

        RectColors[10][0]=branco;
        RectColors[10][1]=branco;
        RectColors[10][2]=branco;
        RectColors[10][3]=branco;
        RectColors[10][4]=branco;
        RectColors[10][5]=branco;
        RectColors[10][6]=branco;
        RectColors[10][7]=branco;
        RectColors[10][8]=branco;
        RectColors[10][9]=branco;
        RectColors[10][10]=preto;
        RectColors[10][11]=preto;
        RectColors[10][12]=preto;
        RectColors[10][13]=preto;
        RectColors[10][14]=preto;
        RectColors[10][15]=preto;
        RectColors[10][16]=preto;
        RectColors[10][17]=preto;
        RectColors[10][18]=preto;
        RectColors[10][19]=preto;


        RectColors[11][0]=branco;
        RectColors[11][1]=branco;
        RectColors[11][2]=branco;
        RectColors[11][3]=branco;
        RectColors[11][4]=branco;
        RectColors[11][5]=branco;
        RectColors[11][6]=branco;
        RectColors[11][7]=branco;
        RectColors[11][8]=branco;
        RectColors[11][9]=branco;
        RectColors[11][10]=preto;
        RectColors[11][11]=preto;
        RectColors[11][12]=preto;
        RectColors[11][13]=preto;
        RectColors[11][14]=preto;
        RectColors[11][15]=preto;
        RectColors[11][16]=preto;
        RectColors[11][17]=preto;
        RectColors[11][18]=preto;
        RectColors[11][19]=preto;

    }
    if(type ==4){

        //linha 1
        RectColors[0][0]=branco;
        RectColors[0][1]=branco;
        RectColors[0][2]=branco;
        RectColors[0][3]=branco;
        RectColors[0][4]=cinza;
        RectColors[0][5]=cinza;
        RectColors[0][6]=branco;
        RectColors[0][7]=branco;
        RectColors[0][8]=branco;
        RectColors[0][9]=branco;
        RectColors[0][10]=preto;
        RectColors[0][11]=preto;
        RectColors[0][12]=preto;
        RectColors[0][13]=preto;
        RectColors[0][14]=preto;
        RectColors[0][15]=preto;
        RectColors[0][16]=preto;
        RectColors[0][17]=preto;
        RectColors[0][18]=preto;
        RectColors[0][19]=preto;
        //linha 2
        RectColors[1][0]=branco;
        RectColors[1][1]=branco;
        RectColors[1][2]=branco;
        RectColors[1][3]=branco;
        RectColors[1][4]=cinza;
        RectColors[1][5]=cinza;
        RectColors[1][6]=branco;
        RectColors[1][7]=branco;
        RectColors[1][8]=branco;
        RectColors[1][9]=branco;
        RectColors[1][10]=preto;
        RectColors[1][11]=preto;
        RectColors[1][12]=preto;
        RectColors[1][13]=preto;
        RectColors[1][14]=preto;
        RectColors[1][15]=preto;
        RectColors[1][16]=preto;
        RectColors[1][17]=preto;
        RectColors[1][18]=preto;
        RectColors[1][19]=preto;


        RectColors[2][0]=branco;
        RectColors[2][1]=branco;
        RectColors[2][2]=branco;
        RectColors[2][3]=branco;
        RectColors[2][4]=cinza;
        RectColors[2][5]=cinza;
        RectColors[2][6]=branco;
        RectColors[2][7]=branco;
        RectColors[2][8]=branco;
        RectColors[2][9]=branco;
        RectColors[2][10]=preto;
        RectColors[2][11]=preto;
        RectColors[2][12]=preto;
        RectColors[2][13]=preto;
        RectColors[2][14]=preto;
        RectColors[2][15]=preto;
        RectColors[2][16]=preto;
        RectColors[2][17]=preto;
        RectColors[2][18]=preto;
        RectColors[2][19]=preto;

        RectColors[3][0]=branco;
        RectColors[3][1]=branco;
        RectColors[3][2]=branco;
        RectColors[3][3]=branco;
        RectColors[3][4]=cinza;
        RectColors[3][5]=cinza;
        RectColors[3][6]=branco;
        RectColors[3][7]=branco;
        RectColors[3][8]=branco;
        RectColors[3][9]=branco;
        RectColors[3][10]=preto;
        RectColors[3][11]=preto;
        RectColors[3][12]=preto;
        RectColors[3][13]=preto;
        RectColors[3][14]=preto;
        RectColors[3][15]=preto;
        RectColors[3][16]=preto;
        RectColors[3][17]=preto;
        RectColors[3][18]=preto;
        RectColors[3][19]=preto;

        RectColors[4][0]=branco;
        RectColors[4][1]=branco;
        RectColors[4][2]=branco;
        RectColors[4][3]=branco;
        RectColors[4][4]=branco;
        RectColors[4][5]=branco;
        RectColors[4][6]=branco;
        RectColors[4][7]=branco;
        RectColors[4][8]=branco;
        RectColors[4][9]=branco;
        RectColors[4][10]=branco;
        RectColors[4][11]=branco;
        RectColors[4][12]=branco;
        RectColors[4][13]=branco;
        RectColors[4][14]=branco;
        RectColors[4][15]=branco;
        RectColors[4][16]=branco;
        RectColors[4][17]=branco;
        RectColors[4][18]=branco;
        RectColors[4][19]=branco;

        RectColors[5][0]=branco;
        RectColors[5][1]=branco;
        RectColors[5][2]=branco;
        RectColors[5][3]=branco;
        RectColors[5][4]=branco;
        RectColors[5][5]=branco;
        RectColors[5][6]=branco;
        RectColors[5][7]=branco;
        RectColors[5][8]=cinza;
        RectColors[5][9]=cinza;
        RectColors[5][10]=cinza;
        RectColors[5][11]=cinza;
        RectColors[5][12]=preto;
        RectColors[5][13]=preto;
        RectColors[5][14]=preto;
        RectColors[5][15]=preto;
        RectColors[5][16]=preto;
        RectColors[5][17]=preto;
        RectColors[5][18]=preto;
        RectColors[5][19]=preto;

        RectColors[6][0]=branco;
        RectColors[6][1]=branco;
        RectColors[6][2]=branco;
        RectColors[6][3]=branco;
        RectColors[6][4]=branco;
        RectColors[6][5]=branco;
        RectColors[6][6]=branco;
        RectColors[6][7]=branco;
        RectColors[6][8]=cinza;
        RectColors[6][9]=cinza;
        RectColors[6][10]=cinza;
        RectColors[6][11]=cinza;
        RectColors[6][12]=preto;
        RectColors[6][13]=preto;
        RectColors[6][14]=preto;
        RectColors[6][15]=preto;
        RectColors[6][16]=preto;
        RectColors[6][17]=preto;
        RectColors[6][18]=preto;
        RectColors[6][19]=preto;

        RectColors[7][0]=preto;
        RectColors[7][1]=preto;
        RectColors[7][2]=preto;
        RectColors[7][3]=preto;
        RectColors[7][4]=preto;
        RectColors[7][5]=preto;
        RectColors[7][6]=preto;
        RectColors[7][7]=preto;
        RectColors[7][8]=preto;
        RectColors[7][9]=preto;
        RectColors[7][10]=preto;
        RectColors[7][11]=preto;
        RectColors[7][12]=preto;
        RectColors[7][13]=preto;
        RectColors[7][14]=preto;
        RectColors[7][15]=preto;
        RectColors[7][16]=preto;
        RectColors[7][17]=preto;
        RectColors[7][18]=preto;
        RectColors[7][19]=preto;

        RectColors[8][0]=branco;
        RectColors[8][1]=branco;
        RectColors[8][2]=branco;
        RectColors[8][3]=branco;
        RectColors[8][4]=branco;
        RectColors[8][5]=branco;
        RectColors[8][6]=branco;
        RectColors[8][7]=branco;
        RectColors[8][8]=branco;
        RectColors[8][9]=branco;
        RectColors[8][10]=preto;
        RectColors[8][11]=preto;
        RectColors[8][12]=preto;
        RectColors[8][13]=preto;
        RectColors[8][14]=cinza;
        RectColors[8][15]=cinza;
        RectColors[8][16]=preto;
        RectColors[8][17]=preto;
        RectColors[8][18]=preto;
        RectColors[8][19]=preto;

        RectColors[9][0]=branco;
        RectColors[9][1]=branco;
        RectColors[9][2]=branco;
        RectColors[9][3]=branco;
        RectColors[9][4]=branco;
        RectColors[9][5]=branco;
        RectColors[9][6]=branco;
        RectColors[9][7]=branco;
        RectColors[9][8]=branco;
        RectColors[9][9]=branco;
        RectColors[9][10]=preto;
        RectColors[9][11]=preto;
        RectColors[9][12]=preto;
        RectColors[9][13]=preto;
        RectColors[9][14]=cinza;
        RectColors[9][15]=cinza;
        RectColors[9][16]=preto;
        RectColors[9][17]=preto;
        RectColors[9][18]=preto;
        RectColors[9][19]=preto;

        RectColors[10][0]=branco;
        RectColors[10][1]=branco;
        RectColors[10][2]=branco;
        RectColors[10][3]=branco;
        RectColors[10][4]=branco;
        RectColors[10][5]=branco;
        RectColors[10][6]=branco;
        RectColors[10][7]=branco;
        RectColors[10][8]=branco;
        RectColors[10][9]=branco;
        RectColors[10][10]=preto;
        RectColors[10][11]=preto;
        RectColors[10][12]=preto;
        RectColors[10][13]=preto;
        RectColors[10][14]=cinza;
        RectColors[10][15]=cinza;
        RectColors[10][16]=preto;
        RectColors[10][17]=preto;
        RectColors[10][18]=preto;
        RectColors[10][19]=preto;


        RectColors[11][0]=branco;
        RectColors[11][1]=branco;
        RectColors[11][2]=branco;
        RectColors[11][3]=branco;
        RectColors[11][4]=branco;
        RectColors[11][5]=branco;
        RectColors[11][6]=branco;
        RectColors[11][7]=branco;
        RectColors[11][8]=branco;
        RectColors[11][9]=branco;
        RectColors[11][10]=preto;
        RectColors[11][11]=preto;
        RectColors[11][12]=preto;
        RectColors[11][13]=preto;
        RectColors[11][14]=cinza;
        RectColors[11][15]=cinza;
        RectColors[11][16]=preto;
        RectColors[11][17]=preto;
        RectColors[11][18]=preto;
        RectColors[11][19]=preto;
    }
    if(type ==5){


        //linha 1
        RectColors[0][0]=branco;
        RectColors[0][1]=branco;
        RectColors[0][2]=branco;
        RectColors[0][3]=branco;
        RectColors[0][4]=branco;
        RectColors[0][5]=branco;
        RectColors[0][6]=branco;
        RectColors[0][7]=branco;
        RectColors[0][8]=branco;
        RectColors[0][9]=branco;
        RectColors[0][10]=branco;
        RectColors[0][11]=branco;
        RectColors[0][12]=cinza;
        RectColors[0][13]=cinza;
        RectColors[0][14]=cinza;
        RectColors[0][15]=cinza;
        RectColors[0][16]=cinza;
        RectColors[0][17]=cinza;
        RectColors[0][18]=cinza;
        RectColors[0][19]=preto;
        //linha 2
        RectColors[1][0]=branco;
        RectColors[1][1]=branco;
        RectColors[1][2]=branco;
        RectColors[1][3]=branco;
        RectColors[1][4]=branco;
        RectColors[1][5]=branco;
        RectColors[1][6]=branco;
        RectColors[1][7]=branco;
        RectColors[1][8]=branco;
        RectColors[1][9]=branco;
        RectColors[1][10]=branco;
        RectColors[1][11]=cinza;
        RectColors[1][12]=cinza;
        RectColors[1][13]=cinza;
        RectColors[1][14]=cinza;
        RectColors[1][15]=cinza;
        RectColors[1][16]=cinza;
        RectColors[1][17]=cinza;
        RectColors[1][18]=preto;
        RectColors[1][19]=preto;


        RectColors[2][0]=branco;
        RectColors[2][1]=branco;
        RectColors[2][2]=branco;
        RectColors[2][3]=branco;
        RectColors[2][4]=branco;
        RectColors[2][5]=branco;
        RectColors[2][6]=branco;
        RectColors[2][7]=branco;
        RectColors[2][8]=branco;
        RectColors[2][9]=branco;
        RectColors[2][10]=branco;
        RectColors[2][11]=branco;
        RectColors[2][12]=branco;
        RectColors[2][13]=cinza;
        RectColors[2][14]=cinza;
        RectColors[2][15]=cinza;
        RectColors[2][16]=cinza;
        RectColors[2][17]=preto;
        RectColors[2][18]=preto;
        RectColors[2][19]=preto;

        RectColors[3][0]=branco;
        RectColors[3][1]=branco;
        RectColors[3][2]=branco;
        RectColors[3][3]=branco;
        RectColors[3][4]=branco;
        RectColors[3][5]=branco;
        RectColors[3][6]=branco;
        RectColors[3][7]=branco;
        RectColors[3][8]=branco;
        RectColors[3][9]=branco;
        RectColors[3][10]=branco;
        RectColors[3][11]=branco;
        RectColors[3][12]=branco;
        RectColors[3][13]=cinza;
        RectColors[3][14]=cinza;
        RectColors[3][15]=cinza;
        RectColors[3][16]=preto;
        RectColors[3][17]=preto;
        RectColors[3][18]=preto;
        RectColors[3][19]=preto;

        RectColors[4][0]=branco;
        RectColors[4][1]=branco;
        RectColors[4][2]=branco;
        RectColors[4][3]=branco;
        RectColors[4][4]=branco;
        RectColors[4][5]=branco;
        RectColors[4][6]=branco;
        RectColors[4][7]=branco;
        RectColors[4][8]=branco;
        RectColors[4][9]=branco;
        RectColors[4][10]=branco;
        RectColors[4][11]=branco;
        RectColors[4][12]=branco;
        RectColors[4][13]=branco;
        RectColors[4][14]=branco;
        RectColors[4][15]=preto;
        RectColors[4][16]=preto;
        RectColors[4][17]=preto;
        RectColors[4][18]=preto;
        RectColors[4][19]=preto;

        RectColors[5][0]=branco;
        RectColors[5][1]=branco;
        RectColors[5][2]=branco;
        RectColors[5][3]=branco;
        RectColors[5][4]=branco;
        RectColors[5][5]=branco;
        RectColors[5][6]=branco;
        RectColors[5][7]=cinza;
        RectColors[5][8]=cinza;
        RectColors[5][9]=cinza;
        RectColors[5][10]=cinza;
        RectColors[5][11]=cinza;
        RectColors[5][12]=cinza;
        RectColors[5][13]=cinza;
        RectColors[5][14]=preto;
        RectColors[5][15]=preto;
        RectColors[5][16]=preto;
        RectColors[5][17]=preto;
        RectColors[5][18]=preto;
        RectColors[5][19]=preto;

        RectColors[6][0]=branco;
        RectColors[6][1]=branco;
        RectColors[6][2]=branco;
        RectColors[6][3]=branco;
        RectColors[6][4]=branco;
        RectColors[6][5]=branco;
        RectColors[6][6]=cinza;
        RectColors[6][7]=cinza;
        RectColors[6][8]=cinza;
        RectColors[6][9]=cinza;
        RectColors[6][10]=cinza;
        RectColors[6][11]=cinza;
        RectColors[6][12]=cinza;
        RectColors[6][13]=preto;
        RectColors[6][14]=preto;
        RectColors[6][15]=preto;
        RectColors[6][16]=preto;
        RectColors[6][17]=preto;
        RectColors[6][18]=preto;
        RectColors[6][19]=preto;

        RectColors[7][0]=branco;
        RectColors[7][1]=branco;
        RectColors[7][2]=branco;
        RectColors[7][3]=branco;
        RectColors[7][4]=branco;
        RectColors[7][5]=preto;
        RectColors[7][6]=preto;
        RectColors[7][7]=preto;
        RectColors[7][8]=preto;
        RectColors[7][9]=preto;
        RectColors[7][10]=preto;
        RectColors[7][11]=preto;
        RectColors[7][12]=preto;
        RectColors[7][13]=preto;
        RectColors[7][14]=preto;
        RectColors[7][15]=preto;
        RectColors[7][16]=preto;
        RectColors[7][17]=preto;
        RectColors[7][18]=preto;
        RectColors[7][19]=preto;

        RectColors[8][0]=branco;
        RectColors[8][1]=branco;
        RectColors[8][2]=branco;
        RectColors[8][3]=branco;
        RectColors[8][4]=cinza;
        RectColors[8][5]=cinza;
        RectColors[8][6]=cinza;
        RectColors[8][7]=preto;
        RectColors[8][8]=preto;
        RectColors[8][9]=preto;
        RectColors[8][10]=preto;
        RectColors[8][11]=preto;
        RectColors[8][12]=preto;
        RectColors[8][13]=preto;
        RectColors[8][14]=preto;
        RectColors[8][15]=preto;
        RectColors[8][16]=preto;
        RectColors[8][17]=preto;
        RectColors[8][18]=preto;
        RectColors[8][19]=preto;

        RectColors[9][0]=branco;
        RectColors[9][1]=branco;
        RectColors[9][2]=branco;
        RectColors[9][3]=cinza;
        RectColors[9][4]=cinza;
        RectColors[9][5]=cinza;
        RectColors[9][6]=cinza;
        RectColors[9][7]=preto;
        RectColors[9][8]=preto;
        RectColors[9][9]=preto;
        RectColors[9][10]=preto;
        RectColors[9][11]=preto;
        RectColors[9][12]=preto;
        RectColors[9][13]=preto;
        RectColors[9][14]=preto;
        RectColors[9][15]=preto;
        RectColors[9][16]=preto;
        RectColors[9][17]=preto;
        RectColors[9][18]=preto;
        RectColors[9][19]=preto;

        RectColors[10][0]=branco;
        RectColors[10][1]=branco;
        RectColors[10][2]=cinza;
        RectColors[10][3]=cinza;
        RectColors[10][4]=cinza;
        RectColors[10][5]=cinza;
        RectColors[10][6]=cinza;
        RectColors[10][7]=cinza;
        RectColors[10][8]=cinza;
        RectColors[10][9]=preto;
        RectColors[10][10]=preto;
        RectColors[10][11]=preto;
        RectColors[10][12]=preto;
        RectColors[10][13]=preto;
        RectColors[10][14]=preto;
        RectColors[10][15]=preto;
        RectColors[10][16]=preto;
        RectColors[10][17]=preto;
        RectColors[10][18]=preto;
        RectColors[10][19]=preto;


        RectColors[11][0]=branco;
        RectColors[11][1]=cinza;
        RectColors[11][2]=cinza;
        RectColors[11][3]=cinza;
        RectColors[11][4]=cinza;
        RectColors[11][5]=cinza;
        RectColors[11][6]=cinza;
        RectColors[11][7]=cinza;
        RectColors[11][8]=preto;
        RectColors[11][9]=preto;
        RectColors[11][10]=preto;
        RectColors[11][11]=preto;
        RectColors[11][12]=preto;
        RectColors[11][13]=preto;
        RectColors[11][14]=preto;
        RectColors[11][15]=preto;
        RectColors[11][16]=preto;
        RectColors[11][17]=preto;
        RectColors[11][18]=preto;
        RectColors[11][19]=preto;
    }
}

int Scenary::Colision_Player(Player *_p)
{
    if(_p->getColor() == Qt::white){
        for(int i=0;i<_Rows;i++){
            for(int j=0;j<_Col;j++){

                if(RectColors[i][j] == cinza || RectColors[i][j] == branco ){

                    if((_p->getX()+_p->getW_size())>=(RectPos[i][j].x()) &&
                            (_p->getX()+salto)<=(RectPos[i][j].x()+_w_sz) &&
                            (_p->getY() + _p->getH_size()) >= (RectPos[i][j].y()) &&
                            (_p->getY()) + salto <= (RectPos[i][j].y()+_h_sz))  {

                        return 1;

                    }

                }
            }
        }
    }

    if(_p->getColor() == Qt::black){
        for(int i=0;i<_Rows;i++){
            for(int j=0;j<_Col;j++){

                if(RectColors[i][j] == cinza || RectColors[i][j] == preto ){

                    if((_p->getX()+_p->getW_size())>=(RectPos[i][j].x()) &&
                            (_p->getX()+salto)<=(RectPos[i][j].x()+_w_sz) &&
                            (_p->getY() + _p->getH_size()) >= (RectPos[i][j].y()) &&
                            (_p->getY()) + salto <= (RectPos[i][j].y()+_h_sz))  {


                        //                        qDebug()<<"Colidiu";

                        return 1;

                    }

                }
            }
        }
    }
}

int Scenary::Colision_Missile_Scenary_black(Missile *_t)
{
    if(_t->getColor() == Qt::black){
        for(int i=0;i<_Rows;i++){
            for(int j=0;j<_Col;j++){

                if(RectColors[i][j] == preto){

                    if((_t->getX()+_t->get_w_sz())>=(RectPos[i][j].x()) &&
                            (_t->getX())<=(RectPos[i][j].x()+_w_sz) &&
                            (_t->getY() + _t->get_h_sz()) >= (RectPos[i][j].y()) &&
                            (_t->getY())<= (RectPos[i][j].y()+_h_sz))  {

                        RectColors[i][j] = branco;

                        if(_colision_music->state() == QMediaPlayer::PlayingState){
                            _colision_music->setPosition(0);
                        }else if (_colision_music->state() == QMediaPlayer::StoppedState){
                            _colision_music->play();
                        }

                        return 1;

                    }

                }

                if(RectColors[i][j] == cinza){

                    if((_t->getX()+_t->get_w_sz())>=(RectPos[i][j].x()) &&
                            (_t->getX())<=(RectPos[i][j].x()+_w_sz) &&
                            (_t->getY() + _t->get_h_sz()) >= (RectPos[i][j].y()) &&
                            (_t->getY())<= (RectPos[i][j].y()+_h_sz))  {

                        //_t->setActive(false);

                        _t->setX(-5000);
                        _t->setY(-5000);

                        return 1;

                    }

                }
                //Colisao com o player adiversario
                if((_t->getX()+_t->get_w_sz())>=(_p1->getX()) &&
                        (_t->getX())<=(_p1->getX()+_p1->getW_size()) &&
                        (_t->getY() + _t->get_h_sz()) >= (_p1->getY()) &&
                        (_t->getY())<= (_p1->getY()+_p1->getH_size()))  {

                    for(int i=0;i<_Rows;i++){
                        for(int j=0;j<_Col;j++){
                            RectColors[i][j] = branco;
                            _p1->setActive(false);
                        }
                    }


                    return 1;

                }
            }
        }
    }
}

int Scenary::Colision_SB_Scenary_white(Missile *_t)
{
    // qDebug()<<"Colision_SB_Scenary_white: "<<_t->getColor();
    if(_t->getColor() == Qt::red ||_t->getColor() == Qt::blue ){
        for(int i=0;i<_Rows;i++){
            for(int j=0;j<_Col;j++){

                if(RectColors[i][j] == branco){

                    if((_t->getX()+_t->get_w_sz())>=(RectPos[i][j].x()) &&
                            (_t->getX())<=(RectPos[i][j].x()+_w_sz) &&
                            (_t->getY() + _t->get_h_sz()) >= (RectPos[i][j].y()) &&
                            (_t->getY())<= (RectPos[i][j].y()+_h_sz))  {

                        RectColors[i][j] = preto;
                        if(_colision_music->state() == QMediaPlayer::PlayingState){
                            _colision_music->setPosition(0);
                        }else if (_colision_music->state() == QMediaPlayer::StoppedState){
                            _colision_music->play();
                        }

                        //qDebug()<<"Colidiu";

                        return 1;

                    }

                }

                if(RectColors[i][j] == cinza){

                    if((_t->getX()+_t->get_w_sz())>=(RectPos[i][j].x()) &&
                            (_t->getX())<=(RectPos[i][j].x()+_w_sz) &&
                            (_t->getY() + _t->get_h_sz()) >= (RectPos[i][j].y()) &&
                            (_t->getY())<= (RectPos[i][j].y()+_h_sz))  {


                        //_t->setActive(false);

                        //teste
                        _t->setX(-5000);
                        _t->setY(-5000);

                        return 1;

                    }

                }
                //Colisao com o player adiversario
                if(_t->getSf_p()== 1){
                    if((_t->getX()+_t->get_w_sz())>=(_p2->getX()) &&
                            (_t->getX())<=(_p2->getX()+_p2->getW_size()) &&
                            (_t->getY() + _t->get_h_sz()) >= (_p2->getY()) &&
                            (_t->getY())<= (_p2->getY()+_p2->getH_size()))  {

                        for(int i=0;i<_Rows;i++){
                            for(int j=0;j<_Col;j++){
                                RectColors[i][j] = preto;
                            }
                        }
                        _p2->setActive(false);
                        return 1;
                    }
                }
            }
        }
    }
}

int Scenary::Colision_SB_Scenary_black(Missile *_t)
{
    //qDebug()<<"aqui";
    if(_t->getColor() == Qt::red ||_t->getColor() == Qt::blue ){
        for(int i=0;i<_Rows;i++){
            for(int j=0;j<_Col;j++){

                if(RectColors[i][j] == preto){

                    if((_t->getX()+_t->get_w_sz())>=(RectPos[i][j].x()) &&
                            (_t->getX())<=(RectPos[i][j].x()+_w_sz) &&
                            (_t->getY() + _t->get_h_sz()) >= (RectPos[i][j].y()) &&
                            (_t->getY())<= (RectPos[i][j].y()+_h_sz))  {

                        RectColors[i][j] = branco;

                        if(_colision_music->state() == QMediaPlayer::PlayingState){
                            _colision_music->setPosition(0);
                        }else if (_colision_music->state() == QMediaPlayer::StoppedState){
                            _colision_music->play();
                        }

                        return 1;

                    }

                }

                if(RectColors[i][j] == cinza){

                    if((_t->getX()+_t->get_w_sz())>=(RectPos[i][j].x()) &&
                            (_t->getX())<=(RectPos[i][j].x()+_w_sz) &&
                            (_t->getY() + _t->get_h_sz()) >= (RectPos[i][j].y()) &&
                            (_t->getY())<= (RectPos[i][j].y()+_h_sz))  {

                        //_t->setActive(false);

                        _t->setX(-5000);
                        _t->setY(-5000);

                        return 1;

                    }

                }
                //Colisao com o player adiversario
                if(_t->getSf_p()== 2){
                    if((_t->getX()+_t->get_w_sz())>=(_p1->getX()) &&
                            (_t->getX())<=(_p1->getX()+_p1->getW_size()) &&
                            (_t->getY() + _t->get_h_sz()) >= (_p1->getY()) &&
                            (_t->getY())<= (_p1->getY()+_p1->getH_size()))  {

                        for(int i=0;i<_Rows;i++){
                            for(int j=0;j<_Col;j++){
                                RectColors[i][j] = branco;
                                _p1->setActive(false);
                            }
                        }


                        return 1;

                    }
                }
            }
        }
    }
}

int Scenary::Colision_Missile_Scenary_white(Missile *_t)
{

    if(_t->getColor() == Qt::white){
        for(int i=0;i<_Rows;i++){
            for(int j=0;j<_Col;j++){

                if(RectColors[i][j] == branco){

                    if((_t->getX()+_t->get_w_sz())>=(RectPos[i][j].x()) &&
                            (_t->getX())<=(RectPos[i][j].x()+_w_sz) &&
                            (_t->getY() + _t->get_h_sz()) >= (RectPos[i][j].y()) &&
                            (_t->getY())<= (RectPos[i][j].y()+_h_sz))  {

                        RectColors[i][j] = preto;
                        if(_colision_music->state() == QMediaPlayer::PlayingState){
                            _colision_music->setPosition(0);
                        }else if (_colision_music->state() == QMediaPlayer::StoppedState){
                            _colision_music->play();
                        }

                        //qDebug()<<"Colidiu";

                        return 1;

                    }

                }

                if(RectColors[i][j] == cinza){

                    if((_t->getX()+_t->get_w_sz())>=(RectPos[i][j].x()) &&
                            (_t->getX())<=(RectPos[i][j].x()+_w_sz) &&
                            (_t->getY() + _t->get_h_sz()) >= (RectPos[i][j].y()) &&
                            (_t->getY())<= (RectPos[i][j].y()+_h_sz))  {


                        //_t->setActive(false);

                        //teste
                        _t->setX(-5000);
                        _t->setY(-5000);

                        return 1;

                    }

                }
                //Colisao com o player adiversario
                if((_t->getX()+_t->get_w_sz())>=(_p2->getX()) &&
                        (_t->getX())<=(_p2->getX()+_p2->getW_size()) &&
                        (_t->getY() + _t->get_h_sz()) >= (_p2->getY()) &&
                        (_t->getY())<= (_p2->getY()+_p2->getH_size()))  {

                    for(int i=0;i<_Rows;i++){
                        for(int j=0;j<_Col;j++){
                            RectColors[i][j] = preto;
                        }
                    }
                    _p2->setActive(false);
                    return 1;

                }
            }
        }
    }

}

int Scenary::Colision_Missile_Missile()
{
    if(_p1->getQtdFire()>=0 && _p2->getQtdFire()>=0 ){
        if(_p1->getActive() && _p2->getActive()){

           // if(_p1->getMunicao().size()>_p2->getMunicao().size()){
                for(int i=0;i<_p1->getMunicao().size();i++){
                    if(_p1->getBullet(i)->getActive()){
                        for(int j=0;j<_p2->getMunicao().size();j++){
                               if(_p2->getBullet(j)->getActive()){
                                   if((_p1->getBullet(i)->getX()+_p1->getBullet(i)->get_w_sz())>=(_p2->getBullet(j)->getX()) &&
                                           (_p1->getBullet(i)->getX())<=(_p2->getBullet(j)->getX()+_p2->getBullet(j)->get_w_sz()) &&
                                           (_p1->getBullet(i)->getY() + _p1->getBullet(i)->get_h_sz()) >= (_p2->getBullet(j)->getY()) &&
                                           (_p1->getBullet(i)->getY())<= (_p2->getBullet(j)->getY() + _p2->getBullet(j)->get_h_sz()))  {

                                       _p1->getBullet(i)->setX(-5000);
                                       _p1->getBullet(i)->setY(-5000);

                                       _p2->getBullet(j)->setX(-5000);
                                       _p2->getBullet(j)->setY(-5000);

                                       return 1;

                                   }

                               }
                        }
                    }

                }
            //}


        }
    }
}

int Scenary::Colision_cenario()
{
    //player 1
    //colisao lado direito do cenario
    if(_p1->getX()+_p1->getW_size()>width()){
        _p1->setX(width() - _p1->getW_size());
    }
    // colisao do parte inferior do cenario
    if (_p1->getY() + _p1->getH_size() > height())
    {
        _p1->setY(height() - _p1->getH_size());
    }
    //colisao lado esquerdo do cenario
    if (_p1->getX() < 0)
    {
        _p1->setX(0);
    }
    // colisao do parte superior do cenario
    if (_p1->getY() < 0)
    {
        _p1->setY(0);
    }

    //player 2
    //colisao lado direito do cenario
    if(_p2->getX()+_p2->getW_size()>width()){
        _p2->setX(width() - _p2->getW_size());
    }
    // colisao do parte inferior do cenario
    if (_p2->getY() + _p2->getH_size() > height())
    {
        _p2->setY(height() - _p2->getH_size());
    }
    //colisao lado esquerdo do cenario
    if (_p2->getX() < 0)
    {
        _p2->setX(0);
    }
    // colisao do parte superior do cenario
    if (_p2->getY() < 0)
    {
        _p2->setY(0);
    }

}

void Scenary::colision_Special_bullet()
{
    if(_p1->getColor() == Qt::white){

        for(int i =0;i<_special.size();i++){
            if(_special.at(i)->getActive()){

                if((_p1->getX()+_p1->getW_size())>=(_special.at(i)->getX()) &&
                        (_p1->getX())<=(_special.at(i)->getX()+_special.at(i)->get_w_sz()) &&
                        (_p1->getY() + _p1->getH_size()) >= (_special.at(i)->getY()) &&
                        (_p1->getY()) <= (_special.at(i)->getY()+_special.at(i)->get_h_sz()))  {



                    _special.at(i)->setActive(false);
                    if( _special.at(i)->getColor()== Qt::blue){
                        _special.at(i)->set_h_sz(height()*0.04);
                        _special.at(i)->set_w_sz(width()*0.04);
                    }
                    _special.at(i)->setOwner();
                    _p1->addSpecialBullet(_special.at(i));
                    _p1->addSpecialFire();




                    //_special.remove(i);

                    // qDebug()<<"colisao";

                }
            }
        }

    }
    if(_p2->getColor() == Qt::black){

        for(int i =0;i<_special.size();i++){
            if(_special.at(i)->getActive()){

                if((_p2->getX()+_p2->getW_size())>=(_special.at(i)->getX()) &&
                        (_p2->getX())<=(_special.at(i)->getX()+_special.at(i)->get_w_sz()) &&
                        (_p2->getY() + _p2->getH_size()) >= (_special.at(i)->getY()) &&
                        (_p2->getY()) <= (_special.at(i)->getY()+_special.at(i)->get_h_sz()))  {


                    _special.at(i)->setActive(false);
                    if( _special.at(i)->getColor()== Qt::blue){
                        _special.at(i)->set_h_sz(height()*0.04);
                        _special.at(i)->set_w_sz(width()*0.04);
                    }
                    _special.at(i)->setOwner();
                    _p2->addSpecialBullet(_special.at(i));
                    _p2->addSpecialFire();




                    //_special.remove(i);

                    // qDebug()<<"colisao";

                }
            }
        }

    }

}

void Scenary::movePalyer()
{
    //player 1
    if (keyLeft && keyUp) {

        _p1->setX(_p1->getX()-2);
        _p1->setY(_p1->getY()-2);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()+2);
            _p1->setY(_p1->getY()+2);
        }
    }

    else if (keyRight && keyUp) {

        _p1->setX(_p1->getX()+2);
        _p1->setY(_p1->getY()-2);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()-2);
            _p1->setY(_p1->getY()+2);
        }
    }

    else if (keyDown && keyLeft) {

        _p1->setX(_p1->getX()-2);
        _p1->setY(_p1->getY()+2);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()+2);
            _p1->setY(_p1->getY()-2);
        }
    }

    else if (keyDown && keyRight) {

        _p1->setX(_p1->getX()+2);
        _p1->setY(_p1->getY()+2);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()-2);
            _p1->setY(_p1->getY()-2);
        }
    }

    if (keyLeft){

        _p1->setX(_p1->getX()-6);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()+6);
        }
    }

    else if (keyRight){
        _p1->setX(_p1->getX()+6);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()-6);
        }
    }
    if (keyDown){
        _p1->setY(_p1->getY()+6);
        if(this->Colision_Player(_p1)==1){
            _p1->setY(_p1->getY()-6);
        }
    }

    else if (keyUp){
        _p1->setY(_p1->getY()-6);
        if(this->Colision_Player(_p1)==1){
            _p1->setY(_p1->getY()+6);
        }
    }

    //player 2
    if (keyA && keyW) {
        _p2->setX(_p2->getX()-5);
        _p2->setY(_p2->getY()-5);
        if(this->Colision_Player(_p2)==1){
            _p2->setX(_p2->getX()+5);
            _p2->setY(_p2->getY()+5);
        }
    }

    else if (keyD && keyW) {
        _p2->setX(_p2->getX()+5);
        _p2->setY(_p2->getY()-5);
        if(this->Colision_Player(_p2)==1){
            _p2->setX(_p2->getX()-5);
            _p2->setY(_p2->getY()+5);
        }
    }

    else if (keyS && keyA) {
        _p2->setX(_p2->getX()-5);
        _p2->setY(_p2->getY()+5);
        if(this->Colision_Player(_p2)==1){
            _p2->setX(_p2->getX()+5);
            _p2->setY(_p2->getY()-5);
        }
    }

    else if (keyS && keyD) {
        _p2->setX(_p2->getX()+5);
        _p2->setY(_p2->getY()+5);
        if(this->Colision_Player(_p2)==1){
            _p2->setX(_p2->getX()-5);
            _p2->setY(_p2->getY()-5);
        }
    }

    if (keyA){
        _p2->setX(_p2->getX()-5);
        if(this->Colision_Player(_p2)==1){
            _p2->setX(_p2->getX()+5);
        }
    }
    else if (keyD){
        _p2->setX(_p2->getX()+5);
        if(this->Colision_Player(_p2)==1){
            _p2->setX(_p2->getX()-5);
        }
    }
    if (keyS){
        _p2->setY(_p2->getY()+5);
        if(this->Colision_Player(_p2)==1){
            _p2->setY(_p2->getY()-5);
        }
    }
    else if (keyW) {
        _p2->setY(_p2->getY()-5);
        if(this->Colision_Player(_p2)==1){
            _p2->setY(_p2->getY()+5);
        }
    }


}

void Scenary::atualizaPosition()
{
    _x = _y = 0;
    _w_sz = width()/_Col;
    _h_sz = height()/_Rows;

    // atualiza a porcentagem x e y atual na janela
    pos_x_atua_p1 = (float) _p1->getX()/width();
    pos_y_atua_p1 = (float) _p1->getY()/height();

    pos_x_atua_p2 = (float) _p2->getX()/width();
    pos_y_atua_p2 = (float) _p2->getY()/height();
}

void Scenary::_tick()
{

    qint64 now = QDateTime::currentMSecsSinceEpoch();

    {

        qint64 passed = now - _last_time_60fps;
        _accumulator60 += passed;
        while (_accumulator60 >= _constant_dt)
        {
            _accumulator60 -= _constant_dt;
        }

        //inicio
        atualizaPosition();
        Colision_cenario();
        Colision_Missile_Scenary();
        colision_Special_bullet();
        Colision_Missile_Missile();
        movePalyer();
        draw();
        // acumula qtd vezes que passou aqui
        _cont_t++;

        _last_time_60fps = now;
    }

    _counter++;
    _counter = _counter % 60;

    // Reset the timer
    QTimer::singleShot(1000/_max_fps, this, SLOT(_tick()));
}

void Scenary::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::gray);

    // impressão do menu
    if(selected_level==false){



        for(int i=0;i<_Rows;i++){
            for(int j=0;j<_Col;j++){

                RectPos [i][j]= QPoint(_x,_y); // guarda a posição de cada quadradinho tabuleiro
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

        // inicio teste menu
        _btn_1.setX(width()/4);
        _btn_1.setY(height()/5);
        _btn_2.setX(width()/4);
        _btn_2.setY(_btn_1.y()+_h_bt+1);
        _btn_3.setX(width()/4);
        _btn_3.setY(_btn_2.y()+_h_bt+1);
        _btn_4.setX(width()/4);
        _btn_4.setY(_btn_3.y()+_h_bt+1);
        _btn_5.setX(width()/4);
        _btn_5.setY(_btn_4.y()+_h_bt+1);

        _w_bt = width()/2;
        _h_bt = height()/10;

        QFont font = QFont ("Arial");
        font.setPointSize (40);
        font.setFixedPitch (true);


        font.setPointSize (height()*0.05);
        //botoes
        painter.setBrush( Qt::white );
        painter.setOpacity(0.8f);
        painter.drawRect(0 ,0,width(),height());
        painter.setBrush( Qt::black );
        painter.setOpacity(100.0f);

        painter.setBrush( Qt::white );
        painter.drawRect(0,0,width(),height()/6);
        painter.setPen(Qt::black);
        painter.setFont(font);
        painter.drawText(width()/4,(height()*0.1),"FLIP GAME - Alan Jhones");

        painter.setBrush( Qt::black );
        //btn_1
        painter.drawRect(_btn_1.x() ,_btn_1.y(),_w_bt,_h_bt);
        painter.setPen(Qt::white);
        painter.setFont(font);
        painter.drawText(_btn_1.x()+_w_bt/2.7,_btn_1.y()+_h_bt/1.3,"Level I");
        //btn_2
        painter.drawRect(_btn_2.x() ,_btn_2.y(),_w_bt,_h_bt);
        painter.setPen(Qt::white);
        painter.setFont(font);
        painter.drawText(_btn_2.x()+_w_bt/2.7,_btn_2.y()+_h_bt/1.3,"Level II");
        //btn_3
        painter.drawRect(_btn_3.x() ,_btn_3.y(),_w_bt,_h_bt);
        painter.setPen(Qt::white);
        painter.setFont(font);
        painter.drawText(_btn_3.x()+_w_bt/2.7,_btn_3.y()+_h_bt/1.3,"Level III");
        //btn_4
        painter.drawRect(_btn_4.x() ,_btn_4.y(),_w_bt,_h_bt);
        painter.setPen(Qt::white);
        painter.setFont(font);
        painter.drawText(_btn_4.x()+_w_bt/2.7,_btn_4.y()+_h_bt/1.3,"Level IV");
        //btn_5
        painter.drawRect(_btn_5.x() ,_btn_5.y(),_w_bt,_h_bt);
        painter.setPen(Qt::white);
        painter.setFont(font);
        painter.drawText(_btn_5.x()+_w_bt/2.7,_btn_5.y()+_h_bt/1.3,"Level V");



        //fim teste menu
    }
    if(selected_level==true){

        //draw tabuleiro
        for(int i=0;i<_Rows;i++){
            for(int j=0;j<_Col;j++){

                RectPos [i][j]= QPoint(_x,_y); // guarda a posição de cada quadradinho tabuleiro
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


        //draw player
        _p1->draw(painter);
        _p2->draw(painter);
        //draw special fire
        generateSpecialFire(painter);
    }


}

void Scenary::keyPressEvent(QKeyEvent *event)
{

    switch(event->key()) {
    case Qt::Key_Left:
        keyLeft = true;
        tecla_b = Qt::Key_Left;
        break;
    case Qt::Key_Right:
        keyRight = true;
        tecla_b = Qt::Key_Right;
        break;
    case Qt::Key_Up:
        tecla_b = Qt::Key_Up;
        keyUp = true;
        break;
    case Qt::Key_Down:
        tecla_b = Qt::Key_Down;
        keyDown = true;
        break;
    case Qt::Key_A:
        tecla_p = Qt::Key_A;
        keyA = true;
        break;
    case Qt::Key_D:
        tecla_p = Qt::Key_D;
        keyD = true;
        break;
    case Qt::Key_W:
        tecla_p =Qt::Key_W;
        keyW = true;
        break;
    case Qt::Key_S:
        tecla_p =Qt::Key_S;
        keyS = true;
        break;
    case Qt::Key_Space:
        if(tecla_b != NULL){

            if(_p1->getQtdFire()<4){
                _p1->addFire();
               // qDebug()<<_p1->getQtdFire();
                if(tecla_b == Qt::Key_Up){
                    _p1->getBullet(_p1->getQtdFire())->setX(_p1->getX()+(_p1->getW_size()/2)-(_p1->getBullet(_p1->getQtdFire())->get_h_sz()/2));
                    _p1->getBullet(_p1->getQtdFire())->setY(_p1->getY()- _p1->getBullet(_p1->getQtdFire())->get_h_sz());
                    _p1->getBullet(_p1->getQtdFire())->setDirection('u');
                }
                if(tecla_b == Qt::Key_Down){
                    _p1->getBullet(_p1->getQtdFire())->setX(_p1->getX()+(_p1->getW_size()/2)-(_p1->getBullet(_p1->getQtdFire())->get_h_sz()/2));
                    _p1->getBullet(_p1->getQtdFire())->setY(_p1->getY()+_p1->getH_size());
                    _p1->getBullet(_p1->getQtdFire())->setDirection('d');
                }
                if(tecla_b == Qt::Key_Right){
                    _p1->getBullet(_p1->getQtdFire())->setX(_p1->getX()+_p1->getW_size());
                    _p1->getBullet(_p1->getQtdFire())->setY(_p1->getY()+(_p1->getH_size())/2-(_p1->getBullet(_p1->getQtdFire())->get_h_sz()/2));
                    _p1->getBullet(_p1->getQtdFire())->setDirection('r');
                }
                if(tecla_b == Qt::Key_Left){
                    _p1->getBullet(_p1->getQtdFire())->setX(_p1->getX()-_p1->getBullet(_p1->getQtdFire())->get_w_sz());
                    _p1->getBullet(_p1->getQtdFire())->setY(_p1->getY()+(_p1->getH_size())/2-(_p1->getBullet(_p1->getQtdFire())->get_h_sz()/2));
                    _p1->getBullet(_p1->getQtdFire())->setDirection('l');
                }

                //start fire
                // retirado do if _p1->getBullet(_p1->getQtdFire())->getQtdTiro()<=5 &&
                // if(tecla_b != NULL){
                _p1->getBullet(_p1->getQtdFire())->setActive(true);
                if(_p1->getBullet(_p1->getQtdFire())->getFireSound()->state() == QMediaPlayer::PlayingState ){
                    _p1->getBullet(_p1->getQtdFire())->getFireSound()->setPosition(0);
                }else if (_p1->getBullet(_p1->getQtdFire())->getFireSound()->state() == QMediaPlayer::StoppedState){
                    _p1->getBullet(_p1->getQtdFire())->getFireSound()->play();
                }

                //_p1->getBullet(_p1->getQtdFire())->addTiro();


                //}
            }

        }

        break;

    case Qt::Key_M:
        int index;
        //qDebug()<< _p1->getQtdSpecialFire();
        if(_p1->getQtdSpecialFire()>0){
            for(int i=0;i<_p1->getMunicao().size();i++){
                if(!(_p1->getBullet(i)->getActive())){
                    //qDebug()<<"index: "<<i;
                    //qDebug()<<_p1->getBullet(i)->getColor();
                    if(_p1->getBullet(i)->getColor() == Qt::red || _p1->getBullet(i)->getColor() == Qt::blue){
                        index = i;

                    }
                }
            }

            if(tecla_b == Qt::Key_Up){
                _p1->getBullet(index)->setX(_p1->getX()+(_p1->getW_size()/2)-( _p1->getBullet(index)->get_h_sz()/2));
                _p1->getBullet(index)->setY(_p1->getY()- _p1->getBullet(index)->get_h_sz()-5);
                _p1->getBullet(index)->setDirection('u');
            }
            if(tecla_b == Qt::Key_Down){
                _p1->getBullet(index)->setX(_p1->getX()+(_p1->getW_size()/2)-( _p1->getBullet(index)->get_h_sz()/2));
                _p1->getBullet(index)->setY(_p1->getY()+_p1->getH_size()+5);
                _p1->getBullet(index)->setDirection('d');
            }
            if(tecla_b == Qt::Key_Right){
                _p1->getBullet(index)->setY(_p1->getY()+(_p1->getH_size())/2-( _p1->getBullet(index)->get_h_sz()/2));
                _p1->getBullet(index)->setX(_p1->getX()+_p1->getW_size()+5);
                _p1->getBullet(index)->setDirection('r');
            }
            if(tecla_b == Qt::Key_Left){
                _p1->getBullet(index)->setY(_p1->getY()+(_p1->getH_size())/2-( _p1->getBullet(index)->get_h_sz()/2));
                _p1->getBullet(index)->setX(_p1->getX()- _p1->getBullet(index)->get_w_sz()-5);
                _p1->getBullet(index)->setDirection('l');
            }

            _p1->getBullet(index)->setSf_p(1);

            if(tecla_b != NULL){
                _p1->getBullet(index)->setActive(true);
                if( _p1->getBullet(index)->getFireSound()->state() == QMediaPlayer::PlayingState ){
                    _p1->getBullet(index)->getFireSound()->setPosition(0);
                }else if ( _p1->getBullet(index)->getFireSound()->state() == QMediaPlayer::StoppedState){
                    _p1->getBullet(index)->getFireSound()->play();
                }
            }

            _p1->removeSpecialFire();


        }
        //        _p1->addSpecialFire();
        //        if(tecla_b == Qt::Key_Up){
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setX(_p1->getX()+(_p1->getW_size()/2)-(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz()/2));
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setY(_p1->getY()- _p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz()-5);
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setDirection('u');
        //        }
        //        if(tecla_b == Qt::Key_Down){
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setX(_p1->getX()+(_p1->getW_size()/2)-(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz()/2));
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setY(_p1->getY()+_p1->getH_size()+5);
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setDirection('d');
        //        }
        //        if(tecla_b == Qt::Key_Right){
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setY(_p1->getY()+(_p1->getH_size())/2-(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz()/2));
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setX(_p1->getX()+_p1->getW_size()+5);
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setDirection('r');
        //        }
        //        if(tecla_b == Qt::Key_Left){
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setY(_p1->getY()+(_p1->getH_size())/2-(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz()/2));
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setX(_p1->getX()-_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_w_sz()-5);
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setDirection('l');
        //        }

        //        if(_p1->getQtdSpecialFire()>=0 && tecla_b != NULL){
        //            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setActive(true);
        //            if(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->getFireSound()->state() == QMediaPlayer::PlayingState ){
        //                _p1->getSpecialBullet(_p1->getQtdSpecialFire())->getFireSound()->setPosition(0);
        //            }else if (_p1->getSpecialBullet(_p1->getQtdSpecialFire())->getFireSound()->state() == QMediaPlayer::StoppedState){
        //                _p1->getSpecialBullet(_p1->getQtdSpecialFire())->getFireSound()->play();
        //            }
        //        }
        break;
    case Qt::Key_I:
        int index2;
        if(_p2->getQtdSpecialFire()>0){
            for(int i=0;i<_p2->getMunicao().size();i++){
                if(!(_p2->getBullet(i)->getActive())){
                    if(_p2->getBullet(i)->getColor() == Qt::red || _p2->getBullet(i)->getColor() == Qt::blue){
                        index2 = i;
                    }
                }
            }

            if(tecla_p == Qt::Key_W){
                _p2->getBullet(index2)->setX(_p2->getX()+(_p2->getW_size()/2)-( _p2->getBullet(index2)->get_h_sz()/2));
                _p2->getBullet(index2)->setY(_p2->getY()- _p2->getBullet(index2)->get_h_sz()-5);
                _p2->getBullet(index2)->setDirection('u');
            }
            if(tecla_p == Qt::Key_S){
                _p2->getBullet(index2)->setX(_p2->getX()+(_p2->getW_size()/2)-( _p2->getBullet(index2)->get_h_sz()/2));
                _p2->getBullet(index2)->setY(_p2->getY()+_p2->getH_size()+5);
                _p2->getBullet(index2)->setDirection('d');
            }
            if(tecla_p == Qt::Key_D){
                _p2->getBullet(index2)->setY(_p2->getY()+(_p2->getH_size())/2-( _p2->getBullet(index2)->get_h_sz()/2));
                _p2->getBullet(index2)->setX(_p2->getX()+_p2->getW_size()+5);
                _p2->getBullet(index2)->setDirection('r');
            }
            if(tecla_p == Qt::Key_A){
                _p2->getBullet(index2)->setY(_p2->getY()+(_p2->getH_size())/2-( _p2->getBullet(index2)->get_h_sz()/2));
                _p2->getBullet(index2)->setX(_p2->getX()- _p2->getBullet(index2)->get_w_sz()-5);
                _p2->getBullet(index2)->setDirection('l');
            }

            _p2->getBullet(index2)->setSf_p(2);

            if(tecla_p != NULL){
                _p2->getBullet(index2)->setActive(true);
                if( _p2->getBullet(index2)->getFireSound()->state() == QMediaPlayer::PlayingState ){
                    _p2->getBullet(index2)->getFireSound()->setPosition(0);
                }else if ( _p2->getBullet(index2)->getFireSound()->state() == QMediaPlayer::StoppedState){
                    _p2->getBullet(index2)->getFireSound()->play();
                }
            }

            _p2->removeSpecialFire();


        }

        break;
    case Qt::Key_U:
        if(_p2->getQtdFire()<4){
            // atualiza as Coordenadas do tiro
            //set direction
            _p2->addFire();
            if(tecla_p == Qt::Key_W){
                _p2->getBullet(_p2->getQtdFire())->setX(_p2->getX()+(_p2->getW_size()/2)-(_p2->getBullet(_p2->getQtdFire())->get_h_sz()/2));
                _p2->getBullet(_p2->getQtdFire())->setY(_p2->getY()- _p2->getBullet(_p2->getQtdFire())->get_h_sz());
                _p2->getBullet(_p2->getQtdFire())->setDirection('u');
            }
            if(tecla_p == Qt::Key_S){
                _p2->getBullet(_p2->getQtdFire())->setX(_p2->getX()+(_p2->getW_size()/2)-(_p2->getBullet(_p2->getQtdFire())->get_h_sz()/2));
                _p2->getBullet(_p2->getQtdFire())->setY(_p2->getY()+_p2->getH_size());
                _p2->getBullet(_p2->getQtdFire())->setDirection('d');
            }
            if(tecla_p == Qt::Key_D){
                _p2->getBullet(_p2->getQtdFire())->setX(_p2->getX()+_p2->getW_size());
                _p2->getBullet(_p2->getQtdFire())->setY(_p2->getY()+(_p2->getH_size())/2-(_p2->getBullet(_p2->getQtdFire())->get_h_sz()/2));
                _p2->getBullet(_p2->getQtdFire())->setDirection('r');
            }
            if(tecla_p == Qt::Key_A){
                _p2->getBullet(_p2->getQtdFire())->setX(_p2->getX()-_p2->getBullet(_p2->getQtdFire())->get_w_sz());
                _p2->getBullet(_p2->getQtdFire())->setY(_p2->getY()+(_p2->getH_size())/2-(_p2->getBullet(_p2->getQtdFire())->get_h_sz()/2));
                _p2->getBullet(_p2->getQtdFire())->setDirection('l');
            }

            //start fire

            if(_p2->getBullet(_p2->getQtdFire())->getQtdTiro()<=5 && tecla_p != NULL){
                _p2->getBullet(_p2->getQtdFire())->setActive(true);

                if(_p2->getBullet(_p2->getQtdFire())->getFireSound()->state() == QMediaPlayer::PlayingState ){
                    _p2->getBullet(_p2->getQtdFire())->getFireSound()->setPosition(0);
                }else if (_p2->getBullet(_p2->getQtdFire())->getFireSound()->state() == QMediaPlayer::StoppedState){
                    _p2->getBullet(_p2->getQtdFire())->getFireSound()->play();
                }

                //_p2->getBullet(_p2->getQtdFire())->addTiro();


            }

        }
        break;

    }
}

void Scenary::keyReleaseEvent(QKeyEvent *event) {

    if (!event->isAutoRepeat()) {
        switch(event->key()) {
        case Qt::Key_Left:
            keyLeft = false;
            break;
        case Qt::Key_Right:
            keyRight = false;
            break;
        case Qt::Key_Up:
            keyUp = false;
            break;
        case Qt::Key_Down:
            keyDown = false;
            break;
        case Qt::Key_A:
            keyA = false;
            break;
        case Qt::Key_D:
            keyD = false;
            break;
        case Qt::Key_W:
            keyW = false;
            break;
        case Qt::Key_S:
            keyS = false;
            break;

        }
    }
}

void Scenary::resizeEvent(QResizeEvent *event)
{
    QFrame::resizeEvent(event);

    // atualiza tamanho dos quadrados tabuleiro
    _x = _y = 0;
    _w_sz = width()/_Col;
    _h_sz = height()/_Rows;

    // atualiza tamanho payer
    _p1->setH_size((height()/12)*0.6);
    _p1->setW_size((width()/20)*0.6);
    _p2->setH_size((height()/12)*0.6);
    _p2->setW_size((width()/20)*0.6);

    //atualiza o x  e y dos players
    if(pos_x_atua_p1 >0 || pos_y_atua_p1 >0){
        _p1->setX(width()*pos_x_atua_p1);
        _p1->setY(height()*pos_y_atua_p1);
        _p2->setX(width()*pos_x_atua_p2);
        _p2->setY(height()*pos_y_atua_p2);
    }

}

Missile *Scenary::getSpecial(int index)
{
    //    if(_special->getActive(index)){

    //        return _special.at(index);
    //    }
}

void Scenary::Colision_Missile_Scenary()
{
    if(_p1->getQtdFire()>=0 || _p1->getQtdSpecialFire()>=0){
        if(_p1->getActive()){

            for(int i=0;i<_p1->getMunicao().size();i++){

                if(_p1->getBullet(i)->getActive()){
                    //qDebug()<<i;
                    Colision_Missile_Scenary_white(_p1->getBullet(i));
                    Colision_SB_Scenary_white(_p1->getBullet(i));
                }

            }
        }
    }
    if(_p2->getQtdFire()>=0 || _p1->getQtdSpecialFire()>=0){
        if(_p2->getActive()){
            for(int i=0;i<_p2->getMunicao().size();i++){

                if(_p2->getBullet(i)->getActive()){

                    Colision_Missile_Scenary_black(_p2->getBullet(i));
                    Colision_SB_Scenary_black(_p2->getBullet(i));
                }

            }
        }
    }
}

void Scenary::generateSpecialFire(QPainter &p)
{
    if(_p1->getActive() && _p2->getActive()){
        if(_cont_t == 500){
            if(_special.size()<5){
                Missile *_fs = new Missile(this,Qt::blue);
                _fs->setX(rand() % width()-50 + 50);
                _fs->setY(rand() % height()-50 + 50);
                _fs->setActive(true);
                _special.push_back(_fs);
            }

        }
        if(_cont_t == 850){

            //qDebug()<<_special.size();
            if(_special.size()<5){
                Missile *_fs = new Missile(this,Qt::red);
                _fs->setX(rand() % width()-100 + 100);
                _fs->setY(rand() % height()-100 + 100);

                _fs->setActive(true);
                _special.push_back(_fs);
            }
            _cont_t =0;
        }

        for(int i =0;i<_special.size();i++){
            if(_special.at(i)->getActive()){
                for(int r=0;r<_Rows;r++){
                    for(int l=0;l<_Col;l++){

                        if(RectColors[r][l] == branco || RectColors[r][l] == preto){
                            if((_special.at(i)->getX()+_special.at(i)->get_w_sz())>=(RectPos[r][l].x()) &&
                                    (_special.at(i)->getX())<=(RectPos[r][l].x()+_w_sz) &&
                                    (_special.at(i)->getY() + _special.at(i)->get_h_sz()) >= (RectPos[r][l].y()) &&
                                    (_special.at(i)->getY())<= (RectPos[r][l].y()+_h_sz))  {

                                _special.at(i)->draw(p);

                            }
                        }
                    }
                }
            }
        }
    }else{
        for(int i =0;i<_special.size();i++){
            _special.at(i)->setActive(false);
        }
    }

}

void Scenary::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){

        QPoint pos = event->pos();
        //botao 1
        if((pos.x()) > (_btn_1.x()) &&
                (pos.x()) < (_btn_1.x()+_w_bt) &&
                (pos.y()) > (_btn_1.y()) &&
                (pos.y()) < (_btn_1.y()+_h_bt))  {

            define_Scenary(1);
            selected_level = true;
            // qDebug()<<"Botão 1 pressionado";

        }
        //botao 2
        if((pos.x()) > (_btn_2.x()) &&
                (pos.x()) < (_btn_2.x()+_w_bt) &&
                (pos.y()) > (_btn_2.y()) &&
                (pos.y()) < (_btn_2.y()+_h_bt))  {

            define_Scenary(2);
            selected_level = true;

        }
        //botao 3
        if((pos.x()) > (_btn_3.x()) &&
                (pos.x()) < (_btn_3.x()+_w_bt) &&
                (pos.y()) > (_btn_3.y()) &&
                (pos.y()) < (_btn_3.y()+_h_bt))  {

            define_Scenary(3);
            selected_level = true;

        }
        //botao 4
        if((pos.x()) > (_btn_4.x()) &&
                (pos.x()) < (_btn_4.x()+_w_bt) &&
                (pos.y()) > (_btn_4.y()) &&
                (pos.y()) < (_btn_4.y()+_h_bt))  {

            define_Scenary(4);
            selected_level = true;

        }
        //botao 5
        if((pos.x()) > (_btn_5.x()) &&
                (pos.x()) < (_btn_5.x()+_w_bt) &&
                (pos.y()) > (_btn_5.y()) &&
                (pos.y()) < (_btn_5.y()+_h_bt))  {

            define_Scenary(5);
            selected_level = true;

        }


    }

}
