#ifndef assurance_H
#define assurance_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <QDate>
#include "Societe.h"
#include "AssuranceAjout.h"
#include "ui_AssuranceAjout.h"


#include"AssuranceAfficher.h"
class assurance
{
public:
    assurance();
    assurance(QString ID,QString societe,QString etat,QString type, QDate date,QDate date2);
    QString getID() ;
    void setID( QString &value);
    QString getSociete() ;
    void setSociete( QString &value);
    QDate getDate2();
    void setDate2(QDate value);
    QString getEtat() ;
    void setEtat(QString &value);
    QDate getDate() ;
    void setDate( QDate &value);
    int getValide() ;
    void setValide();
    QString getType() ;
    void setType(QString value);



    bool ajouter();
    void list_societes(Ui::AFFICHAGE_ASSURANCE *ui);
    void list_societes2(Ui::AjouterAssurance *ui);
    void affichage(Ui::AFFICHAGE_ASSURANCE *ui);
    bool Supprimer(Ui::AFFICHAGE_ASSURANCE *ui);
    void Tri_ID(Ui::AFFICHAGE_ASSURANCE *ui) ;
    void Tri_Societe(Ui::AFFICHAGE_ASSURANCE *ui);

    void Recherche(Ui::AFFICHAGE_ASSURANCE *ui);

    bool modifier(Ui::AFFICHAGE_ASSURANCE *ui);
    void pdf(Ui::AFFICHAGE_ASSURANCE *ui);
private:
    QString ID,societe,type,etat;
    QDate date,date2;
    int age;
    int valide=0;
};

#endif // assurance_H
