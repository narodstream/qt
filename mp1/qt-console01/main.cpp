#include <QCoreApplication>
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
    for(int i=0;i<10;i++)
    {
        qDebug() << i;
        //std::cout << i << std::endl;
    }
    */
    return a.exec();
}
