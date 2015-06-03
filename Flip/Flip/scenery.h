#pragma once
#include <QFrame>
#include <QTimer>
#include <QDateTime>
#include <QVector>
#include <QPoint>
#include "player.h"

class Scenary : public QFrame
{
    Q_OBJECT
public:
    Scenary(QWidget* parent = NULL);
    void draw();
    void define_Scenary(int type);
    int Colision_Player_tab();
    int Colision_Player_gray();
    int Colision_cenario();
    void movePalyer();

    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *);
    void resizeEvent(QResizeEvent* event);
private slots:


private:

    Player *_p1;
    Player *_p2;
    QVector< QVector <QPoint> > RectPos;
    QVector< QVector <int> >  RectColors;
    int _Rows;
    int _Col;
    int _w_sz;
    int _h_sz;
    int _x;
    int _y;
};
