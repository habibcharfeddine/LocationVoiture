#ifndef AFFICHAGE_PERSONNEL_H
#define AFFICHAGE_PERSONNEL_H

#include <QWidget>

namespace Ui {
class AFFICHAGE_PERSONNEL;
}

class AFFICHAGE_PERSONNEL : public QWidget
{
    Q_OBJECT

public:
    explicit AFFICHAGE_PERSONNEL(QWidget *parent = 0);
    ~AFFICHAGE_PERSONNEL();

private slots:
    void on_Annuler_clicked();

    void on_supprimer_clicked();

    void on_annuler_clicked();

    void on_search_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_Valider_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_PDF_clicked();

private:
    Ui::AFFICHAGE_PERSONNEL *ui;
};

#endif // AFFICHAGE_PERSONNEL_H
