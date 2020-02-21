#include <QCoreApplication>
#include <iostream>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <linux/gpio.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define BASE_ADDR  0x50007000

int main(int argc, char *argv[])
{
    char str1[100];
    QTextStream Qcout(stdout);
    struct gpiochip_info chip_info;
    struct gpioline_info line_info;
    struct gpiohandle_request req;
    int ret = 0;
    struct gpiohandle_data dt;
    int fd;
    QCoreApplication a(argc, argv);
    memset(&line_info, 0, sizeof(line_info));
    req.lines = 2;
    req.lineoffsets[0] = 0;
    req.lineoffsets[1] = 1;
    req.default_values[0] = 1;
    req.default_values[1] = 0;
    strcpy(req.consumer_label, "foobar");

    fd = open("/dev/gpiochip5", O_WRONLY);
    if (fd < 0)
    {
       Qcout << QString("Cannot open file");
    }
    else
    {
        ioctl(fd, GPIO_GET_CHIPINFO_IOCTL, &chip_info);
        Qcout << "chip_info:\n";
        Qcout << chip_info.name;
        Qcout << "label: " << chip_info.label << "\n";
        sprintf(str1,"%d",chip_info.lines);
        Qcout << "lines: " << str1 << "\n";
        //PF0 - output
        req.lineoffsets[0] = 0;
        req.lineoffsets[1] = 1;
        req.flags = GPIOHANDLE_REQUEST_OUTPUT;
        req.default_values[0] = 0;
        req.default_values[1] = 0;
        req.lines = 2;
        ret = ioctl(fd, GPIO_GET_LINEHANDLE_IOCTL, &req);
        for(int i=0; i<10; i++)
        {
          dt.values[0] = 0;
          dt.values[1] = 1;
          ret = ioctl(req.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &dt);
          usleep(200000);
          dt.values[0] = 1;
          dt.values[1] = 0;
          ret = ioctl(req.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &dt);
          usleep(200000);
        }
        dt.values[0] = 0;
        ret = ioctl(req.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &dt);
        line_info.line_offset = 0;
        ret = ioctl(fd, GPIO_GET_LINEINFO_IOCTL, &line_info);
        if (ret < 0)
        {
          Qcout << "Cannot get line\n";
        }
        Qcout << "line_info: \n";
        Qcout << "name: " << line_info.name << "\n";
        Qcout << "consumer: " << line_info.consumer << "\n";
        sprintf(str1,"line_offset: 0x%08X\n",line_info.line_offset);
        Qcout << str1;
        sprintf(str1,"flags: 0x%08X\n", line_info.flags);
        Qcout << str1;


        /*
        req.lineoffsets[0] = 14;
        req.flags = GPIOHANDLE_REQUEST_OUTPUT;
        req.default_values[0] = 1;
        req.lines = 1;
        ret = ioctl(fd, GPIO_GET_LINEHANDLE_IOCTL, &req);
        for(int i=0; i<10; i++)
        {
          dt.values[0] = 0;
          ret = ioctl(req.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &dt);
          usleep(100000);
          dt.values[0] = 1;
          ret = ioctl(req.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &dt);
          usleep(100000);
        }
        line_info.line_offset = 14;
        ret = ioctl(fd, GPIO_GET_LINEINFO_IOCTL, &line_info);
        if (ret < 0)
        {
          Qcout << "Cannot get line\n";
        }
        Qcout << "line_info: \n";
        Qcout << "name: " << line_info.name << "\n";
        Qcout << "consumer: " << line_info.consumer << "\n";
        sprintf(str1,"line_offset: 0x%08X\n",line_info.line_offset);
        Qcout << str1;
        sprintf(str1,"flags: 0x%08X\n", line_info.flags);
        Qcout << str1;
        */
        close(fd);
        //--------------------------------------------------------
        int fd_mem = open("/dev/mem", O_WRONLY);
        if (fd_mem < 0)
        {
           Qcout << QString("Cannot open file memory");
           return 0;
        }
        unsigned int *base = ( unsigned int *) mmap(0, getpagesize(), PROT_READ | PROT_WRITE,
                              MAP_SHARED ,fd_mem, BASE_ADDR);
        if (base == MAP_FAILED)
        {
            Qcout << QString("Uncorreted address\n");
        }
        close(fd_mem);

    }
    return 0;
}

