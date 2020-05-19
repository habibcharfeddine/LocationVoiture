#include "PersonnelGestion.h"
#include "ui_PersonnelGestion.h"
#include "GUI_PersonnelDepart.h"
#include "PersonnelAjout.h"
//#include "PersonnelAfficher.h"
Gestion_Personnel::Gestion_Personnel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gestion_Personnel)
{
    ui->setupUi(this);
}

Gestion_Personnel::~Gestion_Personnel()
{
    delete ui;
}

void Gestion_Personnel::on_ajouter_clicked()
{
    AjouterPersonnel *w = new AjouterPersonnel;
    hide();
    w->show();
}

void Gestion_Personnel::on_pushButton_clicked()
{
    GUI_PersonnelDepart *w = new GUI_PersonnelDepart;
    hide();
    w->show();
}
void Gestion_Personnel::on_traiter_clicked()
{
    AFFICHAGE_PERSONNEL *w = new AFFICHAGE_PERSONNEL;
    hide();
    w->show();
}



