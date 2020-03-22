#include "widget.h"
#include "ui_widget.h"
#include "qcheckbox.h"
#include<QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpsocket=new QUdpSocket(this);
    udpsocket->bind(8000);
    setWindowTitle("8000");
    //connect(udpsocket,&QUdpSocket::readyRead,this,&Widget::dealMsg);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_checkBox1_clicked(bool checked)
{
    QString ip=ui->lineEditIP->text();
    quint16 port=ui->lineEditPort->text().toInt();
    if(ui->checkBox1->isChecked()==true){
        QString checkBox="1";
        udpsocket->writeDatagram(checkBox.toUtf8(),QHostAddress(ip),port);
    }else{
        QString checkBox="4";
        udpsocket->writeDatagram(checkBox.toUtf8(),QHostAddress(ip),port);
    }
}

void Widget::on_checkBox2_clicked(bool checked)
{
    QString ip=ui->lineEditIP->text();
    quint16 port=ui->lineEditPort->text().toInt();
    if(ui->checkBox2->isChecked()==true){
        QString checkBox="2";
        udpsocket->writeDatagram(checkBox.toUtf8(),QHostAddress(ip),port);
    }else{
        QString checkBox="5";
        udpsocket->writeDatagram(checkBox.toUtf8(),QHostAddress(ip),port);
    }
}

void Widget::on_checkBox3_clicked(bool checked)
{
    QString ip=ui->lineEditIP->text();
    quint16 port=ui->lineEditPort->text().toInt();
    if(ui->checkBox3->isChecked()==true){
        QString checkBox="3";
        udpsocket->writeDatagram(checkBox.toUtf8(),QHostAddress(ip),port);
    }else{
        QString checkBox="6";
        udpsocket->writeDatagram(checkBox.toUtf8(),QHostAddress(ip),port);
    }
}
