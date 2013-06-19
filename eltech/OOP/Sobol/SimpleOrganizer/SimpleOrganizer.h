#ifndef SIMPLEORGANIZER_H
#define SIMPLEORGANIZER_H

#include <QtGui/QMainWindow>
#include "ui_SimpleOrganizer.h"

#include <QMap>
#include <QTextDocument>

class SimpleOrganizer : public QMainWindow
{
	Q_OBJECT

public:
	SimpleOrganizer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~SimpleOrganizer();

	QMap<QDate,QTextDocument*> tasks;

private:
	Ui::SimpleOrganizerClass ui;

public slots:
	void DataSelected(QDate);
};

#endif // SIMPLEORGANIZER_H
