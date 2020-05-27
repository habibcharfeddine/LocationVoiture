#include "connexion.h"
#include"QDebug"
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    //db.setHostName("localhost");
    db.setDatabaseName("mybase");
    //db.setDatabaseName("marwaproject");
    db.setUserName("marwa");
    db.setPassword("esprit20");

if (db.open())
test=true;
else qDebug()<< db.lastError().text();
    return  test;
}
