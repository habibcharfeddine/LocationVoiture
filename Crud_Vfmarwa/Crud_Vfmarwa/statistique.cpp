#include "statistique.h"
#include "ui_statistique.h"

Statistique::Statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique)
{
    ui->setupUi(this);
}

Statistique::~Statistique()
{
    delete ui;
}
int Statistique::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from CLIENT where AGE BETWEEN '10' AND '30'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Statistique::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from CLIENT where AGE BETWEEN '31' AND '40'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Statistique::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from CLIENT where AGE BETWEEN '41' AND '50'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void Statistique::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    //cout<<b<<endl ;
    int c=Statistique_partie3();
   // cout<<c<<endl ;
    int d=Statistique_partie4();
    //cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::gray);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("age entre : 10-30") ;
    painter.setBrush(Qt::magenta);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("age entre : 31-40") ;
    painter.setBrush(Qt::cyan);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("age entre : 41-50") ;

}
