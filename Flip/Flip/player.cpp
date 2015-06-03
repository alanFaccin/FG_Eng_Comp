#include "player.h"
#include <QPainter>
#include <QDebug>

Player::Player(QFrame *parent){

    _x = _y = 0;
}

void Player::draw(QPainter &p){
    p.setPen(Qt::blue);
    p.setBrush(Qt::blue);
    p.drawRoundedRect(_x,_y,(width()/20)*0.9,(height()/12)*0.9,2.5,2.5);

}
void Player::paintEvent(QPaintEvent *event){

    QFrame::paintEvent(event);

    QPainter painter(this);

    painter.setPen(Qt::gray);
    painter.drawRect(50 ,50, 50,50);
    qDebug()<<"paitevent";

}

void Player::setX(int x)
{
    this->_x = x;
}
void Player::setY(int y)
{
    this->_y = y;
}
void Player::_teste(){

    qDebug()<<"slotTeste";
    //this->draw();
}
