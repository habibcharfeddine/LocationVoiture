#include "Assurance.h"

#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
#include "ui_AssuranceAjout.h"
#include "AssuranceAfficher.h"
#include "ui_AssuranceAfficher.h"
assurance::assurance()
{

}

assurance::assurance(QString ID, QString societe, QString etat, QString type, QDate date, QDate date2)
{
    this->setID(ID);
    this->setSociete(societe);
    this->setEtat(etat);
    this->setType(type);
    this->setDate(date);
    this->setDate2(date2);
}

QString assurance::getID()
{
    return ID;
}

void assurance::setID( QString &value)
{
    ID = value;
}

QString assurance::getSociete()
{
    return societe;
}

void assurance::setSociete(QString &value)
{
    societe = value;
}




QString assurance::getEtat()
{
    return etat;
}

void assurance::setEtat(QString &value)
{
    etat = value;
}

QString assurance::getType()
{
    return type;
}

void assurance::setType(QString value)
{
    type = value;
}
QDate assurance::getDate()
{
    return date;
}

void assurance::setDate(QDate &value)
{
    date = value;
}

int assurance::getValide()
{
    return valide;
}

void assurance::setValide()
{
    valide = 1;
}
QDate assurance::getDate2()
{
    return date2;
}

void assurance::setDate2(QDate value)
{
    date2 = value;
}
bool assurance::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO assurance (ID, SOCIETE, TYPE,ETAT,DATE1,DATE2) "
                  "VALUES (:id, :societe, :type,:etat,:date1,:date2)");
    query.bindValue(":id",getID());
    query.bindValue(":societe", getSociete());
    query.bindValue(":type",getType());
    query.bindValue(":etat", getEtat());
    query.bindValue(":date1", getDate());
    query.bindValue(":date2", getDate2());
    query.exec();

    return query.exec();


}
void assurance::list_societes(Ui::AFFICHAGE_ASSURANCE *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select reference from SOCIETE");
    q.exec();
    modal->setQuery(q);
    ui->societe->setModel(modal);
}

void assurance::list_societes2(Ui::AjouterAssurance *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select reference from SOCIETE");
    q.exec();
    modal->setQuery(q);
    ui->societe->setModel(modal);
}



void assurance::affichage(Ui::AFFICHAGE_ASSURANCE *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from ASSURANCE");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}
void assurance::Tri_ID(Ui::AFFICHAGE_ASSURANCE *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from ASSURANCE order by ID");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

void assurance::Tri_Societe(Ui::AFFICHAGE_ASSURANCE *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from ASSURANCE order by SOCIETE");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}


void assurance::Recherche(Ui::AFFICHAGE_ASSURANCE *ui)
{  QString num;
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString reference =ui->recherche->text();
    q.prepare("select * from ASSURANCE where (ID LIKE '%"+reference+"%')");

    if ( q.exec() )
    { modal->setQuery(q);
        ui->tableView->setModel(modal);}


}
bool assurance::Supprimer(Ui::AFFICHAGE_ASSURANCE *ui)
{
    QSqlQuery q;
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("DELETE FROM ASSURANCE WHERE ID ='"+id+"'");
    return q.exec();

}

bool assurance::modifier(Ui::AFFICHAGE_ASSURANCE *ui)
{
    QSqlQuery q;

    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    q.prepare("UPDATE ASSURANCE set ETAT=:ETAT,TYPE=:TYPE where ID='"+ref+"'") ;


    q.bindValue(":ETAT",ui->etat->text());
    q.bindValue(":TYPE",ui->type->text());


    return q.exec();

}

void assurance::pdf(Ui::AFFICHAGE_ASSURANCE *ui)
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString ID = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    QString date1 = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString();
    QString type = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString();
    QString date2 = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString();
    QString etat= ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString();
    QString societe = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString();
    doc.setHtml("<br> <h1>Information de l'assurance  " " " +ID+ "  <br> <br> </h1>\n <h4 >ID :" " " +ID +" </h4> \n <h4> Societé : " " "+societe+ "  </h4> \n <h4>Date de debut : " " "+date1+" </h4> \n <h4>Date de fin :" " "+date2+" " "ans </h4> \n <h4> etat :" " "+type+" </h4><h4> etat :" " "+etat+" </h4> ");
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

