#include "AssuranceGestion.h"
#include "ui_AssuranceGestion.h"
#include "AssuranceAjout.h"
#include "AssuranceAfficher.h"
#include "GUI_AssuranceSociete.h"
Gestion_Assurance::Gestion_Assurance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Assurance)
{
    ui->setupUi(this);
}

Gestion_Assurance::~Gestion_Assurance()
{
    delete ui;
}

void Gestion_Assurance::on_ajouter_clicked()
{
    AjouterAssurance *w = new AjouterAssurance;
    hide();
    w->show();
}

void Gestion_Assurance::on_pushButton_clicked()
{
    GUI_AssuranceSociete *w = new GUI_AssuranceSociete;
    hide();
    w->show();
}
void Gestion_Assurance::on_traiter_clicked()
{
    AFFICHAGE_ASSURANCE *w = new AFFICHAGE_ASSURANCE;
    hide();
    w->show();
}



