#include "LocationAjout.h"
#include "ui_LocationAjout.h"
#include"LocationGestion.h"
#include <QMessageBox>
#include"Location.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"GUI_LocationPointsF.h"
#include <QPrinter>
#include <QPrintDialog>
AjouterLocation::AjouterLocation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterLocation)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(tmplocation.afficher_location());


}
AjouterLocation::~AjouterLocation()
{
    delete ui;
}

QSqlQueryModel * location::afficher_location()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from location ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("datedeb"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("datefin"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
            return model;
}

void AjouterLocation::on_Valider_clicked()
{
    int id = ui->ID->text().toInt();
    QString datedeb= ui->date->text();
         QString datefin= ui->date2->text();
    int prix = ui->prix->text().toInt();
location l(id,datedeb,datefin,prix);
bool test=l.ajouter_location();
if (test)
{
    ui->tableView_2->setModel(tmplocation.afficher_location());

     QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}

}

void AjouterLocation::on_Annuler_clicked()
{
    Gestion_Location *w = new Gestion_Location;
    hide();
    w->show();
}

void AjouterLocation::on_Modifier_clicked()
{
    QString id,deb,fin,prix;
    id=ui->ID->text();
    deb=ui->date->text();
    fin=ui->date2->text();
    prix=ui->prix->text();

    QSqlQuery qry;

    qry.prepare("update location set id='"+id+"' , datedeb='"+deb+"' , datefin='"+fin+"' , prix='"+prix+"' where id='"+id+"'");
    if (qry.exec())
           {
        ui->tableView_2->setModel(tmplocation.afficher_location());

           QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
           else
           {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void AjouterLocation::on_PDF_2_clicked()
{
location l;
l.pdf(ui);
}

void AjouterLocation::on_imprimer_2_clicked()
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

void AjouterLocation::on_supprimer_2_clicked()
{
    int id = ui->ID->text().toInt();
    bool test=tmplocation.supprimer_location(id);
    if (test)
    {
      ui->tableView_2->setModel(tmplocation.afficher_location());
       QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
               else
               {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void AjouterLocation::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from LOCATION where ID='"+val+"' or datedeb='"+val+"' or datefin='"+val+"' or prix='"+val+"' ");
            if (qry.exec())
            {
                while (qry.next())
                 {
                  ui->ID->setText(qry.value(0).toString());

                // ui->date->setDate(qry.value(1).)

                //  ui->date2->setDate(qry.value(2));

                  ui->prix->setText(qry.value(3).toString());

                 }


            }
}

void AjouterLocation::on_search_2_clicked()
{
    location l;
    l.recherche(ui);
}

void AjouterLocation::on_comboBox_2_currentIndexChanged(int index)
{
    location l;
    if (index==0)
    { l.triid(ui);

    }

    else
    {  l.triprix(ui);

    }
}
