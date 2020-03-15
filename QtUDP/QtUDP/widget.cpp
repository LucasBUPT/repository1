#include "widget.h"
#include "ui_widget.h"
#include<QHostAddress>                //QHostAddress类提供一个IP地址

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpsocket=new QUdpSocket(this);    //指定父对象主要为了回收
    udpsocket->bind(8000);             //设置端口
    setWindowTitle("8000");
    connect(udpsocket,&QUdpSocket::readyRead,this,&Widget::dealMsg);    //发数据过来触发readyRead
}

void Widget::dealMsg(){              //接收数据的函数
    char buff[1024]={0,};            //定义一个缓冲区初始化为0
    QHostAddress clientAdd;
    quint16 port;                    //16位无符号整型

    udpsocket->readDatagram(buff,sizeof(buff),&clientAdd,&port);   //读取文件
    QString str=QString("[%1:%2] %3")
            .arg(clientAdd.toString()).arg(port).arg(buff);
    ui->textEdit->setText(str);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonSend_clicked(){                  //发送数据的函数
    QString ip=ui->lineEditIP->text();                 //取出IP栏内的内容
    quint16 port=ui->lineEditPort->text().toInt();     //取出Port栏内的整型内容
    QString str=ui->textEdit->toPlainText();           //取出传输内容
    udpsocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);     //发送固定格式的数据报
}
