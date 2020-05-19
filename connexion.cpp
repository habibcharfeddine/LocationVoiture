#include "connexion.h"


bool connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("habib");
db.setUserName("habib");//inserer nom de l'utilisateur
db.setPassword("habib");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
return  test;
}
void connexion::fermerConnexion()
{db.close();}
