/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *logoButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *servicebt;
    QPushButton *Orderbt;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Orderbel;
    QLineEdit *OrderEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *tablebel;
    QLineEdit *tableEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *peoplebel;
    QLineEdit *peopleEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *serbel;
    QLineEdit *serEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *Recombt;
    QPushButton *guicaibt;
    QPushButton *yuecai;
    QPushButton *yinpin;
    QTableWidget *Table_on;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QStringLiteral("MenuWindow"));
        MenuWindow->resize(800, 480);
        MenuWindow->setStyleSheet(QLatin1String("QMainWindow#MenuWindow\n"
"{\n"
"	background-color: rgb(45, 53, 64);\n"
"}\n"
""));
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton#Orderbt\n"
"{\n"
"background-color: rgba(47, 56, 71,1);\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid;\n"
"border-style:solid;\n"
"border-width:3px;\n"
"	font: 18pt \"\345\215\216\345\205\211\350\241\214\346\245\267_CNKI\";\n"
"}\n"
"QPushButton#servicebt\n"
"{\n"
"	background-color: rgba(47, 56, 71,1);\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid;\n"
"border-style:solid;\n"
"border-width:3px;\n"
"font: 18pt \"\345\215\216\345\205\211\350\241\214\346\245\267_CNKI\";\n"
"}\n"
"QPushButton#Recombt\n"
"{\n"
"	background-color: rgba(47, 56, 71,1);\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid;\n"
"border-style:solid;\n"
"border-width:3px;\n"
"font: 16pt \"\345\215\216\345\205\211\350\241\214\346\245\267_CNKI\";\n"
"}\n"
"QPushButton#guicaibt\n"
"{\n"
"	background-color: rgba(47, 56, 71,1);\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid;\n"
"border-style:solid;\n"
"border-width:3px;\n"
"font: 16pt \"\345\215\216\345\205\211\350\241\214\346\245\267_CNKI\";\n"
"}\n"
"QPushButton#yi"
                        "npin\n"
"{\n"
"	background-color: rgba(47, 56, 71,1);\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid;\n"
"border-style:solid;\n"
"border-width:3px;\n"
"font: 16pt \"\345\215\216\345\205\211\350\241\214\346\245\267_CNKI\";\n"
"}\n"
"QPushButton#yuecai\n"
"{\n"
"	background-color: rgba(47, 56, 71,1);\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid;\n"
"border-style:solid;\n"
"border-width:3px;\n"
"font: 16pt \"\345\215\216\345\205\211\350\241\214\346\245\267_CNKI\";\n"
"}\n"
"\n"
"QLineEdit#OrderEdit{\n"
"border-radius:5px;\n"
"	background-color: rgba(255, 255, 255,0);\n"
"font: 9pt \"\345\215\216\345\205\211\347\262\227\351\273\221_CNKI\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit#peopleEdit{\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255,0);\n"
"font: 9pt \"\345\215\216\345\205\211\347\262\227\351\273\221_CNKI\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit#tableEdit{\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255,0);\n"
"font: 9pt \"\345\215"
                        "\216\345\205\211\347\262\227\351\273\221_CNKI\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit#serEdit{\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255,0);\n"
"font: 9pt \"\345\215\216\345\205\211\347\262\227\351\273\221_CNKI\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QLabel#Orderbel{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 9pt \"\345\215\216\345\205\211\347\262\227\351\273\221_CNKI\";\n"
"\n"
"}\n"
"QLabel#peoplebel{\n"
"	color: rgb(255, 255, 255);\n"
"font: 9pt \"\345\215\216\345\205\211\347\262\227\351\273\221_CNKI\";\n"
"\n"
"}\n"
"QLabel#tablebel{\n"
"	color: rgb(255, 255, 255);\n"
"font: 9pt \"\345\215\216\345\205\211\347\262\227\351\273\221_CNKI\";\n"
"\n"
"}\n"
"QLabel#serbel{\n"
"	color: rgb(255, 255, 255);\n"
"font: 9pt \"\345\215\216\345\205\211\347\262\227\351\273\221_CNKI\";\n"
"\n"
"}\n"
"QPushButton#logoButton{\n"
"	border-image: url(:/load/logo.png);\n"
"	border-radius:30px;\n"
"}\n"
"QLineEdit#lineEdit{\n"
"border-radius:5px;\n"
"	background-color: rgba(255, 255, "
                        "255,0);\n"
