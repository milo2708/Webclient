#ifndef WEBCLIENT_H
#define WEBCLIENT_H
#include "ui_webclient.h"
#include <QAbstractSocket>
#include <QTcpSocket>

class Webclient : public QWidget, private Ui::Webclient
{
    Q_OBJECT

public:
    explicit Webclient(QWidget *parent = nullptr);
private slots:
    void on_button_clicked();
    void tcp_connect();
    void tcp_receive();
private:
    QTcpSocket* m_socket = nullptr;
    const unsigned short m_port = 80;
    QByteArray m_hostname;
};

#endif // WEBCLIENT_H
