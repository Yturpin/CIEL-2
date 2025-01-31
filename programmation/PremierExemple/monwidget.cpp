#include "monwidget.h"
#include "ui_monwidget.h"
#include <QMessageBox>

MonWidget::MonWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MonWidget)
{
    ui->setupUi(this);
}

MonWidget::~MonWidget()
{
    delete ui;
}

void MonWidget::on_AppuieLeVieux_clicked()
{
    QMessageBox message;
    message.setText("Bjr le vieux");
    message.exec();
    ui->AppuieLeVieux->setText("On Dit Kwé");           //renomme le bouton
}

