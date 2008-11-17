#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>
#include "ui_select.h"

class Selectdialog : public QDialog, Ui::Select {

	Q_OBJECT

	public:
                Selectdialog(char** varnames = 0, int* selected=0, int *k = 0, int *ok = 0,  QWidget *parent = 0);

	private:
		int count;
		int *selected;
                int *k;
                int *ok;

	private slots:
		void on_button_add_clicked();
                void on_button_remove_clicked();
                void setOk(int result);
};

#endif
