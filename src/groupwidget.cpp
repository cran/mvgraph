#include "groupwidget.h"

Groupwidget::Groupwidget(Spinview *sv, QWidget *parent) : QDialog(parent) {
	
	// Save pointer to Spinview and Spinwidget
	spinView = sv;

	// QGroupBoxes
	QGroupBox *left = new QGroupBox(tr("Groups"), this);
	QGroupBox *right = new QGroupBox(tr("Size"), this);

	// Layouts
	hLayout = new QHBoxLayout(this);
	QGridLayout *gridLayout= new QGridLayout(left);
	QHBoxLayout *rightHLayout = new QHBoxLayout(right);

	// Signal Mappers
	buttonMapper = new QSignalMapper(this);
	radioMapper = new QSignalMapper(this);
	
	// RadioButtons, ColorButtons
	for(int i=0; i<6; i++) {
	
                myColors[i] = spinView->getColors(i);
		
		QRadioButton *radio = new QRadioButton(tr("Group %1:").arg(QString::number(i+1)), this);
		if(!i) 
			radio->setChecked(true);
		radioMapper->setMapping(radio, i);
		connect(radio, SIGNAL(clicked()), radioMapper, SLOT(map()));
		gridLayout->addWidget(radio, i, 0);
		myRadios[i] = radio;
		
		QPushButton *button = new QPushButton("", this);
		button->setStyleSheet(tr(
			"QPushButton { border: 2px solid black; border-radius: 5px; background-color: rgb(") +
            		QString::number(myColors[i].red()) + tr(",") +
            		QString::number(myColors[i].green()) + tr(",") +
            		QString::number(myColors[i].blue()) + tr("); }"));
		buttonMapper->setMapping(button, i);
		connect(button, SIGNAL(clicked()), buttonMapper, SLOT(map()));
		gridLayout->addWidget(button, i, 1);
		myButtons[i] = button;
	}
	
    	connect(radioMapper, SIGNAL(mapped(const int &)), this, SLOT(groupClicked(const int &)));
    	connect(buttonMapper, SIGNAL(mapped(const int &)), this, SLOT(buttonClicked(const int &)));
	
	left->setLayout(gridLayout);

	// Cursor Pixmaps
	cursors[0] = QPixmap(":/images/cursor04.png");
	cursors[1] = QPixmap(":/images/cursor08.png");
	cursors[2] = QPixmap(":/images/cursor16.png");
	cursors[3] = QPixmap(":/images/cursor24.png");
	cursors[4] = QPixmap(":/images/cursor36.png");
	cursors[5] = QPixmap(":/images/cursor48.png");

	// Cursor List Widget
	listWidget = new QListWidget(this);
	listWidget->insertItem(0, new QListWidgetItem(QIcon(cursors[0]), tr("tiny")));	
	listWidget->insertItem(1, new QListWidgetItem(QIcon(cursors[1]), tr("small")));	
	listWidget->insertItem(2, new QListWidgetItem(QIcon(cursors[2]), tr("medium")));	
	listWidget->insertItem(3, new QListWidgetItem(QIcon(cursors[3]), tr("large")));
	listWidget->insertItem(4, new QListWidgetItem(QIcon(cursors[4]), tr("very large")));
	listWidget->insertItem(5, new QListWidgetItem(QIcon(cursors[5]), tr("huge")));
	listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	listWidget->setIconSize(QSize(64,64));
	rightHLayout->addWidget(listWidget);
	right->setLayout(rightHLayout);
	connect(listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(currentIconChanged(int)));

	hLayout->addWidget(left);
	hLayout->addWidget(right);
	
	setLayout(hLayout);
	setWindowTitle(tr("Brush"));
	
	widget_pos = parentWidget()->pos() + QPoint(parentWidget()->width(), 0);
}

void Groupwidget::groupClicked(const int &index) {
	
	emit indexChanged(index); // inform view about change
}

void Groupwidget::buttonClicked(const int &index) {
	
	QColor new_color = QColorDialog::getColor(myColors[index], this);
	if(new_color.isValid()) {
		myButtons[index]->setStyleSheet(tr(
			"QPushButton { border: 2px solid black; border-radius: 5px; background-color: rgb(") +
            		QString::number(new_color.red()) + tr(",") +
            		QString::number(new_color.green()) + tr(",") +
            		QString::number(new_color.blue()) + tr("); }"));
		myRadios[index]->click();
		myColors[index] = new_color;
		emit colorChanged(index, new_color); // inform view about change
	}
}

void Groupwidget::currentIconChanged(int index) {

	if(index  < 0) {
		index = 0;
		listWidget->setCurrentRow(0);
	}
	spinView->setCursor(QCursor(cursors[index]));
	spinView->setPickSize(cursors[index].width());
}

void Groupwidget::showEvent(QShowEvent */*event*/) {

	// make sure cursor appears, when no index changed
	int index = listWidget->currentRow();
	if(index  < 0) {
		index = 0;
		listWidget->setCurrentRow(0);
	}
	spinView->setCursor(QCursor(cursors[index]));
	spinView->setPickSize(cursors[index].width());

	// move to the side; otherwise would be displayed in middle of parent
	move(widget_pos);
}

void Groupwidget::moveEvent(QMoveEvent *event) {
	
	widget_pos = event->pos();
}
