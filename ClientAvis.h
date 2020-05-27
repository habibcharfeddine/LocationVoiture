#ifndef ClientAvis_H
#define ClientAvis_H
#include "CLIENT.h"
#include "AVIS_CLIENT.h"
#include <QMainWindow>
#include "capture.h"
#include"statistique.h"
namespace Ui {
class ClientAvis;
}

class ClientAvis : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientAvis(QWidget *parent = nullptr);
    ~ClientAvis();

    void stat();
    void initAVISClient();
private slots:


    void on_pb_supprimer_clicked();

    //void lineEdit_11(const QString &arg1);

    //void on_pb_ajouter_2_clicked();
    void on_retour_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

     void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_radioButton_8_clicked();

   void on_radioButton_18_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_9_clicked();

    void initClient();


    void on_pushButton_1_clicked();

    void on_pb_ajouter_5_clicked();

    void on_pb_ajouter_6_clicked();
    
    void on_pushButton_22_clicked();

    void on_radioButton_17_clicked();





    void on_ajouter_clicked();

    void on_pushButton_6_clicked();

    void on_tabetudiant_2_activated(const QModelIndex &index);



    void on_lineEdit_recherche_3_textChanged(const QString &arg1);

    void on_lineEdit_recherche_textChanged(const QString &arg1);

private:
    Ui::ClientAvis *ui;
    CLIENT tmpCLIENT;
    AVIS_CLIENT tmpAVIS_CLIENT;
    capture *c;
    Statistique *s;
};

#endif // ClientAvis_H
