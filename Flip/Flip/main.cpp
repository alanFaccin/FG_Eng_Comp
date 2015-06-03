#include "scenery.h"
#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])

{
    QApplication app(argc, argv);
    QWidget *window = new QWidget();
    QHBoxLayout* _layout = new QHBoxLayout();

    window->setWindowTitle("Flip Game");
    //window->setFocus();
    Scenary *tabuleiro = new Scenary(window);
    _layout->addWidget(tabuleiro);
    window->setLayout(_layout);
    _layout->setContentsMargins(0, 0, 0, 0);
    window->setMinimumSize(800,600);
    window->show();


    return app.exec();
}

