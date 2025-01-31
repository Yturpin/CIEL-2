/********************************************************************************
** Form generated from reading UI file 'agencebancaire.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENCEBANCAIRE_H
#define UI_AGENCEBANCAIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgenceBancaire
{
public:
    QTabWidget *tabWidget;
    QWidget *ConnexionBDD;
    QLabel *label_5;
    QPushButton *pushButtonConnexio;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditAdresseIP;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEditBdd;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditMotDePasse;
    QLabel *label;
    QWidget *AjoutClient;
    QPushButton *pushButtonAjouter;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditVille;
    QLineEdit *lineEditNom;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEditSolde;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEditNumeroCompte;
    QLabel *label_8;
    QLineEdit *lineEditPrenom;
    QComboBox *comboBoxAgences1;
    QWidget *ConsultationsClients;
    QTableView *tableView;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxAgences2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_12;
    QLineEdit *lineEdit;

    void setupUi(QWidget *AgenceBancaire)
    {
        if (AgenceBancaire->objectName().isEmpty())
            AgenceBancaire->setObjectName("AgenceBancaire");
        AgenceBancaire->resize(800, 600);
        tabWidget = new QTabWidget(AgenceBancaire);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 80, 651, 451));
        ConnexionBDD = new QWidget();
        ConnexionBDD->setObjectName("ConnexionBDD");
        label_5 = new QLabel(ConnexionBDD);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 70, 122, 15));
        pushButtonConnexio = new QPushButton(ConnexionBDD);
        pushButtonConnexio->setObjectName("pushButtonConnexio");
        pushButtonConnexio->setGeometry(QRect(189, 370, 431, 23));
        layoutWidget = new QWidget(ConnexionBDD);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 90, 611, 251));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditAdresseIP = new QLineEdit(layoutWidget);
        lineEditAdresseIP->setObjectName("lineEditAdresseIP");

        gridLayout->addWidget(lineEditAdresseIP, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditBdd = new QLineEdit(layoutWidget);
        lineEditBdd->setObjectName("lineEditBdd");

        gridLayout->addWidget(lineEditBdd, 1, 1, 1, 1);

        lineEditLogin = new QLineEdit(layoutWidget);
        lineEditLogin->setObjectName("lineEditLogin");

        gridLayout->addWidget(lineEditLogin, 2, 1, 1, 1);

        lineEditMotDePasse = new QLineEdit(layoutWidget);
        lineEditMotDePasse->setObjectName("lineEditMotDePasse");

        gridLayout->addWidget(lineEditMotDePasse, 3, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget->addTab(ConnexionBDD, QString());
        AjoutClient = new QWidget();
        AjoutClient->setObjectName("AjoutClient");
        pushButtonAjouter = new QPushButton(AjoutClient);
        pushButtonAjouter->setObjectName("pushButtonAjouter");
        pushButtonAjouter->setGeometry(QRect(139, 380, 501, 23));
        layoutWidget1 = new QWidget(AjoutClient);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 40, 631, 321));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditVille = new QLineEdit(layoutWidget1);
        lineEditVille->setObjectName("lineEditVille");

        gridLayout_2->addWidget(lineEditVille, 4, 1, 1, 1);

        lineEditNom = new QLineEdit(layoutWidget1);
        lineEditNom->setObjectName("lineEditNom");

        gridLayout_2->addWidget(lineEditNom, 0, 1, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName("label_9");

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        lineEditSolde = new QLineEdit(layoutWidget1);
        lineEditSolde->setObjectName("lineEditSolde");

        gridLayout_2->addWidget(lineEditSolde, 3, 1, 1, 1);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName("label_10");

        gridLayout_2->addWidget(label_10, 4, 0, 1, 1);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName("label_11");

        gridLayout_2->addWidget(label_11, 6, 0, 1, 1);

        lineEditNumeroCompte = new QLineEdit(layoutWidget1);
        lineEditNumeroCompte->setObjectName("lineEditNumeroCompte");

        gridLayout_2->addWidget(lineEditNumeroCompte, 2, 1, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        lineEditPrenom = new QLineEdit(layoutWidget1);
        lineEditPrenom->setObjectName("lineEditPrenom");

        gridLayout_2->addWidget(lineEditPrenom, 1, 1, 1, 1);

        comboBoxAgences1 = new QComboBox(layoutWidget1);
        comboBoxAgences1->setObjectName("comboBoxAgences1");

        gridLayout_2->addWidget(comboBoxAgences1, 6, 1, 1, 1);

        tabWidget->addTab(AjoutClient, QString());
        ConsultationsClients = new QWidget();
        ConsultationsClients->setObjectName("ConsultationsClients");
        tableView = new QTableView(ConsultationsClients);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 90, 621, 311));
        layoutWidget2 = new QWidget(ConsultationsClients);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(13, 40, 621, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBoxAgences2 = new QComboBox(layoutWidget2);
        comboBoxAgences2->setObjectName("comboBoxAgences2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxAgences2->sizePolicy().hasHeightForWidth());
        comboBoxAgences2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(comboBoxAgences2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName("label_12");

        horizontalLayout->addWidget(label_12);

        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        tabWidget->addTab(ConsultationsClients, QString());

        retranslateUi(AgenceBancaire);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(AgenceBancaire);
    } // setupUi

    void retranslateUi(QWidget *AgenceBancaire)
    {
        AgenceBancaire->setWindowTitle(QCoreApplication::translate("AgenceBancaire", "AgenceBancaire", nullptr));
        label_5->setText(QCoreApplication::translate("AgenceBancaire", "Connexion \303\240 la BDD", nullptr));
        pushButtonConnexio->setText(QCoreApplication::translate("AgenceBancaire", "Connexion", nullptr));
        label_3->setText(QCoreApplication::translate("AgenceBancaire", "Login : ", nullptr));
        label_4->setText(QCoreApplication::translate("AgenceBancaire", "Mot de passe : ", nullptr));
        label_2->setText(QCoreApplication::translate("AgenceBancaire", "Nom de la base de donn\303\251es : ", nullptr));
        label->setText(QCoreApplication::translate("AgenceBancaire", "Adresse IP : ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ConnexionBDD), QCoreApplication::translate("AgenceBancaire", "Connexion BDD", nullptr));
        pushButtonAjouter->setText(QCoreApplication::translate("AgenceBancaire", "Ajouter", nullptr));
        label_9->setText(QCoreApplication::translate("AgenceBancaire", "Solde : ", nullptr));
        label_6->setText(QCoreApplication::translate("AgenceBancaire", "Nom : ", nullptr));
        label_7->setText(QCoreApplication::translate("AgenceBancaire", "Pr\303\251nom : ", nullptr));
        label_10->setText(QCoreApplication::translate("AgenceBancaire", "Ville : ", nullptr));
        label_11->setText(QCoreApplication::translate("AgenceBancaire", "Agence : ", nullptr));
        label_8->setText(QCoreApplication::translate("AgenceBancaire", "Num\303\251ro de compte : ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AjoutClient), QCoreApplication::translate("AgenceBancaire", "Ajout Client", nullptr));
        label_12->setText(QCoreApplication::translate("AgenceBancaire", "Nombre de clients dans l'agence : ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ConsultationsClients), QCoreApplication::translate("AgenceBancaire", "Consultation Clients", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgenceBancaire: public Ui_AgenceBancaire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENCEBANCAIRE_H
