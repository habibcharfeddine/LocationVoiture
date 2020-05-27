#include "AVIS_CLIENT.h"
#include <QString>
#include <QDate>

AVIS_CLIENT::AVIS_CLIENT()
{

}
AVIS_CLIENT::AVIS_CLIENT(int ID_AVIS,QString AVISCLIENT,QDate DateAVIS,QString CIN)
{
  this->ID_AVIS=ID_AVIS;
  this->AVISCLIENT=AVISCLIENT;
  this->DATEAVIS=DateAVIS;
  this->CIN = CIN;
}
QString AVIS_CLIENT::get_AVISCLIENT(){return  AVISCLIENT;}
QDate AVIS_CLIENT::get_DATEATES(){return DATEAVIS;}
int AVIS_CLIENT::get_ID_AVIS(){return  ID_AVIS;}
QString AVIS_CLIENT::get_CIN(){return  CIN;}

bool AVIS_CLIENT::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID_AVIS);

query.prepare("INSERT INTO AVIS_CLIENT (Id_AVIS, AVISCLIENT, DATEAVIS, CIN) "
                   "VALUES (:Id_AVIS, :AVIS_client, :DateAVIS, :CIN )");


query.bindValue(":Id_AVIS", ID_AVIS);
query.bindValue(":AVIS_client", AVISCLIENT);
query.bindValue(":DateAVIS", DATEAVIS);
query.bindValue(":CIN", CIN);

return    query.exec();
}
bool AVIS_CLIENT::modifier(AVIS_CLIENT A)
{
QSqlQuery query;
QString res= QString::number(ID_AVIS);
query.prepare("update AVIS_CLIENT set Id_AVIS = :Id_AVIS , AVISCLIENT = :AVIS_client , DATEAVIS = :DateAVIS , CIN = :CIN where Id_AVIS = :Id_AVIS");
query.bindValue(":Id_AVIS",A.get_ID_AVIS());
query.bindValue(":AVIS_client",A.get_AVISCLIENT());
query.bindValue(":DateAVIS",A.get_DATEATES());
query.bindValue(":CIN",A.get_CIN());

return    query.exec();
}


QSqlQueryModel * AVIS_CLIENT::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from AVIS_CLIENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_AVIS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("AVIS_client "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_Avis"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}

bool AVIS_CLIENT::supprimer(int Id_AVISd)
{
QSqlQuery query;
QString res= QString::number(Id_AVISd);
query.prepare("Delete from AVIS_CLIENT where Id_AVIS = :Id_AVIS ");
query.bindValue(":Id_AVIS", res);
return    query.exec();
}

QSqlQueryModel *AVIS_CLIENT::rechercher_avis (QString q)
{
    QSqlQueryModel *model= new QSqlQueryModel();


   model->setQuery("select * from AVIS_CLIENT where Id_AVIS like '"+q+"' or AVISCLIENT like '"+q+"'  ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_AVIS"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("AVIS_client "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_Avis"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));

    return (model);
}



bool AVIS_CLIENT::verif_EMAIL(QString ch){
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



bool AVIS_CLIENT::verif_CIN(int ch_CIN){
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
bool AVIS_CLIENT::verif_NOM(QString NOM){
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


QSqlQuery  AVIS_CLIENT::tableclicked(QString a)
{

    QSqlQuery qry ;

  qry.prepare("Select * from AVIS_CLIENT where Id_AVIS='"+a+"' ");
    return qry;
}
// TRI AVIS CLIENT croissant
QSqlQueryModel *  AVIS_CLIENT::afficher_idaz()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from AVIS_CLIENT ORDER BY ID_AVIS ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AVIS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("AVISCLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date DATEAVIS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
return model;
}


QSqlQueryModel *  AVIS_CLIENT::afficher_idza()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from AVIS_CLIENT ORDER BY ID_AVIS  desc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_AVIS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("AVISCLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date DATEAVIS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
return model;
}
