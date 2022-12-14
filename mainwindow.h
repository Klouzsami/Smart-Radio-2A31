#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"invite.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_envoyer_mail_invite_clicked();

    void on_Recherche_clicked();

    void on_Tri_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    invite i;
};


#endif // MAINWINDOW_H
