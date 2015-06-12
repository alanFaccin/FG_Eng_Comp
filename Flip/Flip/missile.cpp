#include "missile.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>

Missile::Missile(QFrame *parent,const QColor color,int x, int y)
{

    this->_x = x;
    this->_y = y;
    this->_w_sz = 10;
    this->_h_sz = 10;
    this->_color = color;
    this->_active = false;
    this->_qtd_tiro=0;

    _fire_sound = new QMediaPlayer();
    _fire_sound->setMedia(QUrl("qrc:/sounds/sounds/fire2.wav"));

}

void Missile::draw(QPainter &p)
{

        if(_active && _qtd_tiro <= 5){

          if(this->getColor() == Qt::blue){

              p.setPen(_color);
              p.setBrush(_color);
              p.drawRect(_x,_y,_w_sz*2,_h_sz*2);
              move();

          }else if(this->getColor() == Qt::red){
              //qDebug()<<"vermelha";
              p.setPen(_color);
              p.setBrush(_color);
              p.drawRect(_x,_y,_w_sz,_h_sz);
              moveRed();
          }else{
              p.setPen(_color);
              p.setBrush(_color);
              p.drawRect(_x,_y,_w_sz,_h_sz);
              move();
          }

//          p.setPen(_color);
//          p.setBrush(_color);
//          p.drawRect(_x,_y,_w_sz,_h_sz);

//          move();
        }else{
           // _active = false;
        }


}

void Missile::setX(int x)
{
    this->_x = x;
}
void Missile::setY(int y)
{
    this->_y = y;
}
int Missile::getX()
{
    return _x;
}
int Missile::getY()
{
    return _y;
}

void Missile::setDirection(char d)
{
    this->_direction = d;
}

char Missile::getDirection()
{
    return this->_direction;
}

void Missile::set_h_sz(int h)
{
    this->_h_sz = h;
}
void Missile::set_w_sz(int w)
{
    this->_w_sz = w;
}

int Missile::get_h_sz()
{
    return this->_h_sz;
}
int Missile::get_w_sz()
{
    return this->_w_sz;
}

void Missile::setColor(QColor c)
{
    this->_color = c;
}
QColor Missile::getColor()
{
    return this->_color;
}

QMediaPlayer *Missile::getFireSound()
{
    return this->_fire_sound;
}

void Missile::setActive(bool act)
{
    this->_active = act;
}

bool Missile::getActive()
{
    return this->_active;
}

void Missile::move()
{
    if(_direction == 'u'){
        _y -=10;
    }
    if(_direction == 'd'){
        _y +=10;
    }
    if(_direction == 'r'){
        _x +=10;
    }
    if(_direction == 'l'){
        _x -=10;
    }
    //qDebug()<<"move";
    //QTimer::singleShot(10, this, SLOT(move()));
}

void Missile::moveRed()
{

    if(_direction == 'u'){
        _y -=20;
    }
    if(_direction == 'd'){
       // qDebug()<<"_direction == 'd'";
        _y +=20;
    }
    if(_direction == 'r'){
        _x +=20;
    }
    if(_direction == 'l'){
        _x -=20;
    }
}
void Missile::setQtdTiro(int t)
{
    this->_qtd_tiro = t;
}
int Missile::getQtdTiro()
{
    return this->_qtd_tiro;
}

void Missile::addTiro()
{
    _qtd_tiro++;
}

void Missile::resetTiro()
{
    _qtd_tiro = 0;
}

