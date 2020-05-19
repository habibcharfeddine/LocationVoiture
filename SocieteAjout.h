#ifndef AjouterSociete_H
#define AjouterSociete_H

#include <QWidget>

namespace Ui {
class AjouterSociete;
}

class AjouterSociete : public QWidget
{
    Q_OBJECT

public:
    explicit AjouterSociete(QWidget *parent = 0);
    ~AjouterSociete();

private slots:
    void on_Valider_clicked();

    void on_Annuler_clicked();

private:
    Ui::AjouterSociete *ui;
};

#endif // AjouterSociete_H
