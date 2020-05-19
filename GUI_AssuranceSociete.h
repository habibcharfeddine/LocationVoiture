#ifndef GUI_AssuranceSociete_H
#define GUI_AssuranceSociete_H

#include <QWidget>

namespace Ui {
class GUI_AssuranceSociete;
}

class GUI_AssuranceSociete : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_AssuranceSociete(QWidget *parent = 0);
    ~GUI_AssuranceSociete();

private slots:
    void on_assurance_clicked();

    void on_societe_clicked();

    void on_pushButton_clicked();

private:
    Ui::GUI_AssuranceSociete *ui;
};

#endif // GUI_AssuranceSociete_H
