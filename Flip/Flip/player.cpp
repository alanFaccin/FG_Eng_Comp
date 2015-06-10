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

    //qDebug()<<"constructor player";
    this->_color=color;
    _x = x;
    _y = y;
    _h_sz = (height()/12)*0.6;
    _w_sz =(width()/20)*0.6;

    _Qtd_fire = 0;

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
    _qtd_print ++;
    if(_qtd_print == 3){

        if(this->getColor() == Qt::white){
            p.setPen(Qt::black);
            p.setBrush(Qt::black);


            //for(int i=0;i<5;i++){
                //qDebug()<< (_x+_w_sz/2-3)+_bx << (_y+2)+_by ;
                //p.drawEllipse((_x+_w_sz/2-3)+_bx,(_y+2)+_by,5,5);
                //p.drawEllipse((_x+_w_sz-8)+_bx,(_y+_h_sz/2-3)+_by,5,5);
                //p.drawEllipse(_x+_w_sz/2,_y+_h_sz/4,5,5);
           // }
            _cont ++;
            if(_cont == 1 || _cont == 2){
                _bx+=5;
                _by+=5;
            }
            if(_cont == 3 || _cont == 4){
                _bx-=5;
                _by+=5;
            }
            if(_cont == 5 || _cont == 6){
                _bx-=5;
                _by-=5;
            }
            if(_cont == 7){
                _bx+=5;
                _by-=5;
            }
            if(_cont == 8){
                _bx = 0;
                _by = 0;
                _cont =0;
            }

//            qDebug()<<_cont;
//            qDebug()<<_bx;
//            qDebug()<<_by;


        }
        if(this->getColor() == Qt::black){
            p.setPen(Qt::white);
            p.setBrush(Qt::white);
            p.drawEllipse(_x+_w_sz/2-3,_y,5,5);
        }

        _qtd_print =0;


    }
    p.drawEllipse((_x+_w_sz/2-3)+_bx,(_y+2)+_by,5,5);




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

Missile* Player::getBala()
{
    //qDebug()<<_Qtd_fire;
    if(!(_municao.isEmpty())){
        //qDebug()<<_municao.size();
        //qDebug()<<"municao retornada";
        //qDebug()<<"qtd Fire"<<this->getColor() <<this->getFire()+1;
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






