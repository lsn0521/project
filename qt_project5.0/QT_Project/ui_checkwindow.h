/********************************************************************************
** Form generated from reading UI file 'checkwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKWINDOW_H
#define UI_CHECKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;

    void setupUi(QMainWindow *CheckWindow)
    {
        if (CheckWindow->objectName().isEmpty())
            CheckWindow->setObjectName(QStringLiteral("CheckWindow"));
        CheckWindow->resize(800, 480);
        centralwidget = new QWidget(CheckWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 30, 361, 361));
        label->setStyleSheet(QStringLiteral("border-image: url(:/load/check.jpg);"));
        CheckWindow->setCentralWidget(centralwidget);

        retranslateUi(CheckWindow);

        QMetaObject::connectSlotsByName(CheckWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CheckWindow)
    {
        CheckWindow->setWindowTitle(QApplication::translate("CheckWindow", "\344\273\230\346\254\276\347\225\214\351\235\242", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckWindow: public Ui_CheckWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKWINDOW_H
