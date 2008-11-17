/********************************************************************************
** Form generated from reading ui file 'about.ui'
**
** Created: Mon Jan 5 13:13:46 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_14;
    QLabel *label_15;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_16;
    QLabel *label_18;
    QSpacerItem *verticalSpacer_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *About)
    {
    if (About->objectName().isEmpty())
        About->setObjectName(QString::fromUtf8("About"));
    About->resize(557, 502);
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")), QIcon::Normal, QIcon::Off);
    About->setWindowIcon(icon);
    horizontalLayout_6 = new QHBoxLayout(About);
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    label = new QLabel(About);
    label->setObjectName(QString::fromUtf8("label"));
    label->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    verticalLayout->addWidget(label);

    verticalSpacer = new QSpacerItem(20, 188, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer);


    horizontalLayout_6->addLayout(verticalLayout);

    verticalLayout_7 = new QVBoxLayout();
    verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
    label_2 = new QLabel(About);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    font.setItalic(false);
    font.setWeight(75);
    label_2->setFont(font);
    label_2->setWordWrap(true);

    verticalLayout_7->addWidget(label_2);

    label_3 = new QLabel(About);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setWordWrap(true);

    verticalLayout_7->addWidget(label_3);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_4 = new QLabel(About);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
    label_4->setSizePolicy(sizePolicy);
    label_4->setMinimumSize(QSize(26, 0));
    label_4->setMaximumSize(QSize(26, 16777215));
    label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/rotate.png")));
    label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    horizontalLayout->addWidget(label_4);

    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    label_5 = new QLabel(About);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    QFont font1;
    font1.setBold(true);
    font1.setWeight(75);
    label_5->setFont(font1);

    verticalLayout_3->addWidget(label_5);

    label_6 = new QLabel(About);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
    label_6->setWordWrap(true);

    verticalLayout_3->addWidget(label_6);


    horizontalLayout->addLayout(verticalLayout_3);


    verticalLayout_7->addLayout(horizontalLayout);

    verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_7->addItem(verticalSpacer_6);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    label_7 = new QLabel(About);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
    label_7->setSizePolicy(sizePolicy);
    label_7->setMinimumSize(QSize(26, 0));
    label_7->setMaximumSize(QSize(26, 16777215));
    label_7->setPixmap(QPixmap(QString::fromUtf8(":/images/move.png")));
    label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    horizontalLayout_2->addWidget(label_7);

    verticalLayout_4 = new QVBoxLayout();
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    label_8 = new QLabel(About);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setFont(font1);

    verticalLayout_4->addWidget(label_8);

    label_9 = new QLabel(About);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
    label_9->setWordWrap(true);

    verticalLayout_4->addWidget(label_9);


    horizontalLayout_2->addLayout(verticalLayout_4);


    verticalLayout_7->addLayout(horizontalLayout_2);

    verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_7->addItem(verticalSpacer_3);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    label_10 = new QLabel(About);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
    label_10->setSizePolicy(sizePolicy);
    label_10->setMinimumSize(QSize(26, 0));
    label_10->setMaximumSize(QSize(26, 16777215));
    label_10->setPixmap(QPixmap(QString::fromUtf8(":/images/brush.png")));
    label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    horizontalLayout_3->addWidget(label_10);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    label_11 = new QLabel(About);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setFont(font1);

    verticalLayout_2->addWidget(label_11);

    label_12 = new QLabel(About);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
    label_12->setWordWrap(true);

    verticalLayout_2->addWidget(label_12);


    horizontalLayout_3->addLayout(verticalLayout_2);


    verticalLayout_7->addLayout(horizontalLayout_3);

    verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_7->addItem(verticalSpacer_4);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    label_13 = new QLabel(About);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
    label_13->setSizePolicy(sizePolicy);
    label_13->setMinimumSize(QSize(26, 0));
    label_13->setMaximumSize(QSize(26, 16777215));
    label_13->setPixmap(QPixmap(QString::fromUtf8(":/images/info.png")));
    label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    horizontalLayout_4->addWidget(label_13);

    verticalLayout_5 = new QVBoxLayout();
    verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
    label_14 = new QLabel(About);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setFont(font1);

    verticalLayout_5->addWidget(label_14);

    label_15 = new QLabel(About);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setWordWrap(true);

    verticalLayout_5->addWidget(label_15);


    horizontalLayout_4->addLayout(verticalLayout_5);


    verticalLayout_7->addLayout(horizontalLayout_4);

    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_7->addItem(verticalSpacer_2);

    horizontalLayout_5 = new QHBoxLayout();
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    label_17 = new QLabel(About);
    label_17->setObjectName(QString::fromUtf8("label_17"));
    label_17->setMinimumSize(QSize(26, 0));
    label_17->setMaximumSize(QSize(26, 16777215));
    label_17->setPixmap(QPixmap(QString::fromUtf8(":/images/identify.png")));
    label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    horizontalLayout_5->addWidget(label_17);

    verticalLayout_6 = new QVBoxLayout();
    verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
    label_16 = new QLabel(About);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setFont(font1);

    verticalLayout_6->addWidget(label_16);

    label_18 = new QLabel(About);
    label_18->setObjectName(QString::fromUtf8("label_18"));

    verticalLayout_6->addWidget(label_18);


    horizontalLayout_5->addLayout(verticalLayout_6);


    verticalLayout_7->addLayout(horizontalLayout_5);

    verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_7->addItem(verticalSpacer_5);

    buttonBox = new QDialogButtonBox(About);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Ok);

    verticalLayout_7->addWidget(buttonBox);


    horizontalLayout_6->addLayout(verticalLayout_7);


    retranslateUi(About);
    QObject::connect(buttonBox, SIGNAL(accepted()), About, SLOT(accept()));

    QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
    About->setWindowTitle(QApplication::translate("About", "About Spin & Brush", 0, QApplication::UnicodeUTF8));
    label->setText(QString());
    label_2->setText(QApplication::translate("About", "Spin & Brush", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("About", "Spin & Brush is an open source tool for visualizing three dimensional data based on openGL.\n"
"\n"
"Five main functions allow user interaction:", 0, QApplication::UnicodeUTF8));
    label_4->setText(QString());
    label_5->setText(QApplication::translate("About", "Spin:", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("About", "Holding a mouse button pressed down and dragging the mouse over the three dimensional scene results in a smooth rotation of the data.", 0, QApplication::UnicodeUTF8));
    label_7->setText(QString());
    label_8->setText(QApplication::translate("About", "Move:", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("About", "Enables the user to drag the scene around.", 0, QApplication::UnicodeUTF8));
    label_10->setText(QString());
    label_11->setText(QApplication::translate("About", "Brush:", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("About", "The brush function allows the user to select data by choosing a group from the group menu and dragging the mouse over the scene. The resulting clustering of the data is recorded and returned.", 0, QApplication::UnicodeUTF8));
    label_13->setText(QString());
    label_14->setText(QApplication::translate("About", "Info:", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("About", "Precise information is delivered to the user when data points are selected.", 0, QApplication::UnicodeUTF8));
    label_17->setText(QString());
    label_16->setText(QApplication::translate("About", "Identify:", 0, QApplication::UnicodeUTF8));
    label_18->setText(QApplication::translate("About", "Data points can be identified by selecting their labels.", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(About);
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
