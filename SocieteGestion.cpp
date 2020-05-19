#include "SocieteGestion.h"
#include "ui_SocieteGestion.h"
#include "SocieteAjout.h"

#include "SocieteAfficher.h"
#include "GUI_AssuranceSociete.h"
Gestion_Societe::Gestion_Societe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Societe)
{
    ui->setupUi(this);
}

Gestion_Societe::~Gestion_Societe()
{
    delete ui;
}

void Gestion_Societe::on_entraineurs_clicked()
{
    AjouterSociete *w = new AjouterSociete;
    hide();
    w->show();
}

void Gestion_Societe::on_pushButton_clicked()
{
    GUI_AssuranceSociete *w = new GUI_AssuranceSociete;
    hide();
    w->show();
}

void Gestion_Societe::on_entraineurs_2_clicked()
{
    AFFICHAGE_SOCIETE *w = new AFFICHAGE_SOCIETE;
    hide();
    w->show();
}
