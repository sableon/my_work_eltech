/********************************************************************************
** Form generated from reading UI file 'Timer.ui'
**
** Created: Wed 22. May 15:53:26 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMER_H
#define UI_TIMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimerClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *count;
    QRadioButton *showing;
    QStackedWidget *stackedWidget;
    QWidget *count_widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *start_stop;
    QWidget *show_widget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *show_hide;

    void setupUi(QMainWindow *TimerClass)
    {
        if (TimerClass->objectName().isEmpty())
            TimerClass->setObjectName(QString::fromUtf8("TimerClass"));
        TimerClass->resize(200, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TimerClass->sizePolicy().hasHeightForWidth());
        TimerClass->setSizePolicy(sizePolicy);
        TimerClass->setMinimumSize(QSize(200, 250));
        TimerClass->setMaximumSize(QSize(200, 250));
        centralWidget = new QWidget(TimerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 151, 73));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        count = new QRadioButton(groupBox);
        count->setObjectName(QString::fromUtf8("count"));
        count->setChecked(true);

        verticalLayout->addWidget(count);

        showing = new QRadioButton(groupBox);
        showing->setObjectName(QString::fromUtf8("showing"));

        verticalLayout->addWidget(showing);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 100, 161, 51));
        count_widget = new QWidget();
        count_widget->setObjectName(QString::fromUtf8("count_widget"));
        verticalLayout_2 = new QVBoxLayout(count_widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        start_stop = new QPushButton(count_widget);
        start_stop->setObjectName(QString::fromUtf8("start_stop"));

        verticalLayout_2->addWidget(start_stop);

        stackedWidget->addWidget(count_widget);
        show_widget = new QWidget();
        show_widget->setObjectName(QString::fromUtf8("show_widget"));
        verticalLayout_3 = new QVBoxLayout(show_widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        show_hide = new QPushButton(show_widget);
        show_hide->setObjectName(QString::fromUtf8("show_hide"));

        verticalLayout_3->addWidget(show_hide);

        stackedWidget->addWidget(show_widget);
        TimerClass->setCentralWidget(centralWidget);

        retranslateUi(TimerClass);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TimerClass);
    } // setupUi

    void retranslateUi(QMainWindow *TimerClass)
    {
        TimerClass->setWindowTitle(QApplication::translate("TimerClass", "Timer", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TimerClass", "Work mode", 0, QApplication::UnicodeUTF8));
        count->setText(QApplication::translate("TimerClass", "Count mode", 0, QApplication::UnicodeUTF8));
        showing->setText(QApplication::translate("TimerClass", "Show time mode", 0, QApplication::UnicodeUTF8));
        start_stop->setText(QApplication::translate("TimerClass", "Start timer", 0, QApplication::UnicodeUTF8));
        show_hide->setText(QApplication::translate("TimerClass", "Show time", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TimerClass: public Ui_TimerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMER_H
