/********************************************************************************
** Form generated from reading UI file 'auditserveurwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDITSERVEURWIDGET_H
#define UI_AUDITSERVEURWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuditServeurWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButtonLancementServeur;
    QPushButton *pushButtonQuitter;
    QTextEdit *textEditInformations;
    QSpinBox *spinBoxPort;

    void setupUi(QWidget *AuditServeurWidget)
    {
        if (AuditServeurWidget->objectName().isEmpty())
            AuditServeurWidget->setObjectName("AuditServeurWidget");
        AuditServeurWidget->resize(800, 600);
        label = new QLabel(AuditServeurWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 80, 95, 15));
        label_2 = new QLabel(AuditServeurWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 160, 76, 15));
        pushButtonLancementServeur = new QPushButton(AuditServeurWidget);
        pushButtonLancementServeur->setObjectName("pushButtonLancementServeur");
        pushButtonLancementServeur->setGeometry(QRect(140, 120, 441, 23));
        pushButtonQuitter = new QPushButton(AuditServeurWidget);
        pushButtonQuitter->setObjectName("pushButtonQuitter");
        pushButtonQuitter->setGeometry(QRect(140, 440, 441, 61));
        textEditInformations = new QTextEdit(AuditServeurWidget);
        textEditInformations->setObjectName("textEditInformations");
        textEditInformations->setGeometry(QRect(140, 180, 441, 241));
        spinBoxPort = new QSpinBox(AuditServeurWidget);
        spinBoxPort->setObjectName("spinBoxPort");
        spinBoxPort->setGeometry(QRect(300, 80, 281, 23));
        spinBoxPort->setMinimum(1025);
        spinBoxPort->setMaximum(65535);

        retranslateUi(AuditServeurWidget);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, AuditServeurWidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(AuditServeurWidget);
    } // setupUi

    void retranslateUi(QWidget *AuditServeurWidget)
    {
        AuditServeurWidget->setWindowTitle(QCoreApplication::translate("AuditServeurWidget", "AuditServeurWidget", nullptr));
        label->setText(QCoreApplication::translate("AuditServeurWidget", "Num\303\251ro de port", nullptr));
        label_2->setText(QCoreApplication::translate("AuditServeurWidget", "Informations", nullptr));
        pushButtonLancementServeur->setText(QCoreApplication::translate("AuditServeurWidget", "Lancement serveur", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("AuditServeurWidget", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuditServeurWidget: public Ui_AuditServeurWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDITSERVEURWIDGET_H
