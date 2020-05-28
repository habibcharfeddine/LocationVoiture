#ifndef PROMOTION_H
#define PROMOTION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMainWindow>
#include <QDialog>
#include <QDate>

class PROMOTION
{


public:
    PROMOTION();
    PROMOTION(int,QString,int,QDate,QDate);
    bool ajouter_promotion();
    QSqlQueryModel * afficher_promotion();
    //QSqlQueryModel * afficher_eventdes();
      //QSqlQueryModel * afficher_eventasc();
    bool supprimer_promotion(int);

    int get_id_promo();
    QString get_nom_promo();
    int get_pourcentage();
    QDate get_datedebut();
    QDate get_datefin();




private:

    int  ID_PROMO ;
    QString NOM_PROMO;
    int POURCENTAGE_PROMO;
    QDate DATE_DEBUT_PROMO,DATE_FIN_PROMO;

};


#endif // PROMOTION_H
