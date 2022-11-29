/********************************************************************************
** Form generated from reading UI file 'menutable.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUTABLE_H
#define UI_MENUTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuTable
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *picLB;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLB;
    QSpacerItem *horizontalSpacer;
    QLabel *tj2LB;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *priLB;
    QLabel *label;
    QLabel *tjLB;
    QPushButton *addBt;

    void setupUi(QWidget *MenuTable)
    {
        if (MenuTable->objectName().isEmpty())
            MenuTable->setObjectName(QStringLiteral("MenuTable"));
        MenuTable->resize(200, 200);
        MenuTable->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 9pt \"\345\215\216\345\205\211\347\262\227\351\273\221_CNKI\";\n"
"}\n"
"QPushButton#addBt\n"
"{\n"
"	border-image: url(:/image/add-circle.png);\n"
"	border-radius:12px;\n"
"}\n"
"QPushButton#addBt:pressed\n"
"{\n"
"	background-color: rgb(0, 85, 127);\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(MenuTable);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        picLB = new QLabel(MenuTable);
        picLB->setObjectName(QStringLiteral("picLB"));
        picLB->setStyleSheet(QLatin1String("border-radius:10px;\n"
"border:2px solid;\n"
"border-top-left-radius:1em;\n"
"border-top-right-radius:1em;\n"
"border-bottom-left-radius:1em;\n"
"border-bottom-right-radius:1em;"));

        verticalLayout_2->addWidget(picLB);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        nameLB = new QLabel(MenuTable);
        nameLB->setObjectName(QStringLiteral("nameLB"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        nameLB->setFont(font);
        nameLB->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 174, 68\357\274\2140.7);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(3, 15, 191);\n"
"border-radius:4px;"));
        nameLB->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(nameLB);

        horizontalSpacer = new QSpacerItem(18, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tj2LB = new QLabel(MenuTable);
        tj2LB->setObjectName(QStringLiteral("tj2LB"));
        tj2LB->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";"));

        horizontalLayout->addWidget(tj2LB);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        priLB = new QLabel(MenuTable);
        priLB->setObjectName(QStringLiteral("priLB"));
        priLB->setMinimumSize(QSize(30, 30));
        priLB->setMaximumSize(QSize(30, 30));
        priLB->setStyleSheet(QStringLiteral(""));
        priLB->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(priLB);

        label = new QLabel(MenuTable);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 30));
        label->setMaximumSize(QSize(30, 30));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_2->addWidget(label);

        tjLB = new QLabel(MenuTable);
        tjLB->setObjectName(QStringLiteral("tjLB"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tjLB->sizePolicy().hasHeightForWidth());
        tjLB->setSizePolicy(sizePolicy);
        tjLB->setMinimumSize(QSize(30, 12));
        tjLB->setMaximumSize(QSize(30, 12));

        horizontalLayout_2->addWidget(tjLB);

        addBt = new QPushButton(MenuTable);
        addBt->setObjectName(QStringLiteral("addBt"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addBt->sizePolicy().hasHeightForWidth());
        addBt->setSizePolicy(sizePolicy1);
        addBt->setMinimumSize(QSize(30, 30));
        addBt->setMaximumSize(QSize(30, 30));
        addBt->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(addBt);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        retranslateUi(MenuTable);

        QMetaObject::connectSlotsByName(MenuTable);
    } // setupUi

    void retranslateUi(QWidget *MenuTable)
    {
        MenuTable->setWindowTitle(QApplication::translate("MenuTable", "Form", 0));
        picLB->setText(QString());
        nameLB->setText(QString());
        tj2LB->setText(QApplication::translate("MenuTable", "\346\216\250\350\215\220\345\272\246\357\274\232", 0));
        priLB->setText(QString());
        label->setText(QString());
        tjLB->setText(QApplication::translate("MenuTable", "*****", 0));
        addBt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuTable: public Ui_MenuTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUTABLE_H
