#ifndef Gestion_Assurance_H
#define Gestion_Assurance_H

#include <QWidget>

namespace Ui {
class Gestion_Assurance;
}

class Gestion_Assurance : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Assurance(QWidget *parent = 0);
    ~Gestion_Assurance();

private slots:
    void on_ajouter_clicked();
    void on_traiter_clicked();
    void on_pushButton_clicked();

private:
    Ui::Gestion_Assurance *ui;
};

#endif // Gestion_Assurance_H
