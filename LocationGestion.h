#ifndef Gestion_Location_H
#define Gestion_Location_H

#include <QWidget>

namespace Ui {
class Gestion_Location;
}

class Gestion_Location : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Location(QWidget *parent = 0);
    ~Gestion_Location();

private slots:
    void on_ajouter_clicked();
    void on_traiter_clicked();
    void on_pushButton_clicked();

private:
    Ui::Gestion_Location *ui;
};

#endif // Gestion_Location_H
