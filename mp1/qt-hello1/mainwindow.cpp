#include <unistd.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>

#define MAJOR_NUM 202
#define IOCTL_LCD_CLEAR _IOWR(MAJOR_NUM, 0, int)
#define IOCTL_LCD_SET_POS _IOWR(MAJOR_NUM, 1, int)
#define IOCTL_GET_NTH_BYTE _IOWR(MAJOR_NUM, 2, int)

int closeFile(int filed)
{
    int err;
    err = close(filed);
    return err;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowFlags( Qt::Window | Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint); //убираем все кнопки
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    ui->pushButtonClose->setEnabled(false);
    ui->pushButtonTest->setEnabled(false);
    ui->pushButtonInit->setEnabled(false);
    ui->pushButtonString->setEnabled(false);
    ui->pushButtonClear->setEnabled(false);
    ui->pushButtonPos->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonInit_clicked()
{
    char c;
    char str1[30];
    cnt01 = 0;
    isStarted = false;
    c = ioctl(fd, IOCTL_GET_NTH_BYTE, 0);
    sprintf(str1, "mygpio char: %d", (int) c);
    ui->label->setText(str1);
    //Clear Display
    ioctl(fd, IOCTL_LCD_CLEAR, 0);
    ui->pushButtonTest->setEnabled(true);
    ui->pushButtonString->setEnabled(true);
    ui->pushButtonClear->setEnabled(true);
    ui->pushButtonPos->setEnabled(true);
    ui->pushButtonInit->setEnabled(false);
}

void MainWindow::on_pushButtonClose_clicked()
{
    int err;
    err = closeFile(fd);
    if (err < 0)
    {
       ui->label->setText("Cannot close file");
    }
    else
    {
        ui->label->setText("mygpio close");
        ui->pushButtonExit->setEnabled(true);
        ui->pushButtonOpen->setEnabled(true);
        ui->pushButtonString->setEnabled(false);
        ui->pushButtonInit->setEnabled(false);
        ui->pushButtonClear->setEnabled(false);
        ui->pushButtonTest->setEnabled(false);
        ui->pushButtonPos->setEnabled(false);
    }
}

void MainWindow::on_pushButtonOpen_clicked()
{
    fd = open("/dev/mygpio", O_RDWR);
    if (fd < 0)
    {
       ui->label->setText("Cannot open file");
    }
    else
    {
        ui->label->setText("mygpio open");
        ui->pushButtonExit->setEnabled(false);
        ui->pushButtonOpen->setEnabled(false);
        ui->pushButtonClose->setEnabled(true);
        ui->pushButtonInit->setEnabled(true);
    }
}

void MainWindow::on_pushButtonString_clicked()
{
    char str1[30];
    //ui->label->setText(ui->lineEdit->text());
    sprintf(str1, ui->lineEdit->text().toStdString().c_str());
    ui->label->setText(str1);
    write(fd,str1,strlen(str1)+1);
}

void MainWindow::on_pushButtonClear_clicked()
{
    char c;
    char str1[30];
    c = ioctl(fd, IOCTL_LCD_CLEAR, 0);
    sprintf(str1, "mygpio char: %d", (int) c);
    ui->label->setText(str1);
}

void MainWindow::on_pushButtonPos_clicked()
{
    char c;
    char str1[30];
    c = ioctl(fd, IOCTL_LCD_SET_POS, ui->spinBox1->value() | ui->spinBox2->value() << 8);
    sprintf(str1, "mygpio char: %d; x=%d; y=%d", (int) c, ui->spinBox1->value(), ui->spinBox2->value());
    ui->label->setText(str1);
}

void MainWindow::slotTimerAlarm()
{
    //ui->label->setText(QTime::currentTime().toString("hh:mm:ss"));
    char str1[30];
    cnt01++;
    if(cnt01>=200000) cnt01=0;
    if(cnt01%2)
    {
        ioctl(fd, IOCTL_LCD_SET_POS, 4 | 3 << 8);
        strcpy(str1,QTime::currentTime().toString("hh:mm:ss").toLocal8Bit().data());
        write(fd,str1,9);
    }
    else
    {
        ioctl(fd, IOCTL_LCD_SET_POS, 6 | 2 << 8);
        //usleep(5000);
        sprintf(str1,"%5d", cnt01/2);
        write(fd,str1,6);
    }
}

void MainWindow::on_pushButtonExit_clicked()
{
    QApplication::quit();
}

void MainWindow::closeEvent(QCloseEvent *event){
    event->ignore();
}

void MainWindow::on_pushButtonTest_clicked()
{
    if(isStarted == false)
    {
        //Clear Display
        ioctl(fd, IOCTL_LCD_CLEAR, 0);
        ui->pushButtonTest->setText("Test stop");
        isStarted = true;
        ui->pushButtonString->setEnabled(false);
        ui->pushButtonClear->setEnabled(false);
        ui->pushButtonPos->setEnabled(false);
        ui->pushButtonClose->setEnabled(false);
        timer->start(100);
    }
    else
    {
        ui->pushButtonTest->setText("Test start");
        isStarted = false;
        timer->stop();
        cnt01 = 0;
        //Clear Display
        ioctl(fd, IOCTL_LCD_CLEAR, 0);
        ui->pushButtonString->setEnabled(true);
        ui->pushButtonClear->setEnabled(true);
        ui->pushButtonPos->setEnabled(true);
        ui->pushButtonClose->setEnabled(true);
    }
}
