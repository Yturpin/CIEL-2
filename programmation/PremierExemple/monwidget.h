#ifndef MONWIDGET_H
#define MONWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MonWidget;
}
QT_END_NAMESPACE

class MonWidget : public QWidget
{
    Q_OBJECT

public:
    MonWidget(QWidget *parent = nullptr);
    ~MonWidget();

private slots:
    void on_AppuieLeVieux_clicked();

private:
    Ui::MonWidget *ui;
};
#endif // MONWIDGET_H
