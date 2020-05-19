#ifndef AjouterPersonnel_H
#define AjouterPersonnel_H
#include "Personnel.h"
#include <QWidget>

namespace Ui {
class AjouterPersonnel;
}

class AjouterPersonnel : public QWidget
{
    Q_OBJECT

public:
    explicit AjouterPersonnel(QWidget *parent = 0);
    ~AjouterPersonnel();

private slots:
    void on_Annuler_clicked();

    void on_Valider_clicked();

private:
    Ui::AjouterPersonnel *ui;
};

#endif // AjouterPersonnel_H
