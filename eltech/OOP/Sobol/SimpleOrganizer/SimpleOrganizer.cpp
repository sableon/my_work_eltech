#include "SimpleOrganizer.h"

SimpleOrganizer::SimpleOrganizer(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	connect(ui.calendarWidget,SIGNAL(clicked(QDate)),	this,SLOT(DataSelected(QDate)));

	DataSelected(ui.calendarWidget->selectedDate());
}

SimpleOrganizer::~SimpleOrganizer()
{
	int N = tasks.keys().size();
	for(int i = 0; i < N; ++i)
	{
		delete (tasks[tasks.keys()[i]]);
	}
	tasks.clear();
}

void SimpleOrganizer::DataSelected(QDate date)
{
	if(!tasks.contains(date))
		tasks.insert(date,new QTextDocument);
	ui.textEdit->setDocument(tasks[date]);
}