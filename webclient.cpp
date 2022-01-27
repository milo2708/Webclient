#include "webclient.h"

Webclient::Webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_socket = new QTcpSocket();

    connect(m_socket, &QTcpSocket::connected, this, &Webclient::tcp_connect);
    connect(m_socket, &QTcpSocket::readyRead, this, &Webclient::tcp_receive);
}

void Webclient::on_button_clicked()
{
    output->clear();
    QString address = input->text();
    m_socket->connectToHost(address, m_port);
    if(!m_socket->waitForConnected(5000))
    {
        output->setTextColor(QColor::fromRgb(255, 0, 0));
        output->setText("connect failed!");
        output->setTextColor(QColor::fromRgb(0, 0, 0));
        m_socket->disconnectFromHost();
    }
}

void Webclient::tcp_connect()
{
     m_socket->write("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n");
}

void Webclient::tcp_receive()
{
    output->setText(m_socket->readAll());
    m_socket->disconnectFromHost();
}
