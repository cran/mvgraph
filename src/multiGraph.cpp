#include <QApplication>
#include <QtGui>
#include "multiDialog.h"

extern "C" {

void multiGraph(int *k, char** varnames, int *selected, int *xC, int *yC, int *add, int *labels, int *index, int *simple, int *boardered, int *diamonds, int *ok)
{
        int argc = 1;
        char c = 'c';
        char *argv[1] = { &c };
        QApplication app(argc, argv);
        MultiDialog multi(k, varnames, selected, xC, yC, add, labels, index, simple, boardered, diamonds, ok, 0);
        multi.show();
        app.exec();
        return;
}

}
