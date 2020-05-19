#ifndef GUI_VoitureParking_H
#define GUI_VoitureParking_H

#include <QWidget>

namespace Ui {
class GUI_VoitureParking;
}

class GUI_VoitureParking : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_VoitureParking(QWidget *parent = 0);
    ~GUI_VoitureParking();

private slots:
    void on_entraineurs_clicked();

    void on_joueurs_clicked();

    void on_pushButton_clicked();

private:
    Ui::GUI_VoitureParking *ui;
};

#endif // GUI_VoitureParking_H
