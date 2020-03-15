#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QUdpSocket>      //QUdpSocket类用于UDP通信

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void dealMsg();

private slots:                  //定义槽函数
    void on_buttonSend_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *udpsocket;
};

#endif // WIDGET_H
