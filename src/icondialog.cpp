#include "icondialog.h"

Icondialog::Icondialog(QWidget *parent) : QDialog(parent) {

	QGridLayout *gridLayout = new QGridLayout(this);
	for (int i = 0; i < 6; i++) {
		Iconview *view = new Iconview(i, this);
		gridLayout->addWidget(view, 2*(i>2), i%3);
	}
	QLabel *label_0 = new QLabel(tr("Dot"), this);
	label_0->setAlignment(Qt::AlignHCenter);
	gridLayout->addWidget(label_0, 1, 0);
	QLabel *label_1 = new QLabel(tr("Cross"), this);
	label_1->setAlignment(Qt::AlignHCenter);
	gridLayout->addWidget(label_1, 1, 1);
	QLabel *label_2 = new QLabel(tr("Oktahedron contour"), this);
	label_2->setAlignment(Qt::AlignHCenter);
	gridLayout->addWidget(label_2, 1, 2);
	QLabel *label_3 = new QLabel(tr("Oktahedron"), this);
	label_3->setAlignment(Qt::AlignHCenter);
	gridLayout->addWidget(label_3, 3, 0);
	QLabel *label_4 = new QLabel(tr("Sphere contour"), this);
	label_4->setAlignment(Qt::AlignHCenter);
	gridLayout->addWidget(label_4, 3, 1);
	QLabel *label_5 = new QLabel(tr("Sphere"), this);
	label_5->setAlignment(Qt::AlignHCenter);
	gridLayout->addWidget(label_5, 3, 2);

	QLabel *label_note = new QLabel(this);
	label_note->setWordWrap(true);
	label_note->setText(tr("Note that the cross object is least, the Oktahedron objects are average and the sphere objects as well as the dot are most computation intensive."));
	gridLayout->addWidget(label_note, 5, 0, 1, 3);

	QPushButton *button_ok = new QPushButton(tr("OK"), this);
	button_ok->setFocusPolicy(Qt::NoFocus);
	connect(button_ok, SIGNAL(clicked()), this, SLOT(accept()));
	gridLayout->addWidget(button_ok, 6, 2);

	QIcon icon;
	icon.addPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")), QIcon::Normal, QIcon::Off);

	setLayout(gridLayout);
	setWindowTitle(tr("Select Item type"));
	setWindowIcon(icon);
}
