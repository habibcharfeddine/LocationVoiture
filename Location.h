#ifndef LOCATION_H
#define LOCATION_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMainWindow>
#include <QDialog>
#include "ui_LocationAjout.h"
class location
{


public:
    location();
    location(int,QString,QString,int);
    bool ajouter_location();
    QSqlQueryModel * afficher_location();
void recherche(Ui::AjouterLocation *ui);
void triid(Ui::AjouterLocation *ui);
void triprix(Ui::AjouterLocation *ui);
void pdf(Ui::AjouterLocation *ui);

    bool supprimer_location(int);
    int get_id();
    QString get_datedeb();
    QString get_datefin();
    int get_prix();

private:
    QString datedeb,datefin;
    int id,prix;

};
#endif // LOCATION_H
