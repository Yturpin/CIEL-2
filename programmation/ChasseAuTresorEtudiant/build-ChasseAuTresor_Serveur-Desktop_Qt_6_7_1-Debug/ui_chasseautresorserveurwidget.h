/********************************************************************************
** Form generated from reading UI file 'chasseautresorserveurwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHASSEAUTRESORSERVEURWIDGET_H
#define UI_CHASSEAUTRESORSERVEURWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChasseAuTresorServeurWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *labelEcoutePort;
    QSpinBox *spinBoxPort;
    QPushButton *pushButtonLancerServeur;
    QPushButton *pushButtonQuitter;

    void setupUi(QWidget *ChasseAuTresorServeurWidget)
    {
        if (ChasseAuTresorServeurWidget->objectName().isEmpty())
            ChasseAuTresorServeurWidget->setObjectName("ChasseAuTresorServeurWidget");
        ChasseAuTresorServeurWidget->resize(305, 300);
        QFont font;
        font.setPointSize(15);
        ChasseAuTresorServeurWidget->setFont(font);
        gridLayout = new QGridLayout(ChasseAuTresorServeurWidget);
        gridLayout->setObjectName("gridLayout");
        labelEcoutePort = new QLabel(ChasseAuTresorServeurWidget);
        labelEcoutePort->setObjectName("labelEcoutePort");

        gridLayout->addWidget(labelEcoutePort, 0, 0, 1, 1);

        spinBoxPort = new QSpinBox(ChasseAuTresorServeurWidget);
        spinBoxPort->setObjectName("spinBoxPort");
        spinBoxPort->setMinimum(2000);
        spinBoxPort->setMaximum(9999);
        spinBoxPort->setValue(8888);

        gridLayout->addWidget(spinBoxPort, 0, 1, 1, 1);

        pushButtonLancerServeur = new QPushButton(ChasseAuTresorServeurWidget);
        pushButtonLancerServeur->setObjectName("pushButtonLancerServeur");

        gridLayout->addWidget(pushButtonLancerServeur, 1, 0, 1, 1);

        pushButtonQuitter = new QPushButton(ChasseAuTresorServeurWidget);
        pushButtonQuitter->setObjectName("pushButtonQuitter");

        gridLayout->addWidget(pushButtonQuitter, 1, 1, 1, 1);


        retranslateUi(ChasseAuTresorServeurWidget);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, ChasseAuTresorServeurWidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(ChasseAuTresorServeurWidget);
    } // setupUi

    void retranslateUi(QWidget *ChasseAuTresorServeurWidget)
    {
        ChasseAuTresorServeurWidget->setWindowTitle(QCoreApplication::translate("ChasseAuTresorServeurWidget", "Serveur Chasse au tr\303\251sor", nullptr));
        labelEcoutePort->setText(QCoreApplication::translate("ChasseAuTresorServeurWidget", "Port d'\303\251coute", nullptr));
        pushButtonLancerServeur->setText(QCoreApplication::translate("ChasseAuTresorServeurWidget", "Lancer", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("ChasseAuTresorServeurWidget", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChasseAuTresorServeurWidget: public Ui_ChasseAuTresorServeurWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHASSEAUTRESORSERVEURWIDGET_H
