/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *top;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *population_sorter;
    QPushButton *walkability_sorter;
    QPushButton *employment_sorter;
    QPushButton *size_sorter;
    QPushButton *households_sorter;
    QPushButton *transit_sorter;
    QLabel *label;
    QComboBox *comboBox;
    QTableWidget *locationTable;
    QWidget *bottom;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1218, 816);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #242424;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        top = new QWidget(centralwidget);
        top->setObjectName("top");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(top->sizePolicy().hasHeightForWidth());
        top->setSizePolicy(sizePolicy1);
        top->setMinimumSize(QSize(0, 40));
        top->setMaximumSize(QSize(16777215, 40));
        top->setStyleSheet(QString::fromUtf8("\n"
"QWidget {\n"
"background-color: #343434;\n"
"border-bottom: 1px solid #505050;\n"
"}\n"
"\n"
"QWidget  > QPushButton  {\n"
" 	background-color: #505050;\n"
"    border: none;\n"
"	border-right: 1px solid #242424;\n"
"    color: #ffffff; \n"
"}\n"
"\n"
"\n"
" QWidget  > QComboBox {\n"
"	background-color: #505050;\n"
"    border: none;\n"
"    color: #ffffff; \n"
"}"));
        horizontalLayoutWidget = new QWidget(top);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, -10, 1221, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        population_sorter = new QPushButton(horizontalLayoutWidget);
        population_sorter->setObjectName("population_sorter");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(population_sorter->sizePolicy().hasHeightForWidth());
        population_sorter->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(population_sorter);

        walkability_sorter = new QPushButton(horizontalLayoutWidget);
        walkability_sorter->setObjectName("walkability_sorter");
        sizePolicy2.setHeightForWidth(walkability_sorter->sizePolicy().hasHeightForWidth());
        walkability_sorter->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(walkability_sorter);

        employment_sorter = new QPushButton(horizontalLayoutWidget);
        employment_sorter->setObjectName("employment_sorter");
        sizePolicy2.setHeightForWidth(employment_sorter->sizePolicy().hasHeightForWidth());
        employment_sorter->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(employment_sorter);

        size_sorter = new QPushButton(horizontalLayoutWidget);
        size_sorter->setObjectName("size_sorter");
        sizePolicy2.setHeightForWidth(size_sorter->sizePolicy().hasHeightForWidth());
        size_sorter->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(size_sorter);

        households_sorter = new QPushButton(horizontalLayoutWidget);
        households_sorter->setObjectName("households_sorter");
        sizePolicy2.setHeightForWidth(households_sorter->sizePolicy().hasHeightForWidth());
        households_sorter->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(households_sorter);

        transit_sorter = new QPushButton(horizontalLayoutWidget);
        transit_sorter->setObjectName("transit_sorter");
        sizePolicy2.setHeightForWidth(transit_sorter->sizePolicy().hasHeightForWidth());
        transit_sorter->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(transit_sorter);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    padding-left: 12px; \n"
"    padding-right: 8px; \n"
"}"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addWidget(top);

        locationTable = new QTableWidget(centralwidget);
        locationTable->setObjectName("locationTable");
        locationTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"border: none;\n"
"color: #d4d4d4\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #343434;\n"
"    color: white;\n"
"    border: 1px solid #404040 !important;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #343434; \n"
"    border: 1px solid #404040 !important; \n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    border: 1px solid #292929 !important;\n"
"    padding: 2px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
""));

        verticalLayout->addWidget(locationTable);

        bottom = new QWidget(centralwidget);
        bottom->setObjectName("bottom");
        bottom->setMinimumSize(QSize(0, 44));
        bottom->setMaximumSize(QSize(16777215, 44));
        bottom->setStyleSheet(QString::fromUtf8("QWidget > * {\n"
"    padding-left: 12px;\n"
"    padding-right: 12px;\n"
"}\n"
"QWidget {\n"
"border-top: 1px solid #505050\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(bottom);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        label_2 = new QLabel(bottom);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(label_2);

        lineEdit = new QLineEdit(bottom);
        lineEdit->setObjectName("lineEdit");
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: #343434;"));
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit);

        label_3 = new QLabel(bottom);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(bottom);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("background-color: #343434;"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_2 = new QLineEdit(bottom);
        lineEdit_2->setObjectName("lineEdit_2");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy4);
        lineEdit_2->setMaximumSize(QSize(100, 16777215));
        lineEdit_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_2->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_2);

        label_5 = new QLabel(bottom);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("background-color: #343434"));

        horizontalLayout_3->addWidget(label_5);

        lineEdit_4 = new QLineEdit(bottom);
        lineEdit_4->setObjectName("lineEdit_4");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy5);
        lineEdit_4->setMaximumSize(QSize(100, 16777215));
        lineEdit_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_4->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_4);

        label_6 = new QLabel(bottom);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("background-color: #343434"));

        horizontalLayout_3->addWidget(label_6);

        lineEdit_3 = new QLineEdit(bottom);
        lineEdit_3->setObjectName("lineEdit_3");
        sizePolicy4.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy4);
        lineEdit_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(lineEdit_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(bottom);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        population_sorter->setText(QCoreApplication::translate("MainWindow", "Population", nullptr));
        walkability_sorter->setText(QCoreApplication::translate("MainWindow", "Walkability Score", nullptr));
        employment_sorter->setText(QCoreApplication::translate("MainWindow", "Employment", nullptr));
        size_sorter->setText(QCoreApplication::translate("MainWindow", "Size (Acres)", nullptr));
        households_sorter->setText(QCoreApplication::translate("MainWindow", "Households", nullptr));
        transit_sorter->setText(QCoreApplication::translate("MainWindow", "Public Transit Score", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sort By:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Highest", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Lowest", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Rows Sorted:", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "2 million", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Sorting Times:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Merge Sort", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "0.00s", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Shell Sort", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "0.00s", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Bubble Sort", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "0.00s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
