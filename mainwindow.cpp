#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sponsor.h"

#include <QSystemTrayIcon>
#include <QtDebug>
#include <QObject>
#include<QtPrintSupport/QPrinter>
#include<QFileDialog>
#include<QTextDocument>
#include<QValidator>
#include<QPdfWriter>
#include<QPainter>
#include <QTextEdit>

/*#include<QPrinter>
#include<QPrintDialog>
#include <src/src/SmtpMime>*/

#include <QtNetwork>
#include <QFile>
#include<QCompleter>
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999,this));
    ui->le_tel->setValidator(new QIntValidator(0,99999999,this));
    /*ui->le_rib->setValidator(new QIntValidator(0,9999999999999999,this));*/ /**************ERREUR***************/
    ui->tableview->setModel(S.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    int rib=ui->le_rib->text().toInt();
    int tel=ui->le_tel->text().toInt();
    QString nom=ui->le_nom->text();
    QString mail=ui->le_mail->text();
    QString duree_contrat=ui->le_duree->text();
    QString debut_contrat=ui->le_debut->text();
    QString fin_contrat=ui->le_fin->text();

    Sponsor S(id,rib,tel,nom,mail,duree_contrat,debut_contrat,fin_contrat);

    bool test=S.ajouter();           /*********************erreur************************/
      if(test)
      {
          QMessageBox::information(nullptr,QObject::tr("database is open"),
                                   QObject::tr("Ajout effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);

      }

      else
          QMessageBox::critical(nullptr,QObject::tr("data base not open"),
                                QObject::tr("Ajout non effectué.\n" "Click Cancel to exit."));


}
/*
void MainWindow::on_pb_supprimer_clicked()
{
    Sponsor S;
    S.setid(ui->le_id_sup->text().toInt());
    bool test= S.supprimer(S.getid());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("SPONSOR DELETED "),
                                              QObject::tr("Suppression effectuée\n"), QMessageBox::Ok);

    ui->tableview->setModel(S.afficher());}

    else
    {QMessageBox::critical(nullptr,QObject::tr("SPONSOR NOT DELETED"),
                              QObject::tr("Suppression non effectuée.\n" "Click Cancel to exit."));}

}
*/
void MainWindow::on_pb_modifier_clicked()
{
        int id=ui->le_id_sup->text().toInt();
        int rib=ui->le_rib->text().toInt();
        int tel=ui->le_tel->text().toInt();
        QString nom=ui->le_nom->text();
        QString mail=ui->le_mail->text();
        QString duree_contrat=ui->le_duree->text();
        QString debut_contrat=ui->le_debut->text();
        QString fin_contrat=ui->le_fin->text();


        Sponsor S (id,rib,tel,nom,mail,duree_contrat,debut_contrat,fin_contrat);
        bool test=S.modifier();
                           if(test )
                           {
                               QMessageBox::information(nullptr, QObject::tr("database is open"),
                                           QObject::tr("modifier successful.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableview->setModel(S.afficher());

                           }
                           else{
                               QMessageBox::information(nullptr, QObject::tr("database is not open"),
                                           QObject::tr("modifier failed.\n"

                                             "Click Cancel to exit."), QMessageBox::Cancel);}

}

void MainWindow::on_pb_chercher_sponsor_clicked()
{
        int id = ui->le_id->text().toInt();
        ui->tableview->setModel(S.chercher(id));

}

void MainWindow::on_pb_trier_sponsor_clicked()
{
            ui->tableview->setModel(S.trier());

}


