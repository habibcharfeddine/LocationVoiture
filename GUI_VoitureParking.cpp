#include "GUI_VoitureParking.h"
#include "ui_GUI_VoitureParking.h"
#include "AssuranceGestion.h"
#include "SocieteGestion.h"
#include "mainwindow.h"
#include "VoitureParking.h"
GUI_VoitureParking::GUI_VoitureParking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_VoitureParking)
{
    ui->setupUi(this);
}

GUI_VoitureParking::~GUI_VoitureParking()
{
    delete ui;
}

void GUI_VoitureParking::on_entraineurs_clicked()
{

    VoitureParking *w = new VoitureParking;
    hide();
    w->show();
}



void GUI_VoitureParking::on_pushButton_clicked()
{
   acceuil *w = new acceuil;
   hide();
   w->show();
}
