#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();
};

#endif // CONNEXION_H
