#include "PointsGestion.h"
#include "ui_PointsGestion.h"
#include "GUI_LocationPointsF.h"
Gestion_Points::Gestion_Points(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Points)
{
    ui->setupUi(this);
}

Gestion_Points::~Gestion_Points()
{
    delete ui;
}

void Gestion_Points::on_ajouter_clicked()
{

}

void Gestion_Points::on_pushButton_clicked()
{
    GUI_LocationPointsF *w = new GUI_LocationPointsF;
    hide();
    w->show();
}
void Gestion_Points::on_traiter_clicked()
{

}



