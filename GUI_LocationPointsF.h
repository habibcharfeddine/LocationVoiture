#ifndef GUI_LocationPointsF_H
#define GUI_LocationPointsF_H

#include <QWidget>

namespace Ui {
class GUI_LocationPointsF;
}

class GUI_LocationPointsF : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_LocationPointsF(QWidget *parent = 0);
    ~GUI_LocationPointsF();

private slots:
    void on_location_clicked();

    void on_points_clicked();

    void on_pushButton_clicked();

private:
    Ui::GUI_LocationPointsF *ui;
};

#endif // GUI_LocationPointsF_H
