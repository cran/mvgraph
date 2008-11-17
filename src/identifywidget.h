#ifndef IDENTIFYWIDGET_H

#define IDENTIFYWIDGET_H



#include <QDialog>

#include <QListWidget>

#include <QGroupBox>

#include <QHBoxLayout>

#include <QVBoxLayout>

#include <QMoveEvent>



class Identifywidget : public QDialog {



        Q_OBJECT



    public:

        Identifywidget(int size = 0, char** names = 0, QWidget *parent = 0);



    protected:

        void hideEvent(QHideEvent*);

        void showEvent(QShowEvent*);

        void moveEvent(QMoveEvent *event);



    signals:

        void identify(int index);



    private:

        QListWidget *listWidget;

        QPoint widget_pos;



};



#endif
