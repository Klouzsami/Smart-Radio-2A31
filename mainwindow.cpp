#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "invite.h"
#include<QMessageBox>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(100, 99999999, this));
    ui->tab_invite->setModel(i.afficher());
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
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("adam.chebaane@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("adam.chebaane@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("adam.chebaane@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

