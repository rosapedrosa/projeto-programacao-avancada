/********************************************************************************
** Form generated from reading UI file 'sculptor.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCULPTOR_H
#define UI_SCULPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sculptor
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sculptor)
    {
        if (sculptor->objectName().isEmpty())
            sculptor->setObjectName(QString::fromUtf8("sculptor"));
        sculptor->resize(800, 600);
        centralwidget = new QWidget(sculptor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sculptor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sculptor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        sculptor->setMenuBar(menubar);
        statusbar = new QStatusBar(sculptor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sculptor->setStatusBar(statusbar);

        retranslateUi(sculptor);

        QMetaObject::connectSlotsByName(sculptor);
    } // setupUi

    void retranslateUi(QMainWindow *sculptor)
    {
        sculptor->setWindowTitle(QCoreApplication::translate("sculptor", "sculptor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sculptor: public Ui_sculptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCULPTOR_H
