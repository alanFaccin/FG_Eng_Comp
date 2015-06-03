#include "scenery.h"
#include "time_anim_improved.h"

#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])

{
    QApplication app(argc, argv);
//    QWidget window;
//    QHBoxLayout _layout(&window);

//    window.setWindowTitle("Flip Game");

//    TimeAnimationImproved time_imp_widget(&window);
//    _layout.addWidget(&time_imp_widget);
//    window.setLayout(&_layout);
//    _layout.setContentsMargins(0, 0, 0, 0);
//    window.setMinimumSize(800,600);
//    window.show();

        //tabuleiro como janela
        Scenary *tabuleiro = new Scenary();
        tabuleiro->setMinimumSize(800,600);
        tabuleiro->show();


    return app.exec();
}

