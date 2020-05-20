#ifndef POINT_H
#define POINT_H


#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMainWindow>
#include <QDialog>
#include "ui_PointAjout.h"
class point
{


public:
    point();
    point(QString,QString,QString);
    bool ajouter_point();
    QSqlQueryModel * afficher_point();
void recherche(Ui::AjouterPoint *ui);
void triclient(Ui::AjouterPoint *ui);
void trinb(Ui::AjouterPoint *ui);
void pdf(Ui::AjouterPoint *ui);

    bool supprimer_point(QString);

private:
    QString client,cadeau,nbp;


};

#endif // POINT_H
