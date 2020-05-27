
#ifndef AVIS_CLIENT_H
#define AVIS_CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>

class AVIS_CLIENT
{public:
    AVIS_CLIENT();
  AVIS_CLIENT (int,QString,QDate,QString);
    QString get_AVISCLIENT();
    QDate get_DATEATES();
    bool ajouter();
    bool modifier(AVIS_CLIENT A);
    int get_ID_AVIS();

    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher_avis(QString);
    bool verif_EMAIL(QString ch);
    bool verif_CIN(int ch_CIN);
    bool verif_NOM(QString NOM);

    QString get_CIN();
    QSqlQuery tableclicked(QString a);
   QSqlQueryModel *afficher_idaz();
   QSqlQueryModel *afficher_idza();
   QSqlQueryModel *afficher_CINA();
private:
    QString AVISCLIENT, CIN;
    int ID_AVIS;
    QDate DATEAVIS;
};
#endif //AVIS_CLIENT_H
