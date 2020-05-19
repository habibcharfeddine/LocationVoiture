#ifndef Gestion_Promo_H
#define Gestion_Promo_H

#include <QWidget>

namespace Ui {
class Gestion_Promo;
}

class Gestion_Promo : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Promo(QWidget *parent = 0);
    ~Gestion_Promo();

private slots:
    void on_ajouter_clicked();
    void on_traiter_clicked();
    void on_pushButton_clicked();

private:
    Ui::Gestion_Promo *ui;
};

#endif // Gestion_Promo_H
