#include "GUI_PersonnelDepart.h"
#include "ui_GUI_PersonnelDepart.h"
#include "PersonnelGestion.h"
#include "DepartementGestion.h"
#include "mainwindow.h"
GUI_PersonnelDepart::GUI_PersonnelDepart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_PersonnelDepart)
{
    ui->setupUi(this);
}

GUI_PersonnelDepart::~GUI_PersonnelDepart()
{
    delete ui;
}

void GUI_PersonnelDepart::on_personnel_clicked()
{

    Gestion_Personnel *w = new Gestion_Personnel;
    hide();
    w->show();
}



void GUI_PersonnelDepart::on_depart_clicked()
{

    Gestion_Departement *w = new Gestion_Departement;
    hide();
    w->show();
}

void GUI_PersonnelDepart::on_pushButton_clicked()
{
   acceuil *w = new acceuil;
   hide();
   w->show();
}
