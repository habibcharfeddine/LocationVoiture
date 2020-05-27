#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     Connection c;
    //w.show();

    bool test=c.createconnect();
     MainWindow w;
      QMessageBox msgBox;
    if(test)
    {w.show();
       /* QMessageBox::information(nullptr, QObject::tr("Database is opened"),
                    QObject::tr("Connection Successful.\n"
                                "Click OK to continue."), QMessageBox::Ok);*/
        QPixmap pix("C:/Users/Lenovo/Downloads/msg.png");

                msgBox.setText("Database is opened\nConnection Successful.\nClick OK to continue.");
                msgBox.setIconPixmap(pix);
                 msgBox.exec();
        //w.afficher();
        //w.stat();

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("Connection Failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
