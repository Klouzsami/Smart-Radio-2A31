#include "invite.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>

invite::invite()
{
id=0;nom=" ";prenom=" ";

}

invite::invite(int id,QString nom ,QString prenom)
{this->id=id;this ->nom=nom; this->prenom=prenom;}
int invite::gedit(){return id;}
QString invite::getnom(){return nom ;}
QString invite::getprenom(){return prenom;}
void invite::setid(int id){this ->id=id;}
void invite::setnom(QString nom){this->nom=nom;}
void invite::setprenom(QString prenom){this->prenom=prenom;}
bool invite::ajouter()
{bool test=false;

    QString id_string= QString::number(id);
    QSqlQuery query;
         query.prepare("INSERT INTO INVITE (ID,NOM,PRENOM) "
                       "VALUES (:id, :nom, :prenom)");
         query.bindValue(":id", id_string );
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         return query.exec();


         return test;
}

bool invite::supprimer(int id)
{
    QSqlQuery query;
         query.prepare("Delete from INVITE where id=:id");
         query.bindValue(":id",id);

         return query.exec();

}
bool invite::modifier(int id)
{
    QSqlQuery query;


             query.prepare("UPDATE INVITE SET nom=:nom, prenom=:prenom where ID=:id");


                   query.bindValue(":id", id);
                   query.bindValue(":nom", nom);
                   query.bindValue(":prenom", prenom);

               return query.exec();
}





QSqlQueryModel* invite::afficher()
{

   QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM INVITE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));



   return model ;

}

QSqlQueryModel *invite::recherche(int id)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     QString res = QString::number(id);

     model->setQuery("select * from invite where id like '" +res+ "%'");

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));


 return model;
 }

QSqlQueryModel *invite::trier() //de A à Z
 {
     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * FROM invite order by nom ASC");
            q->exec();
            model->setQuery(*q);
            return model;
 }
