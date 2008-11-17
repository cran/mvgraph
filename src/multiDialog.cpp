#include "multiDialog.h"
#include <QDebug>

MultiDialog::MultiDialog(int* k, char** varnames, int *selected, int *xC, int *yC, int *add, int *labels, int *index, int *simple, int *boardered, int *diamonds, int *ok, QWidget *parent) : QDialog(parent) {

        setupUi(this);

        // save pointer
        this->selected = selected;
        this->k = k;
        this->xC = xC;
        this->yC = yC;
        this->add = add;
        this->labels = labels;
        this->myIndex = index;
        this->simple = simple;
        this->boardered = boardered;
        this->diamonds = diamonds;
        this->ok = ok;
        this->myIndex = index;

        // load pixmaps
        pm_simple.load(":/images/simple.png");
        pm_boardered.load(":/images/boardered.png");
        pm_diamonds.load(":/images/diamond.png");

        // set comboBoxes and radio buttons
        checkBox_add->setChecked(*add);
        checkBox_labels->setChecked(*labels);
        radioButton_simple->setChecked(*simple);
        radioButton_boardered->setChecked(*boardered);
        radioButton_diamonds->setChecked(*diamonds);

        tabWidget->setCurrentIndex(*myIndex);

        // populate list widgets and comboBoxes
        for(int i=0; i<*k; i++) {
                QListWidgetItem *item_l = new QListWidgetItem(QString::fromUtf8(varnames[i]));
                listWidget_left->addItem(item_l);

                QListWidgetItem *item_r = new QListWidgetItem(QString::fromUtf8(varnames[i]));
                listWidget_right->addItem(item_r);
                item_r->setHidden(true);

                comboBox_xC->addItem(QString::fromUtf8(varnames[i]));
                comboBox_yC->addItem(QString::fromUtf8(varnames[i]));
        }
        connect(comboBox_xC, SIGNAL(currentIndexChanged(int)), this, SLOT(xC_currentIndexChanged(int)));
        connect(comboBox_yC, SIGNAL(currentIndexChanged(int)), this, SLOT(yC_currentIndexChanged(int)));
        if(*k > 1) {
                comboBox_xC->setCurrentIndex(*xC - 1);
                comboBox_yC->setCurrentIndex(*yC - 1);
        }
        for(int i=0; i<*k; i++) {
            if(selected[i]) {
                listWidget_left->setCurrentRow(i);
                button_add->click();
            }
        }
        if(*k) {
            listWidget_left->setCurrentRow(0);
        }
        connect(listWidget_left, SIGNAL(itemClicked(QListWidgetItem *)), listWidget_right, SLOT(clearSelection()));
        connect(listWidget_right, SIGNAL(itemClicked(QListWidgetItem *)), listWidget_left, SLOT(clearSelection()));
        connect(this, SIGNAL(finished(int)), this, SLOT(setOk(int)));
}

void MultiDialog::on_button_add_clicked() {

        int index = listWidget_left->currentRow();
        if(index >= 0) {
                QListWidgetItem *item_l = listWidget_left->item(index);
                item_l->setHidden(true);
                QListWidgetItem *item_r = listWidget_right->item(index);
                item_r->setHidden(false);
                selected[index] = true;
                for(int i=index+1; i< index+ *k - 1; i++) { // select next shown item
                        int j = i % *k;
                        if(!listWidget_left->item(j)->isHidden()) {
                                listWidget_left->setCurrentRow(j);
                                break;
                        }
                }
        }

}

void MultiDialog::on_button_remove_clicked() {

        int index = listWidget_right->currentRow();
        if(index >= 0) {
                QListWidgetItem *item_l = listWidget_left->item(index);
                item_l->setHidden(false);
                QListWidgetItem *item_r = listWidget_right->item(index);
                item_r->setHidden(true);
                selected[index] = false;
                for(int i=index+1; i< index+ *k - 1; i++) { // select next shown item
                        int j = i % *k;
                        if(!listWidget_right->item(j)->isHidden()) {
                                listWidget_right->setCurrentRow(j);
                                break;
                        }
                }
        }
}

void MultiDialog::xC_currentIndexChanged(int index) {

        *xC = index + 1;
}

void MultiDialog::yC_currentIndexChanged(int index) {

        *yC = index + 1;
}

void MultiDialog::on_checkBox_add_stateChanged(int state) {

        *add = state;
}

void MultiDialog::on_checkBox_labels_stateChanged(int state) {

        *labels = state;
}

void MultiDialog::on_radioButton_simple_toggled(bool checked) {

        *simple = checked;
        if(checked)
                label_stars->setPixmap(pm_simple);
}

void MultiDialog::on_radioButton_boardered_toggled(bool checked) {

        *boardered = checked;
        if(checked)
                label_stars->setPixmap(pm_boardered);
}

void MultiDialog::on_radioButton_diamonds_toggled(bool checked) {

        *diamonds = checked;
        if(checked)
                label_stars->setPixmap(pm_diamonds);
}

void MultiDialog::on_tabWidget_currentChanged(int index) {

        *myIndex = index;
}

void MultiDialog::setOk(int result) {

        *ok = result;
}
