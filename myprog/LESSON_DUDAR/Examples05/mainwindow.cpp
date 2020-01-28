#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/img01.jpg");
    int w = ui->lb_image->width();
    int h = ui->lb_image->height();
    ui->lb_image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->pass->text();
    if(login=="Codi" && password=="test")
    {
        //QMessageBox::information(this, "Ура", "Вы успешно авторизовались!");
        ui->statusBar->showMessage("Вы успешно авторизовались!");
    }
    else
    {
        //QMessageBox::warning(this, "Авторизация", "Неправильная учётная пара!");
        ui->statusBar->showMessage("Неправильная учётная пара!");
    }
}
