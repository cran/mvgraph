#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include "ui_about.h"
#include <QDialog>

class Aboutwidget : public QDialog, public Ui::About {

	public:
		Aboutwidget(QWidget *parent = 0);
};

#endif
