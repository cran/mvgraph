#ifndef GROUPWIDGET_H
#define GROUPWIDGET_H

#include <QDialog>
#include <QTimer>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QSignalMapper>
#include <QColorDialog>
#include <QSize>
#include <QShowEvent>
#include <QDebug>
#include "spinview.h"

class Groupwidget : public QDialog {

	Q_OBJECT

	public:
                Groupwidget(Spinview *sv, QWidget *parent = 0);

	protected:
		void showEvent(QShowEvent *event);
		void moveEvent(QMoveEvent *event);
		
	signals:
		void indexChanged(const int &index);
		void colorChanged(const int &index, const QColor &color);
		
	private:
		Spinview *spinView;
		QHBoxLayout *hLayout;
		QSignalMapper *buttonMapper;
		QSignalMapper *radioMapper;
		QColor myColors[6];
		QPushButton *myButtons[6];
		QRadioButton *myRadios[6];
		QPixmap cursors[6];
		QListWidget *listWidget;
		QPoint widget_pos;
		
	private slots:
		void groupClicked(const int &index);
		void buttonClicked(const int &index);
		void currentIconChanged(int index);
};

#endif
