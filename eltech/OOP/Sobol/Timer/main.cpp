#include "Timer.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Timer w;
	w.show();
	return a.exec();
}
