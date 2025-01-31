/********************************************************************************
** Form generated from reading UI file 'miseenoeuvrebdd.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISEENOEUVREBDD_H
#define UI_MISEENOEUVREBDD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiseEnOeuvreBDD
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButtonObtenirNomDep;
    QLineEdit *lineEditNomDepartement;
    QLineEdit *lineEditCodeDepartement;
    QComboBox *comboBoxRegions;
    QComboBox *comboBoxDepartements;
    QComboBox *comboBox_2;

    void setupUi(QWidget *MiseEnOeuvreBDD)
    {
        if (MiseEnOeuvreBDD->objectName().isEmpty())
            MiseEnOeuvreBDD->setObjectName("MiseEnOeuvreBDD");
        MiseEnOeuvreBDD->resize(800, 600);
        label = new QLabel(MiseEnOeuvreBDD);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 230, 200, 15));
        label_2 = new QLabel(MiseEnOeuvreBDD);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 260, 134, 15));
        pushButtonObtenirNomDep = new QPushButton(MiseEnOeuvreBDD);
        pushButtonObtenirNomDep->setObjectName("pushButtonObtenirNomDep");
        pushButtonObtenirNomDep->setGeometry(QRect(500, 220, 191, 23));
        lineEditNomDepartement = new QLineEdit(MiseEnOeuvreBDD);
        lineEditNomDepartement->setObjectName("lineEditNomDepartement");
        lineEditNomDepartement->setGeometry(QRect(380, 260, 311, 22));
        lineEditCodeDepartement = new QLineEdit(MiseEnOeuvreBDD);
        lineEditCodeDepartement->setObjectName("lineEditCodeDepartement");
        lineEditCodeDepartement->setGeometry(QRect(380, 220, 113, 22));
        comboBoxRegions = new QComboBox(MiseEnOeuvreBDD);
        comboBoxRegions->setObjectName("comboBoxRegions");
        comboBoxRegions->setGeometry(QRect(160, 320, 161, 23));
        comboBoxDepartements = new QComboBox(MiseEnOeuvreBDD);
        comboBoxDepartements->setObjectName("comboBoxDepartements");
        comboBoxDepartements->setGeometry(QRect(340, 320, 151, 23));
        comboBox_2 = new QComboBox(MiseEnOeuvreBDD);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(510, 320, 171, 23));

        retranslateUi(MiseEnOeuvreBDD);

        QMetaObject::connectSlotsByName(MiseEnOeuvreBDD);
    } // setupUi

    void retranslateUi(QWidget *MiseEnOeuvreBDD)
    {
        MiseEnOeuvreBDD->setWindowTitle(QCoreApplication::translate("MiseEnOeuvreBDD", "MiseEnOeuvreBDD", nullptr));
        label->setText(QCoreApplication::translate("MiseEnOeuvreBDD", "Donnez un code de d\303\251partement :", nullptr));
        label_2->setText(QCoreApplication::translate("MiseEnOeuvreBDD", "Nom du d\303\251partement :", nullptr));
        pushButtonObtenirNomDep->setText(QCoreApplication::translate("MiseEnOeuvreBDD", "Obtenir le nom du d\303\251partement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MiseEnOeuvreBDD: public Ui_MiseEnOeuvreBDD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISEENOEUVREBDD_H
