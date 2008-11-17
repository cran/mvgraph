#ifndef INFOWIDGET_H
#define IFNOWIDGET_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QGroupBox>
#include <QDebug>

class Infowidget : public QDialog {

	Q_OBJECT

	public:
                Infowidget(int size = 0, int *index = 0, double *x = 0, double *y = 0, double *z = 0, double max = 0, char** names = 0, char** colnames = 0, QWidget *parent = 0);

	private: 
		QLabel *label_cX;
		QLabel *label_cY;
		QLabel *label_cZ;
		double *myX;
		double *myY;
		double *myZ;
		int *myIndex;
		double maximum;

	private slots:
		void fillFields(int index);
};

#endif
