#include "selectdialog.h"

Selectdialog::Selectdialog(char** varnames, int* selected, int* k, int *ok, QWidget *parent) : QDialog(parent) {

	setupUi(this);
	count = 0;
	this->selected = selected;
        this->k = k;
        this->ok = ok;

	for(int i=0; i<*k; i++) {
		QListWidgetItem *item_l = new QListWidgetItem(QString::fromUtf8(varnames[i]));
		listWidget_left->addItem(item_l);
		
		QListWidgetItem *item_r = new QListWidgetItem(QString::fromUtf8(varnames[i]));
		listWidget_right->addItem(item_r);
                item_r->setHidden(true);
        }
        connect(listWidget_left, SIGNAL(itemClicked(QListWidgetItem *)), listWidget_right, SLOT(clearSelection()));
        connect(listWidget_right, SIGNAL(itemClicked(QListWidgetItem *)), listWidget_left, SLOT(clearSelection()));

        for(int i = 0; i <*k; i++) {
            if(selected[i]) {
                listWidget_left->setCurrentRow(i);
                button_add->click();
            }
        }
        if(*k) {
            listWidget_left->setCurrentRow(0);
        }
        connect(this, SIGNAL(finished(int)), this, SLOT(setOk(int)));
}

void Selectdialog::on_button_add_clicked() {

        int index = listWidget_left->currentRow();
        if(listWidget_left->selectedItems().size()) {
                QListWidgetItem *item_l = listWidget_left->item(index);
                item_l->setHidden(true);
		QListWidgetItem *item_r = listWidget_right->item(index);
		item_r->setHidden(false);
		selected[index] = true;
		count++;
                for(int i=index+1; i< index+ *k - 1; i++) { // select next shown item
                        int j = i % *k;
                        if(!listWidget_left->item(j)->isHidden()) {
                                listWidget_left->setCurrentRow(j);
				break;
			}
                }
		button_ok->setEnabled(count == 3);
		button_add->setEnabled(count < 3);
		button_remove->setEnabled(count > 0);
	}
}

void Selectdialog::on_button_remove_clicked() {

        int index = listWidget_right->currentRow();

        if(listWidget_right->selectedItems().size()) {
		QListWidgetItem *item_l = listWidget_left->item(index);
                item_l->setHidden(false);
                QListWidgetItem *item = listWidget_right->item(index);
                item->setHidden(true);
		selected[index] = false;
		count--;
                for(int i=index+1; i< index+ *k - 1; i++) { // select next shown item
                        int j = i % *k;
                        if(!listWidget_right->item(j)->isHidden()) {
                                listWidget_right->setCurrentRow(j);
                                break;
                        }
                }
		button_ok->setEnabled(count == 3);
		button_add->setEnabled(count < 3);
		button_remove->setEnabled(count > 0);
	}
}

void Selectdialog::setOk(int result) {

    *ok = result;
}
