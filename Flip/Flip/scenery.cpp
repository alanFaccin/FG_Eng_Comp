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
    _bg_music->setMedia(QUrl("qrc:/sounds/sounds/bg_music.mp3"));
    //qDebug()<<_bg_music->mediaStatus();
    _bg_music->play();
   // qDebug()<<_bg_music->mediaStatus();
    // sound colision
    _colision_music = new QMediaPlayer();
    _colision_music->setMedia(QUrl("qrc:/sounds/sounds/c_tab.wav"));


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


                        // qDebug()<<"Colidiu";

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

                    //                    qDebug()<< _t->getX()+_t->get_w_sz() << ">="<<(RectPos[i][j].x())
                    //                            << (_t->getX())<<"<="<<(RectPos[i][j].x()+_w_sz)
                    //                            << (_t->getY() + _t->get_h_sz())<< ">=" <<(RectPos[i][j].y())
                    //                            << (_t->getY())<< "<="<< (RectPos[i][j].y()+_h_sz);

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

                        _t->setActive(false);
                        _t->setX(1000);
                        _t->setY(1000);

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
                            // RectColors[i][j] = branco;
                            _p1->setActive(false);
                        }
                    }


                    return 1;

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


                        _t->setActive(false);

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
                            //qDebug()<<RectColors[i][j];
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

                //                qDebug()<< (_p1->getX()+_p1->getW_size())<<">="<<_special.at(i)->getX()
                //                        <<(_p1->getX()+salto)<<"<="<<(_special.at(i)->getX()+_special.at(i)->get_w_sz())
                //                       <<(_p1->getY() + _p1->getH_size()) << ">=" << (_special.at(i)->getY())
                //                      <<(_p1->getY()) + salto << "<=" << (_special.at(i)->getY()+_special.at(i)->get_h_sz());

                if((_p1->getX()+_p1->getW_size())>=(_special.at(i)->getX()) &&
                        (_p1->getX()+salto)<=(_special.at(i)->getX()+_special.at(i)->get_w_sz()) &&
                        (_p1->getY() + _p1->getH_size()) >= (_special.at(i)->getY()) &&
                        (_p1->getY()) + salto <= (_special.at(i)->getY()+_special.at(i)->get_h_sz()))  {

                    _p1->addSpecialBullet(_special.at(i));
                    _special.remove(i);
                    _special.at(i)->setActive(false);

                }
            }
        }

    }

}

void Scenary::movePalyer()
{
    //player 1
    if (keyLeft && keyUp) {

        _p1->setX(_p1->getX()-5);
        _p1->setY(_p1->getY()-5);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()+5);
            _p1->setY(_p1->getY()+5);
        }
    }

    else if (keyRight && keyUp) {

        _p1->setX(_p1->getX()+5);
        _p1->setY(_p1->getY()-5);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()-5);
            _p1->setY(_p1->getY()+5);
        }
    }

    else if (keyDown && keyLeft) {

        _p1->setX(_p1->getX()-5);
        _p1->setY(_p1->getY()+5);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()+5);
            _p1->setY(_p1->getY()-5);
        }
    }

    else if (keyDown && keyRight) {

        _p1->setX(_p1->getX()+5);
        _p1->setY(_p1->getY()+5);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()-5);
            _p1->setY(_p1->getY()-5);
        }
    }

    if (keyLeft){

        _p1->setX(_p1->getX()-5);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()+5);
        }
    }

    else if (keyRight){
        _p1->setX(_p1->getX()+5);
        if(this->Colision_Player(_p1)==1){
            _p1->setX(_p1->getX()-5);
        }
    }
    if (keyDown){
        _p1->setY(_p1->getY()+5);
        if(this->Colision_Player(_p1)==1){
            _p1->setY(_p1->getY()-5);
        }
    }

    else if (keyUp){
        _p1->setY(_p1->getY()-5);
        if(this->Colision_Player(_p1)==1){
            _p1->setY(_p1->getY()+5);
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

        this->draw();
        // acumula qtd vezes que passou aqui
        _cont_t++;

        _last_time_60fps = now;
    }

    _counter++;
    _counter = _counter % 60;

    //qDebug()<<"tick";

    // Reset the timer
    QTimer::singleShot(1000/_max_fps, this, SLOT(_tick()));
}

