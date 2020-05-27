
#include <QDebug>
#include<QVariant>
#include "CLIENT.h"
#include <QString>
#include <QDate>
//#include "statistique.h"


CLIENT::CLIENT()
{

}

CLIENT::CLIENT(int CIN, QString NOM , QString PRENOM, QString EMAIL, QDate DATENAISSANCE, QString ADRESS,QString IMAGE,int AGE)
{
  this->CIN=CIN;
  this->NOM=NOM;
  this->PRENOM=PRENOM;
  this->ADRESS=ADRESS;
  this->DATENAISSANCE=DATENAISSANCE;
  this->EMAIL=EMAIL;
  this->IMAGE=IMAGE;
  this->AGE=AGE;

}
QString CLIENT::get_NOM(){return  NOM;}
QString CLIENT::get_PRENOM(){return PRENOM;}
QString CLIENT::get_ADRESS(){return ADRESS;}
QDate CLIENT::get_DATENAISSANCE(){return DATENAISSANCE;}
QString CLIENT::get_EMAIL(){return EMAIL;}
int CLIENT::get_CIN(){return  CIN;}
QString CLIENT::get_IMAGE(){return IMAGE;}
int CLIENT::get_AGE(){return  AGE;}

bool CLIENT::ajouter()
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("INSERT INTO CLIENT (CIN, NOM, PRENOM,EMAIL,DATENAISSANCE,ADRESS ,IMAGE ,AGE) "
                    "VALUES (:CIN, :NOM, :PRENOM,:EMAIL, :DATENAISSANCE ,:ADRESS,:IMAGE ,:AGE)");
query.bindValue(":CIN", res);
query.bindValue(":NOM", NOM);
query.bindValue(":PRENOM", PRENOM);
query.bindValue(":EMAIL", EMAIL);
query.bindValue(":DATENAISSANCE", DATENAISSANCE);
query.bindValue(":ADRESS", ADRESS);
query.bindValue(":IMAGE", IMAGE);
query.bindValue(":AGE", AGE);




return    query.exec();
}

bool CLIENT::modifier()
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("update CLIENT set NOM = :NOM , PRENOM = :PRENOM , EMAIL = :EMAIL, DATENAISSANCE = :DATENAISSANCE ,ADRESS =:ADRESS ,IMAGE =:IMAGE ,AGE =:AGE where CIN = :CIN  ");
query.bindValue(":CIN", res);
query.bindValue(":NOM", NOM);
query.bindValue(":PRENOM", PRENOM);
query.bindValue(":EMAIL", EMAIL);
query.bindValue(":DATENAISSANCE", DATENAISSANCE);
query.bindValue(":ADRESS", ADRESS);
query.bindValue(":IMAGE", IMAGE);
query.bindValue(":AGE", AGE);


return    query.exec();
}


bool CLIENT::supprimer(int CINN)
{
QSqlQuery query;
QString res= QString::number(CINN);
query.prepare("Delete from CLIENT where CIN = :CIN ");
query.bindValue(":CIN", res);
return    query.exec();
}

QSqlQueryModel * CLIENT::rechercher(QString q)
{
    QSqlQueryModel *model= new QSqlQueryModel();


   model->setQuery("select * from CLIENT where CIN like '"+q+"' or NOM like '"+q+"' OR PRENOM like '"+q+"' or AGE like '"+q+"'  ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESS"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("IMAGE"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));

    return (model);
}


QSqlQueryModel * CLIENT::afficher_Clist()

{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESS"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("IMAGE"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("AGE"));

    return model;
}
bool CLIENT::verif_EMAIL(QString ch){
   bool test=false;
   int i;
   for(i=0;i<ch.length();i++)
   {
       if(ch[i]=='@'){
           test=true;
       }
   }
   return  test;
}

bool CLIENT::verif_CIN(int ch_CIN){
   bool test=true;
   int i;
   QString s = QString::number(ch_CIN);
   if(s.length()!=8){
      test=false;
      return  test;
   }else{
       for(i=0;i<s.length();i++){
           if(!((s[i]>='0')&&(s[i]<='9'))){
               test=false;
               return  test;
       }
       }
   }
return test;}
bool CLIENT::verif_NOM(QString NOM){
    bool test=true;
    int i;
    if(NOM.length()>20){
       test=false;
       return  test;
    }else{
        for(i=0;i<NOM.length();i++){
            if(!(((NOM[i]>='A')&&(NOM[i]<='Z'))||((NOM[i]>='a')&&(NOM[i]<='z')))){
                test=false;
                return  test;
        }
    }
  }
    return  test;
}


QSqlQueryModel *  CLIENT::afficher_nomaz()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from CLIENT ORDER BY NOM ");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESS"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("AGE"));
       return model;
}
QSqlQueryModel *  CLIENT::afficher_nomza()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENT ORDER BY NOM desc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESS"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("AGA"));
return model;

}
QSqlQueryModel *  CLIENT::afficher_MAILA()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENT ORDER BY EMAIL desc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESS"));
return model;
}

QSqlQueryModel *  CLIENT::afficher_CINA()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENT ORDER BY EMAIL");//hethom lezem yetbadlou

model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESS"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE"));
return model;
}

QSqlQueryModel *  CLIENT::afficher_CIND()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENT ORDER BY CIN desc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESS"));
return model;
}
