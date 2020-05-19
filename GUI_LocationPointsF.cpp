#include "GUI_LocationPointsF.h"
#include "ui_GUI_LocationsPointsF.h"
#include "LocationGestion.h"
#include "PointsGestion.h"
#include "mainwindow.h"
GUI_LocationPointsF::GUI_LocationPointsF(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_LocationPointsF)
{
    ui->setupUi(this);
}

GUI_LocationPointsF::~GUI_LocationPointsF()
{
    delete ui;
}

void GUI_LocationPointsF::on_location_clicked()
{

    Gestion_Location *w = new Gestion_Location;
    hide();
    w->show();
}



void GUI_LocationPointsF::on_points_clicked()
{

    Gestion_Points *w = new Gestion_Points;
    hide();
    w->show();
}

void GUI_LocationPointsF::on_pushButton_clicked()
{
   acceuil *w = new acceuil;
   hide();
   w->show();
}
