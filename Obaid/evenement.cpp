#include "evenement.h"
#include <QDebug>
#include <connection.h>
#include <QDate>

EVENEMENT::EVENEMENT()
{
ID_EVENT=0;
NOM_EVENT="";
}

EVENEMENT::EVENEMENT (int ID_EVENT, QString NOM_EVENT,QDate DATE_DEBUT_EVENT,QDate DATE_FIN_EVENT)
{
    this->ID_EVENT=ID_EVENT;
    this->NOM_EVENT=NOM_EVENT;
    this->DATE_DEBUT_EVENT=DATE_DEBUT_EVENT;
    this->DATE_FIN_EVENT=DATE_FIN_EVENT;
}
int EVENEMENT::get_id(){return ID_EVENT;}
QString EVENEMENT::get_nom(){return NOM_EVENT;}
QDate EVENEMENT::get_datedebut(){return DATE_DEBUT_EVENT;}
QDate EVENEMENT::get_datefin(){return DATE_FIN_EVENT;}

bool EVENEMENT::ajouter_event()
{
    QSqlQuery query;
    QString res= QString::number(ID_EVENT);

    query.prepare("INSERT INTO EVENEMENTS (ID_EVENT ,NOM_EVENT ,DATE_DEBUT_EVENT ,DATE_FIN_EVENT)" "VALUES (:ID_EVENT, :NOM_EVENT, :DATE_DEBUT_EVENT, :DATE_FIN_EVENT)");
    query.bindValue(":ID_EVENT",res);
    query.bindValue(":NOM_EVENT",NOM_EVENT);
    query.bindValue(":DATE_DEBUT_EVENT", DATE_DEBUT_EVENT);
    query.bindValue(":DATE_FIN_EVENT", DATE_FIN_EVENT);
    return query.exec();
}


bool EVENEMENT::supprimer_event(int idd)
{
QSqlQuery query;
QString ress= QString::number(idd);
query.prepare("Delete from EVENEMENTS where ID_EVENT = :ID_EVENT ");
query.bindValue(":ID_EVENT", ress);
return    query.exec();
}

