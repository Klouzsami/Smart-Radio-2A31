#ifndef SPONSOR_H
#define SPONSOR_H
#include <QString>
#include<QSqlQueryModel>





class Sponsor
{
private:
    int id,tel,rib;
    QString nom, mail, duree_contrat,debut_contrat,fin_contrat;

public:
    Sponsor();
    Sponsor(int,int,int,QString,QString,QString,QString,QString);

    int getid(){return id;}
    int gettel(){return tel;}
    int getrib(){return rib ;}
    QString getnom(){return nom;};
    QString getmail(){return mail;}
    QString getdureecontrat(){return duree_contrat;}
    QString getdebutcontrat(){return debut_contrat;}
    QString getfincontrat(){return fin_contrat;}

    void setid(int);
    void settel(int);
    void setrib(int);
    void setnom(QString);
    void setmail(QString);
    void setdureecontrat(QString);
    void setdebutcontrat(QString);
    void setfincontrat(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();

    QSqlQueryModel * chercher(int id);
    QSqlQueryModel *trier();
};

#endif // SPONSOR_H
