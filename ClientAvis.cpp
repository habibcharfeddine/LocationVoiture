#include "ClientAvis.h"
#include "ui_ClientAvis.h"
#include "CLIENT.h"
#include "AVIS_CLIENT.h"
#include "qcustomplot.h"
#include <QMessageBox>
#include "ClientAvis.h"
#include "ClientAvis.h"
#include<GUI_ClientAvis.h>
//#include "smtp.h"
#include <QString>
#include <QDate>


ClientAvis::ClientAvis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientAvis)
{

    ui->setupUi(this);
    ui->tabetudiant->setModel(tmpCLIENT.afficher_Clist());
    ui->listeclient->setModel(tmpCLIENT.afficher_Clist());//refreche combobox choix +refreche tableaux
    ui->tabetudiant_2->setModel(tmpAVIS_CLIENT.afficher());
    ui->comboBox_cin->setModel(tmpCLIENT.afficher_Clist());//combobox client => avis client
    ui->lineEdit_CIN->setEnabled(1);//t5alik mil lawel tnajem tekteb fih 3adi
}

ClientAvis::~ClientAvis()
{
    delete ui;
}
void ClientAvis::on_retour_clicked()
{
   GUI_ClientAvis *w = new GUI_ClientAvis;
   hide();
   w->show();
}
void ClientAvis::initClient()
{
    ui->lineEdit_CIN->clear();
    ui->lineEdit_NOM->clear();
    ui->lineEdit_PRENOM->clear();
    ui->lineEdit_Email_client->clear();
    ui->lineEdit_adress_client->clear();
    ui->dateEdit_ajout_client ->clear();
    ui->chemin->clear();
    ui->photo->clear();
    ui->lineEdit_recherche->clear();

}



void ClientAvis::initAVISClient()
{   ui->lineEdit_Id_AVIS_3->clear();
    ui->lineEdit_AVIS_client_2->clear();
    ui->comboBox_cin->clear();
    ui->dateEdit->clear();
}

//partie client


//bouton ajouter client


