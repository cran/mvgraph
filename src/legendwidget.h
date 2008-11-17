#ifndef LEGENDWIDGET_H
#define LEGENDWIDGET_H

#include <QDialog>
#include <QPainter>
#include <QVBoxLayout>
#include <QLabel>

class Legendwidget : public QDialog {

        Q_OBJECT

    public:
        Legendwidget(char** names = 0, QWidget *parent = 0);

};

#endif // LEGENDWIDGET_H
