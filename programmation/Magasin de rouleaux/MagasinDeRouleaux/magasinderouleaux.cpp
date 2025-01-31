#include "magasinderouleaux.h"
#include "ui_magasinderouleaux.h"

MagasinDeRouleaux::MagasinDeRouleaux(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MagasinDeRouleaux)
{
    ui->setupUi(this);
}

MagasinDeRouleaux::~MagasinDeRouleaux()
{
    delete ui;
}
