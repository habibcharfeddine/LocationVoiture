#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QWidget>

namespace Ui {
class acceuil;
}

class acceuil : public QWidget
{
    Q_OBJECT

public:
    explicit acceuil(QWidget *parent = 0);
    ~acceuil();

private slots:
    void on_habib_clicked();
    void on_mahdi_clicked();
    void on_sourour_clicked();
    void on_obaid_clicked();
    void on_marwa_clicked();
    void on_ahmed_clicked();
    void on_logout_clicked();

private:
    Ui::acceuil *ui;
};

#endif // ACCEUIL_H
