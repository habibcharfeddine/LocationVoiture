#ifndef PromoEvent_H
#define PromoEvent_H
#include"promotion.h"
#include"evenement.h"
#include <QMainWindow>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QtSql>
#include<QDialog>
#include<QDir>
#include<QDebug>
#include<QDate>
namespace Ui {
class PromoEvent;
}

class PromoEvent : public QMainWindow
{
    Q_OBJECT

public:
    explicit PromoEvent(QWidget *parent = nullptr);
    ~PromoEvent();

private slots:
void on_pushButton_clicked();
void on_pushButton_2_clicked();
void on_tableView_activated(const QModelIndex &index);
void on_tableView_2_activated (const QModelIndex &index);
void on_retour_clicked();
void on_recherche_clicked();
void on_recherche2_clicked();
void on_imprimer2_clicked();


void pdf();
void on_imprimer_clicked();




void on_pushButton_6_clicked();

void on_pushButton_3_clicked();

void on_pushButton_7_clicked();

void on_pushButton_4_clicked();

void on_pushButton_5_clicked();

void on_pushButton_8_clicked();


void on_comboBox_currentIndexChanged(const QString &arg1);

private:

void refresh();

    Ui::PromoEvent *ui;
     QSqlTableModel *tablemodel;
    EVENEMENT tmpevent,tmpeventdes ;
    PROMOTION tmppromo;
};

#endif // PromoEvent_H
