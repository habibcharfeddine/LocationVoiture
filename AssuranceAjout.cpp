#include "AssuranceAjout.h"
#include "ui_AssuranceAjout.h"
#include "AssuranceGestion.h"
#include "Assurance.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QPainter>
#include<QPdfWriter>
#include<QtWidgets>
AjouterAssurance::AjouterAssurance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterAssurance)
{
    ui->setupUi(this);

    assurance e;

    e.list_societes2(ui);
}

AjouterAssurance::~AjouterAssurance()
{
    delete ui;
}

void AjouterAssurance::on_Annuler_clicked()
{
    Gestion_Assurance *w = new Gestion_Assurance;
    hide();
    w->show();
}

void AjouterAssurance::on_Valider_clicked()
{
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QString msg_type ="type  invalide";
    QString msg_etat ="etat invalide";
    QString msg_id ="id invalide";
    QString msg_nbr="typebre de titres invalide";
    QString msg_vide="";
    QString msg_date="la date est inferieure a la date courante";
    QString msg_date2="la date de fin est inferieure a la date de debut";

    QString ID= ui->ID->text();
    QString Societe= ui->societe->currentText();
    QString etat= ui->etat->text();
    QString type= ui->type->text();
    QDate date=ui->date->date();
    QDate date2=ui->date2->date();
    QDate date3=QDate::currentDate();

    assurance e;
    if(ID.size()>0)
    {ui->ID->setStyleSheet("QLineEdit { color: black;}");
        ui->text_id->setText(msg_vide);}
    else {
        ui->ID->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_id->setText(msg_id);
        ui->text_id->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }

    if ((!type.contains(regex1))||(!type.contains(regex2)))
    {
        ui->type->setStyleSheet("QLineEdit { color: red;}");
        ui->text_type->setText(msg_type);
        ui->text_type->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setValide();
    }
    else { ui->type->setStyleSheet("QLineEdit { color: black;}");
        ui->text_type->setText(msg_vide);

    }

    if ((!etat.contains(regex1))||(!etat.contains(regex2)))
    {
        ui->etat->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_etat->setText(msg_etat);
        ui->text_etat->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->etat->setStyleSheet("QLineEdit { color: black;}");
        ui->text_etat->setText(msg_vide);
    }

    if ((date<date3))
    {
        ui->date->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_date->setText(msg_date);
        ui->text_date->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->date->setStyleSheet("QLineEdit { color: black;}");
        ui->text_date->setText(msg_vide);
    }
    if ((date2<date))
    {
        ui->date2->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_date2->setText(msg_date2);
        ui->text_date2->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->date2->setStyleSheet("QLineEdit { color: black;}");
        ui->text_date2->setText(msg_vide);
    }
    if (e.getValide()==0)
    {
        assurance jr(ID,Societe,etat,type,date,date2);
        bool test=jr.ajouter();


            ui->etat->setStyleSheet("QLineEdit { color: green;}");
            ui->type->setStyleSheet("QLineEdit { color: green;}");
            ui->ID->setStyleSheet("QLineEdit { color: green;}");
            ui->date->setStyleSheet("QDateEdit { color: green;}");
            ui->date2->setStyleSheet("QDateEdit { color: green;}");
            ui->societe->setStyleSheet("QComboBox { color: green;}");
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->setIcon(QIcon("icone.png"));
             notifyIcon->showMessage("GESTION RESERVATION ","reservation  ajouté",QSystemTrayIcon::Information,15000);

            {QMessageBox ::information(this,""," Assurance ajoutÃ©  ") ;}
    }

    else
    {QMessageBox ::information(this,"","erreur d'ajout  ") ;}

}
