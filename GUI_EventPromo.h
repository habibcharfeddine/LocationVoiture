#ifndef GUI_EventPromo_H
#define GUI_EventPromo_H

#include <QWidget>

namespace Ui {
class GUI_EventPromo;
}

class GUI_EventPromo : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_EventPromo(QWidget *parent = 0);
    ~GUI_EventPromo();

private slots:
    void on_event_clicked();

    void on_promo_clicked();

    void on_pushButton_clicked();

private:
    Ui::GUI_EventPromo *ui;
};

#endif // GUI_EventPromo_H
