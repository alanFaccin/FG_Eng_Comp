#include "scenery.h"


#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])

{
    QApplication app(argc, argv);

        //tabuleiro como janela
        Scenary *tabuleiro = new Scenary();
        tabuleiro->setMinimumSize(800,600);
        tabuleiro->show();


    return app.exec();
}

