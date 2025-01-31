#ifndef SPLITTERWIDGET_H
#define SPLITTERWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class SplitterWidget;
}
QT_END_NAMESPACE

class SplitterWidget : public QWidget
{
    Q_OBJECT

public:
    SplitterWidget(QWidget *parent = nullptr);
    ~SplitterWidget();

private slots:
    void on_pushButtonDecoder_clicked();

private:
    Ui::SplitterWidget *ui;
};
#endif // SPLITTERWIDGET_H
