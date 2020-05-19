#include "Personnel.h"

#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
#include "ui_PersonnelAjout.h"
#include "PersonnelAfficher.h"
#include "ui_PersonnelAfficher.h"
PERSONNEL::PERSONNEL()
{

}

PERSONNEL::PERSONNEL(QString cin, QString departement, QString nom, QString prenom, QDate date, QString poste)
{
    this->setCIN(cin);
    this->setDep(departement);
    this->setNom(nom);
    this->setPrenom(prenom);
    this->setDate(date);
    this->setPoste(poste);
}

QString PERSONNEL::getCIN()
{
    return cin;
}

void PERSONNEL::setCIN( QString &value)
{
    cin = value;
}

QString PERSONNEL::getDep()
{
    return departement;
}

void PERSONNEL::setDep(QString &value)
{
    departement = value;
}




QString PERSONNEL::getNom()
{
    return nom;
}

void PERSONNEL::setNom(QString &value)
{
   nom = value;
}

QString PERSONNEL::getPrenom()
{
    return prenom;
}

void PERSONNEL::setPrenom(QString &value)
{
    prenom = value;
}
QDate PERSONNEL::getDate()
{
    return date;
}

void PERSONNEL::setDate(QDate &value)
{
    date = value;
}

int PERSONNEL::getValide()
{
    return valide;
}

void PERSONNEL::setValide()
{
    valide = 1;
}
QString PERSONNEL::getPoste()
{
    return poste;
}

void PERSONNEL::setPoste(QString &value)
{
    poste = value;
}
bool PERSONNEL::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO PERSONNEL (CIN, DEPARTEMENT,NOM,PRENOM,DATE,POSTE) "
                  "VALUES (:CIN, :DEPARTEMENT, :NOM,:PRENOM,:DATE,:POSTE)");
    query.bindValue(":CIN",getCIN());
    query.bindValue(":DEPARTEMENT", getDep());
    query.bindValue(":NOM",getNom());
    query.bindValue(":PRENOM", getPrenom());
    query.bindValue(":DATE", getDate());
    query.bindValue(":POSTE", getPoste());
    query.exec();

    return query.exec();


}
void PERSONNEL::list_departements(Ui::AFFICHAGE_PERSONNEL *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select DEPARTEMENT from DEPARTEMENTS");
    q.exec();
    modal->setQuery(q);
    ui->departement->setModel(modal);
}

void PERSONNEL::list_departements2(Ui::AjouterPersonnel *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select DEPARTEMENT from DEPARTEMENTS");
    q.exec();
    modal->setQuery(q);
    ui->departement->setModel(modal);
}



void PERSONNEL::affichage(Ui::AFFICHAGE_PERSONNEL *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from PERSONNEL");
    q.exec();
    modal->setQuery(q);
    ui->tableView->setModel(modal);
}
void PERSONNEL::Tri_NOM(Ui::AFFICHAGE_PERSONNEL *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from PERSONNEL order by NOM");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

void PERSONNEL::Tri_DEP(Ui::AFFICHAGE_PERSONNEL *ui)
{
    QSqlQuery q;
    QSqlQueryModel *model=new QSqlQueryModel();
    q.prepare("select * from PERSONNEL order by DEPARTEMENT");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}


void PERSONNEL::Recherche(Ui::AFFICHAGE_PERSONNEL *ui)
{  QString num;
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    QString reference =ui->recherche->text();
    q.prepare("select * from PERSONNEL where (NOM LIKE '%"+reference+"%')");

    if ( q.exec() )
    { modal->setQuery(q);
        ui->tableView->setModel(modal);}


}
bool PERSONNEL::Supprimer(Ui::AFFICHAGE_PERSONNEL *ui)
{
    QSqlQuery q;
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("DELETE FROM PERSONNEL WHERE CIN ='"+id+"'");
    return q.exec();

}

bool PERSONNEL::modifier(Ui::AFFICHAGE_PERSONNEL *ui)
{
    QSqlQuery q;

    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    q.prepare("UPDATE PERSONNEL set POSTE=:POSTE,DEPARTEMENT=:DEPARTEMENT where CIN='"+cin+"'") ;


    q.bindValue(":POSTE",ui->poste->text());
    q.bindValue(":DEPARTEMENT",ui->departement->currentText());


    return q.exec();

}

void PERSONNEL::pdf(Ui::AFFICHAGE_PERSONNEL *ui)
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString CIN = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
    QString nom = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString();
    QString prenom = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString();
    QString poste = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString();
    QString date= ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString();
    QString departement = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString();
    doc.setHtml("<br> <h1>Information du personnel " " " +nom+ " " +prenom+ " <br> <br> </h1>\n <h4 >Cin:" " " +CIN +" </h4> \n <h4> Nom et Prenom : " " "+ nom+ " " + prenom +" </h4> \n <h4>Date de naissance : " " "+date+" </h4> \n <h4>Poste:" " "+poste+" " "ans </h4> \n <h4> departement :" " "+departement+" </h4> ");
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}


