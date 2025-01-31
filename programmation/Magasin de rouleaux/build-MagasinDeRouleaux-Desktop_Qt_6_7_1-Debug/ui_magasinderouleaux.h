/********************************************************************************
** Form generated from reading UI file 'magasinderouleaux.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGASINDEROULEAUX_H
#define UI_MAGASINDEROULEAUX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MagasinDeRouleaux
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QWidget *widget1;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget;
    QPushButton *pushButton_2;
    QWidget *widget2;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QListWidget *listWidget_2;

    void setupUi(QWidget *MagasinDeRouleaux)
    {
        if (MagasinDeRouleaux->objectName().isEmpty())
            MagasinDeRouleaux->setObjectName("MagasinDeRouleaux");
        MagasinDeRouleaux->resize(800, 600);
        widget = new QWidget(MagasinDeRouleaux);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 90, 202, 104));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 2, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        widget1 = new QWidget(MagasinDeRouleaux);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(260, 90, 260, 246));
        gridLayout_4 = new QGridLayout(widget1);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        listWidget = new QListWidget(widget1);
        listWidget->setObjectName("listWidget");

        gridLayout_3->addWidget(listWidget, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_3->addWidget(pushButton_2, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);

        widget2 = new QWidget(MagasinDeRouleaux);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(530, 90, 258, 215));
        gridLayout_5 = new QGridLayout(widget2);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget2);
        label_5->setObjectName("label_5");

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        listWidget_2 = new QListWidget(widget2);
        listWidget_2->setObjectName("listWidget_2");

        gridLayout_5->addWidget(listWidget_2, 1, 0, 1, 1);


        retranslateUi(MagasinDeRouleaux);

        QMetaObject::connectSlotsByName(MagasinDeRouleaux);
    } // setupUi

    void retranslateUi(QWidget *MagasinDeRouleaux)
    {
        MagasinDeRouleaux->setWindowTitle(QCoreApplication::translate("MagasinDeRouleaux", "MagasinDeRouleaux", nullptr));
        label_3->setText(QCoreApplication::translate("MagasinDeRouleaux", "Entr\303\251e d'un rouleau", nullptr));
        label->setText(QCoreApplication::translate("MagasinDeRouleaux", "R\303\251ference :", nullptr));
        label_2->setText(QCoreApplication::translate("MagasinDeRouleaux", "Diam\303\250tre :", nullptr));
        pushButton->setText(QCoreApplication::translate("MagasinDeRouleaux", "Entrer un rouleau", nullptr));
        label_4->setText(QCoreApplication::translate("MagasinDeRouleaux", "Rouleaux dans le stock", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MagasinDeRouleaux", "Sortir une s\303\251rie de rouleaux", nullptr));
        label_5->setText(QCoreApplication::translate("MagasinDeRouleaux", "Rouleaux dans l'enceinte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MagasinDeRouleaux: public Ui_MagasinDeRouleaux {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGASINDEROULEAUX_H
