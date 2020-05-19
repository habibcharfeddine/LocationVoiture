#include "Departement.h"

#include "DepartementAfficher.h"
#include "ui_DepartementAfficher.h"
DEPARTEMENT::DEPARTEMENT()
{

}

DEPARTEMENT::DEPARTEMENT(QString departement, QString libelle, QString description, int nbrp)
{
    this->setDepartement(departement);
    this->setLibelle(libelle);
    this->setDescription(description);
    this->setNbrp(nbrp);
}
QString DEPARTEMENT::getDepartement()
{
    return departement;
}

void DEPARTEMENT::setDepartement(QString value)
{
    departement = value;
}

QString DEPARTEMENT::getLibelle()
{
    return libelle;
}

void DEPARTEMENT::setLibelle( QString value)
{
    libelle = value;
}

QString DEPARTEMENT::getDescription()
{
    return description;
}

void DEPARTEMENT::setDescription(QString value)
{
    description = value;
}

int DEPARTEMENT::getNbrp()
{
    return nbrp;
}

void DEPARTEMENT::setNbrp(int value)
{
    nbrp = value;
}


int DEPARTEMENT::getValide()
{
    return valide;
}

void DEPARTEMENT::setValide()
{
    valide = 1;
}

bool DEPARTEMENT::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO DEPARTEMENTS (DEPARTEMENT, LIBELLE, DESCRIPTION,NBRP) "
                  "VALUES (:DEPARTEMENT, :LIBELLE, :DESCRIPTION,:NBRP)");
    query.bindValue(":DEPARTEMENT",getDepartement());
    query.bindValue(":LIBELLE", getLibelle());
    query.bindValue(":DESCRIPTION",getDescription());
    query.bindValue(":NBRP", getNbrp());

    return    query.exec();
}

void DEPARTEMENT::affichage(Ui::AFFICHAGE_DEPARTEMENT *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from DEPARTEMENTS");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}

void DEPARTEMENT::Tri_NBRP(Ui::AFFICHAGE_DEPARTEMENT *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from DEPARTEMENTS order by NBRP");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

void DEPARTEMENT::Tri_libelle(Ui::AFFICHAGE_DEPARTEMENT *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from DEPARTEMENTS order by LIBELLE");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}


void DEPARTEMENT::Recherche(Ui::AFFICHAGE_DEPARTEMENT *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString reference =ui->recherche->text();
    q.prepare("select * from DEPARTEMENTS where (LIBELLE LIKE '%"+reference+"%'");

    if ( q.exec() )
    { modal->setQuery(q);
      ui->tableView->setModel(modal);}

}
bool DEPARTEMENT::Supprimer(Ui::AFFICHAGE_DEPARTEMENT *ui)
{
    QSqlQuery q;
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("DELETE FROM DEPARTEMENTS WHERE reference ='"+id+"'");
    q.exec();


}

bool DEPARTEMENT::modifier(Ui::AFFICHAGE_DEPARTEMENT *ui)
{
    QSqlQuery q;

    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    q.prepare("UPDATE DEPARTEMENT set LIBELLE=:LIBELLE,DESCRIPTION=:DESCRIPTION,NBRP=:NBRP where DEPARTEMENT='"+ref+"'") ;

    q.bindValue(":LIBELLE",ui->libelle->text());
    q.bindValue(":DESCRIPTION",ui->description->text());
    q.bindValue(":NRBP",ui->nbrp->text());

    q.exec();

}

