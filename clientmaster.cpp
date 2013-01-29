#include "myfile.h"
#include "clientmaster.h"
#include <QStringList>

ClientMaster::ClientMaster(QString ip, int port)
{
    this->ip = ip;
    this->port = port;
    this->mySocket = new QTcpSocket();
}


int ClientMaster::login(QString log, QString pass) {
    mySocket->connectToHost(ip, port);
    if(!mySocket->waitForConnected(10000)) {
        return CONNECTION_FAILED;
    }
    QString request = "LOGIN\nlogin:" + log + "\npasswd:" + pass + "\n";
    mySocket->write(request.toAscii());
    mySocket->waitForReadyRead(10000);
    QString response = mySocket->readAll();
    if(response.startsWith("WRONG LOG")) return WRONG_PASSWORD;
    else if(response.startsWith("SUCCESS")) {
        this->log = log;
        this->pass = pass;
        this->ssid = response.remove(0, 10);
        this->ssid = ssid.trimmed();
        return LOGIN_SUCC;
    }
    mySocket->disconnect();
    return ClientMaster::LOGIN_SUCC;
}


 void ClientMaster::getMyFiles(QList< QPair <QString, QString> > * L1, QList< QPair <QString, QString> > * L2) {
    mySocket->connectToHost(ip, port);
    if(!mySocket->waitForConnected(10000)) {
        throw ClientMaster::CONNECTION_FAILED;
    }
    char c[100];
    myFile::qstringToChar("GETLIST\nlogin:" + this->log + "\nssid:" + this->ssid, c);
    mySocket->write(c);
    mySocket->waitForReadyRead();
    QString response = mySocket->readAll();
    mySocket->disconnect();
    if(response.startsWith("|WRONG|")) throw ClientMaster::WRONG_PASSWORD;
    QString folders = response.split(">>>", QString::SkipEmptyParts)[0];
    QString files = response.split(">>>", QString::SkipEmptyParts)[1];
    QStringList foldersList = folders.split("\n", QString::SkipEmptyParts);
    QStringList filesList = (files.split("\n", QString::SkipEmptyParts));
    for(int i = 0; i < foldersList.size(); ++i) L1->append(qMakePair(foldersList[i].split(":")[0], foldersList[i].split(":")[1]));
    for(int i = 0; i < filesList.size(); ++i) L2->append(qMakePair(filesList[i].split(":")[0], filesList[i].split(":")[1]));
}

void ClientMaster::logout() {
    mySocket->connectToHost(ip, port);
    if(!mySocket->waitForConnected(10000)) {
        return;
    }
    mySocket->write("LOGOUT");
    mySocket->disconnect();
}

int ClientMaster::upload(QString) {
    //TODO
}

int ClientMaster::download(QString) {
    //TODO
}
