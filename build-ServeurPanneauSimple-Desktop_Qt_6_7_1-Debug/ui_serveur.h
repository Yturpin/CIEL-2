/********************************************************************************
** Form generated from reading UI file 'serveur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVEUR_H
#define UI_SERVEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serveur
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditInformation;
    QPushButton *pushButtonDiffuser;
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QListWidget *listWidgetMessage;
    QPushButton *pushButtonSupMessage;
    QPushButton *pushButtonLancerDiffusion;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTextEdit *textEditAlerte;
    QPushButton *pushButtonCreerAlerte;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextEdit *textEditInformation_2;
    QPushButton *pushButtonAjouterMessage;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEditMeteo;
    QPushButton *pushButtonModifBulletinMeteo;

    void setupUi(QWidget *Serveur)
    {
        if (Serveur->objectName().isEmpty())
            Serveur->setObjectName("Serveur");
        Serveur->resize(1005, 600);
        layoutWidget = new QWidget(Serveur);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(910, 410, 171, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEditInformation = new QTextEdit(layoutWidget);
        textEditInformation->setObjectName("textEditInformation");

        verticalLayout->addWidget(textEditInformation);

        pushButtonDiffuser = new QPushButton(layoutWidget);
        pushButtonDiffuser->setObjectName("pushButtonDiffuser");

        verticalLayout->addWidget(pushButtonDiffuser);

        widget = new QWidget(Serveur);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 0, 821, 576));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        listWidgetMessage = new QListWidget(widget);
        listWidgetMessage->setObjectName("listWidgetMessage");

        verticalLayout_4->addWidget(listWidgetMessage);

        pushButtonSupMessage = new QPushButton(widget);
        pushButtonSupMessage->setObjectName("pushButtonSupMessage");

        verticalLayout_4->addWidget(pushButtonSupMessage);


        gridLayout->addLayout(verticalLayout_4, 0, 1, 2, 1);

        pushButtonLancerDiffusion = new QPushButton(widget);
        pushButtonLancerDiffusion->setObjectName("pushButtonLancerDiffusion");

        gridLayout->addWidget(pushButtonLancerDiffusion, 3, 0, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        textEditAlerte = new QTextEdit(widget);
        textEditAlerte->setObjectName("textEditAlerte");

        verticalLayout_3->addWidget(textEditAlerte);

        pushButtonCreerAlerte = new QPushButton(widget);
        pushButtonCreerAlerte->setObjectName("pushButtonCreerAlerte");

        verticalLayout_3->addWidget(pushButtonCreerAlerte);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        textEditInformation_2 = new QTextEdit(widget);
        textEditInformation_2->setObjectName("textEditInformation_2");

        verticalLayout_2->addWidget(textEditInformation_2);

        pushButtonAjouterMessage = new QPushButton(widget);
        pushButtonAjouterMessage->setObjectName("pushButtonAjouterMessage");

        verticalLayout_2->addWidget(pushButtonAjouterMessage);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout_5->addWidget(label_3);

        lineEditMeteo = new QLineEdit(widget);
        lineEditMeteo->setObjectName("lineEditMeteo");

        verticalLayout_5->addWidget(lineEditMeteo);


        gridLayout->addLayout(verticalLayout_5, 2, 0, 1, 1);

        pushButtonModifBulletinMeteo = new QPushButton(widget);
        pushButtonModifBulletinMeteo->setObjectName("pushButtonModifBulletinMeteo");

        gridLayout->addWidget(pushButtonModifBulletinMeteo, 2, 1, 1, 1);


        retranslateUi(Serveur);

        QMetaObject::connectSlotsByName(Serveur);
    } // setupUi

    void retranslateUi(QWidget *Serveur)
    {
        Serveur->setWindowTitle(QCoreApplication::translate("Serveur", "Serveur", nullptr));
        pushButtonDiffuser->setText(QCoreApplication::translate("Serveur", "Diffuser", nullptr));
        label_4->setText(QCoreApplication::translate("Serveur", "Liste de messages en cours de diffusion : ", nullptr));
        pushButtonSupMessage->setText(QCoreApplication::translate("Serveur", "Supprimer un message", nullptr));
        pushButtonLancerDiffusion->setText(QCoreApplication::translate("Serveur", "Lancer la diffusion", nullptr));
        label_2->setText(QCoreApplication::translate("Serveur", "Message d'alerte : ", nullptr));
        pushButtonCreerAlerte->setText(QCoreApplication::translate("Serveur", "Cr\303\251er une alerte", nullptr));
        label->setText(QCoreApplication::translate("Serveur", "Message d'information : ", nullptr));
        pushButtonAjouterMessage->setText(QCoreApplication::translate("Serveur", "Ajouter un message", nullptr));
        label_3->setText(QCoreApplication::translate("Serveur", "Bulletin m\303\251t\303\251o : ", nullptr));
        pushButtonModifBulletinMeteo->setText(QCoreApplication::translate("Serveur", "Modifier le bulletin m\303\251teo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Serveur: public Ui_Serveur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVEUR_H
