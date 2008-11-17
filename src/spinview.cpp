#include <math.h>
#include "spinview.h"
#include <QDebug>

#define _BLINK_INTERVAL_ 200

Spinview::Spinview(double *x, double *y, double *z, int *n, int *groups, double *max, Iconview::Icon icon, char** names, char** colnames, int* cols, QWidget *parent) : QGLWidget(parent) {

	points = 0;
	rotation_x = 0;
	rotation_y = 0;
	rotation_z = 0;
        groupIndex = 1;
        identify_index = -1;
        identify_trigger = false;
        this->names = names;
        this->colnames = colnames;

	background = QColor(Qt::white);
	
	xPoints = x;
	yPoints = y;
	zPoints = z;
        col = groups;
	size = *n;
	xPos = 0.0;
	yPos = 0.0;
	zoom = 30.0;
	
	mode = Rotate;

        this->cols = cols;
        myColors[0] = QColor(cols[0], cols[1], cols[2]);
        myColors[1] = QColor(cols[3], cols[4], cols[5]);
        myColors[2] = QColor(cols[6], cols[7], cols[8]);
        myColors[3] = QColor(cols[9], cols[10], cols[11]);
        myColors[4] = QColor(cols[12], cols[13], cols[14]);
        myColors[5] = QColor(cols[15], cols[16], cols[17]);
	
	myIcon = icon;
        maximum = *max;

        identify_timer = new QTimer(this);
        connect(identify_timer, SIGNAL(timeout()), this, SLOT(blink()));
}

Spinview::~Spinview() {

	makeCurrent();
	glDeleteLists(points, 1);
}

QSize Spinview::minimumSizeHint() const {

	return QSize(50, 50);
}

QSize Spinview::sizeHint() const {

	return QSize(400, 400);
}

void Spinview::rotateX(int angle) {

	normalizeAngle(&angle);
	if (angle != rotation_x) {
		rotation_x = angle;
		emit xRotationChanged(angle);
		updateGL();
	}
}

void Spinview::rotateY(int angle) {

	normalizeAngle(&angle);
	if (angle != rotation_y) {
		rotation_y = angle;
		emit yRotationChanged(angle);
		updateGL();
	}
}

void Spinview::rotateZ(int angle) {

	normalizeAngle(&angle);
	if (angle != rotation_z) {
		rotation_z = angle;
		emit zRotationChanged(angle);
		updateGL();
	}
}

void Spinview::initializeGL() {

	qglClearColor(background);
	axes = drawAxes();
	points = drawPoints();
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void Spinview::paintGL() {
	
	int side = qMin(width(), height());

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(xPos, yPos, -5.0);
	setProjectionMatrix(side, side);
	glRotated(rotation_x / 16.0, 1.0, 0.0, 0.0);
	glRotated(rotation_y / 16.0, 0.0, 1.0, 0.0);
	glRotated(rotation_z / 16.0, 0.0, 0.0, 1.0);
	glCallList(axes);
	glCallList(points);
	//glPushMatrix();
}

void Spinview::resizeGL(int width, int height) {

	int side = qMin(width, height);
	glViewport((width - side) / 2, (height - side) / 2, side, side);
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.5, +0.5, +0.5, -0.5, 4.0, 15.0);
	glMatrixMode(GL_MODELVIEW);*/
}

void Spinview::mousePressEvent(QMouseEvent *event) {

	latestPosition = event->pos();
	if( mode == Move ) {
		setCursor(Qt::ClosedHandCursor);
	}
	else if ( mode == Brush || mode == Info) {
		selectPoints(event->x(), event->y(), event->buttons() & Qt::LeftButton);
	}

}

void Spinview::mouseMoveEvent(QMouseEvent *event) {
    
	int x = event->x();
	int y = event->y(); 
	int dx = x - latestPosition.x();
	int dy = y - latestPosition.y();
	
	if( mode == Rotate ) {
		if (event->buttons() & Qt::LeftButton) {
			rotateX(rotation_x + 8 * dy);
			rotateY(rotation_y + 8 * dx);
		}
		else if (event->buttons() & Qt::RightButton) {
			rotateX(rotation_x + 8 * dy);
			rotateZ(rotation_z + 8 * dx);
		}
	}
	else if ( mode == Move ) {
                xPos += ((float) dx)/((float) (5000.0/zoom));
                yPos -= ((float) dy)/((float) (5000.0/zoom));
		updateGL();
	}
	else if ( mode == Brush) {
		selectPoints(x, y, event->buttons() & Qt::LeftButton);
	}
	latestPosition = event->pos();
}

void Spinview::mouseReleaseEvent(QMouseEvent * /*event*/) {

	if( mode == Move ) 
		setCursor(Qt::OpenHandCursor);
}

