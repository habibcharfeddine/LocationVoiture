#ifndef VoitureParking_H
#define VoitureParking_H
#include"voiture.h"
#include"parking.h"
//#include <QVoitureParking>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QtSql>
#include<QDialog>
#include<QDir>
#include<QDebug>
#include <QPdfWriter>
#include <QPainter>

namespace Ui {
class VoitureParking;
}

class VoitureParking : public QMainWindow
{
    Q_OBJECT

public:
    explicit VoitureParking(QMainWindow *parent = 0);
    ~VoitureParking();

private slots:

    void on_retour_clicked();
    void on_pushButton_clicked();
void on_pushButton_2_clicked();
void on_tableView_activated(const QModelIndex &index);
void on_tableView_2_activated (const QModelIndex &index);

void on_pushButton_6_clicked();

void on_pushButton_3_clicked();

void on_pushButton_7_clicked();

void on_pushButton_4_clicked();

void on_pushButton_5_clicked();

void on_comboBox_currentIndexChanged(const QString &arg1);

void on_pushButton_8_clicked();
void on_pushButton_9_clicked();
void on_pushButton_10_clicked();

void on_tabWidget_currentChanged(int index);

void on_pushButton_11_clicked();

private:

void refresh();

    Ui::VoitureParking *ui;
    QSqlTableModel *tablemodel;
    VOITURE tmpvoiture,tmpvoituredes ;
    PARKING tmpparking;
};

#endif // VoitureParking_H
