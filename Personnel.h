#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <QDate>
//#include "Societe.h"
#include "PersonnelAjout.h"
#include "ui_PersonnelAjout.h"


#include"PersonnelAfficher.h"
class PERSONNEL
{
public:
    PERSONNEL();
    PERSONNEL(QString cin,QString departement,QString nom,QString prenom, QDate date,QString poste);
    QString getCIN() ;
    void setCIN( QString &value);
    QString getDep() ;
    void setDep( QString &value);
    QString getNom();
    void setNom(QString &value);
    QString getPrenom() ;
    void setPrenom(QString &value);
    QDate getDate() ;
    void setDate( QDate &value);
    int getValide() ;
    void setValide();
    QString getPoste() ;
    void setPoste(QString &value);



    bool ajouter();
    void list_departements(Ui::AFFICHAGE_PERSONNEL *ui);
    void list_departements2(Ui::AjouterPersonnel *ui);
    void affichage(Ui::AFFICHAGE_PERSONNEL *ui);
    bool Supprimer(Ui::AFFICHAGE_PERSONNEL *ui);
    void Tri_NOM(Ui::AFFICHAGE_PERSONNEL *ui) ;
    void Tri_DEP(Ui::AFFICHAGE_PERSONNEL *ui);

    void Recherche(Ui::AFFICHAGE_PERSONNEL *ui);

    bool modifier(Ui::AFFICHAGE_PERSONNEL *ui);
    void pdf(Ui::AFFICHAGE_PERSONNEL *ui);
private:
    QString cin,nom,prenom,poste,departement;
    QDate date;
    int age;
    int valide=0;
};

#endif // PERSONNEL_H
