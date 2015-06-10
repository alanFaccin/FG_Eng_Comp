#pragma once
#include <QPoint>
#include <QVector>
#include "missile.h"
#include <QFrame>


class Player: public QFrame
{
    Q_OBJECT
public:
    Player(QFrame* parent = NULL, const QColor color = Qt::black, int x=0, int y=0);
    void draw(QPainter& p);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    int getH_size();
    int getW_size();
    void setH_size(int h);
    void setW_size(int w);
    QColor getColor();
    void setColor(QColor c);
    void setQtdFire(int qtd);
    int getQtdFire();
    void addFire();
    void resetfire();
    Missile* getBala();
    void removeBala();
    // teste

signals:
    //void fire();
private slots:
    //void fire();
private:
    QColor _color;
    int _x;
    int _y;
    int _h_sz;
    int _w_sz;
    int _Qtd_fire;

    //Missile *_bala;
    QVector <Missile*> _municao;
};
