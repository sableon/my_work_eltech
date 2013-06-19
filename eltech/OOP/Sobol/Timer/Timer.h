#ifndef TIMER_H
#define TIMER_H

#include <QtGui/QMainWindow>
#include "ui_Timer.h"

#include <QFrame>
#include <QTimer>
#include <QLabel>
#include "DateTime.h"

class Timer : public QMainWindow
{
	Q_OBJECT

public:
	Timer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Timer();

private:
	Ui::TimerClass ui;

	QFrame* time;
	QLabel* time_label;
	QTimer* timer;

	DateTime time_v;

public slots:
	void ChangeMode(bool);
	void StartStopClicked();
	void ShowHideClicked();
	void TimerSlot();
};

#endif // TIMER_H
