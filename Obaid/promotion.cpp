#include "promotion.h"
#include <QDebug>
#include "connection.h"
#include <QDate>

PROMOTION::PROMOTION()
{
ID_PROMO=0;
NOM_PROMO="";
POURCENTAGE_PROMO=0;

}

PROMOTION::PROMOTION (int ID_PROMO, QString NOM_PROMO, int POURCENTAGE_PROMO, QDate DATE_DEBUT_PROMO, QDate DATE_FIN_PROMO)
{
    this->ID_PROMO=ID_PROMO;
    this->NOM_PROMO=NOM_PROMO;
    this->POURCENTAGE_PROMO=POURCENTAGE_PROMO;
    this->DATE_DEBUT_PROMO=DATE_DEBUT_PROMO;
    this->DATE_FIN_PROMO=DATE_FIN_PROMO;

}
int PROMOTION::get_id_promo(){return ID_PROMO;}
QString PROMOTION::get_nom_promo(){return NOM_PROMO;}
int PROMOTION::get_pourcentage(){return POURCENTAGE_PROMO;}
QDate PROMOTION::get_datedebut(){return DATE_DEBUT_PROMO;}
QDate PROMOTION::get_datefin(){return DATE_FIN_PROMO;}

bool PROMOTION::ajouter_promotion()
{
    QSqlQuery query;
    QString res= QString::number(ID_PROMO);
    QString ress= QString::number(POURCENTAGE_PROMO);



    query.prepare("INSERT INTO PROMOTIONS (ID_PROMO ,NOM_PROMO, POURCENTAGE_PROMO, DATE_DEBUT_PROMO, DATE_FIN_PROMO)" "VALUES (:ID_PROMO, :NOM_PROMO, :POURCENTAGE_PROMO, :DATE_DEBUT_PROMO, :DATE_FIN_PROMO)");
    query.bindValue(":ID_PROMO",res);
    query.bindValue(":NOM_PROMO",NOM_PROMO);
    query.bindValue(":POURCENTAGE_PROMO",ress);
    query.bindValue(":DATE_DEBUT_PROMO",DATE_DEBUT_PROMO);
    query.bindValue(":DATE_FIN_PROMO",DATE_FIN_PROMO);

    return query.exec();
}


bool PROMOTION::supprimer_promotion(int idd)
{
QSqlQuery query;
QString ress= QString::number(idd);
query.prepare("Delete from PROMOTIONS where ID_PROMO = :ID_PROMO ");
query.bindValue(":ID_PROMO", ress);
return    query.exec();
}
