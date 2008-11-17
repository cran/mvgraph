#include "rotatewidget.h"

Rotatewidget::Rotatewidget(Spinview *sv, QWidget *parent) : QDialog(parent) {
	
	spinView = sv; // save pointer to spinview
	
	QGroupBox *box = new QGroupBox(tr("Auto Rotation"), this);
	
	// layout
	QGridLayout *gridLayout = new QGridLayout(box);
	QVBoxLayout *layout = new QVBoxLayout(this);

	// auto rotation label
	/*QLabel *label_auto = new QLabel(tr("Toggle Auto Rotation: "));
	label_auto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	gridLayout->addWidget(label_auto, 0, 0, 1, 1);*/

	// auto rotation checkbox
	QCheckBox *check = new QCheckBox(tr("Toggle Auto Rotation"), this);
	gridLayout->addWidget(check, 0, 1, 1, 1);
	connect(check, SIGNAL(stateChanged(int)), this, SLOT(rotateAuto(int)));

	// Rotate Label
	QLabel *label_rotation = new QLabel(tr("Rotate: "));
	label_rotation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	//gridLayout->addWidget(label_rotation, 0, 0, 1, 1);

	// Rotate Buttons
	button_x = new QPushButton(tr("x"));
	button_y = new QPushButton(tr("y"));
	button_z = new QPushButton(tr("z"));
	button_x->setCheckable(true);
	button_y->setCheckable(true);
	button_z->setCheckable(true);
	//gridLayout->addWidget(button_x, 0, 1, 1, 1);
	//gridLayout->addWidget(button_y, 0, 2, 1, 1);
	//gridLayout->addWidget(button_z, 0, 3, 1, 1);
	connect(button_x, SIGNAL(toggled(bool)), this, SLOT(rotateX(bool)));
	connect(button_y, SIGNAL(toggled(bool)), this, SLOT(rotateY(bool)));
	connect(button_z, SIGNAL(toggled(bool)), this, SLOT(rotateZ(bool)));

	// Velocity Label
	QLabel *label_velocity = new QLabel(tr("Speed: "));
	label_velocity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
	gridLayout->addWidget(label_velocity, 1, 0, 1, 1);

	// Velocity Slider
	slider_velocity = new QSlider(Qt::Horizontal);
	slider_velocity->setMinimum(1);
	slider_velocity->setMaximum(10);
	slider_velocity->setValue(5);
	slider_velocity->setSingleStep(1);
	slider_velocity->setPageStep(1);
	slider_velocity->setInvertedAppearance(true);
	slider_velocity->setInvertedControls(true);
	gridLayout->addWidget(slider_velocity, 1, 1, 1, 3);
	connect(slider_velocity, SIGNAL(valueChanged(int)), this, SLOT(velocityChanged(int)));
	
	// Timer
	timer = new QTimer(this);
	timerX = new QTimer(this);
	timerY = new QTimer(this);
	timerZ = new QTimer(this);
	connect(timer, SIGNAL(timeout()), spinView, SLOT(autoRotate()));
	connect(timerX, SIGNAL(timeout()), spinView, SLOT(autoRotateX()));
	connect(timerY, SIGNAL(timeout()), spinView, SLOT(autoRotateY()));
	connect(timerZ, SIGNAL(timeout()), spinView, SLOT(autoRotateZ()));
	
	box->setLayout(gridLayout);
	layout->addWidget(box);

	setLayout(layout);
	setWindowTitle(tr("Rotate"));
	
	widget_pos = parentWidget()->pos() + QPoint(parentWidget()->width(), 0);
}


void Rotatewidget::showEvent(QShowEvent */*event*/) {

	// move to the side; otherwise would be displayed in middle of parent
	move(widget_pos);
}

void Rotatewidget::moveEvent(QMoveEvent *event) {
	
	widget_pos = event->pos();
}

void Rotatewidget::rotateX(bool toggled) {
	
	if(toggled) {
		if(button_y->isChecked()) button_y->click();
		if(button_z->isChecked()) button_z->click();
		timerX->start(slider_velocity->value());
	}
	else {
		timerX->stop();
	}
}

void Rotatewidget::rotateY(bool toggled) {
	
	if(toggled) {
		if(button_x->isChecked()) button_x->click();
		if(button_z->isChecked()) button_z->click();
		timerY->start(slider_velocity->value());
	}
	else {
		timerY->stop();
	}
}

void Rotatewidget::rotateZ(bool toggled) {
	
	if(toggled) {
		if(button_y->isChecked()) button_y->click();
		if(button_x->isChecked()) button_x->click();
		timerZ->start(slider_velocity->value());
	}
	else {
		timerZ->stop();
	}
}

void Rotatewidget::rotateAuto(int state) {

	if(state)
		timer->start(slider_velocity->value());
	else
		timer->stop();
}

void Rotatewidget::velocityChanged(int value) {

	timer->setInterval(value);
	timerX->setInterval(value);
	timerY->setInterval(value);
	timerZ->setInterval(value);
}
