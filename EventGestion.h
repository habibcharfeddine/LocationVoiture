#ifndef Gestion_Event_H
#define Gestion_Event_H

#include <QWidget>

namespace Ui {
class Gestion_Event;
}

class Gestion_Event : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_Event(QWidget *parent = 0);
    ~Gestion_Event();

private slots:
    void on_ajouter_clicked();
    void on_traiter_clicked();
    void on_pushButton_clicked();

private:
    Ui::Gestion_Event *ui;
};

#endif // Gestion_Event_H
