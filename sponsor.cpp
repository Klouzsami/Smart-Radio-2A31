#include "sponsor.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QObject>

Sponsor::Sponsor() //initialisation du constructeur par defaut
{   id=0;
    rib=0;
    tel=0;
    nom="";
    mail="";
    duree_contrat="";
    debut_contrat="";
    fin_contrat="";
}

Sponsor::Sponsor(int id, int rib,int tel,QString nom,QString mail, QString duree_contrat, QString debut_contrat, QString fin_contrat)
{   this->id=id;
    this->rib=rib;
    this->tel=tel;
    this->nom=nom;
    this->mail=mail;
    this->duree_contrat=duree_contrat;
    this->debut_contrat=debut_contrat;
    this->fin_contrat=fin_contrat;
}

bool Sponsor::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO sponsor (id,rib,tel, nom, mail, duree_contrat,debut_contrat,fin_contrat) "
    "VALUES (:id,:rib,:tel, :nom, :mail, :duree_contrat,:debut_contrat,:fin_contrat)");
    query.bindValue(":id", id);
    query.bindValue(":rib", rib);
    query.bindValue(":tel", tel);
    query.bindValue(":nom", nom);
    query.bindValue(":mail", mail);
    query.bindValue(":duree du contrat", duree_contrat);
    query.bindValue(":debut du contrat", debut_contrat);
    query.bindValue(":fin du contrat", fin_contrat);
    return query.exec();

}

bool Sponsor::modifier()

{
QSqlQuery query;
QString up=QString(id);
query.prepare("update Sponsor set rib=:rib,tel=:tel,nom=:nom,mail=:mail,duree_contrat=:duree_contrat,debut_contrat=:debut_contrat,fin_contrat=:fin_contrat where id=:id");
query.bindValue(":id",up);
query.bindValue(":rib",rib);
query.bindValue(":tel",tel);
query.bindValue(":nom",nom);
query.bindValue(":mail",mail);
query.bindValue(":duree_contrat",duree_contrat);
query.bindValue(":debut_contrat",debut_contrat);
query.bindValue(":fin_contrat",fin_contrat);
return query.exec();}

bool Sponsor::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from SPONSOR where id=:id");
    query.bindValue("id",id );
    return query.exec();

}

QSqlQueryModel * Sponsor::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from sponsor");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("rib"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("tel"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree_contrat"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("debut_contrat"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("fin_contrat"));
    return model;
}

QSqlQueryModel *Sponsor::chercher( int id )
{
    QSqlQuery query ;
    QSqlQueryModel* model=new QSqlQueryModel();
    query.prepare("select * from Sponsor where id=:id");
    query.bindValue(":id", id);
    query.exec();
    model->setQuery(query);
return model;
}

QSqlQueryModel *Sponsor::trier()
{

                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      model ->setQuery("SELECT * from Sponsor order by nom ID");
                      return model;
    }
