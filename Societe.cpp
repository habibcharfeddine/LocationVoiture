#include "Societe.h"

#include "SocieteAfficher.h"
#include "ui_SocieteAfficher.h"
societe::societe()
{

}

societe::societe(QString ID, QString nom, QString telephone, QString email)
{
    this->setID(ID);
    this->setNom(nom);
    this->setTelephone(telephone);
    this->setEmail(email);
}
QString societe::getID()
{
    return ID;
}

void societe::setID(QString value)
{
    ID = value;
}

QString societe::getNom()
{
    return nom;
}

void societe::setNom( QString value)
{
    nom = value;
}

QString societe::getTelephone()
{
    return telephone;
}

void societe::setTelephone(QString value)
{
    telephone = value;
}

QString societe::getEmail()
{
    return email;
}

void societe::setEmail(QString value)
{
    email = value;
}


int societe::getValide()
{
    return valide;
}

void societe::setValide()
{
    valide = 1;
}

bool societe::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO SOCIETE (reference, NOM, TELEPHONE,EMAIL) "
                  "VALUES (:reference, :nom, :telephone,:email)");
    query.bindValue(":reference",getID());
    query.bindValue(":nom", getNom());
    query.bindValue(":telephone",getTelephone());
    query.bindValue(":email", getEmail());

    return    query.exec();
}

void societe::affichage(Ui::AFFICHAGE_SOCIETE *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from SOCIETE");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}

void societe::Tri_REF(Ui::AFFICHAGE_SOCIETE *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from societe order by reference");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

void societe::Tri_NOM(Ui::AFFICHAGE_SOCIETE *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from societe order by NOM");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}


void societe::Recherche(Ui::AFFICHAGE_SOCIETE *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString reference =ui->recherche->text();
    q.prepare("select * from SOCIETE where (reference LIKE '%"+reference+"%' or NOM LIKE '%"+reference+"%' or telephone LIKE '%"+reference+"%' )");

    if ( q.exec() )
    { modal->setQuery(q);
      ui->tableView->setModel(modal);}

}
bool societe::Supprimer(Ui::AFFICHAGE_SOCIETE *ui)
{
    QSqlQuery q;
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("DELETE FROM SOCIETE WHERE reference ='"+id+"'");
    q.exec();


}

bool societe::modifier(Ui::AFFICHAGE_SOCIETE *ui)
{
    QSqlQuery q;

    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    q.prepare("UPDATE SOCIETE set NOM=:NOM,TELEPHONE=:TELEPHONE,EMAIL=:EMAIL where reference='"+ref+"'") ;

    q.bindValue(":NOM",ui->nom->text());
    q.bindValue(":TELEPHONE",ui->telephone->text());
    q.bindValue(":EMAIL",ui->email->text());

    q.exec();

}

