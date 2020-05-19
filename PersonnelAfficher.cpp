#include "PersonnelAfficher.h"
#include "ui_PersonnelAfficher.h"
#include "Personnel.h"
#include "PersonnelGestion.h"
#include <QMessageBox>
AFFICHAGE_PERSONNEL::AFFICHAGE_PERSONNEL(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AFFICHAGE_PERSONNEL)
{
    ui->setupUi(this);
    PERSONNEL j ;
    j.affichage(ui);

}

AFFICHAGE_PERSONNEL::~AFFICHAGE_PERSONNEL()
{
    delete ui;
}

void AFFICHAGE_PERSONNEL::on_Annuler_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AFFICHAGE_PERSONNEL::on_supprimer_clicked()
{
    PERSONNEL j;
    j.Supprimer(ui);
    j.affichage(ui);
}

void AFFICHAGE_PERSONNEL::on_annuler_clicked()
{
    Gestion_Personnel *w = new Gestion_Personnel;
    hide();
    w->show();
}

void AFFICHAGE_PERSONNEL::on_search_clicked()
{
    PERSONNEL j;
    j.Recherche(ui);
}

void AFFICHAGE_PERSONNEL::on_comboBox_currentIndexChanged(int index)
{
    PERSONNEL j;
    if (index==0)
    { j.Tri_NOM(ui);

    }

    else
    {  j.Tri_DEP(ui);

    }
}

void AFFICHAGE_PERSONNEL::on_Valider_clicked()
{
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QString msg_poste =" poste invalide";
    QString msg_etat ="etat invalide";
    QString msg_vide="";
    QString poste= ui->poste->text();
    QString departement= ui->departement->currentText();

    PERSONNEL e;

    if ((!poste.contains(regex1))||(!poste.contains(regex2)))
    {
        ui->poste->setStyleSheet("QLineEdit { color: red;}");
        ui->text_poste->setText(msg_poste);
        ui->text_poste->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setValide();
    }
    else { ui->poste->setStyleSheet("QLineEdit { color: black;}");
        ui->text_poste->setText(msg_vide);

    }


    if (e.getValide()==0)
    {
        if (e.modifier(ui))
        {
            ui->poste->setStyleSheet("QLineEdit { color: green;}");
            ui->departement->setStyleSheet("QLineEdit { color: green;}");
            {QMessageBox ::information(this,""," PERSONNEL modifier  ") ;}
            e.affichage(ui);
        }
        else {
            {QMessageBox ::critical(this,"","erreur de modification") ;

            }
        }
    }

    else
    {QMessageBox ::information(this,"","erreur de modification") ;}


}

void AFFICHAGE_PERSONNEL::on_tableView_doubleClicked(const QModelIndex &index)
{
    PERSONNEL j;
    j.list_departements(ui);
    ui->departement->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->poste->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->cin->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->cintex->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->cin->setEnabled(false);

    ui->stackedWidget->setCurrentIndex(1);
}

void AFFICHAGE_PERSONNEL::on_PDF_clicked()
{
    PERSONNEL j;
    j.pdf(ui);
}
