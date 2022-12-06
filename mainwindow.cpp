 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "invite.h"
#include<QMessageBox>
#include<QIntValidator>
#include "dialog.h"
#include "smtp.h"
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix1("C:/azaz.jpg");
   ui->label_5->setPixmap(pix1);
    ui->le_id->setValidator( new QIntValidator(100, 99999999, this));
    ui->tab_invite->setModel(i.afficher());
    /*Smtp* smtp = new Smtp("adam.chebaane@esprit.tn", "211JMT6588", "smtp.gmail.com", 465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
       smtp->sendMail("adam.chebaane@esprit.tn","ahmed.harrabi@esprit.tn","object","saluut");
*/
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
   /*
    gestion_invite gi;
    gi.exec();
    */
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();

    invite i (id,nom,prenom);
    bool test=i.ajouter();
    if(test)
    { QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
        notifier ->setIcon(QIcon(""));
        notifier->show();
        notifier->showMessage(" AJOUT effectué " ,"\n",QSystemTrayIcon::Information,10000);
        ui->tab_invite->setModel(i.afficher());
    }
    else{
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                notifier ->setIcon(QIcon(""));
                notifier->show();
                notifier->showMessage(" AJOUT non effectué " ,"\n",QSystemTrayIcon::Information,10000);
    }


}

void MainWindow::on_pb_supprimer_clicked()
{
    invite i1; i1.setid(ui->le_id_sup->text().toInt());
    bool test=i1.supprimer(i1.gedit());
    QMessageBox msgbox;

    if (test)
    {QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
        notifier ->setIcon(QIcon(""));
        notifier->show();
        notifier->showMessage(" SUPPRESSION effectué " ,"\n",QSystemTrayIcon::Information,10000);
        ui->tab_invite->setModel(i.afficher());
       }
    else
       {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                notifier ->setIcon(QIcon(""));
                notifier->show();
                notifier->showMessage(" SUPPRESSION non effectué " ,"\n",QSystemTrayIcon::Information,10000);
    }



}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
        QString nom=ui->lineEdit_2->text();
        QString prenom=ui->lineEdit_3->text();

        invite i(id,nom,prenom);
        bool test=i.modifier(id);
        ui->tab_invite->setModel(i.afficher());

     if(test){

         QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                 notifier ->setIcon(QIcon(""));
                 notifier->show();
                 notifier->showMessage(" MODIFICATION effectué " ,"\n",QSystemTrayIcon::Information,10000);
     }else{
         QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                 notifier ->setIcon(QIcon(""));
                 notifier->show();
                 notifier->showMessage(" MODIFICATION non effectué " ,"\n",QSystemTrayIcon::Information,10000);}
}

void MainWindow::on_Recherche_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    if(id==0)
    {
        QMessageBox::information(nullptr,QObject::tr("Champ vide"),QObject::tr("Veuiller insérer une id!"),QMessageBox::Cancel);
        ui->tab_invite->setModel(i.afficher());
    }
    else
    {
        ui->tab_invite->setModel(i.recherche(id));
    }
}


void MainWindow::on_Tri_clicked()
{
 //   ui->table_tri->setModel(i.trier());
}


void MainWindow::on_envoyer_mail_invite_clicked()
{

   /* QItemSelectionModel *select = ui->tableView->selectionModel();

    QString email_recipient = select->selectedRows(5).value(0).data().toString();
    QString nom_recipient = select->selectedRows(1).value(0).data().toString();
    QString prenom_recipient = select->selectedRows(2).value(0).data().toString();

    QDialog *d=new Dialog(email_recipient,nom_recipient,prenom_recipient,this);
    d->show();
    d->exec();*/
}



void MainWindow::on_pushButton_2_clicked()
{
     ui->tab_invite->setModel(i.trier());
}

void MainWindow::on_pushButton_3_clicked()
{
    QString strStream;
                   QTextStream out(&strStream);

                    const int rowCount = ui->tab_invite->model()->rowCount();
                    const int columnCount = ui->tab_invite->model()->columnCount();
                   out <<  "<html>\n"
                   "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("strTitle")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"

                                   //     "<align='right'> " << datefich << "</align>"
                                    "<center> <H1>Liste des invités</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                // headers
                                out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                out<<"<cellspacing=10 cellpadding=3>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tab_invite->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tab_invite->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";

                                // data table
                                for (int row = 0; row < rowCount; row++) {
                                    out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                    for (int column = 0; column < columnCount; column++) {
                                        if (!ui->tab_invite->isColumnHidden(column)) {
                                            QString data = ui->tab_invite->model()->data(ui->tab_invite->model()->index(row, column)).toString().simplified();
                                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                        }
                                    }
                                    out << "</tr>\n";
                                }
                                out <<  "</table> </center>\n"
                                    "</body>\n"
                                    "</html>\n";

                          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                           QPrinter printer (QPrinter::PrinterResolution);
                            printer.setOutputFormat(QPrinter::PdfFormat);
                           printer.setPaperSize(QPrinter::A4);
                          printer.setOutputFileName(fileName);

                           QTextDocument doc;
                            doc.setHtml(strStream);
                            doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                            doc.print(&printer);
}
