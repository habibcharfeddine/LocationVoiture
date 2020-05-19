#ifndef VOITURE_H
#define VOITURE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMainWindow>
#include <QDialog>
#include "qcustomplot.h"


class VOITURE
{


public:
    VOITURE();
    VOITURE(int,QString,QString,int,int,QString,int);
    bool ajouter_voiture();
    QSqlQueryModel * afficher_voiture();
    QSqlQueryModel * afficher_voituredes();
      QSqlQueryModel * afficher_voitureasc();
    bool supprimer_voiture(int);
    int get_place_parking();
    int get_matricule();
    QString get_marque();
    QString get_couleur();
    int get_age();

    QString get_fournisseur();
    int get_prix();
     void chercher();
     QSqlQueryModel * recherche(QString valeur,int,QString);
       void statistique(QVector<double>*,QVector<QString>*);

   



private:
    QString MARQUE,COULEUR,FOURNISSEUR;
    int  MATRICULE,PLACE_PARKING,AGE,PRIX ;

};

#endif // VOITURE_H

