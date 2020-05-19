#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <QDate>
#include "DepartementGestion.h"

#include "DepartementAfficher.h"
class DEPARTEMENT
{
public:
    DEPARTEMENT();
    DEPARTEMENT(QString departement,QString libelle,QString description,int nbrp);

    QString getDepartement() ;
    void setDepartement( QString value);
    QString getLibelle() ;
    void setLibelle( QString value);
    QString getDescription() ;
    void setDescription( QString value);
    int getNbrp();
    void setNbrp( int value);
    int getValide();
    void setValide();

    bool ajouter();
void affichage(Ui::AFFICHAGE_DEPARTEMENT *ui);
bool Supprimer(Ui::AFFICHAGE_DEPARTEMENT *ui);
void Tri_NBRP(Ui::AFFICHAGE_DEPARTEMENT *ui) ;
 void Tri_libelle(Ui::AFFICHAGE_DEPARTEMENT *ui);

 void Recherche(Ui::AFFICHAGE_DEPARTEMENT *ui);
 bool modifier(Ui::AFFICHAGE_DEPARTEMENT *ui);
private:
    QString departement,libelle,description;
int valide=0,nbrp;
};

#endif // DEPARTEMENT_H
