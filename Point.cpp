#include "Point.h"

#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
point::point()
{
client="";
nbp="";
cadeau="";
}

point::point (QString client, QString nbp,QString cadeau)
{
    this->client=client;
    this->nbp=nbp;
    this->cadeau=cadeau;

}


bool point::ajouter_point()
{
    QSqlQuery query;
    QString res=client;
    query.prepare("INSERT INTO point (client, nb_point, type) VALUES (:client, :nbp, :cadeau)");
    query.bindValue(":id", res);
    query.bindValue(":nbp", nbp);
    query.bindValue(":cadeau", cadeau);

    return query.exec();
}

void point::recherche(Ui::AjouterPoint *ui)
{
    QString num;
       QSqlQuery q;
       QSqlQueryModel *modal=new QSqlQueryModel();
       QString reference =ui->recherche_2->text();
       q.prepare("select * from point where (client LIKE '%"+reference+"%')");

       if ( q.exec() )
       { modal->setQuery(q);
           ui->tableView_2->setModel(modal);}
}

bool point::supprimer_point(QString cclient )
{

    QSqlQuery query;
    QString res=(cclient);
    query.prepare("Delete from point where client = :cclient ");
    query.bindValue(":id", res);
    return query.exec();

}
void point::triclient(Ui::AjouterPoint *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from point order by client");
    q.exec();
    model->setQuery(q);
    ui->tableView_2->setModel(model);
}

void point::trinb(Ui::AjouterPoint *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from point order by nb_point");
    q.exec();
    model->setQuery(q);
    ui->tableView_2->setModel(model);
}

void point::pdf(Ui::AjouterPoint *ui)
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString client = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),0)).toString();
    QString nbp = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),1)).toString();
    QString cadeau = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),3)).toString();
    doc.setHtml("<br> <h1> points de fidelité  " " " +client+ "  <br> <br> </h1>\n <h4 >id :" " " +client +" </h4> \n <h4> Nombre de points : " " "+nbp+ "  </h4> \n <h4>Cadeau : " " "+cadeau+" </h4> \n  ");
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}
