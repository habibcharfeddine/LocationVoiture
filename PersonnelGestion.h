#ifndef Gestion_Personnel_H
#define Gestion_Personnel_H

#include <QWidget>

namespace Ui {
class Gestion_Personnel;
}

class Gestion_Personnel : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Personnel(QWidget *parent = 0);
    ~Gestion_Personnel();

private slots:
    void on_ajouter_clicked();
    void on_traiter_clicked();
    void on_pushButton_clicked();

private:
    Ui::Gestion_Personnel *ui;
};

#endif // Gestion_Personnel_H
