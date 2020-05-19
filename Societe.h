#ifndef societe_H
#define societe_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <QDate>
#include "SocieteGestion.h"

#include "SocieteAfficher.h"
class societe
{
public:
    societe();
    societe(QString ID,QString nom,QString telephone,QString email);

    QString getID() ;
    void setID( QString value);
    QString getNom() ;
    void setNom( QString value);
    QString getTelephone() ;
    void setTelephone( QString value);
    QString getEmail();
    void setEmail( QString value);
    int getNombre_titres() ;
    void setNombre_titres(int value);
    int getNombre_joueurs() ;
    void setNombre_joueurs(int value);
    int getValide();
    void setValide();

    bool ajouter();
void affichage(Ui::AFFICHAGE_SOCIETE *ui);
bool Supprimer(Ui::AFFICHAGE_SOCIETE *ui);
void Tri_REF(Ui::AFFICHAGE_SOCIETE *ui) ;
 void Tri_NOM(Ui::AFFICHAGE_SOCIETE *ui);

 void Recherche(Ui::AFFICHAGE_SOCIETE *ui);
 bool modifier(Ui::AFFICHAGE_SOCIETE *ui);
private:
    QString ID,nom,telephone,email;
int valide=0;
};

#endif // societe_H
