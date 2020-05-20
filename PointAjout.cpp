#include "PointAjout.h"
#include "ui_PointAjout.h"
#include"LocationGestion.h"
#include <QMessageBox>
#include"Point.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"GUI_LocationPointsF.h"
#include <QPrinter>
#include <QPrintDialog>
#include "PointsGestion.h"

AjouterPoint::AjouterPoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjouterPoint)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(tmppoint.afficher_point());


}
AjouterPoint::~AjouterPoint()
{
    delete ui;
}

QSqlQueryModel * point::afficher_point()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from point ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("client"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_point"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("cadeau"));
            return model;
}

void AjouterPoint::on_Valider_clicked()
{
    QString client = ui->Client->text();
    QString nbp= ui->NB->text();
         QString cadeau= ui->Cadeau->text();
point p(client,nbp,cadeau);
bool test=p.ajouter_point();
if (test)
{
    ui->tableView_2->setModel(tmppoint.afficher_point());

     QMessageBox::information(this,tr("Done"),tr("Ajout succès"));}
else
    {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}

}

void AjouterPoint::on_Annuler_clicked()
{
    Gestion_Points *w = new Gestion_Points;
    hide();
    w->show();
}

void AjouterPoint::on_Modifier_clicked()
{
    QString client,nbp,cadeau;
    client=ui->Client->text();
    nbp=ui->NB->text();
    cadeau=ui->Cadeau->text();

    QSqlQuery qry;

    qry.prepare("update point set client='"+client+"' , nb_point='"+nbp+"' , type='"+cadeau+"'  where client='"+client+"'");
    if (qry.exec())
           {
        ui->tableView_2->setModel(tmppoint.afficher_point());

           QMessageBox::information(this,tr("Done"),tr("Modifier succès"));}
           else
           {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void AjouterPoint::on_PDF_2_clicked()
{
point p;
p.pdf(ui);
}

void AjouterPoint::on_imprimer_2_clicked()
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

void AjouterPoint::on_supprimer_2_clicked()
{
    QString client = ui->Client->text();
    bool test=tmppoint.supprimer_point(client);
    if (test)
    {
      ui->tableView_2->setModel(tmppoint.afficher_point());
       QMessageBox::information(this,tr("Done"),tr("Supprimers succès"));}
               else
               {QMessageBox::critical(this,tr("Sorry"),tr("Error"));}
}

void AjouterPoint::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from point where client='"+val+"' or nb_point='"+val+"' or type='"+val+"'  ");
            if (qry.exec())
            {
                while (qry.next())
                 {
                  ui->Client->setText(qry.value(0).toString());

                 ui->NB->setText(qry.value(1).toString());

                  ui->Cadeau->setText(qry.value(2).toString());



                 }


            }
}

void AjouterPoint::on_search_2_clicked()
{
    point p;
    p.recherche(ui);
}

void AjouterPoint::on_comboBox_2_currentIndexChanged(int index)
{
    point p;
    if (index==0)
    { p.triclient(ui);

    }

    else
    {  p.trinb(ui);

    }
}
