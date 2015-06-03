#include "player.h"
#include <QPainter>
#include <QDebug>

Player::Player(QFrame *parent, const QColor color, int x, int y){

    this->_color=color;
    _x = x;
            _y = y;
    _h_sz = (height()/12)*0.9;
    _w_sz =(width()/20)*0.9;
}

void Player::draw(QPainter &p){
    _h_sz = (height()/12)*0.9;
    _w_sz =(width()/20)*0.9;
    p.setPen(_color);
    p.setBrush(_color);
    p.drawRoundedRect(_x,_y,_w_sz,_h_sz,2.5,2.5);

}

void Player::draw2()
{
    repaint();
}
void Player::paintEvent(QPaintEvent *event){

    QFrame::paintEvent(event);

    QPainter painter(this);

    _h_sz = (height()/12)*0.9;
    _w_sz =(width()/20)*0.9;
    painter.setPen(_color);
    painter.setBrush(_color);
    painter.drawRoundedRect(_x,_y,_w_sz,_h_sz,2.5,2.5);

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
void Player::_teste(){

    qDebug()<<"slotTeste";
    //this->draw();
}
