/********************************************************************************
** Form generated from reading UI file 'clientfiestawidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTFIESTAWIDGET_H
#define UI_CLIENTFIESTAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientFiestaWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonConnexion;
    QLineEdit *lineEditPropMot;
    QPushButton *pushButtonPropMot;
    QPushButton *pushButtonQuitter;
    QPushButton *pushButtonNewGame;
    QTextEdit *textEdit;
    QLineEdit *lineEditPseudo;

    void setupUi(QWidget *ClientFiestaWidget)
    {
        if (ClientFiestaWidget->objectName().isEmpty())
            ClientFiestaWidget->setObjectName("ClientFiestaWidget");
        ClientFiestaWidget->resize(800, 600);
        layoutWidget = new QWidget(ClientFiestaWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(179, 160, 411, 201));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonConnexion = new QPushButton(layoutWidget);
        pushButtonConnexion->setObjectName("pushButtonConnexion");

        gridLayout->addWidget(pushButtonConnexion, 0, 0, 1, 2);

        lineEditPropMot = new QLineEdit(layoutWidget);
        lineEditPropMot->setObjectName("lineEditPropMot");

        gridLayout->addWidget(lineEditPropMot, 1, 0, 1, 1);

        pushButtonPropMot = new QPushButton(layoutWidget);
        pushButtonPropMot->setObjectName("pushButtonPropMot");

        gridLayout->addWidget(pushButtonPropMot, 1, 1, 1, 1);

        pushButtonQuitter = new QPushButton(layoutWidget);
        pushButtonQuitter->setObjectName("pushButtonQuitter");

        gridLayout->addWidget(pushButtonQuitter, 2, 0, 1, 1);

        pushButtonNewGame = new QPushButton(layoutWidget);
        pushButtonNewGame->setObjectName("pushButtonNewGame");

        gridLayout->addWidget(pushButtonNewGame, 2, 1, 1, 1);

        textEdit = new QTextEdit(ClientFiestaWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(340, 399, 361, 121));
        lineEditPseudo = new QLineEdit(ClientFiestaWidget);
        lineEditPseudo->setObjectName("lineEditPseudo");
        lineEditPseudo->setGeometry(QRect(200, 130, 171, 22));

        retranslateUi(ClientFiestaWidget);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, ClientFiestaWidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(ClientFiestaWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientFiestaWidget)
    {
        ClientFiestaWidget->setWindowTitle(QCoreApplication::translate("ClientFiestaWidget", "ClientFiestaWidget", nullptr));
        pushButtonConnexion->setText(QCoreApplication::translate("ClientFiestaWidget", "Connexion", nullptr));
        pushButtonPropMot->setText(QCoreApplication::translate("ClientFiestaWidget", "Proposition", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("ClientFiestaWidget", "Quitter", nullptr));
        pushButtonNewGame->setText(QCoreApplication::translate("ClientFiestaWidget", "New Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientFiestaWidget: public Ui_ClientFiestaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTFIESTAWIDGET_H
