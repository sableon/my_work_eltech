#include "Timer.h"

Timer::Timer(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags),
	time_v(0)
{
	ui.setupUi(this);

	time = new QFrame(this);
	time->setGeometry(40,150,120,35);
	time->setStyleSheet("QFrame{background-color: white;}");
	time->hide();
	time_label = new QLabel(time);
	time_label->setText(time_v.to_string_Just_time());
	time_label->resize(time->size());
	time_label->setAlignment(Qt::AlignCenter);
	QFont *f = new QFont;
	f->setPixelSize(14);
	time_label->setFont(*f);

	ui.stackedWidget->setCurrentIndex(0);

	timer = new QTimer(this);
	timer->setInterval(1000);

	connect(ui.count,SIGNAL(toggled(bool)),		this,SLOT(ChangeMode(bool)));
	connect(ui.showing,SIGNAL(toggled(bool)),	this,SLOT(ChangeMode(bool)));
	connect(ui.start_stop,SIGNAL(clicked()),	this,SLOT(StartStopClicked()));
	connect(ui.show_hide,SIGNAL(clicked()),		this,SLOT(ShowHideClicked()));

	connect(timer,SIGNAL(timeout()),			&time_v,SLOT(second_increment()));
	connect(timer,SIGNAL(timeout()),			this,SLOT(TimerSlot()));
}

Timer::~Timer()
{

}

void Timer::ChangeMode(bool checked)
{
	if(checked)
	{
		if(ui.stackedWidget->currentIndex() == 0)
			ui.stackedWidget->setCurrentIndex(1);
		else
			ui.stackedWidget->setCurrentIndex(0);
	}
}
void Timer::StartStopClicked()
{
	if(ui.start_stop->text() == QString("Start timer"))
	{
		ui.start_stop->setText("Stop timer");
		timer->start();
	}
	else
	{
		ui.start_stop->setText("Start timer");
		timer->stop();
	}
}
void Timer::ShowHideClicked()
{
	if(ui.show_hide->text() == QString("Show time"))
	{
		ui.show_hide->setText("Hide time");
		time->show();
	}
	else
	{
		ui.show_hide->setText("Show time");
		time->hide();
	}
}
void Timer::TimerSlot()
{
	if(ui.show_hide->text() == QString("Hide time"))
		time_label->setText(time_v.to_string_Just_time());
}