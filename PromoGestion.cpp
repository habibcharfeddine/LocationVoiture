#include "PromoGestion.h"
#include "ui_PromoGestion.h"
#include "GUI_EventPromo.h"
Gestion_Promo::Gestion_Promo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Promo)
{
    ui->setupUi(this);
}

Gestion_Promo::~Gestion_Promo()
{
    delete ui;
}

void Gestion_Promo::on_ajouter_clicked()
{
    //AjouterPromo *w = new AjouterPromo;
    //hide();
    //w->show();
}

void Gestion_Promo::on_pushButton_clicked()
{
    GUI_EventPromo *w = new GUI_EventPromo;
    hide();
    w->show();
}
void Gestion_Promo::on_traiter_clicked()
{
    //AFFICHAGE_Promo *w = new AFFICHAGE_Promo;
    //hide();
    //w->show();
}



