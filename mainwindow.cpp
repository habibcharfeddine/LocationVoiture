#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDateTime>
#include <QStyleFactory>
#include <QMediaPlayer>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
qApp->setStyle(QStyleFactory::create("Fusion"));
    QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
     ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{

    delete ui;

}


void MainWindow::on_login_clicked()
{
    QString res = ui->cx_login->text() ;
    QString res1 = ui->cx_mdp->text() ;
     if (res=="habib" && res1=="habib")
    {
         acceuil *w = new acceuil;
        hide();
        w->show();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur d'authentification"),
                    QObject::tr("Information incorrecte .\n"
                                "Click Close to exit."), QMessageBox::Close);
    }
}
