#include "PromoEvent.h"
#include "ui_PromoEvent.h"
#include <QMessageBox>
#include "evenement.h"
#include "promotion.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <GUI_EventPromo.h>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QPrintDialog>
PromoEvent::PromoEvent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PromoEvent)
{
    ui->setupUi(this);

   /* tablemodel = new QSqlTableModel();//affichage et modification en meme temps mais n'envoie pas a la bd
    tablemodel->setTable("location");
    tablemodel->select();
    ui->tableView->setModel(tablemodel);*/

ui->tableView->setModel(tmpevent.afficher_event());
}

PromoEvent::~PromoEvent()
{
    delete ui;
}


void PromoEvent::on_pushButton_clicked()
{
    int ID_EVENT = ui->ID_EVENT->text().toInt();
    QString NOM_EVENT= ui->NOM_EVENT->text();
    QDate DATE_DEBUT_EVENT= ui->DATE_DEBUT_EVENT->date();
    QDate DATE_FIN_EVENT= ui->DATE_FIN_EVENT->date();
EVENEMENT f(ID_EVENT,NOM_EVENT,DATE_DEBUT_EVENT,DATE_FIN_EVENT);
bool test=f.ajouter_event();
if (test)
{
     ui->tableView->setModel(tmpevent.afficher_event());
     QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}

}


QSqlQueryModel * EVENEMENT::afficher_event()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from EVENEMENTS ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENT"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EVENT"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEBUT_EVENT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN_EVENT"));
            return model;
}
QSqlQueryModel * EVENEMENT::afficher_eventdes()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" SELECT * FROM EVENEMENTS ORDER BY ID_EVENT DESC ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENT"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EVENT"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEBUT_EVENT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN_EVENT"));
            return model;
}
QSqlQueryModel * EVENEMENT::afficher_eventasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" SELECT * FROM EVENEMENTS ORDER BY ID_EVENT ASC ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EVENT"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EVENT"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEBUT_EVENT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_FIN_EVENT"));
            return model;
}


