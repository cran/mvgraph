#include <QApplication>
#include "selectdialog.h"

extern "C" {

void selectvars(char** varnames, int *selected, int* k, int *ok) {

	int argc = 1;
	char c = 'c';
	char *argv[1] = { &c };
	QApplication app(argc, argv);
        Selectdialog sp(varnames, selected, k, ok, 0);
	sp.show();
	app.exec();
	return;
}

}
