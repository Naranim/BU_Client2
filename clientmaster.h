#ifndef CLIENTMASTER_H
#define CLIENTMASTER_H
#include <QString>
#include <QTcpSocket>
#include <QList>
#include <QPair>

class ClientMaster
{
public:
    ClientMaster(QString ip, int port);
    int login(QString, QString);
    void getMyFiles(QList< QPair <QString, QString> > *, QList<QPair<QString, QString> > *);
    void logout();
    int upload(QString);
    int download(QString);

    static const int WRONG_PASSWORD = 0;
    static const int LOGIN_SUCC = 1;
    static const int CONNECTION_FAILED = 2;

private:
    QString ip;
    int port;
    QTcpSocket * mySocket;
    QString ssid;
    QString log;
    QString pass;
};



#endif // CLIENTMASTER_H
