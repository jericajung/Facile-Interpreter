#include <QApplication>
#include "LoadWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	LoadWindow loadwindow;
	loadwindow.show();
	return app.exec();
}