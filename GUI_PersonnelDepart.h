#ifndef GUI_PersonnelDepart_H
#define GUI_PersonnelDepart_H

#include <QWidget>

namespace Ui {
class GUI_PersonnelDepart;
}

class GUI_PersonnelDepart : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_PersonnelDepart(QWidget *parent = 0);
    ~GUI_PersonnelDepart();

private slots:
    void on_personnel_clicked();

    void on_depart_clicked();

    void on_pushButton_clicked();

private:
    Ui::GUI_PersonnelDepart *ui;
};

#endif // GUI_PersonnelDepart_H
