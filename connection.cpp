#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("testbase");
db.setUserName("adam");
db.setPassword("adam");

if (db.open())
test=true;
    return  test;
}
