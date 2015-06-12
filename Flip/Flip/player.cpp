#include "player.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QApplication>
#include <math.h>
#include "missile.h"

double _bx = 0,_bx_2 = 0;
double _by = 0,_by_2 = 0;
double _rad = 0,_rad_2= 0;
double _raio = 0;
int _gr = 72,_gr_2 = 72;


int _cont = 0;
int _qtd_print = 0;

Player::Player(QFrame *parent, const QColor color, int x, int y){

    _active = true;
    this->_color=color;
    _x = x;
    _y = y;
    _h_sz = (height()/12)*0.6;
    _w_sz =(width()/20)*0.6;

    _Qtd_fire = -1;
    _Qtd_specialFire = -1;

    for(int i=0;i<5;i++){
        Missile *_bullet= new Missile(this,this->_color);
        //        if(i==0){
        //            Missile *_bullet= new Missile(this,Qt::red);
        //            _municao.push_back(_bullet);
        //        }
        //        if(i==1){
        //            Missile *_bullet= new Missile(this,Qt::blue);
        //            _municao.push_back(_bullet);
        //        }
        //        if(i==2){
        //            Missile *_bullet= new Missile(this,Qt::green);
        //            _municao.push_back(_bullet);
        //        }
        //        if(i==3){
        //            Missile *_bullet= new Missile(this,Qt::yellow);
        //            _municao.push_back(_bullet);
        //        }
        //        if(i==4){
        //            Missile *_bullet= new Missile(this,Qt::magenta);
        //            _municao.push_back(_bullet);
        //        }
        _municao.push_back(_bullet);
    }
    // qDebug()<<_municao.size();

    for(int i=0;i<5;i++){
        // qDebug()<<_municao.at(i)->getActive();
    }


}

void Player::draw(QPainter &p){

    if(_active){
        p.setPen(_color);
        p.setBrush(_color);
        p.drawRoundedRect(_x,_y,_w_sz,_h_sz,2.5,2.5);
        _qtd_print ++;



        if(this->getColor() == Qt::white){

            for(int i=1;i<6;i++){

                _raio = _h_sz/3.5;
                _rad = _gr * (M_PI/180);
                _bx = cos(_rad)*_raio+_x+_w_sz/2.5;
                _by = sin(_rad)*_raio +_y+_h_sz/2.5;

                p.setBrush(Qt::black);
                p.setPen(Qt::black);
                p.drawEllipse(_bx,_by,_w_sz*0.3,_h_sz*0.2);

                _gr+=72;
                _gr %=370;

            }
            //qDebug()<<_qtd_print;
//            if(_qtd_print == 21){
//                _gr+=34;
//                _qtd_print = 1;
//            }





            if(_Qtd_fire >=0){
                for(int i=0;i<5;i++){
                    if(_municao.at(i)->getActive()){
                        _municao.at(i)->draw(p);
                    }
                }
            }
            if(_Qtd_specialFire >=0){
                for(int i=0;i<_municao_special.size();i++){
                    if(_municao_special.at(i)->getActive()){
                        _municao_special.at(i)->draw(p);
                    }
                }
            }
        }

        //player 2

        if(this->getColor() == Qt::black){

            for(int i=1;i<6;i++){

                _raio = _h_sz/3.5;
                _rad = _gr_2 * (M_PI/180);
                _bx = cos(_rad)*_raio+_x+_w_sz/2.5;
                _by = sin(_rad)*_raio +_y+_h_sz/2.5;

                p.setBrush(Qt::white);
                p.setPen(Qt::white);
                p.drawEllipse(_bx,_by,_w_sz*0.3,_h_sz*0.2);

                _gr_2+=72;
                _gr_2 %=370;

            }

//            //qDebug()<<_qtd_print;
//            if(_qtd_print == 21){
//                _gr+=34;
//                _qtd_print = 1;
//            }





            if(_Qtd_fire >=0){
                for(int i=0;i<5;i++){
                    if(_municao.at(i)->getActive()){
                        _municao.at(i)->draw(p);
                    }
                }
            }
        }



    }

}

void Player::setX(int x)
{
    this->_x = x;
}
void Player::setY(int y)
{
    this->_y = y;
}
int Player::getX()
{
    return this->_x;
}
int Player::getY()
{
    return this->_y;
}

int Player::getH_size()
{
    return this->_h_sz;
}
int Player::getW_size()
{
    return this->_w_sz;
}

void Player::setH_size(int h)
{
    this->_h_sz = h;
}
void Player::setW_size(int w)
{
    this->_w_sz = w;
}

QColor Player::getColor()
{
    return this->_color;
}

void Player::setColor(QColor c)
{
    this->_color = c;
}

void Player::setQtdFire(int qtd)
{
    this->_Qtd_fire = qtd;
}
int Player::getQtdFire(){
    return this->_Qtd_fire;
}

void Player::addFire()
{
    _Qtd_fire++;
}

void Player::resetfire()
{
    _Qtd_fire = 0;
}

Missile* Player::getBala(int index)
{
    //qDebug()<<"index: "<<index;
    if(this->getActive()){
        if(index<5 && index >=0 ){
            return _municao.at(index);
        }
        else{
            // qDebug()<<"else: ";
        }
    }


}

void Player::removeBala()
{
    if(!(_municao.isEmpty())){
        qDebug()<< _municao.size();
        _municao.pop_front();
        qDebug()<< _municao.size();
    }else{
        qDebug()<<"sem munição";
    }
}

void Player::setActive(bool act)
{
    this->_active = act;
}

bool Player::getActive()
{
    return this->_active;
}

void Player::addSpecialBullet(Missile *bullet)
{
    this->_municao_special.push_back(bullet);
    //this->_Qtd_specialFire++;
    qDebug()<<"Size special:"<<_municao_special.size();
}

Missile *Player::getSpecialBullet(int index)
{

    return _municao_special.at(index);

}

void Player::addSpecialFire()
{
    this->_Qtd_specialFire++;
}

void Player::removeSpecialFire()
{
    this->_Qtd_specialFire--;
}

int Player::getQtdSpecialFire()
{
    return this->_Qtd_specialFire;
}








