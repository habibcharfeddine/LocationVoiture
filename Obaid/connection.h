#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include<QMessageBox>
#include<QtSql>
#include<QDialog>

class Connection
{
public:
    Connection();
    bool createconnect();

private:

    QSqlDatabase database;
    QSqlTableModel *tablemodel;
};

#endif // CONNECTION_H
