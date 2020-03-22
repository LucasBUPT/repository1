#ifndef WIDGET_H
#define WIDGET_H

#include<QWidget>
#include<QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
   // void dealMsg();

private slots:
    void on_checkBox1_clicked(bool checked);
    void on_checkBox2_clicked(bool checked);
    void on_checkBox3_clicked(bool checked);

private:
    Ui::Widget *ui;
    QUdpSocket *udpsocket;
};

#endif // WIDGET_H
