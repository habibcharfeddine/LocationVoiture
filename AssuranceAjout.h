#ifndef AjouterAssurance_H
#define AjouterAssurance_H
#include "Assurance.h"
#include <QWidget>

namespace Ui {
class AjouterAssurance;
}

class AjouterAssurance : public QWidget
{
    Q_OBJECT

public:
    explicit AjouterAssurance(QWidget *parent = 0);
    ~AjouterAssurance();

private slots:
    void on_Annuler_clicked();

    void on_Valider_clicked();

private:
    Ui::AjouterAssurance *ui;
};

#endif // AjouterAssurance_H
