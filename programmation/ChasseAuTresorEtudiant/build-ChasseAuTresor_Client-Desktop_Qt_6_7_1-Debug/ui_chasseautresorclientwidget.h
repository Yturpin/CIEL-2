/********************************************************************************
** Form generated from reading UI file 'chasseautresorclientwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHASSEAUTRESORCLIENTWIDGET_H
#define UI_CHASSEAUTRESORCLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChasseAuTresorClientWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxInfo;
    QGridLayout *gridLayout;
    QLabel *labelDistance;
    QLCDNumber *lcdNumberDistance;
    QLabel *labelInformations;
    QGroupBox *groupBoxControle;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayoutConnexion;
    QLabel *labelAdresseServeur;
    QLineEdit *lineEditAdresseServeur;
    QLabel *labelNumeroPort;
    QSpinBox *spinBoxPortServeur;
    QPushButton *pushButtonConnexion;
    QPushButton *pushButtonQuitter;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayoutFleches;
    QPushButton *pushButtonUp;
    QPushButton *pushButtonLeft;
    QPushButton *pushButtonRight;
    QPushButton *pushButtonDown;

    void setupUi(QWidget *ChasseAuTresorClientWidget)
    {
        if (ChasseAuTresorClientWidget->objectName().isEmpty())
            ChasseAuTresorClientWidget->setObjectName("ChasseAuTresorClientWidget");
        ChasseAuTresorClientWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(ChasseAuTresorClientWidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxInfo = new QGroupBox(ChasseAuTresorClientWidget);
        groupBoxInfo->setObjectName("groupBoxInfo");
        gridLayout = new QGridLayout(groupBoxInfo);
        gridLayout->setObjectName("gridLayout");
        labelDistance = new QLabel(groupBoxInfo);
        labelDistance->setObjectName("labelDistance");
        labelDistance->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelDistance, 0, 0, 1, 1);

        lcdNumberDistance = new QLCDNumber(groupBoxInfo);
        lcdNumberDistance->setObjectName("lcdNumberDistance");
        lcdNumberDistance->setMinimumSize(QSize(0, 0));
        lcdNumberDistance->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        lcdNumberDistance->setFont(font);
        lcdNumberDistance->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdNumberDistance, 0, 1, 1, 1);

        labelInformations = new QLabel(groupBoxInfo);
        labelInformations->setObjectName("labelInformations");

        gridLayout->addWidget(labelInformations, 0, 2, 1, 1);


        verticalLayout->addWidget(groupBoxInfo);

        groupBoxControle = new QGroupBox(ChasseAuTresorClientWidget);
        groupBoxControle->setObjectName("groupBoxControle");
        gridLayout_3 = new QGridLayout(groupBoxControle);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayoutConnexion = new QGridLayout();
        gridLayoutConnexion->setObjectName("gridLayoutConnexion");
        labelAdresseServeur = new QLabel(groupBoxControle);
        labelAdresseServeur->setObjectName("labelAdresseServeur");

        gridLayoutConnexion->addWidget(labelAdresseServeur, 0, 0, 1, 1);

        lineEditAdresseServeur = new QLineEdit(groupBoxControle);
        lineEditAdresseServeur->setObjectName("lineEditAdresseServeur");

        gridLayoutConnexion->addWidget(lineEditAdresseServeur, 0, 1, 1, 1);

        labelNumeroPort = new QLabel(groupBoxControle);
        labelNumeroPort->setObjectName("labelNumeroPort");

        gridLayoutConnexion->addWidget(labelNumeroPort, 1, 0, 1, 1);

        spinBoxPortServeur = new QSpinBox(groupBoxControle);
        spinBoxPortServeur->setObjectName("spinBoxPortServeur");
        spinBoxPortServeur->setMinimum(8888);
        spinBoxPortServeur->setMaximum(9999);

        gridLayoutConnexion->addWidget(spinBoxPortServeur, 1, 1, 1, 1);

        pushButtonConnexion = new QPushButton(groupBoxControle);
        pushButtonConnexion->setObjectName("pushButtonConnexion");

        gridLayoutConnexion->addWidget(pushButtonConnexion, 2, 0, 1, 1);

        pushButtonQuitter = new QPushButton(groupBoxControle);
        pushButtonQuitter->setObjectName("pushButtonQuitter");

        gridLayoutConnexion->addWidget(pushButtonQuitter, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayoutConnexion, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        gridLayoutFleches = new QGridLayout();
        gridLayoutFleches->setObjectName("gridLayoutFleches");
        pushButtonUp = new QPushButton(groupBoxControle);
        pushButtonUp->setObjectName("pushButtonUp");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/arrow-top-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonUp->setIcon(icon);

        gridLayoutFleches->addWidget(pushButtonUp, 0, 1, 1, 1);

        pushButtonLeft = new QPushButton(groupBoxControle);
        pushButtonLeft->setObjectName("pushButtonLeft");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/arrow-left-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonLeft->setIcon(icon1);

        gridLayoutFleches->addWidget(pushButtonLeft, 1, 0, 1, 1);

        pushButtonRight = new QPushButton(groupBoxControle);
        pushButtonRight->setObjectName("pushButtonRight");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/arrow-right-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRight->setIcon(icon2);

        gridLayoutFleches->addWidget(pushButtonRight, 1, 2, 1, 1);

        pushButtonDown = new QPushButton(groupBoxControle);
        pushButtonDown->setObjectName("pushButtonDown");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/arrow-bottom-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDown->setIcon(icon3);

        gridLayoutFleches->addWidget(pushButtonDown, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayoutFleches, 0, 2, 1, 1);


        verticalLayout->addWidget(groupBoxControle);


        retranslateUi(ChasseAuTresorClientWidget);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, ChasseAuTresorClientWidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(ChasseAuTresorClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ChasseAuTresorClientWidget)
    {
        ChasseAuTresorClientWidget->setWindowTitle(QCoreApplication::translate("ChasseAuTresorClientWidget", "ChasseAuTresorClientWidget", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("ChasseAuTresorClientWidget", "Information", nullptr));
        labelDistance->setText(QCoreApplication::translate("ChasseAuTresorClientWidget", "Distance :", nullptr));
        labelInformations->setText(QCoreApplication::translate("ChasseAuTresorClientWidget", "Informations", nullptr));
        groupBoxControle->setTitle(QCoreApplication::translate("ChasseAuTresorClientWidget", "Contr\303\264le", nullptr));
        labelAdresseServeur->setText(QCoreApplication::translate("ChasseAuTresorClientWidget", "Adresse du serveur :", nullptr));
        lineEditAdresseServeur->setText(QCoreApplication::translate("ChasseAuTresorClientWidget", "127.0.0.1", nullptr));
        labelNumeroPort->setText(QCoreApplication::translate("ChasseAuTresorClientWidget", "Port :", nullptr));
        pushButtonConnexion->setText(QCoreApplication::translate("ChasseAuTresorClientWidget", "Connexion", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("ChasseAuTresorClientWidget", "Quitter", nullptr));
        pushButtonUp->setText(QString());
        pushButtonLeft->setText(QString());
        pushButtonRight->setText(QString());
        pushButtonDown->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChasseAuTresorClientWidget: public Ui_ChasseAuTresorClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHASSEAUTRESORCLIENTWIDGET_H
