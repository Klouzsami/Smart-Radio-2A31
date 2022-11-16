#include "dialog.h"
#include "ui_dialog.h"
#include "smtp.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::Dialog(QString e,QString n,QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QString contenu="Contenu";
    ui->setupUi(this);


    ui->uname->setText("adam.chebaane@esprit.tn");
    ui->passwd->setText("211JMT6588");
    ui->passwd->setEchoMode(QLineEdit::Password);
    ui->recipient->setText(e);
    ui->recipient_n->setText(n);
    ui->recipient_s->setText(s);

    ui->message->setText("Cher invité "+s+" "+n+",\n\n"+contenu+"\n\n"+"Cordialement,\n");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_envoyer_dialog_clicked()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->passwd->text(), "smtp.gmail.com", 465);

    smtp->sendMail(ui->uname->text(), ui->recipient->text() , ui->subjectLineEdit->text() ,ui->message->toPlainText());

    /*if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );*/

}

