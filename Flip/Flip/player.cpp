#include "player.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include "missile.h"

int _bx = 1;
int _by = 1;
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
    qDebug()<<_municao.size();

    for(int i=0;i<5;i++){
        qDebug()<<_municao.at(i)->getActive();
    }


}

void Player::draw(QPainter &p){

    if(_active){
        p.setPen(_color);
        p.setBrush(_color);
        p.drawRoundedRect(_x,_y,_w_sz,_h_sz,2.5,2.5);
        _qtd_print ++;
    }else{
        //this->getBala(this->getQtdFire())->setActive(false);
        //this->getBala(this->getQtdFire())->setQtdTiro(10);
    }

    qDebug()<<_Qtd_fire;
    if(_Qtd_fire >=0){
          qDebug()<<"Alan";
        for(int i=0;i<5;i++){

            if(_municao.at(i)->getActive()){

                _municao.at(i)->draw(p);
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
    if(!(_municao.isEmpty())){
        return _municao.at(index);
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








