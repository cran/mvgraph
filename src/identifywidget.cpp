#include "identifywidget.h"





Identifywidget::Identifywidget(int size, char** names, QWidget *parent) : QDialog(parent) {



    QGroupBox *box = new QGroupBox(tr("Identify"), this);

    QHBoxLayout *hLayout = new QHBoxLayout(box);

    QVBoxLayout *layout = new QVBoxLayout(this);



    box->setLayout(hLayout);

    layout->addWidget(box);



    listWidget = new QListWidget(this);

    for(int i = 0; i<size; i++) {

        listWidget->addItem(QString::fromUtf8(names[i]));

    }



    hLayout->addWidget(listWidget);



    setLayout(layout);

    setWindowTitle(tr("Identify"));



    connect(listWidget, SIGNAL(currentRowChanged(int)), this, SIGNAL(identify(int)));

    widget_pos = parentWidget()->pos() + QPoint(parentWidget()->width(), 0);

}



void Identifywidget::hideEvent(QHideEvent */*event*/) {



    listWidget->setCurrentRow(-1);

}



void Identifywidget::showEvent(QShowEvent */*event*/) {



    // move to the side; otherwise would be displayed in middle of parent

    move(widget_pos);

}



void Identifywidget::moveEvent(QMoveEvent *event) {



    widget_pos = event->pos();

}

