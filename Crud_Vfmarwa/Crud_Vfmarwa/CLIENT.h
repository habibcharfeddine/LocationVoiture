#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
//#include"statistique.h"

class CLIENT
{ public:
    CLIENT();
    CLIENT (int,QString,QString,QString,QDate,QString,QString,int);
    QString get_NOM();
    QString get_IMAGE();
    QString get_PRENOM();
    QString get_ADRESS();
    QDate get_DATENAISSANCE();
    QString get_EMAIL();
    int get_CIN();
    int get_AGE();
    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher_Clist();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    bool verif_EMAIL(QString ch);
    bool verif_CIN(int ch_CIN);
    bool verif_NOM(QString NOM);


    QSqlQueryModel *afficher_nomaz();
    QSqlQueryModel *afficher_nomza();
    QSqlQueryModel *afficher_MAILA();
    QSqlQueryModel *afficher_CINA();
    QSqlQueryModel *afficher_CIND();

    QSqlQuery tableclicked(QString a);
private:
    QString NOM,PRENOM,ADRESS,EMAIL,IMAGE;
    int CIN,AGE;
   // Statistique *s ;
    QDate DATENAISSANCE;

};

#endif // CLIENT_H
