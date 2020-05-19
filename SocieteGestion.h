#ifndef Gestion_Societe_H
#define Gestion_Societe_H

#include <QWidget>

namespace Ui {
class Gestion_Societe;
}

class Gestion_Societe : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Societe(QWidget *parent = 0);
    ~Gestion_Societe();

private slots:
    void on_entraineurs_clicked();

    void on_pushButton_clicked();

    void on_entraineurs_2_clicked();

private:
    Ui::Gestion_Societe *ui;
};

#endif // Gestion_Societe_H
