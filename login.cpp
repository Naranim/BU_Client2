#include "login.h"
#include "ui_login.h"
#include "clientmaster.h"

Login::Login(MainWindow * mainWindow, ClientMaster *clientMaster, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login),
    mainWindow(mainWindow),
    clientMaster(clientMaster)
{
    this->mySocket = new QTcpSocket(this);
    ui->setupUi(this);
    ui->OKButton->setEnabled(false);
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancelButtonPressed()));
    connect(ui->OKButton, SIGNAL(clicked()), this, SLOT(OKButtonPressed()));
    connect(ui->loginTextField, SIGNAL(textChanged(QString)), this, SLOT(textChanged()));
    connect(ui->passwdTextField, SIGNAL(textChanged(QString)), this, SLOT(textChanged()));
}

Login::~Login() {
    delete ui;
}


void Login::OKButtonPressed() {
    setInfo("Connecting...");
    qDebug() << "Heh";
    int response = clientMaster->login(ui->loginTextField->text(), ui->passwdTextField->text());
    switch (response) {
        case ClientMaster::CONNECTION_FAILED:
            setInfo("Connection failed");
            break;
        case ClientMaster::WRONG_PASSWORD:
            setInfo("Wrong login or password");
            break;
        case ClientMaster::LOGIN_SUCC:
            mainWindow->show();
            this->hide();
            break;
    }

}

void Login::cancelButtonPressed() {
    this->close();
}

void Login::textChanged() {
    if(ui->loginTextField->text().length() > 0 && ui->passwdTextField->text().length() > 0) {
        ui->OKButton->setEnabled(true);
    }
    else ui->OKButton->setEnabled(false);
}

void Login::setInfo(QString s) {
    ui->infoLabel->setText(s);
}
