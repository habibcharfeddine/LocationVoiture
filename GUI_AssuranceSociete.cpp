#include "GUI_AssuranceSociete.h"
#include "ui_GUI_AssuranceSociete.h"
#include "AssuranceGestion.h"
#include "SocieteGestion.h"
#include "mainwindow.h"
GUI_AssuranceSociete::GUI_AssuranceSociete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_AssuranceSociete)
{
    ui->setupUi(this);
}

GUI_AssuranceSociete::~GUI_AssuranceSociete()
{
    delete ui;
}

void GUI_AssuranceSociete::on_societe_clicked()
{

    Gestion_Societe *w = new Gestion_Societe;
    hide();
    w->show();
}



void GUI_AssuranceSociete::on_assurance_clicked()
{

    Gestion_Assurance *w = new Gestion_Assurance;
    hide();
    w->show();
}

void GUI_AssuranceSociete::on_pushButton_clicked()
{
   acceuil *w = new acceuil;
   hide();
   w->show();
}
