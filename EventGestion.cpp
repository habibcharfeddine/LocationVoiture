#include "EventGestion.h"
#include "ui_EventGestion.h"
#include "GUI_EventPromo.h"
Gestion_Event::Gestion_Event(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Event)
{
    ui->setupUi(this);
}

Gestion_Event::~Gestion_Event()
{
    delete ui;
}

void Gestion_Event::on_ajouter_clicked()
{
    //AjouterEvent *w = new AjouterEvent;
    //hide();
    //w->show();
}

void Gestion_Event::on_pushButton_clicked()
{
    GUI_EventPromo *w = new GUI_EventPromo;
    hide();
    w->show();
}
void Gestion_Event::on_traiter_clicked()
{
    //AFFICHAGE_Event *w = new AFFICHAGE_Event;
    //hide();
    //w->show();
}



