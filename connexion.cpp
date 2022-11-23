#include "connexion.h"

Connexion::Connexion(){}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("0708");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
return  test;
}

void Connexion::closeconnexion()
{
    db.close();
}
