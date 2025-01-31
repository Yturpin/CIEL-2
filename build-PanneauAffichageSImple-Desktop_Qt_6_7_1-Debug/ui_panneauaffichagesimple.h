/********************************************************************************
** Form generated from reading UI file 'panneauaffichagesimple.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANNEAUAFFICHAGESIMPLE_H
#define UI_PANNEAUAFFICHAGESIMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PanneauAffichageSimple
{
public:
    QTextEdit *textEditInformation;

    void setupUi(QWidget *PanneauAffichageSimple)
    {
        if (PanneauAffichageSimple->objectName().isEmpty())
            PanneauAffichageSimple->setObjectName("PanneauAffichageSimple");
        PanneauAffichageSimple->resize(800, 600);
        textEditInformation = new QTextEdit(PanneauAffichageSimple);
        textEditInformation->setObjectName("textEditInformation");
        textEditInformation->setGeometry(QRect(90, 100, 581, 351));

        retranslateUi(PanneauAffichageSimple);

        QMetaObject::connectSlotsByName(PanneauAffichageSimple);
    } // setupUi

    void retranslateUi(QWidget *PanneauAffichageSimple)
    {
        PanneauAffichageSimple->setWindowTitle(QCoreApplication::translate("PanneauAffichageSimple", "Panneau d'affichage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PanneauAffichageSimple: public Ui_PanneauAffichageSimple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANNEAUAFFICHAGESIMPLE_H
