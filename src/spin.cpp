#include <QApplication>
#include "spinwidget.h"

extern "C" {

void spin( /* int argc, char *argv[] */ double *x, double *y, double *z, int *n, int *groups, int *colors, double *max, char** names, char** colnames)
{
	int argc = 1;
	char c = 'c';
	char *argv[1] = { &c };
	QApplication app(argc, argv);
        Spinwidget sp(x, y, z, n, groups, colors, max, names, colnames);
	sp.show();
	app.exec();
	return;
}
 
}
