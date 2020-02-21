/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *displayPanel;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *actionClear;
    QPushButton *actionDel;
    QPushButton *actionPercent;
    QPushButton *actionDiv;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *num7;
    QPushButton *num8;
    QPushButton *num9;
    QPushButton *actionMul;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num6;
    QPushButton *actionMinus;
    QHBoxLayout *horizontalLayout;
    QPushButton *num1;
    QPushButton *num2;
    QPushButton *num3;
    QPushButton *actionPlus;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *num0;
    QPushButton *comma;
    QPushButton *actionSign;
    QPushButton *actionCalc;
    QButtonGroup *actionGroup;
    QButtonGroup *numberGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(306, 319);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(306, 319));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QLatin1String("background-color: #f5f5f5;\n"
"color: rgb(0, 0, 0);\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setStyleSheet(QLatin1String("QPushButton {\n"
"min-width: 65;\n"
"min-height: 40;\n"
"max-width: 65;\n"
"max-height: 40;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        displayPanel = new QLabel(centralWidget);
        displayPanel->setObjectName(QStringLiteral("displayPanel"));
        displayPanel->setMinimumSize(QSize(290, 40));
        displayPanel->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QStringLiteral("Open Sans"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setKerning(true);
        displayPanel->setFont(font);
        displayPanel->setLayoutDirection(Qt::LeftToRight);
        displayPanel->setStyleSheet(QLatin1String("border: 1 solid #b8b8b8;\n"
"background-color: #fff;"));
        displayPanel->setScaledContents(true);
        displayPanel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        displayPanel->setWordWrap(true);
        displayPanel->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(displayPanel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        actionClear = new QPushButton(centralWidget);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionClear->setStyleSheet(QLatin1String("background-color: #cb1a21;\n"
"color: #ffffff;"));

        horizontalLayout_5->addWidget(actionClear);

        actionDel = new QPushButton(centralWidget);
        actionDel->setObjectName(QStringLiteral("actionDel"));

        horizontalLayout_5->addWidget(actionDel);

        actionPercent = new QPushButton(centralWidget);
        actionPercent->setObjectName(QStringLiteral("actionPercent"));

        horizontalLayout_5->addWidget(actionPercent);

        actionDiv = new QPushButton(centralWidget);
        actionGroup = new QButtonGroup(MainWindow);
        actionGroup->setObjectName(QStringLiteral("actionGroup"));
        actionGroup->addButton(actionDiv);
        actionDiv->setObjectName(QStringLiteral("actionDiv"));

        horizontalLayout_5->addWidget(actionDiv);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        num7 = new QPushButton(centralWidget);
        numberGroup = new QButtonGroup(MainWindow);
        numberGroup->setObjectName(QStringLiteral("numberGroup"));
        numberGroup->addButton(num7);
        num7->setObjectName(QStringLiteral("num7"));

        horizontalLayout_3->addWidget(num7);

        num8 = new QPushButton(centralWidget);
        numberGroup->addButton(num8);
        num8->setObjectName(QStringLiteral("num8"));
        sizePolicy.setHeightForWidth(num8->sizePolicy().hasHeightForWidth());
        num8->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(num8);

        num9 = new QPushButton(centralWidget);
        numberGroup->addButton(num9);
        num9->setObjectName(QStringLiteral("num9"));

        horizontalLayout_3->addWidget(num9);

        actionMul = new QPushButton(centralWidget);
        actionGroup->addButton(actionMul);
        actionMul->setObjectName(QStringLiteral("actionMul"));

        horizontalLayout_3->addWidget(actionMul);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        num4 = new QPushButton(centralWidget);
        numberGroup->addButton(num4);
        num4->setObjectName(QStringLiteral("num4"));

        horizontalLayout_2->addWidget(num4);

        num5 = new QPushButton(centralWidget);
        numberGroup->addButton(num5);
        num5->setObjectName(QStringLiteral("num5"));

        horizontalLayout_2->addWidget(num5);

        num6 = new QPushButton(centralWidget);
        numberGroup->addButton(num6);
        num6->setObjectName(QStringLiteral("num6"));

        horizontalLayout_2->addWidget(num6);

        actionMinus = new QPushButton(centralWidget);
        actionGroup->addButton(actionMinus);
        actionMinus->setObjectName(QStringLiteral("actionMinus"));

        horizontalLayout_2->addWidget(actionMinus);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        num1 = new QPushButton(centralWidget);
        numberGroup->addButton(num1);
        num1->setObjectName(QStringLiteral("num1"));
        sizePolicy.setHeightForWidth(num1->sizePolicy().hasHeightForWidth());
        num1->setSizePolicy(sizePolicy);
        num1->setMinimumSize(QSize(67, 42));
        num1->setMaximumSize(QSize(67, 42));

        horizontalLayout->addWidget(num1);

        num2 = new QPushButton(centralWidget);
        numberGroup->addButton(num2);
        num2->setObjectName(QStringLiteral("num2"));
        sizePolicy.setHeightForWidth(num2->sizePolicy().hasHeightForWidth());
        num2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(num2);

        num3 = new QPushButton(centralWidget);
        numberGroup->addButton(num3);
        num3->setObjectName(QStringLiteral("num3"));
        sizePolicy.setHeightForWidth(num3->sizePolicy().hasHeightForWidth());
        num3->setSizePolicy(sizePolicy);
        num3->setMaximumSize(QSize(67, 42));

        horizontalLayout->addWidget(num3);

        actionPlus = new QPushButton(centralWidget);
        actionGroup->addButton(actionPlus);
        actionPlus->setObjectName(QStringLiteral("actionPlus"));

        horizontalLayout->addWidget(actionPlus);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        num0 = new QPushButton(centralWidget);
        numberGroup->addButton(num0);
        num0->setObjectName(QStringLiteral("num0"));

        horizontalLayout_4->addWidget(num0);

        comma = new QPushButton(centralWidget);
        comma->setObjectName(QStringLiteral("comma"));

        horizontalLayout_4->addWidget(comma);

        actionSign = new QPushButton(centralWidget);
        actionSign->setObjectName(QStringLiteral("actionSign"));

        horizontalLayout_4->addWidget(actionSign);

        actionCalc = new QPushButton(centralWidget);
        actionCalc->setObjectName(QStringLiteral("actionCalc"));
        actionCalc->setStyleSheet(QLatin1String("background-color: #3490cd;\n"
"color: #ffffff;"));

        horizontalLayout_4->addWidget(actionCalc);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator", Q_NULLPTR));
        displayPanel->setText(QString());
        actionClear->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        actionDel->setText(QApplication::translate("MainWindow", "Del", Q_NULLPTR));
        actionPercent->setText(QApplication::translate("MainWindow", "%", Q_NULLPTR));
        actionDiv->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        num7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        num8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        num9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        actionMul->setText(QApplication::translate("MainWindow", "x", Q_NULLPTR));
        num4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        num5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        num6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        actionMinus->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        num1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        num2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        num3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        actionPlus->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        num0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        comma->setText(QApplication::translate("MainWindow", ".", Q_NULLPTR));
        actionSign->setText(QApplication::translate("MainWindow", "+/-", Q_NULLPTR));
        actionCalc->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
