#ifndef GUI_ClientAvis_H
#define GUI_ClientAvis_H

#include <QWidget>

namespace Ui {
class GUI_ClientAvis;
}

class GUI_ClientAvis : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_ClientAvis(QWidget *parent = 0);
    ~GUI_ClientAvis();

private slots:
    void on_entraineurs_clicked();

    void on_joueurs_clicked();

    void on_pushButton_clicked();

private:
    Ui::GUI_ClientAvis *ui;
};

#endif // GUI_ClientAvis_H
