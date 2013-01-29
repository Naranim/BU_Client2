#ifndef LOGIN_H
#define LOGIN_H


#include <QDialog>
#include <QTcpSocket>
#include "mainwindow.h"
#include "clientmaster.h"
//#include "buconfig.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(MainWindow * mainWindow, ClientMaster * clientMaster, QWidget *parent = 0);
    ~Login();

private:
    Ui::Login *ui;
    MainWindow * mainWindow;
    QString * sessionId;
    QTcpSocket * mySocket;
    void setInfo(QString);
    ClientMaster * clientMaster;

private slots:
    void OKButtonPressed();
    void cancelButtonPressed();
    void textChanged();
};


#endif // LOGIN_H
