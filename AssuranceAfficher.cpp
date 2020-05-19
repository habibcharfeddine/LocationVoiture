#include "AssuranceAfficher.h"
#include "ui_AssuranceAfficher.h"
#include "Assurance.h"
#include "AssuranceGestion.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
AFFICHAGE_ASSURANCE::AFFICHAGE_ASSURANCE(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AFFICHAGE_ASSURANCE)
{
    ui->setupUi(this);
    assurance j ;
    j.affichage(ui);

}

AFFICHAGE_ASSURANCE::~AFFICHAGE_ASSURANCE()
{
    delete ui;
}

void AFFICHAGE_ASSURANCE::on_Annuler_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AFFICHAGE_ASSURANCE::on_supprimer_clicked()
{
    assurance j;
    j.Supprimer(ui);
    j.affichage(ui);
}

void AFFICHAGE_ASSURANCE::on_annuler_clicked()
{
    Gestion_Assurance *w = new Gestion_Assurance;
    hide();
    w->show();
}

void AFFICHAGE_ASSURANCE::on_search_clicked()
{
    assurance j;
    j.Recherche(ui);
}

void AFFICHAGE_ASSURANCE::on_comboBox_currentIndexChanged(int index)
{
    assurance j;
    if (index==0)
    { j.Tri_ID(ui);

    }

    else
    {  j.Tri_Societe(ui);

    }
}

void AFFICHAGE_ASSURANCE::on_Valider_clicked()
{
    QRegExp regex1 ("[a-z]$");
    QRegExp regex2 ("^[a-z]");
    QString msg_type ="  invalide";
    QString msg_etat ="etat invalide";
    QString msg_vide="";
    QString type= ui->type->text();
    QString etat= ui->etat->text();
    QString societe= ui->societe->currentText();

    assurance e;

    if ((!type.contains(regex1))||(!type.contains(regex2)))
    {
        ui->type->setStyleSheet("QLineEdit { color: red;}");
        ui->text_type->setText(msg_type);
        ui->text_type->setStyleSheet("QLabel { background-color : transparent; color : red; }");
        e.setValide();
    }
    else { ui->type->setStyleSheet("QLineEdit { color: black;}");
        ui->text_type->setText(msg_vide);

    }

    if ((!etat.contains(regex1))||(!etat.contains(regex2)))
    {
        ui->etat->setStyleSheet("QLineEdit { color: red;}");
        e.setValide();
        ui->text_etat->setText(msg_etat);
        ui->text_etat->setStyleSheet("QLabel { background-color : transparent; color : red; }");
    }
    else { ui->etat->setStyleSheet("QLineEdit { color: black;}");
        ui->text_etat->setText(msg_vide);
    }


    if (e.getValide()==0)
    {
        if (e.modifier(ui))
        {
            ui->type->setStyleSheet("QLineEdit { color: green;}");
            ui->etat->setStyleSheet("QLineEdit { color: green;}");
            {QMessageBox ::information(this,""," Assurance modifier  ") ;}
            e.affichage(ui);
        }
        else {
            {QMessageBox ::critical(this,"","erreur de modification") ;

            }
        }
    }

    else
    {QMessageBox ::information(this,"","erreur de modification") ;}


}

void AFFICHAGE_ASSURANCE::on_tableView_doubleClicked(const QModelIndex &index)
{
    assurance j;
    j.list_societes(ui);
    ui->societe->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->etat->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->type->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());
    ui->ID->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->cintex->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->ID->setEnabled(false);

    ui->stackedWidget->setCurrentIndex(1);
}

void AFFICHAGE_ASSURANCE::on_PDF_clicked()
{
    assurance j;
    j.pdf(ui);
}
void AFFICHAGE_ASSURANCE::on_imprimer_clicked()
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
