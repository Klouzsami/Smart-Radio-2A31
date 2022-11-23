#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"sponsor.h"
#include <QMainWindow>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pb_ajouter_clicked();


    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_chercher_sponsor_clicked();

    void on_pb_trier_sponsor_clicked();

    void on_tab_sponsor_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    Sponsor S;
};
#endif // MAINWINDOW_H
