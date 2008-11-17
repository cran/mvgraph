#include "iconview.h"

Iconview::Iconview(int type, QWidget *parent) : QGLWidget(parent) {

	setFocusPolicy(Qt::StrongFocus);

	// sets the icon type
	if(type == 0) setIcon(Dot); 
	else if(type == 1) setIcon(Cross); 
	else if(type == 2) setIcon(Oktaeder_contour); 
	else if(type == 3) setIcon(Oktaeder);
	else if(type == 4) setIcon(Sphere_contour); 
	else if(type == 5) setIcon(Sphere); 
	rotation = 0;
	zoom = 10.0;
	background = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
	foreground = Qt::black;

	// QTimers for animation
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(rotate()));
	timer->start(5);
	zoomInTimer = new QTimer(this);
	connect(zoomInTimer, SIGNAL(timeout()), this, SLOT(zoomIn()));
	zoomOutTimer = new QTimer(this);
	connect(zoomOutTimer, SIGNAL(timeout()), this, SLOT(zoomOut()));

	setAttribute(Qt::WA_NoSystemBackground);
}

Iconview::~Iconview() {

	makeCurrent();
	glDeleteLists(point, 1);
}

void Iconview::setIcon(const Icon &new_icon) {

	icon = new_icon;
}

QSize Iconview::minimumSizeHint() const {

	return QSize(50, 50);
}

QSize Iconview::sizeHint() const {

	return QSize(120, 120);
}

void Iconview::initializeGL() {

	point = drawPoint(); // draw the icon
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void Iconview::paintGL() {

	if(hasFocus())
		qglClearColor(background); // clear and set background
	else
		qglClearColor(Qt::white); // clear and set background

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0.0, 0.0, -1.0); // move one unit down the z-axis
	int side = qMin(width(), height());
	setProjectionMatrix(side, side); // set perspective
	glRotated(rotation, 1.0, 1.0, 0.0); // rotate object
	glCallList(point); // call display list

}

void Iconview::resizeGL(int width, int height) {

	int side = qMin(width, height);
	glViewport((width - side) / 2, (height - side) / 2, side, side);
}

GLuint Iconview::drawPoint()
{
	glMatrixMode(GL_MODELVIEW);
	GLuint list = glGenLists(1);
	glNewList(list, GL_COMPILE);
	GLUquadric *q = gluNewQuadric();
	

	if( icon == Dot) {
		qglColor(foreground);
		gluSphere(q, 0.002, 10, 10);
	}
	else if( icon == Cross) {
		glBegin(GL_LINES);
		qglColor(foreground);
		glVertex3d(-0.01, 0, 0);
		glVertex3d(0.01, 0, 0);
		glVertex3d(0, -0.01, 0);
		glVertex3d(0, 0.01, 0);
		glVertex3d(0, 0, -0.01);
		glVertex3d(0, 0, 0.01);
		glEnd();
	}
	else if( icon == Oktaeder_contour) {
		qglColor(foreground);
		gluQuadricDrawStyle(q, GLU_SILHOUETTE);
		gluSphere(q, 0.01, 4, 2);
	}
	else if( icon == Sphere_contour ) {
		qglColor(foreground);
		gluQuadricDrawStyle(q, GLU_SILHOUETTE);
		gluSphere(q, 0.01, 10, 10);
	}
	else if( icon == Oktaeder ) {
		qglColor(foreground);
		gluSphere(q, 0.01, 4, 2);
	}
	else if( icon == Sphere ) {
		qglColor(foreground);
		gluSphere(q, 0.01, 10, 10);
	}
	gluDeleteQuadric(q);
	glEndList();
	return list;
}

void Iconview::setProjectionMatrix(int width, int height) { 
	
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(zoom, (float)width/(float)height, 10, 0);
	glMatrixMode(GL_MODELVIEW);
}

void Iconview::rotate() {

	rotation++;
	if( rotation == 360) 
		rotation = 0;
	updateGL();
}

void Iconview::focusInEvent(QFocusEvent *event) {

	if(event->gotFocus()){
		zoomInTimer->start(1);
		zoomOutTimer->stop();
		updateGL();
	}
}

void Iconview::focusOutEvent(QFocusEvent *event) {

	if(event->lostFocus()){
		zoomOutTimer->start(1);
		zoomInTimer->stop();
		updateGL();
	}
}

void Iconview::zoomIn() {

	if (zoom > 2.0) {
		zoom -= 0.02;
	}
	else {
		zoomInTimer->stop();
	}
	updateGL();
}

void Iconview::zoomOut() {

	if (zoom < 10.0) {
		zoom += 0.02;
	}
	else {
		zoomOutTimer->stop();
	}
	updateGL();
}
