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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    char c;
    char str1[30];
    c = ioctl(fd, IOCTL_GET_NTH_BYTE, 0);
    sprintf(str1, "mygpio char: %d", (int) c);
    ui->label->setText(str1);
}

void MainWindow::on_pushButton_3_clicked()
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
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    fd = open("/dev/mygpio", O_RDWR);
    if (fd < 0)
    {
       ui->label->setText("Cannot open file");
    }
    else
    {
        ui->label->setText("mygpio open");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    char str1[30];
    //ui->label->setText(ui->lineEdit->text());
    sprintf(str1, ui->lineEdit->text().toStdString().c_str());
    ui->label->setText(str1);
    write(fd,str1,strlen(str1));
}

void MainWindow::on_pushButton_5_clicked()
{
    char c;
    char str1[30];
    c = ioctl(fd, IOCTL_LCD_CLEAR, 0);
    sprintf(str1, "mygpio char: %d", (int) c);
    ui->label->setText(str1);
}

void MainWindow::on_pushButton_6_clicked()
{
    char c;
    char str1[30];
    c = ioctl(fd, IOCTL_LCD_SET_POS, ui->spinBox1->value() | ui->spinBox2->value() << 8);
    sprintf(str1, "mygpio char: %d", (int) c);
    ui->label->setText(str1);
}
