#include "parking.h"
#include <QDebug>
#include "connexion.h"

PARKING::PARKING()
{
ID_PLACE=0;
ETAT="";
CONTACT_MAINTENANCE="";

}

PARKING::PARKING (int ID_PLACE, QString ETAT, QString CONTACT_MAINTENANCE)
{
    this->ID_PLACE=ID_PLACE;
    this->ETAT=ETAT;
    this->CONTACT_MAINTENANCE=CONTACT_MAINTENANCE;

}
int PARKING::get_id_place(){return ID_PLACE;}
QString PARKING::get_etat(){return ETAT;}
QString PARKING::get_contact_maintenance(){return CONTACT_MAINTENANCE;}


bool PARKING::ajouter_parking()
{
    QSqlQuery query;
    QString res= QString::number(ID_PLACE);


    query.prepare("INSERT INTO PARKING (ID_PLACE ,ETAT,CONTACT_MAINTENANCE)" "VALUES (:ID_PLACE, :ETAT, :CONTACT_MAINTENANCE)");
    query.bindValue(":ID_PLACE",res);
    query.bindValue(":ETAT",ETAT);
    query.bindValue(":CONTACT_MAINTENANCE",CONTACT_MAINTENANCE);

    return query.exec();
}
QSqlQueryModel * PARKING::afficher_parking()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from PARKING");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PLACE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CONTACT_MAINTANCE"));


    return model;
}


bool PARKING::supprimer_parking(int idd)
{
QSqlQuery query;
QString ress= QString::number(idd);
query.prepare("Delete from PARKING where ID_PLACE = :ID_PLACE ");
query.bindValue(":ID_PLACE", ress);
return    query.exec();
}
QSqlQueryModel * PARKING:: recherche(QString mat,bool *test)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from PARKING where ETAT='"+mat+"'");
    q.exec();
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PLACE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CONTACT_MAINTANCE"));
    *test=q.first();
    return model;

}

