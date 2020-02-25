#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int fd, cnt01;
    bool isStarted;
    ~MainWindow();

protected:
    virtual void closeEvent( QCloseEvent *event);

private slots:
    void on_pushButtonInit_clicked();

    void on_pushButtonClose_clicked();

    void on_pushButtonOpen_clicked();

    void on_pushButtonString_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonPos_clicked();

    void slotTimerAlarm();

    void on_pushButtonExit_clicked();

    void on_pushButtonTest_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
};

#endif // MAINWINDOW_H