void Spinview::selectPoints(int x, int y, bool left) {
	
	GLint viewport[4];
	GLuint myBuffer[40000];
	
	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(40000, myBuffer);

	(void) glRenderMode(GL_SELECT);
		
	glInitNames();
	glPushName(0);
 	
 	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	
	if(mode == Brush) 
		gluPickMatrix((GLdouble) x, (GLdouble) (viewport[3]-y), (GLfloat) pickSize, (GLfloat) pickSize, viewport);
	else if( mode == Info )
		gluPickMatrix((GLdouble) x, (GLdouble) (viewport[3]-y), 1.0, 1.0, viewport);
	gluPerspective(zoom, 1.0f, 10.0f, 0.0f);
	drawTargets();	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	
	glFlush();
	GLint anzahl = glRenderMode(GL_RENDER);
	if( mode == Brush) {
		for(int i = 0; i < anzahl; i++) {
				col[myBuffer[4*i+3]-1] = left*groupIndex;
		}
		initializeGL();
		updateGL();
	}
	else if ( mode == Info ) {
		int *index = (int *) malloc(sizeof(int)*anzahl);
		for(int i = 0; i < anzahl; i++) {
				index[i] = myBuffer[4*i+3];
		}
		if(anzahl) {
                        Infowidget infoWidget(anzahl, index, xPoints, yPoints, zPoints, maximum, names, colnames, this);
			infoWidget.exec();
		}
	}
}

void Spinview::wheelEvent(QWheelEvent *event) {

	float numDegrees = event->delta() / 8;
	float numSteps = numDegrees / 15;
	float newZoom = zoom - numSteps;
	changeZoom(newZoom);
	event->accept();
}

void Spinview::changeZoom(int newZoom) {

	if( newZoom >= 1 && newZoom <= 100 && zoom != newZoom) {
		zoom = newZoom;
		emit zoomChanged(zoom);
		updateGL();
	}
}

GLuint Spinview::drawAxes() {
	
	glMatrixMode(GL_MODELVIEW);
	GLuint axes = glGenLists(1);
	glNewList(axes, GL_COMPILE);
	
	glBegin(GL_LINES);
	qglColor(QColor(255, 0, 0));
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);

	qglColor(QColor(0, 255, 0));
	glVertex3d(0, 0, 0);
	glVertex3d(0, 1, 0);

	qglColor(QColor(0, 0, 255));
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 1);
	glEnd();
	
	glEndList();
	return axes;
}

GLuint Spinview::drawPoints()
{
	QCursor cursor = this->cursor();
	QProgressDialog progress("Processing data ...", 0, 0, size, this);
	progress.setWindowModality(Qt::WindowModal);
	progress.setMinimumDuration(500);

	glMatrixMode(GL_MODELVIEW);
	GLuint list = glGenLists(1);
	glNewList(list, GL_COMPILE);
	
	GLUquadric *q = gluNewQuadric();

	for (int i = 0; i < size; i++) {
		progress.setValue(i);
		if(myIcon == Iconview::Dot) {
			if(col[i])
				qglColor(myColors[col[i]-1]);
			else
                                qglColor(QColor(0, 0, 0));
                        if(i == identify_index && identify_trigger) {
                                qglColor(QColor(255, 255, 255));
                        }
			glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluSphere(q, 0.005, 20, 20);
			glPopMatrix();
		}
		else if(myIcon == Iconview::Cross) {
			glBegin(GL_LINES);
			if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));
                        if(i == identify_index && identify_trigger) {
                                qglColor(QColor(255, 255, 255));
                        }
                        glVertex3d(xPoints[i]-0.03, yPoints[i], zPoints[i]);
			glVertex3d(xPoints[i]+0.03, yPoints[i], zPoints[i]);
			glVertex3d(xPoints[i], yPoints[i]-0.03, zPoints[i]);
			glVertex3d(xPoints[i], yPoints[i]+0.03, zPoints[i]);
			glVertex3d(xPoints[i], yPoints[i], zPoints[i]-0.03);
			glVertex3d(xPoints[i], yPoints[i], zPoints[i]+0.03);
			glEnd();
		}
		else if(myIcon == Iconview::Oktaeder_contour) {
			if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));
                        if(i == identify_index && identify_trigger) {
                                qglColor(QColor(255, 255, 255));
                        }
                        glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluQuadricDrawStyle(q, GLU_SILHOUETTE);
			gluSphere(q, 0.02, 4, 2);
			glPopMatrix();
		}
		else if(myIcon == Iconview::Sphere_contour) {
			if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));
                        if(i == identify_index && identify_trigger) {
                                qglColor(QColor(255, 255, 255));
                        }
                        glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluQuadricDrawStyle(q, GLU_SILHOUETTE);
			gluSphere(q, 0.02, 10, 10);
			glPopMatrix();
		}
		else if(myIcon == Iconview::Oktaeder) {
			if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));
                        if(i == identify_index && identify_trigger) {
                                qglColor(QColor(255, 255, 255));
                        }
                        glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluSphere(q, 0.02, 4, 2);
			glPopMatrix();
		}
		else if(myIcon == Iconview::Sphere) {
			if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));
                        if(i == identify_index && identify_trigger) {
                                qglColor(QColor(255, 255, 255));
                        }
                        glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluSphere(q, 0.02, 10, 10);
			glPopMatrix();
		}
	}
	
	glEndList();
	progress.setValue(size);
	setCursor(cursor);
	return list;
}

