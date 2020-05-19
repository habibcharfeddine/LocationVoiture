#ifndef Gestion_Departement_H
#define Gestion_Departement_H

#include <QWidget>

namespace Ui {
class Gestion_Departement;
}

class Gestion_Departement : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Departement(QWidget *parent = 0);
    ~Gestion_Departement();

private slots:
    void on_ajouter_clicked();
    void on_traiter_clicked();
    void on_pushButton_clicked();

private:
    Ui::Gestion_Departement *ui;
};

#endif // Gestion_Departement_H
