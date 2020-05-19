#ifndef AFFICHAGE_ASSURANCE_H
#define AFFICHAGE_ASSURANCE_H

#include <QWidget>

namespace Ui {
class AFFICHAGE_ASSURANCE;
}

class AFFICHAGE_ASSURANCE : public QWidget
{
    Q_OBJECT

public:
    explicit AFFICHAGE_ASSURANCE(QWidget *parent = 0);
    ~AFFICHAGE_ASSURANCE();

private slots:
    void on_Annuler_clicked();

    void on_supprimer_clicked();

    void on_annuler_clicked();

    void on_search_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_Valider_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_PDF_clicked();
    void on_imprimer_clicked();

private:
    Ui::AFFICHAGE_ASSURANCE *ui;
};

#endif // AFFICHAGE_ASSURANCE_H
