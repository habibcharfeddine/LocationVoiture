#ifndef AFFICHAGE_SOCIETE_H
#define AFFICHAGE_SOCIETE_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class AFFICHAGE_SOCIETE;
}

class AFFICHAGE_SOCIETE : public QWidget
{
    Q_OBJECT

public:
    explicit AFFICHAGE_SOCIETE(QWidget *parent = 0);
    ~AFFICHAGE_SOCIETE();

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
    Ui::AFFICHAGE_SOCIETE *ui;
};

#endif // AFFICHAGE_SOCIETE_H
