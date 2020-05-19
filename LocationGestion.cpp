#include "LocationGestion.h"
#include "ui_LocationGestion.h"
#include "GUI_LocationPointsF.h"
Gestion_Location::Gestion_Location(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Location)
{
    ui->setupUi(this);
}

Gestion_Location::~Gestion_Location()
{
    delete ui;
}

void Gestion_Location::on_ajouter_clicked()
{

}

void Gestion_Location::on_pushButton_clicked()
{
    GUI_LocationPointsF *w = new GUI_LocationPointsF;
    hide();
    w->show();
}
void Gestion_Location::on_traiter_clicked()
{

}