"}\n"
"QTableWidget#Table_on{\n"
"	background-color: rgba(255, 255, 255,0.8);\n"
"}\n"
""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        logoButton = new QPushButton(centralwidget);
        logoButton->setObjectName(QStringLiteral("logoButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logoButton->sizePolicy().hasHeightForWidth());
        logoButton->setSizePolicy(sizePolicy);
        logoButton->setFlat(true);

        horizontalLayout_2->addWidget(logoButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        servicebt = new QPushButton(centralwidget);
        servicebt->setObjectName(QStringLiteral("servicebt"));
        sizePolicy.setHeightForWidth(servicebt->sizePolicy().hasHeightForWidth());
        servicebt->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/load/ser.png"), QSize(), QIcon::Normal, QIcon::Off);
        servicebt->setIcon(icon);
        servicebt->setIconSize(QSize(46, 46));
        servicebt->setFlat(true);

        horizontalLayout->addWidget(servicebt);

        Orderbt = new QPushButton(centralwidget);
        Orderbt->setObjectName(QStringLiteral("Orderbt"));
        sizePolicy.setHeightForWidth(Orderbt->sizePolicy().hasHeightForWidth());
        Orderbt->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/load/ding.png"), QSize(), QIcon::Normal, QIcon::Off);
        Orderbt->setIcon(icon1);
        Orderbt->setIconSize(QSize(46, 46));
        Orderbt->setFlat(true);

        horizontalLayout->addWidget(Orderbt);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 8);

        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Orderbel = new QLabel(widget);
        Orderbel->setObjectName(QStringLiteral("Orderbel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Orderbel->sizePolicy().hasHeightForWidth());
        Orderbel->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(Orderbel);

        OrderEdit = new QLineEdit(widget);
        OrderEdit->setObjectName(QStringLiteral("OrderEdit"));
        OrderEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(OrderEdit->sizePolicy().hasHeightForWidth());
        OrderEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(OrderEdit);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 10);

        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        tablebel = new QLabel(widget);
        tablebel->setObjectName(QStringLiteral("tablebel"));
        sizePolicy1.setHeightForWidth(tablebel->sizePolicy().hasHeightForWidth());
        tablebel->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(tablebel);

        tableEdit = new QLineEdit(widget);
        tableEdit->setObjectName(QStringLiteral("tableEdit"));
        tableEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(tableEdit->sizePolicy().hasHeightForWidth());
        tableEdit->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(tableEdit);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 10);

        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        peoplebel = new QLabel(widget);
        peoplebel->setObjectName(QStringLiteral("peoplebel"));
        sizePolicy1.setHeightForWidth(peoplebel->sizePolicy().hasHeightForWidth());
        peoplebel->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(peoplebel);

        peopleEdit = new QLineEdit(widget);
        peopleEdit->setObjectName(QStringLiteral("peopleEdit"));
        peopleEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(peopleEdit->sizePolicy().hasHeightForWidth());
        peopleEdit->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(peopleEdit);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 10);

        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        serbel = new QLabel(widget);
        serbel->setObjectName(QStringLiteral("serbel"));
        sizePolicy1.setHeightForWidth(serbel->sizePolicy().hasHeightForWidth());
        serbel->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(serbel);

        serEdit = new QLineEdit(widget);
        serEdit->setObjectName(QStringLiteral("serEdit"));
        serEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(serEdit->sizePolicy().hasHeightForWidth());
        serEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(serEdit);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 10);

        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Recombt = new QPushButton(centralwidget);
        Recombt->setObjectName(QStringLiteral("Recombt"));
        sizePolicy.setHeightForWidth(Recombt->sizePolicy().hasHeightForWidth());
        Recombt->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/load/rec.png"), QSize(), QIcon::Normal, QIcon::Off);
        Recombt->setIcon(icon2);
        Recombt->setIconSize(QSize(47, 47));
        Recombt->setFlat(true);

        verticalLayout->addWidget(Recombt);

        guicaibt = new QPushButton(centralwidget);
        guicaibt->setObjectName(QStringLiteral("guicaibt"));
        sizePolicy.setHeightForWidth(guicaibt->sizePolicy().hasHeightForWidth());
        guicaibt->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/load/ma.png"), QSize(), QIcon::Normal, QIcon::Off);
        guicaibt->setIcon(icon3);
        guicaibt->setIconSize(QSize(47, 47));
        guicaibt->setFlat(true);

        verticalLayout->addWidget(guicaibt);

        yuecai = new QPushButton(centralwidget);
        yuecai->setObjectName(QStringLiteral("yuecai"));
        sizePolicy.setHeightForWidth(yuecai->sizePolicy().hasHeightForWidth());
        yuecai->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/load/soup.png"), QSize(), QIcon::Normal, QIcon::Off);
        yuecai->setIcon(icon4);
        yuecai->setIconSize(QSize(47, 47));
        yuecai->setFlat(true);

        verticalLayout->addWidget(yuecai);

        yinpin = new QPushButton(centralwidget);
        yinpin->setObjectName(QStringLiteral("yinpin"));
        sizePolicy.setHeightForWidth(yinpin->sizePolicy().hasHeightForWidth());
        yinpin->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/load/drink.png"), QSize(), QIcon::Normal, QIcon::Off);
        yinpin->setIcon(icon5);
        yinpin->setIconSize(QSize(47, 47));
        yinpin->setFlat(true);

        verticalLayout->addWidget(yinpin);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_3->setStretch(0, 4);
        verticalLayout_3->setStretch(1, 15);

        horizontalLayout_7->addLayout(verticalLayout_3);

        Table_on = new QTableWidget(centralwidget);
        Table_on->setObjectName(QStringLiteral("Table_on"));
        sizePolicy.setHeightForWidth(Table_on->sizePolicy().hasHeightForWidth());
        Table_on->setSizePolicy(sizePolicy);
        Table_on->setAutoScroll(true);
        Table_on->horizontalHeader()->setVisible(false);
        Table_on->horizontalHeader()->setDefaultSectionSize(200);
        Table_on->horizontalHeader()->setHighlightSections(true);
        Table_on->verticalHeader()->setVisible(false);
        Table_on->verticalHeader()->setDefaultSectionSize(199);
        Table_on->verticalHeader()->setHighlightSections(true);

        horizontalLayout_7->addWidget(Table_on);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 8);

        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalLayout_4->setStretch(0, 2);
        verticalLayout_4->setStretch(1, 10);

        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        MenuWindow->setCentralWidget(centralwidget);

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "MenuWindow", 0));
        logoButton->setText(QString());
        servicebt->setText(QApplication::translate("MenuWindow", "\346\234\215\345\212\241", 0));
        Orderbt->setText(QApplication::translate("MenuWindow", "\345\267\262\347\202\271", 0));
        Orderbel->setText(QApplication::translate("MenuWindow", "\350\256\242\345\215\225\345\217\267\357\274\232", 0));
        tablebel->setText(QApplication::translate("MenuWindow", "\346\241\214  \345\217\267\357\274\232", 0));
        peoplebel->setText(QApplication::translate("MenuWindow", "\344\272\272  \346\225\260\357\274\232", 0));
        serbel->setText(QApplication::translate("MenuWindow", "\346\234\215\345\212\241\345\217\267\357\274\232", 0));
        Recombt->setText(QApplication::translate("MenuWindow", "\346\216\250\350\215\220", 0));
        guicaibt->setText(QApplication::translate("MenuWindow", "\344\270\273\350\217\234", 0));
        yuecai->setText(QApplication::translate("MenuWindow", "\347\202\226\346\261\244", 0));
        yinpin->setText(QApplication::translate("MenuWindow", "\351\245\256\346\226\231", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
