#include "missile.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>

int cont=0;
Missile::Missile(QFrame *parent,const QColor color,int x, int y)
{

    this->_x = x;
    this->_y = y;
    this->_w_sz = 10;
    this->_h_sz = 10;
    this->_color = color;
    this->_active = false;
    this->_qtd_tiro=0;
    this->_sf_p=0;
    this->_player = false;

    _fire_sound = new QMediaPlayer();
    _fire_sound->setMedia(QUrl("qrc:/sounds/sounds/fire2.wav"));

}

void Missile::draw(QPainter &p)
{
    // tirado do if abaixo:  && _qtd_tiro <= 5
    if(_active ){

        if(this->getColor() == Qt::red){
            p.setPen(_color);
            p.setBrush(_color);
            //p.drawRect(_x,_y,_w_sz,_h_sz);
            if(!this->isInPlayer()){
                ++cont;
                if(cont <100 || cont>200){
                    p.drawRect(_x,_y,_w_sz,_h_sz);
                }
                if(cont > 100 && cont < 200){
                    p.drawRect(_x+2,_y+2,(_w_sz/2),(_h_sz/2));
                }
                if(cont == 250){
                    cont=0;
                }

            }else{
                p.drawRect(_x,_y,_w_sz,_h_sz);
            }
            moveRed();

        }else if (this->getColor() == Qt::blue){
            p.setPen(_color);
            p.setBrush(_color);
            if(!(this->isInPlayer())){
                ++cont;
                if(cont <100 || cont>200){
                    p.drawRect(_x,_y,_w_sz,_h_sz);
                }
                if(cont > 100 && cont < 200){
                    p.drawRect(_x+2,_y+2,(_w_sz/2),(_h_sz/2));
                }
                if(cont == 250){
                    cont=0;
                }

            }else{
                p.drawRect(_x,_y,_w_sz,_h_sz);
            }
            move();
        }else{
            p.setPen(_color);
            p.setBrush(_color);
            p.drawRect(_x,_y,_w_sz,_h_sz);
            move();
        }

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
        _y -=7;
    }
    if(_direction == 'd'){
        _y +=7;
    }
    if(_direction == 'r'){
        _x +=7;
    }
    if(_direction == 'l'){
        _x -=7;
    }
}

void Missile::moveRed()
{

    if(_direction == 'u'){
        _y -=12;
    }
    if(_direction == 'd'){
        _y +=12;
    }
    if(_direction == 'r'){
        _x +=12;
    }
    if(_direction == 'l'){
        _x -=12;
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

void Missile::setSf_p(int p)
{
    this->_sf_p =p;
}

int Missile::getSf_p()
{
    return this->_sf_p;
}

void Missile::setOwner()
{
    this->_player = true;
}

bool Missile::isInPlayer()
{
    return this->_player;
}
