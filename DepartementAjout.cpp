#include "DepartementAjout.h"
#include "ui_DepartementAjout.h"
#include "Departement.h"
#include "DepartementGestion.h"
#include <QMessageBox>
AjouterDepartement::AjouterDepartement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterDepartement)
{
    ui->setupUi(this);
}

AjouterDepartement::~AjouterDepartement()
{
    delete ui;
}

void AjouterDepartement::on_Valider_clicked()
{

    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QRegExp regex3 ("^[0-9]*$");

    QString msg_dep ="ID invalide";
    QString msg_libelle ="libelle  invalide";
    QString msg_desc ="description invalide";
    QString msg_nbrp ="nbrp invalide";
    QString msg_vide="";

    QString departement= ui->departement->text();
    QString libelle= ui->libelle->text();
    QString description= ui->description->text();
    QString nbr= ui->nbrp->text();
    bool ok;

    int nbrp= nbr.toInt(&ok, 10);



    DEPARTEMENT e(departement,libelle,description,nbrp);

    if(departement.size()>0)
    {ui->departement->setStyleSheet("QLineEdit { color: black;}");
        ui->text_departement->setText(msg_vide);}
    else {
        ui->departement->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_departement->setText(msg_dep);
        ui->text_departement->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }


    if ((!libelle.contains(regex1))||(!libelle.contains(regex2)))
    {
        ui->libelle->setStyleSheet("QLineEdit { color: red;}");
        ui->text_libelle->setText(msg_libelle);
        ui->text_libelle->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setValide();
    }
    else { ui->libelle->setStyleSheet("QLineEdit { color: black;}");
        ui->text_libelle->setText(msg_vide);

    }
    if ((!description.contains(regex1))||(!description.contains(regex2)))
    {
        ui->description->setStyleSheet("QLineEdit { color: red;}");
        ui->text_desc->setText(msg_desc);
        ui->text_desc->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setValide();
    }
    else { ui->description->setStyleSheet("QLineEdit { color: black;}");
        ui->text_desc->setText(msg_vide);

    }

    if ((nbrp<1) )
    {
        ui->nbrp->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_nbrp->setText(msg_nbrp);
        ui->text_nbrp->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->nbrp->setStyleSheet("QLineEdit { color: black;}");
        ui->text_nbrp->setText(msg_vide);
    }


    if (e.getValide()==0)
    {
        if (e.ajouter())
        {
            ui->departement->setStyleSheet("QLineEdit { color: green;}");
            ui->libelle->setStyleSheet("QLineEdit { color: green;}");
            ui->nbrp->setStyleSheet("QLineEdit { color: green;}");
            ui->description->setStyleSheet("QLineEdit { color: green;}");

            {QMessageBox ::information(this,""," Departement ajouté  ") ;}
        }

    }

    else
    {QMessageBox ::information(this,"","erreur d'ajout  ") ;}

}

void AjouterDepartement::on_Annuler_clicked()
{
    Gestion_Departement *w = new Gestion_Departement;
    hide();
    w->show();
}
