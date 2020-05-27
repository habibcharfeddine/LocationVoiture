#include "GUI_ClientAvis.h"
#include "ui_GUI_ClientAvis.h"
#include "ClientAvis.h"
#include "SocieteGestion.h"
#include "mainwindow.h"
GUI_ClientAvis::GUI_ClientAvis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_ClientAvis)
{
    ui->setupUi(this);
}

GUI_ClientAvis::~GUI_ClientAvis()
{
    delete ui;
}

void GUI_ClientAvis::on_entraineurs_clicked()
{

    ClientAvis *w = new ClientAvis;
    hide();
    w->show();
}





void GUI_ClientAvis::on_pushButton_clicked()
{
   acceuil *w = new acceuil;
   hide();
   w->show();
}
