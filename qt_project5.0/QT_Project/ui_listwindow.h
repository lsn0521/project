/********************************************************************************
** Form generated from reading UI file 'listwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWINDOW_H
#define UI_LISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lable_11;
    QLabel *AllLB;
    QLabel *lable_12;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *finishBt;
    QPushButton *Order_Bt;
    QPushButton *returnBt;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *ListWindow)
    {
        if (ListWindow->objectName().isEmpty())
            ListWindow->setObjectName(QStringLiteral("ListWindow"));
        ListWindow->resize(800, 480);
        ListWindow->setStyleSheet(QLatin1String("QMainWindow#ListWindow\n"
"{\n"
"	background-color: rgb(38, 44, 56);\n"
"}\n"
""));
        centralwidget = new QWidget(ListWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"	background-color: rgba(67, 67, 67,0.9);\n"
"color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\215\216\345\205\211\350\241\214\346\245\267_CNKI\";\n"
"border:2px solid;\n"
"border-bottom-left-radius:1em;\n"
"border-bottom-right-radius:1em;\n"
"border-top-left-radius:1em;\n"
"border-top-right-radius:1em;\n"
"border-style:solid;\n"
"border-width:3px;\n"
"}\n"
"QPushButton#Order_Bt:pressed\n"
"{\n"
"	background-color: rgb(170, 170, 0);\n"
"}\n"
"QPushButton#finishBt:pressed\n"
"\n"
"{\n"
"	background-color: rgb(170, 170, 0);\n"
"}\n"
"QLabel#AllLB\n"
"{\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QLabel#lable_11\n"
"{\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QLabel#lable_12\n"
"{\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lable_11 = new QLabel(centralwidget);
        lable_11->setObjectName(QStringLiteral("lable_11"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(15);
        lable_11->setFont(font);

        horizontalLayout_2->addWidget(lable_11);

        AllLB = new QLabel(centralwidget);
        AllLB->setObjectName(QStringLiteral("AllLB"));
        AllLB->setMinimumSize(QSize(40, 15));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        font1.setPointSize(12);
        AllLB->setFont(font1);
        AllLB->setLayoutDirection(Qt::LeftToRight);
        AllLB->setLineWidth(10);
        AllLB->setAlignment(Qt::AlignCenter);
        AllLB->setIndent(0);

        horizontalLayout_2->addWidget(AllLB);

        lable_12 = new QLabel(centralwidget);
        lable_12->setObjectName(QStringLiteral("lable_12"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        font2.setPointSize(15);
        lable_12->setFont(font2);

        horizontalLayout_2->addWidget(lable_12);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        finishBt = new QPushButton(centralwidget);
        finishBt->setObjectName(QStringLiteral("finishBt"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(finishBt->sizePolicy().hasHeightForWidth());
        finishBt->setSizePolicy(sizePolicy);
        finishBt->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(finishBt);

        Order_Bt = new QPushButton(centralwidget);
        Order_Bt->setObjectName(QStringLiteral("Order_Bt"));
        sizePolicy.setHeightForWidth(Order_Bt->sizePolicy().hasHeightForWidth());
        Order_Bt->setSizePolicy(sizePolicy);
        Order_Bt->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(Order_Bt);

        returnBt = new QPushButton(centralwidget);
        returnBt->setObjectName(QStringLiteral("returnBt"));
        sizePolicy.setHeightForWidth(returnBt->sizePolicy().hasHeightForWidth());
        returnBt->setSizePolicy(sizePolicy);
        returnBt->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\215\216\345\205\211\350\241\214\346\245\267_CNKI\";\n"
"border:2px solid;\n"
"border-bottom-left-radius:1em;\n"
"border-bottom-right-radius:1em;\n"
"border-top-left-radius:1em;\n"
"border-top-right-radius:1em;\n"
"border-style:solid;\n"
"border-width:3px;\n"
"background-color: rgba(67, 67, 67,0.9)"));

        horizontalLayout->addWidget(returnBt);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font2);
        label->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255,0.9);"));

        verticalLayout_2->addWidget(label);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMaximumSize(QSize(500, 600));
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(225);
        tableWidget->horizontalHeader()->setMinimumSectionSize(180);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(225);
        tableWidget->verticalHeader()->setMinimumSectionSize(180);

        verticalLayout_2->addWidget(tableWidget);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 8);

        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 4);
        ListWindow->setCentralWidget(centralwidget);

        retranslateUi(ListWindow);

        QMetaObject::connectSlotsByName(ListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ListWindow)
    {
        ListWindow->setWindowTitle(QApplication::translate("ListWindow", "MainWindow", 0));
        lable_11->setText(QApplication::translate("ListWindow", "\346\200\273\351\207\221\351\242\235\357\274\232", 0));
        AllLB->setText(QApplication::translate("ListWindow", "0", 0));
        lable_12->setText(QApplication::translate("ListWindow", "\345\205\203", 0));
        finishBt->setText(QApplication::translate("ListWindow", "\347\273\223\350\264\246", 0));
        Order_Bt->setText(QApplication::translate("ListWindow", "\344\270\213\345\215\225", 0));
        returnBt->setText(QApplication::translate("ListWindow", "\350\277\224\345\233\236", 0));
        label->setText(QApplication::translate("ListWindow", "         \346\270\251\351\246\250\346\217\220\347\244\272\357\274\232\346\202\250\347\202\271\344\270\273\351\243\237\344\272\206\345\220\227\357\274\237", 0));
    } // retranslateUi

};

namespace Ui {
    class ListWindow: public Ui_ListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWINDOW_H
