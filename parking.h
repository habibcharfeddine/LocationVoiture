#ifndef PARKING_H
#define PARKING_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMainWindow>
#include <QDialog>


class PARKING
{


public:
    PARKING();
    PARKING(int,QString,QString);
    bool ajouter_parking();
    QSqlQueryModel * afficher_parking();
     QSqlQueryModel *  recherche(QString,bool *);
    //QSqlQueryModel * afficher_voituredes();
      //QSqlQueryModel * afficher_voitureasc();
    bool supprimer_parking(int);

    int get_id_place();
    QString get_etat();
    QString get_contact_maintenance();




private:

    int  ID_PLACE ;
    QString ETAT,CONTACT_MAINTENANCE;

};


#endif // PARKING_H
