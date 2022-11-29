/********************************************************************************
** Form generated from reading UI file 'firstwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTWINDOW_H
#define UI_FIRSTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <softkeyinputwin.h>

QT_BEGIN_NAMESPACE

class Ui_FirstWindow
{
public:
    QWidget *centralwidget;
    SoftKeyInputWin *widget_2;
    QWidget *kaizhuo;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLineEdit *peopleEt;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QLineEdit *tableEt;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QLineEdit *workEt;
    QLabel *label;
    QLabel *label_2;
    QPushButton *sureBt;

    void setupUi(QMainWindow *FirstWindow)
    {
        if (FirstWindow->objectName().isEmpty())
            FirstWindow->setObjectName(QStringLiteral("FirstWindow"));
        FirstWindow->resize(800, 480);
        FirstWindow->setStyleSheet(QLatin1String("\n"
"QPushButton#sureBt\n"
"{\n"
"	background-color: rgba(255, 170, 255,0.8);\n"
"}\n"
"QMainWindow#FirstWindow\n"
"{\n"
"	border-image: url(:/load/loading2.jpg);\n"
"}\n"
""));
        centralwidget = new QWidget(FirstWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius:15px;\n"
"}\n"
"QLineEdit#peopleEt{\n"
"background-color: rgba(255, 255, 255,0.6);\n"
"}\n"
"QLineEdit#tableEt{\n"
"background-color: rgba(255, 255, 255,0.6);\n"
"}\n"
"QLineEdit#workEt{\n"
"background-color: rgba(255, 255, 255,0.6);\n"
"}\n"
"QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	\n"
"	font: 16pt \"\345\215\216\345\205\211\345\275\251\344\272\221_CNKI\";\n"
"}\n"
"QLabel{\n"
"color: rgba(255, 255, 255,0.7);\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"	font: 15pt \"\345\215\216\345\205\211\346\240\207\351\242\230\345\256\213_CNKI\";\n"
"}\n"
"QPushButton#sureBt{\n"
"	\n"
"	\n"
"	background-color: rgba(255, 59, 59,0.8);\n"
"	color: rgb(0, 0, 0);\n"
"	font: 20pt \"\345\215\216\345\205\211\345\275\251\344\272\221_CNKI\";\n"
"	border-radius:10px;\n"
"}"));
        widget_2 = new SoftKeyInputWin(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 280, 800, 200));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgba(172, 172, 172,0.5);"));
        kaizhuo = new QWidget(centralwidget);
        kaizhuo->setObjectName(QStringLiteral("kaizhuo"));
        kaizhuo->setGeometry(QRect(210, 0, 361, 211));
        kaizhuo->setStyleSheet(QLatin1String("QWidget#kaizhuo\n"
"{\n"
"	background-color: rgba(239, 239, 239,0.3);\n"
"	border-radius:40px;\n"
"}"));
        layoutWidget = new QWidget(kaizhuo);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 20, 341, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/load/hu.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(32, 32));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        peopleEt = new QLineEdit(layoutWidget);
        peopleEt->setObjectName(QStringLiteral("peopleEt"));
        sizePolicy.setHeightForWidth(peopleEt->sizePolicy().hasHeightForWidth());
        peopleEt->setSizePolicy(sizePolicy);
        peopleEt->setMaximumSize(QSize(300, 50));
        peopleEt->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(peopleEt);

        layoutWidget1 = new QWidget(kaizhuo);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 82, 341, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/load/desk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(32, 32));
        pushButton_2->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_2);

        tableEt = new QLineEdit(layoutWidget1);
        tableEt->setObjectName(QStringLiteral("tableEt"));
        sizePolicy.setHeightForWidth(tableEt->sizePolicy().hasHeightForWidth());
        tableEt->setSizePolicy(sizePolicy);
        tableEt->setMaximumSize(QSize(300, 50));
        tableEt->setFocusPolicy(Qt::ClickFocus);
        tableEt->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(tableEt);

        layoutWidget2 = new QWidget(kaizhuo);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 140, 341, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/load/server.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(32, 32));
        pushButton_3->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_3);

        workEt = new QLineEdit(layoutWidget2);
        workEt->setObjectName(QStringLiteral("workEt"));
        sizePolicy.setHeightForWidth(workEt->sizePolicy().hasHeightForWidth());
        workEt->setSizePolicy(sizePolicy);
        workEt->setMaximumSize(QSize(300, 50));
        workEt->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(workEt);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 141, 30));
        label->setMinimumSize(QSize(70, 30));
        label->setMaximumSize(QSize(150, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\345\205\211\346\240\207\351\242\230\345\256\213_CNKI"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 40, 141, 30));
        label_2->setMinimumSize(QSize(50, 30));
        label_2->setMaximumSize(QSize(150, 50));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        sureBt = new QPushButton(centralwidget);
        sureBt->setObjectName(QStringLiteral("sureBt"));
        sureBt->setGeometry(QRect(330, 210, 131, 71));
        sureBt->setMinimumSize(QSize(50, 30));
        sureBt->setMaximumSize(QSize(150, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\345\205\211\345\275\251\344\272\221_CNKI"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        sureBt->setFont(font1);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/load/fox.png"), QSize(), QIcon::Normal, QIcon::Off);
        sureBt->setIcon(icon3);
        sureBt->setIconSize(QSize(46, 46));
        sureBt->setFlat(false);
        FirstWindow->setCentralWidget(centralwidget);

        retranslateUi(FirstWindow);

        QMetaObject::connectSlotsByName(FirstWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FirstWindow)
    {
        FirstWindow->setWindowTitle(QApplication::translate("FirstWindow", "FirstWindow", 0));
        pushButton->setText(QApplication::translate("FirstWindow", "\344\272\272      \346\225\260\357\274\232", 0));
        pushButton_2->setText(QApplication::translate("FirstWindow", "\346\241\214      \345\217\267\357\274\232", 0));
        pushButton_3->setText(QApplication::translate("FirstWindow", "\346\234\215\345\212\241\345\267\245\345\217\267\357\274\232", 0));
        label->setText(QString());
        label_2->setText(QString());
        sureBt->setText(QApplication::translate("FirstWindow", "\345\274\200\346\241\214", 0));
    } // retranslateUi

};

namespace Ui {
    class FirstWindow: public Ui_FirstWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTWINDOW_H
