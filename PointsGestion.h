#ifndef Gestion_Points_H
#define Gestion_Points_H

#include <QWidget>

namespace Ui {
class Gestion_Points;
}

class Gestion_Points : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Points(QWidget *parent = 0);
    ~Gestion_Points();

private slots:
    void on_ajouter_clicked();
    void on_traiter_clicked();
    void on_pushButton_clicked();

private:
    Ui::Gestion_Points *ui;
};

#endif // Gestion_Points_H
