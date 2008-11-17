/********************************************************************************
** Form generated from reading ui file 'multigraph.ui'
**
** Created: Mon Dec 8 16:27:48 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MULTIGRAPH_H
#define UI_MULTIGRAPH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiGraph
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *label_variables;
    QSpacerItem *verticalSpacer;
    QPushButton *button_remove;
    QListWidget *listWidget_left;
    QPushButton *button_add;
    QListWidget *listWidget_right;
    QComboBox *comboBox_yC;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_xC;
    QLabel *label_xC;
    QLabel *label_yC;
    QCheckBox *checkBox_add;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QCheckBox *checkBox_labels;
    QTabWidget *tabWidget;
    QWidget *stars;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_starsdesc;
    QRadioButton *radioButton_simple;
    QRadioButton *radioButton_boardered;
    QRadioButton *radioButton_diamonds;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_stars;
    QWidget *segments;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_segmentsdesc;
    QFrame *frame_stars;
    QHBoxLayout *horizontalLayout;
    QLabel *label_segments;
    QWidget *boxes;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_boxesdesc;
    QFrame *frame_boxes;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_boxes;
    QWidget *polys;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_polysdesc;
    QFrame *frame_polys;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_polys;
    QWidget *trees;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_treesdesc;
    QFrame *frame_trees;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_trees;
    QWidget *castles;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_castlesdesc;
    QFrame *frame_castles;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_castels;

    void setupUi(QDialog *MultiGraph)
    {
    if (MultiGraph->objectName().isEmpty())
        MultiGraph->setObjectName(QString::fromUtf8("MultiGraph"));
    MultiGraph->resize(500, 562);
    verticalLayout = new QVBoxLayout(MultiGraph);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    groupBox = new QGroupBox(MultiGraph);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout = new QGridLayout(groupBox);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    buttonBox = new QDialogButtonBox(groupBox);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    gridLayout->addWidget(buttonBox, 15, 2, 1, 1);

    label_variables = new QLabel(groupBox);
    label_variables->setObjectName(QString::fromUtf8("label_variables"));
    label_variables->setMaximumSize(QSize(16777215, 20));

    gridLayout->addWidget(label_variables, 5, 0, 1, 1);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

    gridLayout->addItem(verticalSpacer, 11, 0, 1, 1);

    button_remove = new QPushButton(groupBox);
    button_remove->setObjectName(QString::fromUtf8("button_remove"));
    button_remove->setMaximumSize(QSize(40, 16777215));

    gridLayout->addWidget(button_remove, 8, 1, 1, 1);

    listWidget_left = new QListWidget(groupBox);
    listWidget_left->setObjectName(QString::fromUtf8("listWidget_left"));

    gridLayout->addWidget(listWidget_left, 7, 0, 3, 1);

    button_add = new QPushButton(groupBox);
    button_add->setObjectName(QString::fromUtf8("button_add"));
    button_add->setMaximumSize(QSize(40, 16777215));

    gridLayout->addWidget(button_add, 7, 1, 1, 1);

    listWidget_right = new QListWidget(groupBox);
    listWidget_right->setObjectName(QString::fromUtf8("listWidget_right"));

    gridLayout->addWidget(listWidget_right, 7, 2, 3, 1);

    comboBox_yC = new QComboBox(groupBox);
    comboBox_yC->setObjectName(QString::fromUtf8("comboBox_yC"));

    gridLayout->addWidget(comboBox_yC, 3, 2, 1, 1);

    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 1);

    verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

    verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_4, 4, 2, 1, 1);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

    comboBox_xC = new QComboBox(groupBox);
    comboBox_xC->setObjectName(QString::fromUtf8("comboBox_xC"));
    comboBox_xC->setMaximumSize(QSize(1000, 16777215));

    gridLayout->addWidget(comboBox_xC, 3, 0, 1, 1);

    label_xC = new QLabel(groupBox);
    label_xC->setObjectName(QString::fromUtf8("label_xC"));

    gridLayout->addWidget(label_xC, 2, 0, 1, 1);

    label_yC = new QLabel(groupBox);
    label_yC->setObjectName(QString::fromUtf8("label_yC"));

    gridLayout->addWidget(label_yC, 2, 2, 1, 1);

    checkBox_add = new QCheckBox(groupBox);
    checkBox_add->setObjectName(QString::fromUtf8("checkBox_add"));

    gridLayout->addWidget(checkBox_add, 13, 0, 1, 1);

    verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_8, 14, 0, 1, 1);

    verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_5, 1, 0, 1, 1);

    verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_6, 1, 1, 1, 1);

    verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_7, 1, 2, 1, 1);

    checkBox_labels = new QCheckBox(groupBox);
    checkBox_labels->setObjectName(QString::fromUtf8("checkBox_labels"));

    gridLayout->addWidget(checkBox_labels, 12, 0, 1, 1);

    tabWidget = new QTabWidget(groupBox);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setMinimumSize(QSize(0, 130));
    tabWidget->setIconSize(QSize(16, 16));
    stars = new QWidget();
    stars->setObjectName(QString::fromUtf8("stars"));
    horizontalLayout_7 = new QHBoxLayout(stars);
    horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
    verticalLayout_6 = new QVBoxLayout();
    verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
    label_starsdesc = new QLabel(stars);
    label_starsdesc->setObjectName(QString::fromUtf8("label_starsdesc"));
    QFont font;
    font.setItalic(true);
    label_starsdesc->setFont(font);
    label_starsdesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    verticalLayout_6->addWidget(label_starsdesc);

    radioButton_simple = new QRadioButton(stars);
    radioButton_simple->setObjectName(QString::fromUtf8("radioButton_simple"));
    radioButton_simple->setChecked(true);

    verticalLayout_6->addWidget(radioButton_simple);

    radioButton_boardered = new QRadioButton(stars);
    radioButton_boardered->setObjectName(QString::fromUtf8("radioButton_boardered"));

    verticalLayout_6->addWidget(radioButton_boardered);

    radioButton_diamonds = new QRadioButton(stars);
    radioButton_diamonds->setObjectName(QString::fromUtf8("radioButton_diamonds"));

    verticalLayout_6->addWidget(radioButton_diamonds);


    horizontalLayout_7->addLayout(verticalLayout_6);

    frame = new QFrame(stars);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setMinimumSize(QSize(80, 80));
    frame->setMaximumSize(QSize(80, 80));
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);
    horizontalLayout_6 = new QHBoxLayout(frame);
    horizontalLayout_6->setSpacing(0);
    horizontalLayout_6->setMargin(0);
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    label_stars = new QLabel(frame);
    label_stars->setObjectName(QString::fromUtf8("label_stars"));
    label_stars->setMinimumSize(QSize(75, 75));
    label_stars->setMaximumSize(QSize(75, 75));
    label_stars->setPixmap(QPixmap(QString::fromUtf8(":/images/simple.png")));

    horizontalLayout_6->addWidget(label_stars);


    horizontalLayout_7->addWidget(frame);

    tabWidget->addTab(stars, QString());
    segments = new QWidget();
    segments->setObjectName(QString::fromUtf8("segments"));
    horizontalLayout_2 = new QHBoxLayout(segments);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    label_segmentsdesc = new QLabel(segments);
    label_segmentsdesc->setObjectName(QString::fromUtf8("label_segmentsdesc"));
    QFont font1;
    font1.setBold(false);
    font1.setItalic(true);
    font1.setWeight(50);
    label_segmentsdesc->setFont(font1);
    label_segmentsdesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
    label_segmentsdesc->setWordWrap(true);

    verticalLayout_3->addWidget(label_segmentsdesc);


    horizontalLayout_2->addLayout(verticalLayout_3);

    frame_stars = new QFrame(segments);
    frame_stars->setObjectName(QString::fromUtf8("frame_stars"));
    frame_stars->setMinimumSize(QSize(80, 80));
    frame_stars->setMaximumSize(QSize(80, 80));
    QPalette palette;
    frame_stars->setPalette(palette);
    frame_stars->setFrameShape(QFrame::StyledPanel);
    frame_stars->setFrameShadow(QFrame::Raised);
    horizontalLayout = new QHBoxLayout(frame_stars);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setMargin(0);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_segments = new QLabel(frame_stars);
    label_segments->setObjectName(QString::fromUtf8("label_segments"));
    label_segments->setMaximumSize(QSize(75, 75));
    label_segments->setPixmap(QPixmap(QString::fromUtf8(":/images/star.png")));

    horizontalLayout->addWidget(label_segments);


    horizontalLayout_2->addWidget(frame_stars);

    tabWidget->addTab(segments, QString());
    boxes = new QWidget();
    boxes->setObjectName(QString::fromUtf8("boxes"));
    horizontalLayout_3 = new QHBoxLayout(boxes);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    label_boxesdesc = new QLabel(boxes);
    label_boxesdesc->setObjectName(QString::fromUtf8("label_boxesdesc"));
    label_boxesdesc->setFont(font);
    label_boxesdesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
    label_boxesdesc->setWordWrap(true);

    horizontalLayout_3->addWidget(label_boxesdesc);

    frame_boxes = new QFrame(boxes);
    frame_boxes->setObjectName(QString::fromUtf8("frame_boxes"));
    frame_boxes->setMaximumSize(QSize(80, 80));
    frame_boxes->setFrameShape(QFrame::StyledPanel);
    frame_boxes->setFrameShadow(QFrame::Raised);
    verticalLayout_2 = new QVBoxLayout(frame_boxes);
    verticalLayout_2->setSpacing(0);
    verticalLayout_2->setMargin(0);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    label_boxes = new QLabel(frame_boxes);
    label_boxes->setObjectName(QString::fromUtf8("label_boxes"));
    label_boxes->setMinimumSize(QSize(75, 75));
    label_boxes->setPixmap(QPixmap(QString::fromUtf8(":/images/box.png")));

    verticalLayout_2->addWidget(label_boxes);


    horizontalLayout_3->addWidget(frame_boxes);

    tabWidget->addTab(boxes, QString());
    polys = new QWidget();
    polys->setObjectName(QString::fromUtf8("polys"));
    horizontalLayout_4 = new QHBoxLayout(polys);
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    label_polysdesc = new QLabel(polys);
    label_polysdesc->setObjectName(QString::fromUtf8("label_polysdesc"));
    label_polysdesc->setFont(font);
    label_polysdesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
    label_polysdesc->setWordWrap(true);

    horizontalLayout_4->addWidget(label_polysdesc);

    frame_polys = new QFrame(polys);
    frame_polys->setObjectName(QString::fromUtf8("frame_polys"));
    frame_polys->setMinimumSize(QSize(80, 80));
    frame_polys->setMaximumSize(QSize(80, 80));
    frame_polys->setFrameShape(QFrame::StyledPanel);
    frame_polys->setFrameShadow(QFrame::Raised);
    verticalLayout_4 = new QVBoxLayout(frame_polys);
    verticalLayout_4->setSpacing(0);
    verticalLayout_4->setMargin(0);
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    label_polys = new QLabel(frame_polys);
    label_polys->setObjectName(QString::fromUtf8("label_polys"));
    label_polys->setPixmap(QPixmap(QString::fromUtf8(":/images/poly.png")));

    verticalLayout_4->addWidget(label_polys);


    horizontalLayout_4->addWidget(frame_polys);

    tabWidget->addTab(polys, QString());
    trees = new QWidget();
    trees->setObjectName(QString::fromUtf8("trees"));
    horizontalLayout_5 = new QHBoxLayout(trees);
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    label_treesdesc = new QLabel(trees);
    label_treesdesc->setObjectName(QString::fromUtf8("label_treesdesc"));
    label_treesdesc->setFont(font);
    label_treesdesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
    label_treesdesc->setWordWrap(true);

    horizontalLayout_5->addWidget(label_treesdesc);

    frame_trees = new QFrame(trees);
    frame_trees->setObjectName(QString::fromUtf8("frame_trees"));
    frame_trees->setMinimumSize(QSize(80, 80));
    frame_trees->setMaximumSize(QSize(80, 80));
    frame_trees->setFrameShape(QFrame::StyledPanel);
    frame_trees->setFrameShadow(QFrame::Raised);
    verticalLayout_5 = new QVBoxLayout(frame_trees);
    verticalLayout_5->setSpacing(0);
    verticalLayout_5->setMargin(0);
    verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
    label_trees = new QLabel(frame_trees);
    label_trees->setObjectName(QString::fromUtf8("label_trees"));
    label_trees->setMinimumSize(QSize(75, 75));
    label_trees->setMaximumSize(QSize(75, 75));
    label_trees->setPixmap(QPixmap(QString::fromUtf8(":/images/tree.png")));

    verticalLayout_5->addWidget(label_trees);


    horizontalLayout_5->addWidget(frame_trees);

    tabWidget->addTab(trees, QString());
    castles = new QWidget();
    castles->setObjectName(QString::fromUtf8("castles"));
    horizontalLayout_8 = new QHBoxLayout(castles);
    horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
    label_castlesdesc = new QLabel(castles);
    label_castlesdesc->setObjectName(QString::fromUtf8("label_castlesdesc"));
    label_castlesdesc->setFont(font);
    label_castlesdesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
    label_castlesdesc->setWordWrap(true);

    horizontalLayout_8->addWidget(label_castlesdesc);

    frame_castles = new QFrame(castles);
    frame_castles->setObjectName(QString::fromUtf8("frame_castles"));
    frame_castles->setMinimumSize(QSize(80, 80));
    frame_castles->setMaximumSize(QSize(80, 80));
    frame_castles->setFrameShape(QFrame::StyledPanel);
    frame_castles->setFrameShadow(QFrame::Raised);
    verticalLayout_7 = new QVBoxLayout(frame_castles);
    verticalLayout_7->setSpacing(0);
    verticalLayout_7->setMargin(0);
    verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
    label_castels = new QLabel(frame_castles);
    label_castels->setObjectName(QString::fromUtf8("label_castels"));
    label_castels->setMinimumSize(QSize(75, 75));
    label_castels->setMaximumSize(QSize(75, 75));
    label_castels->setPixmap(QPixmap(QString::fromUtf8(":/images/castle.png")));

    verticalLayout_7->addWidget(label_castels);


    horizontalLayout_8->addWidget(frame_castles);

    tabWidget->addTab(castles, QString());

    gridLayout->addWidget(tabWidget, 0, 0, 1, 3);

    buttonBox->raise();
    label_variables->raise();
    button_remove->raise();
    listWidget_left->raise();
    button_add->raise();
    listWidget_right->raise();
    comboBox_yC->raise();
    comboBox_xC->raise();
    label_xC->raise();
    label_yC->raise();
    checkBox_add->raise();
    checkBox_labels->raise();
    tabWidget->raise();

    verticalLayout->addWidget(groupBox);


    retranslateUi(MultiGraph);
    QObject::connect(buttonBox, SIGNAL(rejected()), MultiGraph, SLOT(reject()));
    QObject::connect(buttonBox, SIGNAL(accepted()), MultiGraph, SLOT(accept()));

    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MultiGraph);
    } // setupUi

    void retranslateUi(QDialog *MultiGraph)
    {
    MultiGraph->setWindowTitle(QApplication::translate("MultiGraph", "Draw Multivariate Graphics", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("MultiGraph", "Multivariate Graphics", 0, QApplication::UnicodeUTF8));
    label_variables->setText(QApplication::translate("MultiGraph", "Select Variables:", 0, QApplication::UnicodeUTF8));
    button_remove->setText(QApplication::translate("MultiGraph", "<<", 0, QApplication::UnicodeUTF8));
    button_add->setText(QApplication::translate("MultiGraph", ">>", 0, QApplication::UnicodeUTF8));
    label_xC->setText(QApplication::translate("MultiGraph", "X Coordinate:", 0, QApplication::UnicodeUTF8));
    label_yC->setText(QApplication::translate("MultiGraph", "Y Coordinate:", 0, QApplication::UnicodeUTF8));
    checkBox_add->setText(QApplication::translate("MultiGraph", "Add to existing plot", 0, QApplication::UnicodeUTF8));
    checkBox_labels->setText(QApplication::translate("MultiGraph", "Show labels", 0, QApplication::UnicodeUTF8));
    label_starsdesc->setText(QApplication::translate("MultiGraph", "Choose a style option ...", 0, QApplication::UnicodeUTF8));
    radioButton_simple->setText(QApplication::translate("MultiGraph", "Simple Stars", 0, QApplication::UnicodeUTF8));
    radioButton_boardered->setText(QApplication::translate("MultiGraph", "Bordered Stars", 0, QApplication::UnicodeUTF8));
    radioButton_diamonds->setText(QApplication::translate("MultiGraph", "Diamonds", 0, QApplication::UnicodeUTF8));
    label_stars->setText(QString());
    tabWidget->setTabText(tabWidget->indexOf(stars), QApplication::translate("MultiGraph", "Stars", 0, QApplication::UnicodeUTF8));
    label_segmentsdesc->setText(QApplication::translate("MultiGraph", "These pie chart lookalikes can handle many variables without confusing the user.", 0, QApplication::UnicodeUTF8));
    label_segments->setText(QString());
    tabWidget->setTabText(tabWidget->indexOf(segments), QApplication::translate("MultiGraph", "Segments", 0, QApplication::UnicodeUTF8));
    label_boxesdesc->setText(QApplication::translate("MultiGraph", "Boxes represent multivariate data by a cube which is split up in sub-cubes which represent the selected variables.", 0, QApplication::UnicodeUTF8));
    label_boxes->setText(QString());
    tabWidget->setTabText(tabWidget->indexOf(boxes), QApplication::translate("MultiGraph", "Boxes", 0, QApplication::UnicodeUTF8));
    label_polysdesc->setText(QApplication::translate("MultiGraph", "Polygons are a simple way to represent a multivariate data point using a single line.", 0, QApplication::UnicodeUTF8));
    label_polys->setText(QString());
    tabWidget->setTabText(tabWidget->indexOf(polys), QApplication::translate("MultiGraph", "Polygons", 0, QApplication::UnicodeUTF8));
    label_treesdesc->setText(QApplication::translate("MultiGraph", "Trees visualize multivariate data with their branches, each one representing a variable.", 0, QApplication::UnicodeUTF8));
    label_trees->setText(QString());
    tabWidget->setTabText(tabWidget->indexOf(trees), QApplication::translate("MultiGraph", "Trees", 0, QApplication::UnicodeUTF8));
    label_castlesdesc->setText(QApplication::translate("MultiGraph", "Castles consist of towers of which the heights are proportional to the values of the variables.", 0, QApplication::UnicodeUTF8));
    label_castels->setText(QString());
    tabWidget->setTabText(tabWidget->indexOf(castles), QApplication::translate("MultiGraph", "Castles", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MultiGraph);
    } // retranslateUi

};

namespace Ui {
    class MultiGraph: public Ui_MultiGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIGRAPH_H
