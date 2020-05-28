#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMainWindow>
#include <QDialog>
#include <QDate>

class EVENEMENT
{


public:
    EVENEMENT();
    EVENEMENT(int,QString,QDate,QDate);
    bool ajouter_event();
    QSqlQueryModel * afficher_event();
    QSqlQueryModel * afficher_eventdes();
    QSqlQueryModel * afficher_eventasc();
    bool supprimer_event(int);
    int get_id();
    QString get_nom();
    QDate get_datedebut();
    QDate get_datefin();


private:
    QString NOM_EVENT;
    int  ID_EVENT;
    QDate DATE_DEBUT_EVENT, DATE_FIN_EVENT;

};

#endif // EVENEMENT_H

