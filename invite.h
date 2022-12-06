#ifndef INVITE_H
#define INVITE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class invite
{
public:
    invite();
    invite(int,QString,QString);
    int gedit();
    QString getnom();
    QString getprenom();
    void setid(int);
    void setnom(QString nom);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* recherche(int);
    QSqlQueryModel* trier();

//**

private:
    int id;
    QString nom,prenom;
};

#endif // INVITE_H
