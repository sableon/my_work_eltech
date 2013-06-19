/********************************************************************************
** Form generated from reading UI file 'SimpleOrganizer.ui'
**
** Created: Wed 22. May 16:32:06 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEORGANIZER_H
#define UI_SIMPLEORGANIZER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimpleOrganizerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCalendarWidget *calendarWidget;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *SimpleOrganizerClass)
    {
        if (SimpleOrganizerClass->objectName().isEmpty())
            SimpleOrganizerClass->setObjectName(QString::fromUtf8("SimpleOrganizerClass"));
        SimpleOrganizerClass->resize(300, 300);
        SimpleOrganizerClass->setMinimumSize(QSize(300, 300));
        SimpleOrganizerClass->setMaximumSize(QSize(300, 300));
        centralWidget = new QWidget(SimpleOrganizerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        gridLayout->addWidget(calendarWidget, 0, 0, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);

        SimpleOrganizerClass->setCentralWidget(centralWidget);

        retranslateUi(SimpleOrganizerClass);

        QMetaObject::connectSlotsByName(SimpleOrganizerClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimpleOrganizerClass)
    {
        SimpleOrganizerClass->setWindowTitle(QApplication::translate("SimpleOrganizerClass", "SimpleOrganizer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SimpleOrganizerClass: public Ui_SimpleOrganizerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEORGANIZER_H
