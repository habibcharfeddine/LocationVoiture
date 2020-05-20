#ifndef POINTAJOUT_H
#define POINTAJOUT_H


#include"Point.h"
#include <QMainWindow>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QtSql>
#include<QDialog>
#include<QDir>
#include<QDebug>
namespace Ui {
    class AjouterPoint;
    }

    class AjouterPoint : public QWidget
    {
        Q_OBJECT

    public:
        explicit AjouterPoint(QWidget *parent = 0);
        ~AjouterPoint();

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
        point tmppoint;
        Ui::AjouterPoint *ui;
    };
#endif // POINTAJOUT_H
