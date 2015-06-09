#include "player.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include "missile.h"

Player::Player(QFrame *parent, const QColor color, int x, int y){

    //qDebug()<<"constructor player";
    this->_color=color;
    _x = x;
    _y = y;
    _h_sz = (height()/12)*0.6;
    _w_sz =(width()/20)*0.6;

    fire = -1;

    for(int i=0;i<5;i++){
        Missile *_bullet= new Missile(this,this->_color);
        _municao.push_back(_bullet);
    }


    //    Missile _bullet(this,this->_color);
    //    _municao.push_back( &_bullet);



    //funcionava
    //_bala = new Missile(this,Qt::red,this->_x,this->_y);


}

void Player::draw(QPainter &p){

    p.setPen(_color);
    p.setBrush(_color);
    p.drawRoundedRect(_x,_y,_w_sz,_h_sz,2.5,2.5);

    if(!(_municao.isEmpty())){
      this->getBala()->draw(p);
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

void Player::setFire(int qtd)
{
    this->fire = qtd;
}
int Player::getFire(){
    return this->fire;
}

Missile* Player::getBala()
{
    if(!(_municao.isEmpty() && this->getFire()+1 >0)){
        //qDebug()<<_municao.size();
        //qDebug()<<"municao retornada";
        qDebug()<<"qtd Fire"<<this->getColor() <<this->getFire()+1;
        return _municao.at(1);
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






