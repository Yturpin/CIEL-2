/********************************************************************************
** Form generated from reading UI file 'testgestionstock.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTGESTIONSTOCK_H
#define UI_TESTGESTIONSTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestGestionStock
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidgetStock;
    QPushButton *pushButtonDemanderRetrait;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *listWidgetRouleauxRetenus;
    QPushButton *pushButtonSupprimerDuSotck;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *labelReference;
    QLineEdit *lineEditReference;
    QLabel *labelDiametre;
    QLineEdit *lineEditDiametre;
    QPushButton *pushButtonQuitter;
    QPushButton *pushButtonAjouterNouveau;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonCharger;
    QPushButton *pushButtonEnregistrer;

    void setupUi(QWidget *TestGestionStock)
    {
        if (TestGestionStock->objectName().isEmpty())
            TestGestionStock->setObjectName("TestGestionStock");
        TestGestionStock->resize(1104, 600);
        layoutWidget = new QWidget(TestGestionStock);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(370, 83, 258, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        listWidgetStock = new QListWidget(layoutWidget);
        listWidgetStock->setObjectName("listWidgetStock");

        verticalLayout->addWidget(listWidgetStock);

        pushButtonDemanderRetrait = new QPushButton(layoutWidget);
        pushButtonDemanderRetrait->setObjectName("pushButtonDemanderRetrait");

        verticalLayout->addWidget(pushButtonDemanderRetrait);

        layoutWidget_2 = new QWidget(TestGestionStock);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(650, 80, 258, 321));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        listWidgetRouleauxRetenus = new QListWidget(layoutWidget_2);
        listWidgetRouleauxRetenus->setObjectName("listWidgetRouleauxRetenus");

        verticalLayout_2->addWidget(listWidgetRouleauxRetenus);

        pushButtonSupprimerDuSotck = new QPushButton(layoutWidget_2);
        pushButtonSupprimerDuSotck->setObjectName("pushButtonSupprimerDuSotck");

        verticalLayout_2->addWidget(pushButtonSupprimerDuSotck);

        layoutWidget1 = new QWidget(TestGestionStock);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(60, 231, 200, 131));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelReference = new QLabel(layoutWidget1);
        labelReference->setObjectName("labelReference");

        gridLayout->addWidget(labelReference, 1, 0, 1, 1);

        lineEditReference = new QLineEdit(layoutWidget1);
        lineEditReference->setObjectName("lineEditReference");

        gridLayout->addWidget(lineEditReference, 1, 1, 1, 1);

        labelDiametre = new QLabel(layoutWidget1);
        labelDiametre->setObjectName("labelDiametre");

        gridLayout->addWidget(labelDiametre, 2, 0, 1, 1);

        lineEditDiametre = new QLineEdit(layoutWidget1);
        lineEditDiametre->setObjectName("lineEditDiametre");

        gridLayout->addWidget(lineEditDiametre, 2, 1, 1, 1);

        pushButtonQuitter = new QPushButton(layoutWidget1);
        pushButtonQuitter->setObjectName("pushButtonQuitter");

        gridLayout->addWidget(pushButtonQuitter, 4, 0, 1, 2);

        pushButtonAjouterNouveau = new QPushButton(layoutWidget1);
        pushButtonAjouterNouveau->setObjectName("pushButtonAjouterNouveau");

        gridLayout->addWidget(pushButtonAjouterNouveau, 3, 0, 1, 2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        widget = new QWidget(TestGestionStock);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(290, 460, 82, 54));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonCharger = new QPushButton(widget);
        pushButtonCharger->setObjectName("pushButtonCharger");

        verticalLayout_3->addWidget(pushButtonCharger);

        pushButtonEnregistrer = new QPushButton(widget);
        pushButtonEnregistrer->setObjectName("pushButtonEnregistrer");

        verticalLayout_3->addWidget(pushButtonEnregistrer);

        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget_2->raise();
        pushButtonEnregistrer->raise();
        pushButtonCharger->raise();

        retranslateUi(TestGestionStock);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, TestGestionStock, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(TestGestionStock);
    } // setupUi

    void retranslateUi(QWidget *TestGestionStock)
    {
        TestGestionStock->setWindowTitle(QCoreApplication::translate("TestGestionStock", "TestGestionStock", nullptr));
        label->setText(QCoreApplication::translate("TestGestionStock", "Rouleaux en stock", nullptr));
        pushButtonDemanderRetrait->setText(QCoreApplication::translate("TestGestionStock", "Demander retrait", nullptr));
        label_2->setText(QCoreApplication::translate("TestGestionStock", "Rouleaux retenus", nullptr));
        pushButtonSupprimerDuSotck->setText(QCoreApplication::translate("TestGestionStock", "Supprimer du stock", nullptr));
        labelReference->setText(QCoreApplication::translate("TestGestionStock", "R\303\251f\303\251rence :", nullptr));
        labelDiametre->setText(QCoreApplication::translate("TestGestionStock", "Diam\303\250tre :", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("TestGestionStock", "Quitter", nullptr));
        pushButtonAjouterNouveau->setText(QCoreApplication::translate("TestGestionStock", "Ajouter nouveau", nullptr));
        label_3->setText(QCoreApplication::translate("TestGestionStock", "Entr\303\251e d'un rouleau", nullptr));
        pushButtonCharger->setText(QCoreApplication::translate("TestGestionStock", "Charger", nullptr));
        pushButtonEnregistrer->setText(QCoreApplication::translate("TestGestionStock", "Enregistrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestGestionStock: public Ui_TestGestionStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTGESTIONSTOCK_H
