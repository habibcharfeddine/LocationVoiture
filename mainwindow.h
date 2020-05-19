#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include <QMediaPlayer>
#include"acceuil.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void myfunction();


    void on_login_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
