#include "infowidget.h"


Infowidget::Infowidget(int size, int *index, double *x, double *y, double *z, double max, char** names, char** colnames, QWidget *parent) : QDialog(parent) {

	myIndex = index;
	myX = x;
	myY = y;
	myZ = z;
	maximum = max;

	QGroupBox *box = new QGroupBox(tr("Info"), this);
	QGridLayout *gridLayout = new QGridLayout(box);
	QVBoxLayout *layout = new QVBoxLayout(this);

	QLabel *label_index = new QLabel(tr("Index: "), this);
	label_index->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	gridLayout->addWidget(label_index, 0, 0);

        QLabel *label_x = new QLabel(QString::fromUtf8(colnames[0]) + tr(":"), this);
	label_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	gridLayout->addWidget(label_x, 1, 0);

        QLabel *label_y = new QLabel(QString::fromUtf8(colnames[1]) + tr(":"), this);
	label_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	gridLayout->addWidget(label_y, 2, 0);

        QLabel *label_z = new QLabel(QString::fromUtf8(colnames[2]) + tr(":"), this);
	label_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	gridLayout->addWidget(label_z, 3, 0);
	
	label_cX = new QLabel("", this);
	//label_cX->setAlignment(Qt::AlignLeft|Qt::AlignTrailing|Qt::AlignVCenter);
	gridLayout->addWidget(label_cX, 1, 1);

	label_cY = new QLabel("", this);
	//label_cY->setAlignment(Qt::AlignLeft|Qt::AlignTrailing|Qt::AlignVCenter);
	gridLayout->addWidget(label_cY, 2, 1);

	label_cZ = new QLabel("", this);
	//label_cZ->setAlignment(Qt::AlignLeft|Qt::AlignTrailing|Qt::AlignVCenter);
	gridLayout->addWidget(label_cZ, 3, 1);

	QComboBox *combo = new QComboBox(this);
	connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(fillFields(int)));
	for(int i=0; i<size; i++) {
                combo->addItem(QString::fromUtf8(names[myIndex[i]-1]));
	}
	gridLayout->addWidget(combo, 0, 1);
	
	QPushButton *button = new QPushButton(tr("OK"), this);
	gridLayout->addWidget(button, 4, 0, 1, 2);
	connect(button, SIGNAL(clicked()), this, SLOT(accept()));

	box->setLayout(gridLayout);
	layout->addWidget(box);

	QIcon icon;
	icon.addPixmap(QPixmap(QString::fromUtf8(":/images/info.png")), QIcon::Normal, QIcon::Off);

	setLayout(layout);
	setWindowTitle(tr("Info"));
	setWindowIcon(icon);
}

void Infowidget::fillFields(int index) {

	if( index >= 0) {
		label_cX->setNum(maximum*myX[myIndex[index] - 1]);
		label_cY->setNum(maximum*myY[myIndex[index] - 1]);
		label_cZ->setNum(maximum*myZ[myIndex[index] - 1]);
	}
}