void ClientAvis::on_ajouter_clicked()
{
    int CIN = ui->lineEdit_CIN->text().toInt();
    QString NOM= ui->lineEdit_NOM->text();
    QString PRENOM= ui->lineEdit_PRENOM->text();
    QString EMAIL= ui->lineEdit_Email_client->text();
    QString ADRESS= ui->lineEdit_adress_client->text();
    QDate DATENAISSANCE= ui->dateEdit_ajout_client->date();
    QString IMAGE= ui->chemin->text();
    int AGE = ui->age->text().toInt();
    ui->lineEdit_CIN->setEnabled(1);
    CLIENT e(CIN, NOM , PRENOM, EMAIL, DATENAISSANCE, ADRESS,IMAGE, AGE);

    if(e.verif_EMAIL(e.get_EMAIL())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Client"),
                              QObject::tr("verifier Mail !\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }else if(e.verif_CIN(e.get_CIN())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Client"),
                              QObject::tr(" CIN doit contenir 8 chiffres !\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    }else if(e.verif_NOM(e.get_NOM())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Client"),
                              QObject::tr(" Nom doit contenir 20 caractéres !\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }else if(e.verif_NOM(e.get_PRENOM())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Client"),
                              QObject::tr(" Prenom doit contenir 20 caractéres !\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else{
        bool test=e.ajouter();
        if(test)
        {
            QFile file("C:/Users/QT/Desktop/Crud_Vfmarwa/Crud_Vfmarwa/Historique/HistoriqueClient.txt");
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                return;
            QTextStream cout(&file);
            QString message2="\n client a été ajoutée sous le prenom :"+PRENOM+" et sous le nom : "+NOM+"";
            cout << message2;

            ui->tabetudiant->setModel(tmpCLIENT.afficher_Clist());
            ui->listeclient->setModel(tmpCLIENT.afficher_Clist());//refreche combobox choix +refreche tableaux
            initClient();

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter client"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);


    }
}
//bouton supprimer client
void ClientAvis::on_pb_supprimer_clicked()
{
    int CIN = ui->lineEdit_CIN->text().toInt();
    bool test=tmpCLIENT.supprimer(CIN);
    if(test)
    {ui->tabetudiant->setModel(tmpCLIENT.afficher_Clist());//refresh
        ui->lineEdit_CIN->setEnabled(1);
        ui->listeclient->setModel(tmpCLIENT.afficher_Clist());
         ui->comboBox_cin->setModel(tmpCLIENT.afficher_Clist());
        initClient();//t5alilek les line edlit yofor5ou ba3ed ma tsuprimie
        QMessageBox::information(nullptr, QObject::tr("Supprimer CLIENT"),
                                 QObject::tr("CLIENT supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer CLIENT"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}
//bouton afficher client
void ClientAvis::on_pushButton_1_clicked()
{
    ui->tabetudiant->setModel(tmpCLIENT.afficher_Clist());
    ui->listeclient->setModel(tmpCLIENT.afficher_Clist());//refreche combobox choix +refreche tableaux
    initClient();
}



//bouton modifier client
void ClientAvis::on_pb_ajouter_3_clicked()
{
    int CIN = ui->lineEdit_CIN->text().toInt();
    QString NOM= ui->lineEdit_NOM->text();
    QString PRENOM= ui->lineEdit_PRENOM->text();
    QString EMAIL= ui->lineEdit_Email_client->text();
    QString ADRESS= ui->lineEdit_adress_client->text();
    QDate DATENAISSANCE= ui->dateEdit_ajout_client->date();
    QString IMAGE= ui->chemin->text();
    int AGE = ui->age->text().toInt();


    CLIENT e(CIN, NOM, PRENOM,EMAIL,DATENAISSANCE,ADRESS ,IMAGE ,AGE);
    bool test=e.modifier();
    if(test)
    {ui->tabetudiant->setModel(tmpCLIENT.afficher_Clist());//refresh
        ui->listeclient->setModel(tmpCLIENT.afficher_Clist());
        ui->lineEdit_CIN->setEnabled(1);
        initClient();
        QMessageBox::information(nullptr, QObject::tr("Modifier client"),
                                 QObject::tr("CLIENT modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

//imprimer historique client
void ClientAvis::on_pushButton_8_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
    ui->textBrowser->print(&printer);
}

//triez ordre croissant mail
void ClientAvis::on_radioButton_8_clicked()
{
    ui->tabetudiant->setModel(tmpCLIENT.afficher_MAILA());//refresh
}


//trier ordre croissant avis client
void ClientAvis::on_radioButton_18_clicked()
{
     ui->tabetudiant_2->setModel(tmpAVIS_CLIENT.afficher_idaz());//refresh
}



// tri dans ordre croissent
void ClientAvis::on_radioButton_17_clicked()
{
   ui->tabetudiant_2->setModel(tmpAVIS_CLIENT.afficher_idza());//refre
}

//trier selon nom croissant
void ClientAvis::on_radioButton_3_clicked()
{
    ui->tabetudiant->setModel(tmpCLIENT.afficher_nomaz());//refresh
}


//trier selon nom decroissant
void ClientAvis::on_radioButton_4_clicked()
{
    ui->tabetudiant->setModel(tmpCLIENT.afficher_nomza());//refresh
}


//trier ordre croissant cin
void ClientAvis::on_radioButton_5_clicked()
{
        ui->tabetudiant->setModel(tmpCLIENT.afficher_CINA());//refresh
}



//trrier selon ordre decroissant cin
void ClientAvis::on_radioButton_9_clicked()
{
    ui->tabetudiant->setModel(tmpCLIENT.afficher_CIND());//refresh
}

//bouton chercher client

//ouvrir historique client
void ClientAvis::on_pushButton_7_clicked()
{
    QFile file ("C:\\Users\\ASUS\\Downloads\\Crud_Vfmarwa\\HistoriqueClient.txt");//tbadel i chemin
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->textBrowser->setText(in.readAll());
}


//bouton ajouter image
void ClientAvis::on_pushButton_2_clicked()
{QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin->setText(filename);
            image =image.scaledToWidth(ui->photo->width(),Qt::SmoothTransformation);
            ui->photo->setPixmap(QPixmap::fromImage(image));
        }

    }

}
//bouton fenetre capture image
void ClientAvis::on_pushButton_3_clicked()
{
    c=new capture (this);
    c->show();
}
//bouton modifier image

void ClientAvis::on_pushButton_4_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin->setText(filename);
            image =image.scaledToWidth(ui->photo->width(),Qt::SmoothTransformation);
            ui->photo->setPixmap(QPixmap::fromImage(image));
        }

    }
}
//bouton choix client
void ClientAvis::on_pushButton_5_clicked()
{

    QString val=ui->listeclient->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from CLIENT where CIN='"+val+"'") ;

    if (query.exec())
    {
        while (query.next()) {

            ui->lineEdit_CIN->setText(query.value(0).toString()) ;
            ui->lineEdit_CIN->setDisabled(1);
            ui->lineEdit_NOM->setText(query.value(1).toString()) ;
            ui->lineEdit_PRENOM->setText(query.value(2).toString()) ;
            ui->lineEdit_Email_client->setText(query.value(3).toString()) ;
            ui->dateEdit_ajout_client->setDate(query.value(4).toDate()) ;
            ui->lineEdit_adress_client->setText(query.value(5).toString()) ;
            ui->chemin->setText(query.value(6).toString()) ;
            ui->age->setValue(query.value(7).toInt()) ;
            QPixmap pix(ui->chemin->text());
            int w =ui->photo->width();
            int h =ui->photo->height();
            ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        }
    }
}
//partie avis client
//bouton ajouter avis client
void ClientAvis::on_pb_ajouter_5_clicked()
{
    int Id_AVIS = ui->lineEdit_Id_AVIS_3->text().toInt();
    QString AVIS_client= ui->lineEdit_AVIS_client_2->text();
    QDate Date_AVIS= ui->dateEdit->date();
    QString CIN=ui->comboBox_cin->currentText();

    AVIS_CLIENT e(Id_AVIS ,AVIS_client ,Date_AVIS, CIN);
    /*if(e.verif_CIN(e.get_ID_AVIS())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter avis client"),
                              QObject::tr(" Id_AVIS doit contenir 8 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else if(e.verif_CIN(e.get_CIN())==false){
        QMessageBox::critical(nullptr, QObject::tr("Ajouter avis client"),
                              QObject::tr(" CIN doit contenir 8 chiffres !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{*/
        bool test=e.ajouter();
        if(test)
        {ui->tabetudiant_2->setModel(tmpAVIS_CLIENT.afficher());//refresh

           /* QMessageBox::information(nullptr, QObject::tr("Ajouter avis client"),
                                     QObject::tr("AVIS CLIENT ajouté.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);*/

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter avis client"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

    }

void ClientAvis::on_pb_supprimer_2_clicked()
{
    int Id_AVIS = ui->lineEdit_Id_AVIS_3->text().toInt();
    bool test=tmpAVIS_CLIENT.supprimer(Id_AVIS);
    if(test)
    {ui->tabetudiant_2->setModel(tmpAVIS_CLIENT.afficher());//refresh
        initAVISClient();
        QMessageBox::information(nullptr, QObject::tr("Supprimer avis client"),
                                 QObject::tr("avis client supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer avis client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}





//bouton modifier avis client
void ClientAvis::on_pb_ajouter_6_clicked()
{
    int Id_AVIS = ui->lineEdit_Id_AVIS_3->text().toInt();
    QString AVIS_client= ui->lineEdit_AVIS_client_2->text();
    QDate Date_AVIS= ui->dateEdit->date();
    QString CIN= ui->comboBox_cin->currentText();


    AVIS_CLIENT e(Id_AVIS ,AVIS_client ,Date_AVIS, CIN);
    bool test=tmpAVIS_CLIENT.modifier(e);
    if(test)
    {ui->tabetudiant_2->setModel(tmpAVIS_CLIENT.afficher());//refresh
        //ui->listeclient->setModel(tmpAVIS_CLIENT.afficher());
        ui->lineEdit_CIN->setEnabled(1);
        initAVISClient();
       /* QMessageBox::information(nullptr, QObject::tr("Modifier avis client"),
                                 QObject::tr("avis CLIENT modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);*/

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier avis client"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

//bouton afficher AVIS client
void ClientAvis::on_pushButton_22_clicked()

{
    ui->tabetudiant_2->setModel(tmpAVIS_CLIENT.afficher());
    ui->listeclient->setModel(tmpAVIS_CLIENT.afficher());//refreche combobox choix +refreche tableaux
     initAVISClient();
}
//bouton chercher  avis client




void ClientAvis::on_pushButton_6_clicked()
{
    s=new Statistique(this);
    s->show();
}

void ClientAvis::on_tabetudiant_2_activated(const QModelIndex &index)
{
    QString val=ui->tabetudiant_2->model()->data(index).toString();
       QSqlQuery qry ;

       qry=tmpAVIS_CLIENT.tableclicked(val);
       if (qry.exec())
       {
           while (qry.next())
           {

               ui->lineEdit_Id_AVIS_3->setDisabled(1);//idm mayetbadalech !!
               ui->lineEdit_Id_AVIS_3->setText(qry.value(0).toString());
               ui->lineEdit_AVIS_client_2->setText(qry.value(1).toString());
               ui->comboBox_cin->setCurrentText(qry.value(3).toString());
               ui->dateEdit->setDate(qry.value(2).toDate());
           }
       }
}



void ClientAvis::on_lineEdit_recherche_3_textChanged(const QString &arg1)
{
    QString q = ui->lineEdit_recherche_3->text();
       if (q=="")
       {ui->tabetudiant_2->setModel(tmpAVIS_CLIENT.afficher()) ; }
       else {
           ui->tabetudiant_2->setModel(tmpAVIS_CLIENT.rechercher_avis(q)) ;
       }
}

void ClientAvis::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    QString q = ui->lineEdit_recherche->text();
       if (q=="")
       {ui->tabetudiant->setModel(tmpCLIENT.afficher_Clist()) ; }
       else {
           ui->tabetudiant->setModel(tmpCLIENT.rechercher(q)) ;
       }
}
