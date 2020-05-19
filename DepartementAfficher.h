#ifndef AFFICHAGE_DEPARTEMENT_H
#define AFFICHAGE_DEPARTEMENT_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class AFFICHAGE_DEPARTEMENT;
}

class AFFICHAGE_DEPARTEMENT : public QWidget
{
    Q_OBJECT

public:
    explicit AFFICHAGE_DEPARTEMENT(QWidget *parent = 0);
    ~AFFICHAGE_DEPARTEMENT();

private slots:
    void on_annuler_clicked();

    void on_supprimer_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_search_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_Annuler_clicked();

    void on_Valider_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::AFFICHAGE_DEPARTEMENT *ui;
};

#endif // AFFICHAGE_DEPARTEMENT_H
