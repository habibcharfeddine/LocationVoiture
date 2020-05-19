#ifndef AjouterDepartement_H
#define AjouterDepartement_H

#include <QWidget>

namespace Ui {
class AjouterDepartement;
}

class AjouterDepartement : public QWidget
{
    Q_OBJECT

public:
    explicit AjouterDepartement(QWidget *parent = 0);
    ~AjouterDepartement();

private slots:
    void on_Valider_clicked();

    void on_Annuler_clicked();

private:
    Ui::AjouterDepartement *ui;
};

#endif // AjouterDepartement_H
