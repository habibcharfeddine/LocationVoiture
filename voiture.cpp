#include "voiture.h"
#include <QDebug>
#include "connexion.h"


VOITURE::VOITURE()
{
MATRICULE=0;
MARQUE="";
COULEUR="";
PLACE_PARKING=0;
AGE=0;
FOURNISSEUR="";
PRIX=0;
}

VOITURE::VOITURE (int MATRICULE, QString MARQUE,QString COULEUR,int PLACE_PARKING,int AGE, QString FOURNISSEUR, int PRIX)
{
    this->MATRICULE=MATRICULE;
    this->MARQUE=MARQUE;
    this->COULEUR=COULEUR;
    this->PLACE_PARKING=PLACE_PARKING;
    this->AGE=AGE;
    this->FOURNISSEUR=FOURNISSEUR;
    this->PRIX=PRIX;
}
int VOITURE::get_matricule(){return MATRICULE;}
QString VOITURE::get_marque(){return MARQUE;}
QString VOITURE::get_couleur(){return COULEUR;}
int VOITURE::get_place_parking(){return PLACE_PARKING;}
int VOITURE::get_age(){return AGE;}
QString VOITURE::get_fournisseur(){return FOURNISSEUR;}
int VOITURE::get_prix(){return PRIX;}

bool VOITURE::ajouter_voiture()
{
    QSqlQuery query;
    QString res= QString::number(PLACE_PARKING);
    QString ress= QString::number(MATRICULE);
    QString resss= QString::number(AGE);
  QString ressss= QString::number(PRIX);
    query.prepare("INSERT INTO VOITURE (MATRICULE ,MARQUE ,COULEUR ,PLACE_PARKING,AGE,FOURNISSEUR,PRIX)" "VALUES (:MATRICULE, :MARQUE, :COULEUR, :PLACE_PARKING, :AGE, :FOURNISSEUR, :PRIX)");
    query.bindValue(":MATRICULE",ress);
    query.bindValue(":MARQUE",MARQUE);
    query.bindValue(":COULEUR", COULEUR);
    query.bindValue(":PLACE_PARKING", res);
        query.bindValue(":AGE", resss);
            query.bindValue(":FOURNISSEUR", FOURNISSEUR);
                query.bindValue(":PRIX", ressss);
    return query.exec();
}
QSqlQueryModel * VOITURE::afficher_voiture()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from VOITURE ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("COULEUR"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("PLACE_PARKING"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("FOURNISSEUR"));
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX"));
            return model;
}
QSqlQueryModel * VOITURE::afficher_voituredes()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" SELECT * FROM VOITURE ORDER BY PLACE_PARKING DESC ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("COULEUR"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("PLACE_PARKING"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("FOURNISSEUR"));
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX"));
            return model;
}
QSqlQueryModel * VOITURE::afficher_voitureasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" SELECT * FROM VOITURE ORDER BY PLACE_PARKING ASC ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("COULEUR"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("PLACE_PARKING"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("FOURNISSEUR"));
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("PRIX"));
            return model;
}


bool VOITURE::supprimer_voiture(int idd)
{
QSqlQuery query;
QString ress= QString::number(idd);
query.prepare("Delete from VOITURE where MATRICULE = :MATRICULE ");
query.bindValue(":MATRICULE", ress);
return    query.exec();
}
void VOITURE::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select MATRICULE from VOITURE");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}
