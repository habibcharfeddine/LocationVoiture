#include "GUI_EventPromo.h"
#include "ui_GUI_EventPromo.h"
#include "PromoGestion.h"
#include "EventGestion.h"
#include "mainwindow.h"
GUI_EventPromo::GUI_EventPromo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI_EventPromo)
{
    ui->setupUi(this);
}

GUI_EventPromo::~GUI_EventPromo()
{
    delete ui;
}

void GUI_EventPromo::on_event_clicked()
{

    Gestion_Event *w = new Gestion_Event;
    hide();
    w->show();
}



void GUI_EventPromo::on_promo_clicked()
{

    Gestion_Promo *w = new Gestion_Promo;
    hide();
    w->show();
}

void GUI_EventPromo::on_pushButton_clicked()
{
   acceuil *w = new acceuil;
   hide();
   w->show();
}
