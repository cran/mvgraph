/********************************************************************************
** Form generated from reading ui file 'select.ui'
**
** Created: Sat Dec 6 15:50:44 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SELECT_H
#define UI_SELECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Select
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_variables;
    QPushButton *button_remove;
    QListWidget *listWidget_left;
    QPushButton *button_add;
    QListWidget *listWidget_right;
    QPushButton *button_ok;

    void setupUi(QDialog *Select)
    {
    if (Select->objectName().isEmpty())
        Select->setObjectName(QString::fromUtf8("Select"));
    Select->resize(517, 281);
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/logo24.png")), QIcon::Normal, QIcon::Off);
    Select->setWindowIcon(icon);
    verticalLayout = new QVBoxLayout(Select);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    groupBox = new QGroupBox(Select);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout = new QGridLayout(groupBox);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label_variables = new QLabel(groupBox);
    label_variables->setObjectName(QString::fromUtf8("label_variables"));
    label_variables->setMaximumSize(QSize(16777215, 20));

    gridLayout->addWidget(label_variables, 0, 0, 1, 1);

    button_remove = new QPushButton(groupBox);
    button_remove->setObjectName(QString::fromUtf8("button_remove"));
    button_remove->setEnabled(false);
    button_remove->setMaximumSize(QSize(40, 16777215));

    gridLayout->addWidget(button_remove, 3, 1, 1, 1);

    listWidget_left = new QListWidget(groupBox);
    listWidget_left->setObjectName(QString::fromUtf8("listWidget_left"));

    gridLayout->addWidget(listWidget_left, 2, 0, 3, 1);

    button_add = new QPushButton(groupBox);
    button_add->setObjectName(QString::fromUtf8("button_add"));
    button_add->setMaximumSize(QSize(40, 16777215));

    gridLayout->addWidget(button_add, 2, 1, 1, 1);

    listWidget_right = new QListWidget(groupBox);
    listWidget_right->setObjectName(QString::fromUtf8("listWidget_right"));

    gridLayout->addWidget(listWidget_right, 2, 2, 3, 1);

    button_ok = new QPushButton(groupBox);
    button_ok->setObjectName(QString::fromUtf8("button_ok"));
    button_ok->setEnabled(false);

    gridLayout->addWidget(button_ok, 5, 2, 1, 1);


    verticalLayout->addWidget(groupBox);


    retranslateUi(Select);
    QObject::connect(button_ok, SIGNAL(clicked()), Select, SLOT(accept()));

    QMetaObject::connectSlotsByName(Select);
    } // setupUi

    void retranslateUi(QDialog *Select)
    {
    Select->setWindowTitle(QApplication::translate("Select", "Spin & Brush", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Select", "Spin and Brush", 0, QApplication::UnicodeUTF8));
    label_variables->setText(QApplication::translate("Select", "Select Variables:", 0, QApplication::UnicodeUTF8));
    button_remove->setText(QApplication::translate("Select", "<<", 0, QApplication::UnicodeUTF8));
    button_add->setText(QApplication::translate("Select", ">>", 0, QApplication::UnicodeUTF8));
    button_ok->setText(QApplication::translate("Select", "OK", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Select);
    } // retranslateUi

};

namespace Ui {
    class Select: public Ui_Select {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_H