void Scenary::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::gray);
    _x = _y = 0;
    _w_sz = width()/_Col;
    _h_sz = height()/_Rows;

    // atualiza a porcentagem x e y atual na janela
    pos_x_atua_p1 = (float) _p1->getX()/width();
    pos_y_atua_p1 = (float) _p1->getY()/height();

    pos_x_atua_p2 = (float) _p2->getX()/width();
    pos_y_atua_p2 = (float) _p2->getY()/height();

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
    this->Colision_cenario();
    colision_Special_bullet();

    if(_p1->getQtdFire()>=0){
        if(_p1->getActive()){

            for(int i=0;i<5;i++){

                if(_p1->getBala(i)->getActive()){

                    Colision_Missile_Scenary_white(_p1->getBala(i));

                }

            }
        }
    }
    if(_p2->getQtdFire()>=0){
        if(_p2->getActive()){
            for(int i=0;i<5;i++){

                if(_p2->getBala(i)->getActive()){

                    Colision_Missile_Scenary_black(_p2->getBala(i));
                }

            }
        }
    }


    _p1->draw(painter);
    _p2->draw(painter);



    // imprime um tiro especial no cenário
    if(_cont_t == 120){

        Missile *_fs = new Missile(this,Qt::blue);
        _fs->setX(rand() % 799 + 0);
        _fs->setY(rand() % 600 + 0);

        _fs->setActive(true);
        _special.push_back(_fs);


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

                            _special.at(i)->draw(painter);

                        }
                    }
                }
            }
        }
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
        if(_p1->getQtdFire()<4){
            //qDebug()<<"space"<<_p1->getQtdFire();
            //set direction
            _p1->addFire();
            if(tecla_b == Qt::Key_Up){
                _p1->getBala(_p1->getQtdFire())->setX(_p1->getX()+(_p1->getW_size()/2)-(_p1->getBala(_p1->getQtdFire())->get_h_sz()/2));
                _p1->getBala(_p1->getQtdFire())->setY(_p1->getY()- _p1->getBala(_p1->getQtdFire())->get_h_sz());
                _p1->getBala(_p1->getQtdFire())->setDirection('u');
            }
            if(tecla_b == Qt::Key_Down){
                _p1->getBala(_p1->getQtdFire())->setX(_p1->getX()+(_p1->getW_size()/2)-(_p1->getBala(_p1->getQtdFire())->get_h_sz()/2));
                _p1->getBala(_p1->getQtdFire())->setY(_p1->getY()+_p1->getH_size());
                _p1->getBala(_p1->getQtdFire())->setDirection('d');
            }
            if(tecla_b == Qt::Key_Right){
                _p1->getBala(_p1->getQtdFire())->setX(_p1->getX()+_p1->getW_size());
                _p1->getBala(_p1->getQtdFire())->setY(_p1->getY()+(_p1->getH_size())/2-(_p1->getBala(_p1->getQtdFire())->get_h_sz()/2));
                _p1->getBala(_p1->getQtdFire())->setDirection('r');
            }
            if(tecla_b == Qt::Key_Left){
                _p1->getBala(_p1->getQtdFire())->setX(_p1->getX()-_p1->getBala(_p1->getQtdFire())->get_w_sz());
                _p1->getBala(_p1->getQtdFire())->setY(_p1->getY()+(_p1->getH_size())/2-(_p1->getBala(_p1->getQtdFire())->get_h_sz()/2));
                _p1->getBala(_p1->getQtdFire())->setDirection('l');
            }

            //start fire

            if(_p1->getBala(_p1->getQtdFire())->getQtdTiro()<=5 && tecla_b != NULL){
                _p1->getBala(_p1->getQtdFire())->setActive(true);
                if(_p1->getBala(_p1->getQtdFire())->getFireSound()->state() == QMediaPlayer::PlayingState ){
                    _p1->getBala(_p1->getQtdFire())->getFireSound()->setPosition(0);
                }else if (_p1->getBala(_p1->getQtdFire())->getFireSound()->state() == QMediaPlayer::StoppedState){
                    _p1->getBala(_p1->getQtdFire())->getFireSound()->play();
                }

                _p1->getBala(_p1->getQtdFire())->addTiro();


            }else{
                //_p1->getBala(_p1->getQtdFire())->resetTiro();
            }

        }
        break;

    case Qt::Key_M:
        _p1->addSpecialFire();
        if(tecla_b == Qt::Key_Up){
           // qDebug()<<_p1->getQtdSpecialFire();
            //qDebug()<<_p1->getSpecialBullet(0);
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setX(_p1->getX()+(_p1->getW_size()/2)-(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz()/2));
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setY(_p1->getY()- _p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz());
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setDirection('u');
        }
        if(tecla_b == Qt::Key_Down){
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setX(_p1->getX()+(_p1->getW_size()/2)-(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz()/2));
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setY(_p1->getY()+_p1->getH_size());
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setDirection('d');
        }
        if(tecla_b == Qt::Key_Right){
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setX(_p1->getX()+_p1->getW_size());
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setY(_p1->getY()+(_p1->getH_size())/2-(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz()/2));
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setDirection('r');
        }
        if(tecla_b == Qt::Key_Left){
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setX(_p1->getX()-_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_w_sz());
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setY(_p1->getY()+(_p1->getH_size())/2-(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->get_h_sz()/2));
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setDirection('l');
        }

        if(_p1->getQtdSpecialFire()>=0 && tecla_b != NULL){
            _p1->getSpecialBullet(_p1->getQtdSpecialFire())->setActive(true);
            if(_p1->getSpecialBullet(_p1->getQtdSpecialFire())->getFireSound()->state() == QMediaPlayer::PlayingState ){
                _p1->getSpecialBullet(_p1->getQtdSpecialFire())->getFireSound()->setPosition(0);
            }else if (_p1->getSpecialBullet(_p1->getQtdSpecialFire())->getFireSound()->state() == QMediaPlayer::StoppedState){
                _p1->getSpecialBullet(_p1->getQtdSpecialFire())->getFireSound()->play();
            }
        }
        break;
    case Qt::Key_U:
        if(_p2->getQtdFire()<4){
            // atualiza as Coordenadas do tiro
            //set direction
            _p2->addFire();
            if(tecla_p == Qt::Key_W){
                _p2->getBala(_p2->getQtdFire())->setX(_p2->getX()+(_p2->getW_size()/2)-(_p2->getBala(_p2->getQtdFire())->get_h_sz()/2));
                _p2->getBala(_p2->getQtdFire())->setY(_p2->getY()- _p2->getBala(_p2->getQtdFire())->get_h_sz());
                _p2->getBala(_p2->getQtdFire())->setDirection('u');
            }
            if(tecla_p == Qt::Key_S){
                _p2->getBala(_p2->getQtdFire())->setX(_p2->getX()+(_p2->getW_size()/2)-(_p2->getBala(_p2->getQtdFire())->get_h_sz()/2));
                _p2->getBala(_p2->getQtdFire())->setY(_p2->getY()+_p2->getH_size());
                _p2->getBala(_p2->getQtdFire())->setDirection('d');
            }
            if(tecla_p == Qt::Key_D){
                _p2->getBala(_p2->getQtdFire())->setX(_p2->getX()+_p2->getW_size());
                _p2->getBala(_p2->getQtdFire())->setY(_p2->getY()+(_p2->getH_size())/2-(_p2->getBala(_p2->getQtdFire())->get_h_sz()/2));
                _p2->getBala(_p2->getQtdFire())->setDirection('r');
            }
            if(tecla_p == Qt::Key_A){
                _p2->getBala(_p2->getQtdFire())->setX(_p2->getX()-_p2->getBala(_p2->getQtdFire())->get_w_sz());
                _p2->getBala(_p2->getQtdFire())->setY(_p2->getY()+(_p2->getH_size())/2-(_p2->getBala(_p2->getQtdFire())->get_h_sz()/2));
                _p2->getBala(_p2->getQtdFire())->setDirection('l');
            }

            //start fire

            if(_p2->getBala(_p2->getQtdFire())->getQtdTiro()<=5 && tecla_p != NULL){
                _p2->getBala(_p2->getQtdFire())->setActive(true);

                if(_p2->getBala(_p2->getQtdFire())->getFireSound()->state() == QMediaPlayer::PlayingState ){
                    _p2->getBala(_p2->getQtdFire())->getFireSound()->setPosition(0);
                }else if (_p2->getBala(_p2->getQtdFire())->getFireSound()->state() == QMediaPlayer::StoppedState){
                    _p2->getBala(_p2->getQtdFire())->getFireSound()->play();
                }

                _p2->getBala(_p2->getQtdFire())->addTiro();


            }else{
                //_p1->getBala(_p1->getQtdFire())->resetTiro();
            }

        }
        break;



    }
    movePalyer();
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
        case Qt::Key_Space:
            //           qDebug()<<"soltou o space bar";
            //            _p1->setFire(false);
            break;

        }
    }
    //    // atualiza as coordenadas de movimentação de acordo com as teclas pressionadas
    movePalyer();
    //    //repintar a tela
    //repaint();
}

void Scenary::resizeEvent(QResizeEvent *event)
{
    QFrame::resizeEvent(event);

    //    //qDebug()<< width();
    //    //qDebug()<< height();
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
