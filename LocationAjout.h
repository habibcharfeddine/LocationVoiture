#ifndef LOCATIONAJOUT_H
#define LOCATIONAJOUT_H

#include"Location.h"
#include <QMainWindow>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QtSql>
#include<QDialog>
#include<QDir>
#include<QDebug>
namespace Ui {
    class AjouterLocation;
    }

    class AjouterLocation : public QWidget
    {
        Q_OBJECT

    public:
        explicit AjouterLocation(QWidget *parent = 0);
        ~AjouterLocation();

    private slots:
        void on_Annuler_clicked();

        void on_Valider_clicked();

        void on_Modifier_clicked();

        void on_PDF_2_clicked();

        void on_imprimer_2_clicked();

        void on_supprimer_2_clicked();

        void on_tableView_2_activated(const QModelIndex &index);

        void on_search_2_clicked();

        void on_comboBox_2_currentIndexChanged(const QString &arg1);

        void on_comboBox_2_currentIndexChanged(int index);

    private:
        location tmplocation;
        Ui::AjouterLocation *ui;
    };
#endif // LOCATIONAJOUT_H
