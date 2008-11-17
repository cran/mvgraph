#include "spinwidget.h"
#include <QDebug>

Spinwidget::Spinwidget(double *x, double *y, double *z, int *n, int *colors, int* cols, double *max, char** names, char **colnames, QWidget *parent) : QWidget(parent) {

	// icon dialog first
	Icondialog icondialog(this);
	Iconview::Icon selectedIcon = Iconview::Cross;
	
	if(icondialog.exec()) {
		Iconview *iv = static_cast<Iconview *>(icondialog.focusWidget());
		selectedIcon = iv->getIcon();
	}

	// Layouts
	gridLayout = new QGridLayout(this);
	QVBoxLayout *leftLayout = new QVBoxLayout(0);
	QVBoxLayout *rightLayout = new QVBoxLayout(0);

	// OpenGL View
        view = new Spinview(x, y, z, n, colors, max, selectedIcon, names, colnames, cols, this);
	//gridLayout->addWidget(view, 0, 1, 7, 4);

	// Zoom In Button
	QPushButton *button_zoomin = new QPushButton("+");
	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(button_zoomin->sizePolicy().hasHeightForWidth());
	button_zoomin->setSizePolicy(sizePolicy);
	button_zoomin->setFixedSize(QSize(35, 35));
	button_zoomin->setToolTip(tr("Zoom in"));
	//gridLayout->addWidget(button_zoomin, 0, 5, 1, 1);
	rightLayout->addWidget(button_zoomin);
	connect(button_zoomin, SIGNAL(clicked()), this, SLOT(zoomInClicked()));

	// Zoom Slider
	slider_zoom = new QSlider(this);
	slider_zoom->setMinimumSize(QSize(30, 0));
	slider_zoom->setOrientation(Qt::Vertical);
	slider_zoom->setMinimum(1);
	slider_zoom->setMaximum(100);
	slider_zoom->setSingleStep(1);
	slider_zoom->setPageStep(10);
	slider_zoom->setValue(30);
	slider_zoom->setInvertedAppearance(true);
	slider_zoom->setInvertedControls(true);
	slider_zoom->setToolTip(tr("Zoom in/out"));
	//gridLayout->addWidget(slider_zoom, 1, 5, 5, 1);
	rightLayout->addWidget(slider_zoom);
	connect(slider_zoom, SIGNAL(valueChanged(int)), this, SLOT(zoomChanged(int)));

	// ZoomOut Button
	QPushButton *button_zoomout = new QPushButton("-");
	sizePolicy.setHeightForWidth(button_zoomout->sizePolicy().hasHeightForWidth());
	button_zoomout->setSizePolicy(sizePolicy);
	button_zoomout->setFixedSize(QSize(35, 35));
	button_zoomout->setToolTip(tr("Zoom out"));
	//gridLayout->addWidget(button_zoomout, 6, 5, 1, 1);
	rightLayout->addWidget(button_zoomout);
	connect(button_zoomout, SIGNAL(clicked()), this, SLOT(zoomOutClicked()));

	// info label
	info = new QLabel(this);
	gridLayout->addWidget(info, 1, 1);

	// exit button
	QPushButton *button_exit = new QPushButton(this);
	button_exit->setFixedSize(QSize(35, 35));
	button_exit->setToolTip(tr("Exit"));
	QIcon icon7;
	icon7.addPixmap(QPixmap(QString::fromUtf8(":/images/exit.png")), QIcon::Normal, QIcon::Off);
	button_exit->setIcon(icon7);
	gridLayout->addWidget(button_exit, 1, 2);
	connect(button_exit, SIGNAL(clicked()), this, SLOT(close()));

	// Rotate Mode Button
	QPushButton *button_rotate = new QPushButton(this);
	connect(button_rotate, SIGNAL(clicked()), this, SLOT(setRotateMode()));
	button_rotate->setFixedSize(QSize(35, 35));
	QIcon icon;
	icon.addPixmap(QPixmap(QString::fromUtf8(":/images/rotate.png")), QIcon::Normal, QIcon::Off);
	button_rotate->setIcon(icon);
	button_rotate->setAutoExclusive(true);
	button_rotate->setCheckable(true);
	button_rotate->setToolTip(tr("Spin"));
	//gridLayout->addWidget(button_rotate, 0, 0, 1, 1);
	leftLayout->addWidget(button_rotate);

	// Move Mode Button
	QPushButton *button_move = new QPushButton(this);
	button_move->setFixedSize(QSize(35, 35));
	QIcon icon1;
	icon1.addPixmap(QPixmap(QString::fromUtf8(":/images/move.png")), QIcon::Normal, QIcon::Off);
	button_move->setIcon(icon1);
	button_move->setAutoExclusive(true);
	button_move->setCheckable(true);
	button_move->setToolTip(tr("Move"));
	//gridLayout->addWidget(button_move, 1, 0, 1, 1);
	leftLayout->addWidget(button_move);
	connect(button_move, SIGNAL(clicked()), this, SLOT(setMoveMode()));

	// Brush Mode Button
	QPushButton *button_brush = new QPushButton(this);
	button_brush->setFixedSize(QSize(35, 35));
	QIcon icon2;
	icon2.addPixmap(QPixmap(QString::fromUtf8(":/images/brush.png")), QIcon::Normal, QIcon::Off);
	button_brush->setIcon(icon2);
	button_brush->setAutoExclusive(true);
	button_brush->setCheckable(true);
	button_brush->setToolTip(tr("Brush"));
	//gridLayout->addWidget(button_brush, 2, 0, 1, 1);
	leftLayout->addWidget(button_brush);
	connect(button_brush, SIGNAL(clicked()), this, SLOT(setBrushMode()));

	// Info Mode Button
	QPushButton *button_info = new QPushButton(this);
	button_info->setFixedSize(QSize(35, 35));
	QIcon icon3;
	icon3.addPixmap(QPixmap(QString::fromUtf8(":/images/info.png")), QIcon::Normal, QIcon::Off);
	button_info->setIcon(icon3);
	button_info->setAutoExclusive(true);
	button_info->setCheckable(true);
	button_info->setToolTip(tr("Info"));
	//gridLayout->addWidget(button_brush, 2, 0, 1, 1);
	leftLayout->addWidget(button_info);
	connect(button_info, SIGNAL(clicked()), this, SLOT(setInfoMode()));

	QPushButton *button_identify = new QPushButton(this);
	button_identify->setFixedSize(QSize(35, 35));
        QIcon icon8;
        icon8.addPixmap(QPixmap(QString::fromUtf8(":/images/identify.png")), QIcon::Normal, QIcon::Off);
        button_identify->setIcon(icon8);
	button_identify->setAutoExclusive(true);
	button_identify->setCheckable(true);
	button_identify->setToolTip(tr("Identify"));
	//gridLayout->addWidget(button_brush, 2, 0, 1, 1);
	leftLayout->addWidget(button_identify);
	connect(button_identify, SIGNAL(clicked()), this, SLOT(setIdentifyMode()));


	// Spacer
	leftLayout->addStretch(1);

	// item change button
	QPushButton *button_item = new QPushButton(this);
	button_item->setFixedSize(QSize(35, 35));
	QIcon icon6;
	icon6.addPixmap(QPixmap(QString::fromUtf8(":/images/icons.png")), QIcon::Normal, QIcon::Off);
	button_item->setIcon(icon6);
	button_item->setToolTip(tr("Change Item type"));
	leftLayout->addWidget(button_item);
	connect(button_item, SIGNAL(clicked()), this, SLOT(changeIcon()));

	// Spacer
	leftLayout->addStretch(1);

	Aboutwidget *about = new Aboutwidget(this);

	// about S&B Button
	QPushButton *button_sb = new QPushButton(this);
	button_sb->setFixedSize(QSize(35, 35));
	QIcon icon5;
	icon5.addPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")), QIcon::Normal, QIcon::Off);
	button_sb->setIcon(icon5);
	button_sb->setToolTip(tr("About"));
	leftLayout->addWidget(button_sb);
	connect(button_sb, SIGNAL(clicked()), about, SLOT(exec()));

	// about Qt Button
	QPushButton *button_qt = new QPushButton(this);
	button_qt->setFixedSize(QSize(35, 35));
	QIcon icon4;
	icon4.addPixmap(QPixmap(QString::fromUtf8(":/images/qt.png")), QIcon::Normal, QIcon::Off);
	button_qt->setIcon(icon4);
	button_qt->setToolTip(tr("About Qt"));
	//gridLayout->addWidget(button_qt, 6, 0, 1, 1);
	leftLayout->addWidget(button_qt);
	connect(button_qt, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
	
	move(200, 200); // move widget on screen
	
	// Group Widget
        Groupwidget *groupWidget = new Groupwidget(view, this);
	groupWidget->setWindowIcon(icon2);
	connect(button_brush, SIGNAL(toggled(bool)), groupWidget, SLOT(setVisible(bool)));
	connect(groupWidget, SIGNAL(indexChanged(const int &)), view, SLOT(setGroupIndex(const int &)));
	connect(groupWidget, SIGNAL(colorChanged(const int &, const QColor &)), view, SLOT(setColor(const int &, const QColor &)));	

	// Rotate Widget
	Rotatewidget *rotateWidget = new Rotatewidget(view, this);
	rotateWidget->setWindowIcon(icon);
	connect(button_rotate, SIGNAL(toggled(bool)), rotateWidget, SLOT(setVisible(bool)));

	// Identify Widget
        Identifywidget *identifyWidget = new Identifywidget(*n, names, this);
        identifyWidget->setWindowIcon(icon8);
        connect(button_identify, SIGNAL(toggled(bool)), identifyWidget, SLOT(setVisible(bool)));
        connect(identifyWidget, SIGNAL(identify(int)), view, SLOT(identify(int)));


	gridLayout->addLayout(leftLayout, 0, 0);
	gridLayout->addWidget(view, 0, 1);
	gridLayout->addLayout(rightLayout, 0, 2);
	setLayout(gridLayout);
        setWindowTitle(tr("Spin & Brush"));
	setWindowIcon(icon5);

	button_rotate->click(); // click() instead of setChecked(true) ist used to emit signal 
	connect(view, SIGNAL(zoomChanged(int)), slider_zoom, SLOT(setValue(int)));

	Legendwidget *legend = new Legendwidget(colnames, this);
	legend->show();
}


void Spinwidget::zoomChanged(int value) {

	float fval = (float)value;
	view->changeZoom(fval);
}

void Spinwidget::zoomInClicked() {

	slider_zoom->setValue(slider_zoom->value() - 1);
}

void Spinwidget::zoomOutClicked() {

	slider_zoom->setValue(slider_zoom->value() + 1);
}

void Spinwidget::setRotateMode() {

	view->setMode(Spinview::Rotate);
	view->setCursor(Qt::ArrowCursor);
	info->setText(tr("Push a mouse button and drag the mouse over the scene to rotate it.\n"));
}

void Spinwidget::setMoveMode() {

	view->setMode(Spinview::Move);
	view->setCursor(Qt::OpenHandCursor);
	info->setText(tr("Move the scene by dragging the mouse over it.\n"));
}

void Spinwidget::setBrushMode() {

	view->setMode(Spinview::Brush);
	info->setText(tr("Choose a color, a group and a cursor size from the menu.\nSelect a point with the left mouse button. Deselect it with the right button."));
}

void Spinwidget::setInfoMode() {

	view->setMode(Spinview::Info);
	view->setCursor(Qt::ArrowCursor);
	info->setText(tr("Select an item to open the info dialog.\n"));
}

void Spinwidget::setIdentifyMode() {

	view->setMode(Spinview::Identify);
	view->setCursor(Qt::ArrowCursor);
	info->setText(tr("Select a label to identify the item.\n"));
}

void Spinwidget::changeIcon() {

		Icondialog icondialog(this);
		if(icondialog.exec()) {
			Iconview *iv = static_cast<Iconview *>(icondialog.focusWidget());
			view->changeIcon(iv->getIcon());
		}
}
