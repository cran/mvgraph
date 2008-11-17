#ifndef SPINWIDGET_H
#define SPINWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include "spinview.h"
#include "icondialog.h"
#include "groupwidget.h"
#include "rotatewidget.h"
#include "aboutwidget.h"
#include "identifywidget.h"
#include "legendwidget.h"

class Spinwidget : public QWidget {

	Q_OBJECT

	public:
                Spinwidget(double *x = 0, double *y = 0, double *z = 0, int *n = 0, int *colors = 0, int* cols=0, double *max = 0, char** names = 0, char** colnames = 0, QWidget *parent = 0);
		
	private:
		QGridLayout *gridLayout;
		Spinview *view;
		QSlider *slider_zoom;
		QLabel *info;
		
	private slots:
		void zoomChanged(int value);
		void zoomInClicked();
		void zoomOutClicked();
		void setRotateMode();
		void setMoveMode();
		void setBrushMode();
                void setInfoMode();
                void setIdentifyMode();
		void changeIcon();
};

#endif
