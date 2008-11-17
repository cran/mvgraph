#ifndef ICONVIEW_H
#define ICONVIEW_H

#include <QtOpenGL>
#include <QGLWidget>
#include <QDebug>

class Iconview : public QGLWidget {

	Q_OBJECT

	public:
		Iconview(int type = 0, QWidget *parent = 0); // constructor
		~Iconview(); // destructor

		enum Icon { Dot = 0, Cross = 1, Oktaeder_contour = 2, Oktaeder = 3, Sphere_contour = 4, Sphere = 5 }; // icon type enum
		
		QSize minimumSizeHint() const; // geometry hint
		QSize sizeHint() const; // geometry hint

		Icon getIcon() const { return icon; } // getter; inline
		void setIcon(const Icon &new_icon); // setter

	protected:
		void initializeGL(); // openGL function, called once at beginning
		void paintGL(); // openGL function, called, when updateGL() is called
		void resizeGL(int width, int height); // resets the viewport
		void focusInEvent(QFocusEvent *event); // executed when selecting widget
		void focusOutEvent(QFocusEvent *event); // executed when deselecting widget

	private:
		GLuint drawPoint(); // draws the icon
		void setProjectionMatrix(int width, int height); // sets the projection matrix

		QColor background; // holds the background color
		QColor foreground; // holds item color on focus
		GLuint point; // holds the display list
		Icon icon; // holds the displayed openGL icon
		int rotation; // holds the rotation value
		float zoom; // holds the zoom value 

		QTimer *zoomInTimer; // timer for zooming in on focus
		QTimer *zoomOutTimer; // timer for zooming out on focus lost

	private slots:
		void rotate(); // rotation slot
		void zoomIn(); // zoom in slot
		void zoomOut(); // zoom out slot
};

#endif
