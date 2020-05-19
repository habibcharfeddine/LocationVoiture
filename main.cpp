#include "mainwindow.h"
#include <QApplication>
#include"GUI_AssuranceSociete.h"
#include"connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow v;
    GUI_AssuranceSociete w;
    connexion c;
    bool test=c.ouvrirConnexion();
    v.show();
    //w.show();

    return a.exec();
}
