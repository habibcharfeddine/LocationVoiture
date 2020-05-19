#include "DepartementAfficher.h"
#include "ui_DepartementAfficher.h"
#include "Departement.h"
#include "DepartementGestion.h"

#include<QDebug>
#include <QMessageBox>
AFFICHAGE_DEPARTEMENT::AFFICHAGE_DEPARTEMENT(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AFFICHAGE_DEPARTEMENT)
{
    ui->setupUi(this);
    DEPARTEMENT e ;
    e.affichage(ui);
}

AFFICHAGE_DEPARTEMENT::~AFFICHAGE_DEPARTEMENT()
{
    delete ui;
}

void AFFICHAGE_DEPARTEMENT::on_annuler_clicked()
{
    Gestion_Departement *w = new Gestion_Departement;
    hide();
    w->show();
}

void AFFICHAGE_DEPARTEMENT::on_supprimer_clicked()
{
    DEPARTEMENT e;
    e.Supprimer(ui);
    e.affichage(ui);
}

void AFFICHAGE_DEPARTEMENT::on_comboBox_currentIndexChanged(int index)
{
    DEPARTEMENT e;
    if (index==0)
    { e.Tri_libelle(ui);

    }

    else
    {  e.Tri_NBRP(ui);

    }
}

void AFFICHAGE_DEPARTEMENT::on_search_clicked()
{
    DEPARTEMENT e;
    e.Recherche(ui);
}

void AFFICHAGE_DEPARTEMENT::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->libelle->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->description->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->nbrp->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->departement->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->stackedWidget->setCurrentIndex(1);

}

void AFFICHAGE_DEPARTEMENT::on_Annuler_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AFFICHAGE_DEPARTEMENT::on_Valider_clicked()
{
    DEPARTEMENT e;

    if(e.modifier(ui))
    {
        QMessageBox ::information(this,"","Departement modifié")  ;
        ui->stackedWidget->setCurrentIndex(0);
        e.affichage(ui);
    }
    else
    { QMessageBox ::critical(this,"","erreur de modification") ;}
}