void Spinview::drawTargets() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(xPos, yPos, -5.0);
	glRotated(rotation_x / 16.0, 1.0, 0.0, 0.0);
	glRotated(rotation_y / 16.0, 0.0, 1.0, 0.0);
	glRotated(rotation_z / 16.0, 0.0, 0.0, 1.0);
	GLUquadric *q = gluNewQuadric();
	
	for (int i = 0; i < size; i++) {
		glLoadName(i+1);
		if(myIcon == Iconview::Dot) {
			/*if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));*/
			glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluSphere(q, 0.005, 20, 20);
			glPopMatrix();
		}
		else if(myIcon == Iconview::Cross) {
			glBegin(GL_LINES);
			/*if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));*/
			glVertex3d(xPoints[i]-0.03, yPoints[i], zPoints[i]);
			glVertex3d(xPoints[i]+0.03, yPoints[i], zPoints[i]);
			glVertex3d(xPoints[i], yPoints[i]-0.03, zPoints[i]);
			glVertex3d(xPoints[i], yPoints[i]+0.03, zPoints[i]);
			glVertex3d(xPoints[i], yPoints[i], zPoints[i]-0.03);
			glVertex3d(xPoints[i], yPoints[i], zPoints[i]+0.03);
			glEnd();
		}
		else if(myIcon == Iconview::Oktaeder_contour) {
			/*if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));*/
			glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluQuadricDrawStyle(q, GLU_SILHOUETTE);
			gluSphere(q, 0.02, 4, 2);
			glPopMatrix();
		}
		else if(myIcon == Iconview::Sphere_contour) {
			/*if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));*/
			glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluQuadricDrawStyle(q, GLU_SILHOUETTE);
			gluSphere(q, 0.02, 10, 10);
			glPopMatrix();
		}
		else if(myIcon == Iconview::Oktaeder) {
			/*if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));*/
			glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluSphere(q, 0.02, 4, 2);
			glPopMatrix();
		}
		else if(myIcon == Iconview::Sphere) {
			/*if(col[i])
				qglColor(myColors[col[i]-1]);
			else
				qglColor(QColor(0, 0, 0));*/
			glPushMatrix();
			glTranslated(xPoints[i], yPoints[i], zPoints[i]);
			gluSphere(q, 0.02, 10, 10);
			glPopMatrix();
		}
	}
}

void Spinview::normalizeAngle(int *angle) {

	while (*angle < 0)
		*angle += 360 * 16;
	while (*angle > 360 * 16)
		*angle -= 360 * 16;
}


void Spinview::setProjectionMatrix(int width, int height) { 
	
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(zoom, (float)width/(float)height, 10, 0);
	glMatrixMode(GL_MODELVIEW);
}

void Spinview::setMode(Mode new_mode) {

	mode = new_mode;
}

void Spinview::setPickSize(int new_size) {

	pickSize = new_size;	
}

void Spinview::setGroupIndex(const int &new_index) {
	
	groupIndex = new_index+1;
}

void Spinview::setColor(const int &index, const QColor &color) {
	
        myColors[index] = color;
        cols[index*3] = color.red();
        cols[index*3+1] = color.green();
        cols[index*3+2] = color.blue();
        initializeGL();
	updateGL();
}

void Spinview::autoRotate() {
	
	for(int i = 0; i < 5; i++) {
		int x = rand() % 2;
		if(x) {
			rotation_x += 1;
			normalizeAngle(&rotation_x);
		}
		int y = rand() % 2;
		if(y) {
			rotation_y += 1;
			normalizeAngle(&rotation_y);
		}
		int z = rand() % 2;
		if(z) { 
			rotation_z += 1;
			normalizeAngle(&rotation_z);
		}
		updateGL();
	}
}


void Spinview::autoRotateX() {
	
}

void Spinview::autoRotateY() {
	
}

void Spinview::autoRotateZ() {
		
}

void Spinview::changeIcon(Iconview::Icon icon) {

	if(myIcon != icon) {
		myIcon = icon;
		initializeGL();
		updateGL();
		initializeGL();
		updateGL();
        }
}

void Spinview::identify(int index) {

    if(index >= 0) {
        identify_timer->start(_BLINK_INTERVAL_);
        identify_index = index;
    }
    else {
        identify_timer->stop();
        identify_index = -1;
        if(identify_trigger)
            blink();
    }
}

void Spinview::blink() {

    identify_trigger = !identify_trigger;
    initializeGL();
    updateGL();
}
