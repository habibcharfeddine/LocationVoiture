#include "VoitureParking.h"
#include "ui_VoitureParking.h"
#include"voiture.h"
#include"parking.h"
#include "qcustomplot.h"
#include"stmp.h"
#include <src/SmtpMime>
#include <QDialog>
#include<QPrintDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QMessageBox>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QTextEdit>
#include <QMessageBox>
#include<QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include<QPainter>
#include <QAbstractSocket>
#include<QDesktopServices>
#include<QPdfWriter>
#include <QMessageBox>
#include<QUrl>
#include<QFileDialog>
#include <QPixmap>
#include <QTabWidget>
#include <QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include<QNetworkConfiguration>
#include<QNetworkAddressEntry>
#include "GUI_VoitureParking.h"


VoitureParking::VoitureParking(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::VoitureParking)
{
    ui->setupUi(this);

   /* tablemodel = new QSqlTableModel();//affichage et modification en meme temps mais n'envoie pas a la bd
    tablemodel->setTable("location");
    tablemodel->select();
    ui->tableView->setModel(tablemodel);*/

ui->tableView->setModel(tmpvoiture.afficher_voiture());
}

VoitureParking::~VoitureParking()
{
    delete ui;
}
void VoitureParking:: refresh()
{ ui->tableView->setModel(tmpvoiture.afficher_voiture());
ui->tableView_2->setModel(tmpparking.afficher_parking());

}



void VoitureParking::on_pushButton_clicked()
{
    int MATRICULE = ui->lineEdit->text().toInt();
    QString MARQUE= ui->lineEdit_2->text();
         QString COULEUR= ui->lineEdit_3->text();
    int PLACE_PARKING = ui->lineEdit_5->text().toInt();
   int AGE= ui->lineEdit_6->text().toInt();
    QString FOURNISSEUR= ui->lineEdit_7->text();
    int PRIX= ui->lineEdit_8->text().toInt();;
VOITURE v(MATRICULE,MARQUE,COULEUR,PLACE_PARKING,AGE,FOURNISSEUR,PRIX);
bool test=v.ajouter_voiture();
if (test)
{
     ui->tableView->setModel(tmpvoiture.afficher_voiture());
     QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}

}



//rechercher



