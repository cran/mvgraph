#ifndef ROTATEWIDGET_H
#define ROTATEWIDGET_H

#include <QDialog>
#include "spinview.h"

class Rotatewidget : public QDialog {

	Q_OBJECT

	public:
		Rotatewidget(Spinview *sv = 0, QWidget *parent = 0);

	protected:
		void showEvent(QShowEvent *event);
		void moveEvent(QMoveEvent *event);
		
	private:
		Spinview *spinView; // pointer to the view
		QTimer *timer; // timer for auto rotation
		QTimer *timerX; // timer for x rotation
		QTimer *timerY; // timer for y rotation
		QTimer *timerZ; // timer for z rotation
		QSlider *slider_velocity; // holds rotation velocity
		QPushButton *button_x; // button for x rotation
		QPushButton *button_y; // button for y rotation
		QPushButton *button_z; // button for z rotation
		QPoint widget_pos; // holds widgets position

	private slots:
		void rotateAuto(int state);
		void rotateX(bool toggled);
		void rotateY(bool toggled);
		void rotateZ(bool toggled);
		void velocityChanged(int value);
};

#endif
