/********************************************************************************
** Form generated from reading UI file 'auditclientwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDITCLIENTWIDGET_H
#define UI_AUDITCLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuditClientWidget
{
public:
    QGroupBox *groupBoxInformationClient;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonOrdinateur;
    QPushButton *pushButtonUtilisateur;
    QPushButton *pushButtonProcesseur;
    QPushButton *pushButtonOs;
    QLineEdit *lineEditOs;
    QLineEdit *lineEditProcesseur;
    QLineEdit *lineEditUtilisateur;
    QLineEdit *lineEditOrdinateur;
    QGroupBox *groupBox_2;
    QTextEdit *textEditEtat;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditAdresseIP;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEditPort;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonQuitter;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonConnexion;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label;

    void setupUi(QWidget *AuditClientWidget)
    {
        if (AuditClientWidget->objectName().isEmpty())
            AuditClientWidget->setObjectName("AuditClientWidget");
        AuditClientWidget->resize(985, 632);
        groupBoxInformationClient = new QGroupBox(AuditClientWidget);
        groupBoxInformationClient->setObjectName("groupBoxInformationClient");
        groupBoxInformationClient->setGeometry(QRect(10, 300, 741, 251));
        widget = new QWidget(groupBoxInformationClient);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 30, 671, 196));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonOrdinateur = new QPushButton(widget);
        pushButtonOrdinateur->setObjectName("pushButtonOrdinateur");

        gridLayout_3->addWidget(pushButtonOrdinateur, 3, 0, 1, 1);

        pushButtonUtilisateur = new QPushButton(widget);
        pushButtonUtilisateur->setObjectName("pushButtonUtilisateur");

        gridLayout_3->addWidget(pushButtonUtilisateur, 4, 0, 1, 1);

        pushButtonProcesseur = new QPushButton(widget);
        pushButtonProcesseur->setObjectName("pushButtonProcesseur");

        gridLayout_3->addWidget(pushButtonProcesseur, 5, 0, 1, 1);

        pushButtonOs = new QPushButton(widget);
        pushButtonOs->setObjectName("pushButtonOs");

        gridLayout_3->addWidget(pushButtonOs, 6, 0, 1, 1);

        lineEditOs = new QLineEdit(widget);
        lineEditOs->setObjectName("lineEditOs");

        gridLayout_3->addWidget(lineEditOs, 6, 1, 1, 1);

        lineEditProcesseur = new QLineEdit(widget);
        lineEditProcesseur->setObjectName("lineEditProcesseur");

        gridLayout_3->addWidget(lineEditProcesseur, 5, 1, 1, 1);

        lineEditUtilisateur = new QLineEdit(widget);
        lineEditUtilisateur->setObjectName("lineEditUtilisateur");

        gridLayout_3->addWidget(lineEditUtilisateur, 4, 1, 1, 1);

        lineEditOrdinateur = new QLineEdit(widget);
        lineEditOrdinateur->setObjectName("lineEditOrdinateur");

        gridLayout_3->addWidget(lineEditOrdinateur, 3, 1, 1, 1);

        groupBox_2 = new QGroupBox(AuditClientWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 30, 971, 231));
        textEditEtat = new QTextEdit(groupBox_2);
        textEditEtat->setObjectName("textEditEtat");
        textEditEtat->setGeometry(QRect(430, 30, 521, 171));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 391, 161));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(48, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 2);

        lineEditAdresseIP = new QLineEdit(layoutWidget);
        lineEditAdresseIP->setObjectName("lineEditAdresseIP");

        gridLayout->addWidget(lineEditAdresseIP, 0, 4, 2, 1);

        horizontalSpacer = new QSpacerItem(48, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 2, 2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        lineEditPort = new QLineEdit(layoutWidget);
        lineEditPort->setObjectName("lineEditPort");

        gridLayout->addWidget(lineEditPort, 2, 4, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 2, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonQuitter = new QPushButton(layoutWidget);
        pushButtonQuitter->setObjectName("pushButtonQuitter");
        pushButtonQuitter->setEnabled(true);

        horizontalLayout->addWidget(pushButtonQuitter);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButtonConnexion = new QPushButton(layoutWidget);
        pushButtonConnexion->setObjectName("pushButtonConnexion");

        horizontalLayout->addWidget(pushButtonConnexion);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(430, 10, 120, 15));
        label_4 = new QLabel(AuditClientWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 280, 112, 15));
        label = new QLabel(AuditClientWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 128, 15));

        retranslateUi(AuditClientWidget);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, AuditClientWidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(AuditClientWidget);
    } // setupUi

    void retranslateUi(QWidget *AuditClientWidget)
    {
        AuditClientWidget->setWindowTitle(QCoreApplication::translate("AuditClientWidget", "AuditClientWidget", nullptr));
        groupBoxInformationClient->setTitle(QString());
        pushButtonOrdinateur->setText(QCoreApplication::translate("AuditClientWidget", "Nom de l'ordinateur distant", nullptr));
        pushButtonUtilisateur->setText(QCoreApplication::translate("AuditClientWidget", "Nom de l'utilisateur", nullptr));
        pushButtonProcesseur->setText(QCoreApplication::translate("AuditClientWidget", "Architecture processeur", nullptr));
        pushButtonOs->setText(QCoreApplication::translate("AuditClientWidget", "OS de l'ordinateur", nullptr));
        groupBox_2->setTitle(QString());
        label_3->setText(QCoreApplication::translate("AuditClientWidget", "Num\303\251ro de port du serveur :", nullptr));
        label_2->setText(QCoreApplication::translate("AuditClientWidget", "Adresse IPdu serveur :", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("AuditClientWidget", "Quitter", nullptr));
        pushButtonConnexion->setText(QCoreApplication::translate("AuditClientWidget", "Connexion", nullptr));
        label_5->setText(QCoreApplication::translate("AuditClientWidget", "Etat de la connexion", nullptr));
        label_4->setText(QCoreApplication::translate("AuditClientWidget", "Informations client", nullptr));
        label->setText(QCoreApplication::translate("AuditClientWidget", "Connexion au serveur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuditClientWidget: public Ui_AuditClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDITCLIENTWIDGET_H
