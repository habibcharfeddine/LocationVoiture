#include "Location.h"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
location::location()
{
id=0;
datedeb="";
datefin="";
prix=0;
}

location::location (int id,QString datedeb, QString datefin,int prix)
{
    this->id=id;
    this->datedeb=datedeb;
    this->datefin=datefin;
    this->prix=prix;
}
int location::get_id(){return id;}
QString location::get_datedeb(){return datedeb;}
QString location::get_datefin(){return datefin;}
int location::get_prix(){return prix;}

bool location::ajouter_location()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO location (id, datedeb, datefin, prix) VALUES (:id, :datedeb, :datefin, :prix)");
    query.bindValue(":id", res);
    query.bindValue(":datedeb", datedeb);
    query.bindValue(":datefin", datefin);
    query.bindValue(":prix", prix);
    return query.exec();
}

void location::recherche(Ui::AjouterLocation *ui)
{
    QString num;
       QSqlQuery q;
       QSqlQueryModel *modal=new QSqlQueryModel();
       QString reference =ui->recherche_2->text();
       q.prepare("select * from location where (ID LIKE '%"+reference+"%')");

       if ( q.exec() )
       { modal->setQuery(q);
           ui->tableView_2->setModel(modal);}
}

bool location::supprimer_location(int idd)
{

    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from location where ID = :id ");
    query.bindValue(":id", res);
    return query.exec();

}
void location::triid(Ui::AjouterLocation *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from location order by ID");
    q.exec();
    model->setQuery(q);
    ui->tableView_2->setModel(model);
}

void location::triprix(Ui::AjouterLocation *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from location order by prix");
    q.exec();
    model->setQuery(q);
    ui->tableView_2->setModel(model);
}

void location::pdf(Ui::AjouterLocation *ui)
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString id = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),0)).toString();
    QString date1 = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),1)).toString();
    QString prix = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),3)).toString();
    QString date2 = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),2)).toString();
    doc.setHtml("<br> <h1>liste des locations  " " " +id+ "  <br> <br> </h1>\n <h4 >id :" " " +id +" </h4> \n <h4> prix : " " "+prix+ "  </h4> \n <h4>Date de debut : " " "+date1+" </h4> \n <h4>Date de fin :" " "+date2+"  ");
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}
