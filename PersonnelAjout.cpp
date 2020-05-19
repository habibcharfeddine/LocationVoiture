#include "PersonnelAjout.h"
#include "ui_PersonnelAjout.h"
#include "PersonnelGestion.h"
#include "Personnel.h"
#include <QMessageBox>
AjouterPersonnel::AjouterPersonnel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterPersonnel)
{
    ui->setupUi(this);

    PERSONNEL e;

    //e.list_societes2(ui);
}

AjouterPersonnel::~AjouterPersonnel()
{
    delete ui;
}

void AjouterPersonnel::on_Annuler_clicked()
{
    Gestion_Personnel *w = new Gestion_Personnel;
    hide();
    w->show();
}

void AjouterPersonnel::on_Valider_clicked()
{
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QString msg_nom ="nom  invalide";
    QString msg_prenom ="prenom invalide";
    QString msg_cin ="cin invalide";
    QString msg_poste="poste invalide";
    QString msg_vide="";
    QString msg_date="la date est inferieure a la date courante";

    QString cin= ui->cin->text();
    QString departement= ui->departement->currentText();
    QString nom= ui->nom->text();
    QString prenom= ui->prenom->text();
    QString poste= ui->poste->text();
    QDate date=ui->date->date();
    QDate date3=QDate::currentDate();
    PERSONNEL e;
    if(cin.size()==8)
    {ui->cin->setStyleSheet("QLineEdit { color: black;}");
        ui->text_cin->setText(msg_vide);}
    else {
        ui->cin->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_cin->setText(msg_cin);
        ui->text_cin->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }

    if ((!nom.contains(regex1))||(!nom.contains(regex2)))
    {
        ui->nom->setStyleSheet("QLineEdit { color: red;}");
        ui->text_nom->setText(msg_nom);
        ui->text_nom->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setValide();
    }
    else { ui->nom->setStyleSheet("QLineEdit { color: black;}");
        ui->text_nom->setText(msg_vide);

    }

    if ((!prenom.contains(regex1))||(!prenom.contains(regex2)))
    {
        ui->prenom->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_prenom->setText(msg_prenom);
        ui->text_prenom->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->prenom->setStyleSheet("QLineEdit { color: black;}");
        ui->text_prenom->setText(msg_vide);
    }

    if ((!poste.contains(regex1))||(!poste.contains(regex2)))
    {
        ui->poste->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_poste->setText(msg_poste);
        ui->text_poste->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->poste->setStyleSheet("QLineEdit { color: black;}");
        ui->text_poste->setText(msg_vide);
    }

    if ((date>date3))
    {
        ui->date->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_date->setText(msg_date);
        ui->text_date->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->date->setStyleSheet("QLineEdit { color: black;}");
        ui->text_date->setText(msg_vide);
    }

    if (e.getValide()==0)
    { PERSONNEL jr(cin,departement,nom,prenom,date,poste);
        if (jr.ajouter())
        {

            ui->nom->setStyleSheet("QLineEdit { color: green;}");
            ui->prenom->setStyleSheet("QLineEdit { color: green;}");
            ui->cin->setStyleSheet("QLineEdit { color: green;}");

            {QMessageBox ::information(this,""," entraineur ajouté  ") ;}
        }
        else {
            {QMessageBox ::critical(this,"","erreur d'ajout \n ID dupliquée") ;
                ui->cin->setStyleSheet("QLineEdit { color: red;}");
            }
        }
    }

    else
    {QMessageBox ::information(this,"","erreur d'ajout  ") ;}
}