/*void PromoEvent::afficher()
{

}*/
 void PromoEvent::on_pushButton_2_clicked()
 {
     int ID_EVENT = ui->ID_EVENT->text().toInt();
     bool test=tmpevent.supprimer_event(ID_EVENT);
     if (test)
     {
       ui->tableView->setModel(tmpevent.afficher_event());
        QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
                else
                {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
     }

void PromoEvent::on_retour_clicked()
{
    GUI_EventPromo *w = new GUI_EventPromo;
    hide();
    w->show();
}

void PromoEvent::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from EVENEMENTS where ID_EVENT='"+val+"' or NOM_EVENT='"+val+"' or DATE_DEBUT_EVENT='"+val+"' or DATE_FIN_EVENT='"+val+"' ");
            if (qry.exec())
            {
                while (qry.next())
                 {
                  ui->ID_EVENT->setText(qry.value(0).toString());
                  ui->NOM_EVENT->setText(qry.value(1).toString());

                  ui->DATE_DEBUT_EVENT->setDate(qry.value(2).toDate());

                  ui->DATE_FIN_EVENT->setDate(qry.value(3).toDate());


                 }


            }

}

void PromoEvent::on_pushButton_6_clicked()
{
    QString ID_EVENT,NOM_EVENT,DATE_DEBUT_EVENT,DATE_FIN_EVENT;
    ID_EVENT=ui->ID_EVENT->text();
    NOM_EVENT=ui->NOM_EVENT->text();
    DATE_DEBUT_EVENT=ui->DATE_DEBUT_EVENT->text();
    DATE_FIN_EVENT=ui->DATE_FIN_EVENT->text();

    QSqlQuery qry;

    qry.prepare("update EVENEMENTS set ID_EVENT='"+ID_EVENT+"' , NOM_EVENT='"+NOM_EVENT+"' , DATE_DEBUT_EVENT='"+DATE_DEBUT_EVENT+"' , DATE_FIN_EVENT='"+DATE_FIN_EVENT+"' where ID_EVENT='"+ID_EVENT+"'");
    if (qry.exec())
           {
        ui->tableView->setModel(tmpevent.afficher_event());

           QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
           else
           {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void PromoEvent::on_pushButton_3_clicked()
{

        int ID_PROMO = ui->ID_PROMO->text().toInt();
        QString NOM_PROMO= ui->NOM_PROMO->text();
        int POURCENTAGE_PROMO = ui->POURCENTAGE_PROMO->text().toInt();
        QDate DATE_DEBUT_PROMO= ui->DATE_DEBUT_PROMO->date();
        QDate DATE_FIN_PROMO= ui->DATE_FIN_PROMO->date();

    PROMOTION p(ID_PROMO,NOM_PROMO,POURCENTAGE_PROMO,DATE_DEBUT_PROMO,DATE_FIN_PROMO);
    bool test=p.ajouter_promotion();
    if (test)
    {
         ui->tableView_2->setModel(tmppromo.afficher_promotion());
         QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
    else
        {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}


}
QSqlQueryModel * PROMOTION::afficher_promotion()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from PROMOTIONS ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROMO"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROMO"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("POURCENTAGE_PROMO"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEBUT_PROMO"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FIN_PROMO"));

            return model;
}

void PromoEvent::on_pushButton_4_clicked()
{
    int ID_PROMO = ui->ID_PROMO->text().toInt();
    bool test=tmppromo.supprimer_promotion(ID_PROMO);
    if (test)
    {
      ui->tableView_2->setModel(tmppromo.afficher_promotion());
       QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
               else
               {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}
void PromoEvent::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from PROMOTIONS where ID_PROMO='"+val+"' or NOM_PROMO='"+val+"' or POURCENTAGE_PROMO='"+val+"' or DATE_DEBUT_PROMO='"+val+"' or DATE_FIN_PROMO='"+val+"'  ");
            if (qry.exec())
            {
                while (qry.next())
                 {
                  ui->ID_PROMO->setText(qry.value(0).toString());
                  ui->NOM_PROMO->setText(qry.value(1).toString());
                  ui->POURCENTAGE_PROMO->setText(qry.value(2).toString());
                  ui->DATE_DEBUT_PROMO->setDate(qry.value(3).toDate());
                  ui->DATE_FIN_PROMO->setDate(qry.value(4).toDate());

                 }


            }

}
void PromoEvent::on_pushButton_7_clicked()
{
    QString ID_PROMO,NOM_PROMO,POURCENTAGE_PROMO,DATE_DEBUT_PROMO,DATE_FIN_PROMO;
    ID_PROMO=ui->ID_PROMO->text();
    NOM_PROMO=ui->NOM_PROMO->text();
    POURCENTAGE_PROMO=ui->POURCENTAGE_PROMO->text();
    DATE_DEBUT_PROMO=ui->DATE_DEBUT_PROMO->text();
    DATE_FIN_PROMO=ui->DATE_FIN_PROMO->text();


    QSqlQuery qry;

    qry.prepare("update PROMOTIONS set ID_PROMO='"+ID_PROMO+"' , NOM_PROMO='"+NOM_PROMO+"' , POURCENTAGE_PROMO='"+POURCENTAGE_PROMO+"' , DATE_DEBUT_PROMO='"+DATE_DEBUT_PROMO+"' , DATE_FIN_PROMO='"+DATE_FIN_PROMO+"'  where ID_PROMO='"+ID_PROMO+"'");
    if (qry.exec())
           {
        ui->tableView_2->setModel(tmppromo.afficher_promotion());

           QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
           else
           {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}



void PromoEvent::on_pushButton_5_clicked()
{
    ui->tableView->setModel(tmpeventdes.afficher_eventdes());
}
void PromoEvent::on_recherche_clicked()
{
    QString num;
        QSqlQuery q;
        QSqlQueryModel *modal=new QSqlQueryModel();
        QString reference =ui->Rechercher->text();
        q.prepare("select * from EVENEMENTS where (ID_EVENT LIKE '%"+reference+"%')");

        if ( q.exec() )
        { modal->setQuery(q);
            ui->tableView->setModel(modal);}


}
void PromoEvent::on_recherche2_clicked()
{
    QString num;
        QSqlQuery q;
        QSqlQueryModel *modal=new QSqlQueryModel();
        QString reference =ui->Rechercher2->text();
        q.prepare("select * from PROMOTIONS where (ID_PROMO LIKE '%"+reference+"%')");

        if ( q.exec() )
        { modal->setQuery(q);
            ui->tableView_2->setModel(modal);}


}

void PromoEvent::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (ui->comboBox->currentText()=="DESC")
    ui->tableView->setModel(tmpevent.afficher_eventdes());
    else
    ui->tableView->setModel(tmpevent.afficher_eventasc());


}


void PromoEvent::on_imprimer_clicked()
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
void PromoEvent::on_imprimer2_clicked()
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
                         ui->tableView_2->render( &printer, startPoint, printRegion, QWidget::DrawChildren );
                     }


    }
}

