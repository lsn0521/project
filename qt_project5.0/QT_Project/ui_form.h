/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *cai_namelb;
    QLabel *cai_price_lb;
    QPushButton *subBt;
    QLabel *cai_number_lb;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(310, 50);
        Form->setMinimumSize(QSize(280, 40));
        Form->setMaximumSize(QSize(310, 50));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cai_namelb = new QLabel(Form);
        cai_namelb->setObjectName(QStringLiteral("cai_namelb"));
        cai_namelb->setMinimumSize(QSize(100, 30));
        cai_namelb->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\345\205\211\350\241\214\346\245\267_CNKI"));
        font.setPointSize(13);
        cai_namelb->setFont(font);
        cai_namelb->setStyleSheet(QStringLiteral(""));
        cai_namelb->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(cai_namelb);

        cai_price_lb = new QLabel(Form);
        cai_price_lb->setObjectName(QStringLiteral("cai_price_lb"));
        cai_price_lb->setMinimumSize(QSize(60, 40));
        cai_price_lb->setMaximumSize(QSize(80, 40));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        cai_price_lb->setFont(font1);
        cai_price_lb->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(cai_price_lb);

        subBt = new QPushButton(Form);
        subBt->setObjectName(QStringLiteral("subBt"));
        subBt->setMinimumSize(QSize(40, 40));
        subBt->setMaximumSize(QSize(40, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\345\205\211\347\262\227\351\273\221_CNKI"));
        font2.setPointSize(15);
        subBt->setFont(font2);
        subBt->setStyleSheet(QLatin1String("border-radius:18px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border-image: url(:/im/minus-circle.png);"));

        horizontalLayout->addWidget(subBt);

        cai_number_lb = new QLabel(Form);
        cai_number_lb->setObjectName(QStringLiteral("cai_number_lb"));
        cai_number_lb->setMaximumSize(QSize(20, 50));
        QFont font3;
        font3.setPointSize(20);
        cai_number_lb->setFont(font3);

        horizontalLayout->addWidget(cai_number_lb);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(40, 40));
        pushButton->setMaximumSize(QSize(40, 40));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\215\216\345\205\211\347\262\227\345\234\206_CNKI"));
        font4.setPointSize(15);
        pushButton->setFont(font4);
        pushButton->setStyleSheet(QLatin1String("border-radius:18px;\n"
"color: rgb(0, 0, 0);\n"
"border-image: url(:/im/add-circle.png);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        cai_namelb->setText(QApplication::translate("Form", "\350\217\234\345\220\215", 0));
        cai_price_lb->setText(QApplication::translate("Form", "77\345\205\203", 0));
        subBt->setText(QApplication::translate("Form", "-", 0));
        cai_number_lb->setText(QApplication::translate("Form", "1", 0));
        pushButton->setText(QApplication::translate("Form", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
