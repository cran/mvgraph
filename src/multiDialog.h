#ifndef MULTIDIALOG_H
#define MULTIDIALOG_H

#include <QDialog>
#include "ui_multigraph.h"

class MultiDialog : public QDialog, public Ui::MultiGraph {

        Q_OBJECT

        public:
            MultiDialog(int *k = 0, char** varnames = 0, int *selected = 0, int *xC = 0, int *yC = 0, int *add = 0, int *labels = 0, int *index = 0, int *simple = 0, int *boardered = 0, int *diamonds = 0, int *ok = 0, QWidget *parent = 0);

        private:
                int *selected;
                int *k;
                int *xC;
                int *yC;
                int *add;
                int *labels;
                int *myIndex;
                int *simple;
                int *boardered;
                int *diamonds;
                int *ok;

                QPixmap pm_simple;
                QPixmap pm_boardered;
                QPixmap pm_diamonds;

        private slots:
                void on_button_add_clicked();
                void on_button_remove_clicked();
                void xC_currentIndexChanged(int index);
                void yC_currentIndexChanged(int index);
                void on_checkBox_add_stateChanged(int state);
                void on_checkBox_labels_stateChanged(int state);
                void on_radioButton_simple_toggled(bool checked);
                void on_radioButton_boardered_toggled(bool checked);
                void on_radioButton_diamonds_toggled(bool checked);
                void on_tabWidget_currentChanged(int index);
                void setOk(int result);
};

#endif
