#include "legendwidget.h"


Legendwidget::Legendwidget(char** names, QWidget *parent) : QDialog(parent) {

	QVBoxLayout *layout = new QVBoxLayout(this);

	QLabel *label1 = new QLabel("<font color='red'>"+QString::fromUtf8(names[0])+"</font>");
	layout->addWidget(label1);
	QLabel *label2 = new QLabel("<font color='green'>"+QString::fromUtf8(names[1])+"</font>");
	layout->addWidget(label2);
	QLabel *label3 = new QLabel("<font color='blue'>"+QString::fromUtf8(names[2])+"</font>");
	layout->addWidget(label3);

	setLayout(layout);
	setWindowTitle(tr("Legend"));
}