/*void VoitureParking::afficher()
{

}*/
 void VoitureParking::on_pushButton_2_clicked()
 {
     int MATRICULE = ui->lineEdit->text().toInt();
     bool test=tmpvoiture.supprimer_voiture(MATRICULE);
     if (test)
     {
       ui->tableView->setModel(tmpvoiture.afficher_voiture());
        QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
                else
                {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
     }


void VoitureParking::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from VOITURE where MATRICULE='"+val+"' or MARQUE='"+val+"' or COULEUR='"+val+"' or PLACE_PARKING='"+val+"' or AGE='"+val+"' or FOURNISSEUR='"+val+"' or PRIX='"+val+"' ");
            if (qry.exec())
            {
                while (qry.next())
                 {
                  ui->lineEdit->setText(qry.value(0).toString());
                  ui->lineEdit_2->setText(qry.value(1).toString());

                  ui->lineEdit_3->setText(qry.value(2).toString());

                  ui->lineEdit_5->setText(qry.value(3).toString());
                   ui->lineEdit_6->setText(qry.value(4).toString());
                    ui->lineEdit_7->setText(qry.value(5).toString());
                     ui->lineEdit_8->setText(qry.value(6).toString());



                 }


            }

}

void VoitureParking::on_pushButton_6_clicked()
{
    QString MATRICULE,MARQUE,COULEUR,PLACE_PARKING;
    MATRICULE=ui->lineEdit->text();
    MARQUE=ui->lineEdit_2->text();
    COULEUR=ui->lineEdit_3->text();
    PLACE_PARKING=ui->lineEdit_5->text();
    QString AGE= ui->lineEdit_6->text();
    QString FOURNISSEUR= ui->lineEdit_7->text();
    QString PRIX= ui->lineEdit_8->text();

    QSqlQuery qry;

    qry.prepare("update VOITURE set MATRICULE='"+MATRICULE+"' , MARQUE='"+MARQUE+"' , COULEUR='"+COULEUR+"' , PLACE_PARKING='"+PLACE_PARKING+"', AGE='"+AGE+"' ,FOURNISSEUR='"+FOURNISSEUR+"' ,PRIX='"+PRIX+"' where MATRICULE='"+MATRICULE+"'");
    if (qry.exec())
           {
        ui->tableView->setModel(tmpvoiture.afficher_voiture());

           QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
           else
           {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void VoitureParking::on_pushButton_3_clicked()
{

        int ID_PLACE = ui->lineEdit_14->text().toInt();
        QString ETAT= ui->lineEdit_15->text();
        QString CONTACT_MAINTENACE= ui->lineEdit_16->text();

    PARKING p(ID_PLACE,ETAT,CONTACT_MAINTENACE);
    bool test=p.ajouter_parking();
    if (test)
    {
         ui->tableView_2->setModel(tmpparking.afficher_parking());
         QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
    else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}


}


void VoitureParking::on_pushButton_4_clicked()
{
    int ID_PLACE = ui->lineEdit_14->text().toInt();
    bool test=tmpparking.supprimer_parking(ID_PLACE);
    if (test)
    {
      ui->tableView_2->setModel(tmpparking.afficher_parking());
       QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
               else
               {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}
void VoitureParking::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from PARKING where ID_PLACE='"+val+"' or ETAT='"+val+"' or CONTACT_MAINTENACE='"+val+"' ");
            if (qry.exec())
            {
                while (qry.next())
                 {
                  ui->lineEdit_14->setText(qry.value(0).toString());
                  ui->lineEdit_15->setText(qry.value(1).toString());
                  ui->lineEdit_16->setText(qry.value(2).toString());

                 }


            }

}
void VoitureParking::on_retour_clicked()
{
    GUI_VoitureParking *w = new GUI_VoitureParking;
    hide();
    w->show();
}
void VoitureParking::on_pushButton_7_clicked()
{
    QString ID_PLACE,ETAT,CONTACT_MAINTENACE;
    ID_PLACE=ui->lineEdit_14->text();
    ETAT=ui->lineEdit_15->text();
    CONTACT_MAINTENACE=ui->lineEdit_16->text();


    QSqlQuery qry;

    qry.prepare("update PARKING set ID_PLACE='"+ID_PLACE+"' , ETAT='"+ETAT+"' ,CONTACT_MAINTENACE='"+CONTACT_MAINTENACE+"'  where ID_PLACE='"+ID_PLACE+"'");
    if (qry.exec())
           {
        ui->tableView_2->setModel(tmpparking.afficher_parking());

           QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
           else
           {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}



void VoitureParking::on_pushButton_5_clicked()
{
    ui->tableView->setModel(tmpvoituredes.afficher_voituredes());
}

void VoitureParking::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (ui->comboBox->currentText()=="DESC")
    ui->tableView->setModel(tmpvoiture.afficher_voituredes());
    else
    ui->tableView->setModel(tmpvoiture.afficher_voitureasc());
}




void VoitureParking::on_pushButton_8_clicked()
{

     QPrinter printer;
     printer.setPrinterName("printer name");
     QPrintDialog dialog(&printer,this);
      if(QDialog::Accepted == dialog.exec()){

          if(QPrinter::Landscape != printer.orientation())
                 {
                     printer.setOrientation(QPrinter::Landscape);
                 }
                 QPoint startPoint = QPoint(20, 20);
                 QRegion printRegion = QRegion( 20, 20, printer.paperRect().width(),printer.paperRect().height() );
                     for( int i = 0; i < 10; ++i ) // still need to fix this
                     {
                         ui->tableView->render( &printer, startPoint, printRegion, QWidget::DrawChildren );
                     }


    }
}

void VoitureParking::on_pushButton_9_clicked()
{
    QPdfWriter pdf("C:/Users/Sourour/Desktop/test.pdf");/*il faut toujour changer le nom (*/
    QPainter painter;
    if (! painter.begin(&pdf))
    {

                        qWarning("failed to open file, is it writable?");

    }
    QString titre =ui->lineEdit_9->text();
    const time_t ctt = time(0);
    QSqlQuery query;
     qWarning("testpdf1");
    query.exec("SELECT MATRICULE,MARQUE,COULEUR,PLACE_PARKING,AGE,FOURNISSEUR,PRIX FROM VOITURE WHERE MATRICULE='"+titre+"'");
      qWarning("testpdf2");

            while (query.next())
                  {

                int MATRICULE = query.value(0).toInt();
                QString MARQUE = query.value(1).toString();
                QString COULEUR = query.value(2).toString();
                int PLACE_PARKING = query.value(3).toInt();
                QString AGE = query.value(4).toString();
                QString FOURNISSEUR = query.value(5).toString();
                QString PRIX = query.value(6).toString();


        painter.drawText(2200,4000,MARQUE);
        painter.drawText(2200,4500,COULEUR);
         painter.drawText(2200,5000,AGE);
          painter.drawText(2200,5500,FOURNISSEUR);
           painter.drawText(2200,6000,PRIX);


        painter.setPen(Qt::red);
        painter.drawText(4500,2000,"VOITURE");
        painter.setPen(Qt::black);
        painter.drawText(500,2000,asctime(localtime(&ctt)));
        painter.drawText(500,3500,"MARQUE Du voiture:");
        painter.drawText(500,4000,"COULEUR:");
        painter.drawText(500,4500,"AGE:");
        painter.drawText(500,5000,"FOURNISSEUR:");
        painter.drawText(500,5500,"PRIX:");

            }

}



void VoitureParking::on_pushButton_10_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
            smtp.setUser("sourour.cherif@esprit.tn");
            smtp.setPassword("181JFT1668");
            MimeMessage message;
            message.setSender(new EmailAddress("sourour.cherif@esprit.tn", "Cherif sourour"));
            QString emaiil =ui->khra->text();
            message.addRecipient(new EmailAddress(emaiil, "Cherif sourour"));
            message.setSubject("voiture");
            MimeText text;
            QString emaill = ui->cp->toPlainText();
            text.setText(emaill);
            message.addPart(&text);
            smtp.connectToHost();
            smtp.login();
            if(smtp.sendMail(message))
            {
                QMessageBox::information(this, "PAS D'ERREUR", "Envoyé");
            }
            else
            {
                QMessageBox::critical(this, "ERREUR", "Non Envoyé (probleme de connexion)");
            }
            smtp.quit();

}

void VoitureParking::on_tabWidget_currentChanged(int index)
{
    // set dark background gradient:
          QLinearGradient gradient(0, 0, 0, 400);
          gradient.setColorAt(0, QColor(90, 90, 90));
          gradient.setColorAt(0.38, QColor(105, 105, 105));
          gradient.setColorAt(1, QColor(70, 70, 70));
          ui->customPlot->setBackground(QBrush(gradient));


          // create empty bar chart objects:
          QCPBars *amande = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
          amande->setAntialiased(false);
          amande->setStackingGap(1);
           //set names and colors:
          amande->setName("Repartition des MATRICULE selon leurs AGE ");
          amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
          amande->setBrush(QColor(0, 168, 140));
          // stack bars on top of each other:


          // prepare x axis with country labels:
          QVector<double> ticks;
          QVector<QString> labels;
          tmpvoiture.statistique(&ticks,&labels);

          /*QSqlQuery q;
          int i=0;
          q.exec("select MATRICULE from VOITURE");
          while (q.next()) {
              QString refer = q.value(0).toString();
              i++;
              ticks<<i;
              labels <<refer;
          }*/

          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
          textTicker->addTicks(ticks, labels);
          ui->customPlot->xAxis->setTicker(textTicker);
          ui->customPlot->xAxis->setTickLabelRotation(60);
          ui->customPlot->xAxis->setSubTicks(false);
          ui->customPlot->xAxis->setTickLength(0, 4);
          ui->customPlot->xAxis->setRange(0, 8);
          ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->xAxis->grid()->setVisible(true);
          ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
          ui->customPlot->xAxis->setTickLabelColor(Qt::white);
          ui->customPlot->xAxis->setLabelColor(Qt::white);

          // prepare y axis:
          ui->customPlot->yAxis->setRange(0,10);
          ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
          ui->customPlot->yAxis->setLabel("Statistics");
          ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->grid()->setSubGridVisible(true);
          ui->customPlot->yAxis->setTickLabelColor(Qt::white);
          ui->customPlot->yAxis->setLabelColor(Qt::white);
          ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
          ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

          // Add data:

          QVector<double> PlaceData;
          QSqlQuery q1("select AGE from VOITURE");
          while (q1.next()) {
                        int  nbr_fautee = q1.value(0).toInt();
                        PlaceData<< nbr_fautee;
                          }
          amande->setData(ticks, PlaceData);
          // setup legend:
          ui->customPlot->legend->setVisible(true);
          ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
          ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
          ui->customPlot->legend->setBorderPen(Qt::NoPen);
          QFont legendFont = font();
          legendFont.setPointSize(10);
          ui->customPlot->legend->setFont(legendFont);
          ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


          refresh();
}



void VoitureParking::on_pushButton_11_clicked()
{
   PARKING  p;
  int id = ui->Rechercher->text().toInt();
  QSqlQuery qry;
    QString res= QString::number(id);
    qry.prepare("Select *from PARKING where ID_PLACE = :id");
    qry.bindValue(":id", res);

    if(qry.exec())
    {

        while(qry.next())
        {
            ui->lineEdit_14->setText(qry.value(0).toString());
            ui->lineEdit_15->setText(qry.value(1).toString());
            ui->lineEdit_16->setText(qry.value(2).toString());

        }
        QMessageBox::information(this,"Gestion Parking:","cliquez sur OK pour continuer.");
        ui->Rechercher->setText("");
    }
    else
    {
        QMessageBox::critical(this,"Gestion Parking:","erreur!");
    }
}
