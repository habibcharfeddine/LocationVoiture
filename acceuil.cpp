#include "acceuil.h"
#include "ui_acceuil.h"
#include "GUI_LocationPointsF.h"
#include "GUI_AssuranceSociete.h"
#include "GUI_VoitureParking.h"
#include "GUI_EventPromo.h"
#include "GUI_ClientAvis.h"
#include "GUI_PersonnelDepart.h"
#include "mainwindow.h"
#include <QStyleFactory>


acceuil::acceuil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::acceuil)
{
    ui->setupUi(this);
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPixmap pix("C:/Users/QT/Desktop/LocationVoiture/icons/template.jpg");
    int w =ui->pic->width();
    int h =ui->pic->height();
     ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

acceuil::~acceuil()
{
    delete ui;
}

void acceuil::on_habib_clicked()
{
    GUI_AssuranceSociete *w = new GUI_AssuranceSociete;
   hide();
   w->show();
}
void acceuil::on_mahdi_clicked()
{
    GUI_LocationPointsF *w = new GUI_LocationPointsF;
   hide();
   w->show();
}
void acceuil::on_sourour_clicked()
{
    GUI_VoitureParking *w = new GUI_VoitureParking;
   hide();
   w->show();
}

void acceuil::on_obaid_clicked()
{
    GUI_EventPromo *w = new GUI_EventPromo;
   hide();
   w->show();
}
void acceuil::on_marwa_clicked()
{
    GUI_ClientAvis *w = new GUI_ClientAvis;
   hide();
   w->show();
}
void acceuil::on_ahmed_clicked()
{
    GUI_PersonnelDepart *w = new GUI_PersonnelDepart;
   hide();
   w->show();
}



void acceuil::on_logout_clicked()
{
    MainWindow *w = new MainWindow;
   hide();
   w->show();
}
