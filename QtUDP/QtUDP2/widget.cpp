#include "widget.h"
#include "ui_widget.h"
//#include<QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
        udpsocket=new QUdpSocket(this);
        udpsocket->bind(8001);
        setWindowTitle("8001");
        connect(udpsocket,&QUdpSocket::readyRead,this,&Widget::dealMsg);
}

void Widget::dealMsg()
{
    char buff[1024]={0,};
    QHostAddress  clientAdd;
    quint16 port;

    udpsocket->readDatagram(buff,sizeof(buff),&clientAdd,&port);
    QString str=QString("[%1:%2] %3")
            .arg(clientAdd.toString()).arg(port).arg(buff);
    ui->textEdit->setText(str);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonSend_clicked()
{
    //获取对方ip和端口
    QString ip=ui->lineEditIP->text(); //text（）是字符串
    quint16  port=ui->lineEditPort->text().toInt(); //转化为整形
    //获取编辑区内容
    QString str=ui->textEdit->toPlainText();
    //发送信息
    udpsocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}
