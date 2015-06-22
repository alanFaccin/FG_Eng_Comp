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
    void removeFire();
    void resetfire();
    Missile* getBullet(int index);
    void removeBullet(int index);
    void setActive(bool act);
    bool getActive();
    void addSpecialBullet(Missile* bullet);
    Missile* getSpecialBullet(int index);
    void addSpecialFire();
    void removeSpecialFire();
    int getQtdSpecialFire();
    QVector <Missile*> getMunicao();
    QVector <Missile*> getMS();



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
    bool _active;
    int _Qtd_specialFire;


    //Missile *_bala;
    QVector <Missile*> _municao;
    QVector <Missile*> _municao_special;
};
