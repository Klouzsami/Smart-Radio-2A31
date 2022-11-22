#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "invite.h"
#include<QMessageBox>
#include<QIntValidator>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(100, 99999999, this));
    ui->tab_invite->setModel(i.afficher());

    /*//maps
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->quickWidget->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");

   */
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();

    invite i (id,nom,prenom);
    bool test=i.ajouter();
    if(test)
    {QMessageBox::information(nullptr,QObject::tr("ok"),
                              QObject::tr("Ajout effectué \n"
                                          "Click cancel to exit ."),QMessageBox::Cancel);
        ui->tab_invite->setModel(i.afficher());
    }
    else QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("ajout non effectué.\n"
                                           "Clic cancel to exit"),QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
    invite i1; i1.setid(ui->le_id_sup->text().toInt());
    bool test=i1.supprimer(i1.gedit());
    QMessageBox msgbox;

    if (test)
    {msgbox.setText("suppression avec succes.");
        ui->tab_invite->setModel(i.afficher());
       }
    else
        msgbox.setText("suppresion echoué.");
    msgbox.exec();



}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->le_id_4->text().toInt();
        QString nom=ui->le_nom_4->text();
        QString prenom=ui->le_prenom_4->text();

        invite i(id,nom,prenom);
        bool test=i.modifier(id);
        ui->tab_invite->setModel(i.afficher());

     if(test){

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);

     }else{
         QMessageBox::information(nullptr,QObject::tr("Not oK"),
                                  QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
}
}

void MainWindow::on_Recherche_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    if(id==0)
    {
        QMessageBox::information(nullptr,QObject::tr("Champ vide"),QObject::tr("Veuiller insérer une id!"),QMessageBox::Cancel);
        ui->table_recherche->setModel(i.afficher());
    }
    else
    {
        ui->table_recherche->setModel(i.recherche(id));
    }
}


void MainWindow::on_Tri_clicked()
{
    ui->table_tri->setModel(i.trier());
}


void MainWindow::on_envoyer_mail_invite_clicked()
{

    QItemSelectionModel *select = ui->tableView->selectionModel();

    QString email_recipient = select->selectedRows(5).value(0).data().toString();
    QString nom_recipient = select->selectedRows(1).value(0).data().toString();
    QString prenom_recipient = select->selectedRows(2).value(0).data().toString();

    QDialog *d=new Dialog(email_recipient,nom_recipient,prenom_recipient,this);
    d->show();
    d->exec();
}


