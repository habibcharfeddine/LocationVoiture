#include "DepartementGestion.h"
#include "ui_DepartementGestion.h"
#include "DepartementAfficher.h"
#include "DepartementAjout.h"
#include "GUI_PersonnelDepart.h"
Gestion_Departement::Gestion_Departement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Departement)
{
    ui->setupUi(this);
}

Gestion_Departement::~Gestion_Departement()
{
    delete ui;
}

void Gestion_Departement::on_ajouter_clicked()
{
    AjouterDepartement *w = new AjouterDepartement;
    hide();
    w->show();
}

void Gestion_Departement::on_pushButton_clicked()
{
    GUI_PersonnelDepart *w = new GUI_PersonnelDepart;
    hide();
    w->show();
}
void Gestion_Departement::on_traiter_clicked()
{
    AFFICHAGE_DEPARTEMENT *w = new AFFICHAGE_DEPARTEMENT;
    hide();
    w->show();
}



