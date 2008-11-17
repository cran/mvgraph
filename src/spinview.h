#ifndef SPINVIEW_H
#define SPINVIEW_H

#include <QWidget>
#include <QSize>
#include <QPoint>
#include <QCursor>
#include <QColor>
#include <QProgressDialog>
#include <QtOpenGL>
#include <QGLWidget>
#include "iconview.h"
#include "infowidget.h"

class Spinview : public QGLWidget {

	Q_OBJECT

	public:
                Spinview(double *x = 0, double *y = 0, double *z = 0, int *n = 0, int *groups = 0, double *max = 0, Iconview::Icon icon = Iconview::Cross, char** names = 0, char** colnames = 0, int* cols = 0, QWidget *parent = 0);
		~Spinview();

                enum Mode { Rotate, Move, Brush, Info, Identify };

		QSize minimumSizeHint() const;
		QSize sizeHint() const;
		
		int getRotationX() const { return rotation_x; }
		int getRotationY() const { return rotation_y; }
		int getRotationZ() const { return rotation_z; }
                QColor getColors(int i) const { return myColors[i]; }

		Mode getMode() const { return mode; }
		void setMode(Mode new_mode);
		
		int getPickSize() const { return pickSize; }
		void setPickSize(int new_size);
		
	public slots:
		void rotateX(int angle);
		void rotateY(int angle);
		void rotateZ(int angle);
		void autoRotate();
		void autoRotateX();
		void autoRotateY();
		void autoRotateZ();
		void changeZoom(int newZoom);
                void changeIcon(Iconview::Icon icon);
                void identify(int index);
		void setGroupIndex(const int &new_index);
                void setColor(const int &new_index, const QColor &color);
                void blink();

	signals:
		void xRotationChanged(int angle);
		void yRotationChanged(int angle);
		void zRotationChanged(int angle);
		void zoomChanged(int zoom);

	protected:
		void initializeGL();
		void paintGL();
		void resizeGL(int width, int height);
		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);
		void wheelEvent(QWheelEvent *event);

	private:
		GLuint drawPoints();
		GLuint drawAxes();
		void drawTargets();
		double calculateMaximum();
		void normalizeAngle(int *angle);
		void setProjectionMatrix(int width, int height);
		void selectPoints(int x, int y, bool left);

		Iconview::Icon myIcon;
		GLuint points;
		GLuint axes;
		bool *selected;
		double *xPoints;
		double *yPoints;
		double *zPoints;
		double maximum;
		int *col;
		int rotation_x;
		int rotation_y;
		int rotation_z;
		int size;
		int pickSize;
		int groupIndex;
		float zoom;
		float xPos;
		float yPos;
		QPoint latestPosition;
		QColor background;
		QColor myColors[6];
                Mode mode;
                QTimer *identify_timer;
                bool identify_trigger;
                int identify_index;
                char** names;
                char** colnames;
                int *cols;
};

#endif
