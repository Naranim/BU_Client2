#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>

MainWindow::MainWindow(ClientMaster *clientMaster, QWidget *parent) :
    QMainWindow(parent),
    clientMaster(clientMaster),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->refreshButton, SIGNAL(clicked()), this, SLOT(refreshButtonPressed()));
    this->serverFiles = new QList<QPair<QString, QString> >();
    this->serverFolders = new QList<QPair<QString, QString> >();
    this->localFiles = new QList<QPair<QString, QString> >();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::init() {

}

void MainWindow::refreshButtonPressed() {
    this->serverFiles->clear();
    this->serverFolders->clear();
    clientMaster->getMyFiles(serverFolders, serverFiles);
    //for(int i = 0; i < serverFolders->size(); ++i) ui->foldersView->addItem(serverFolder);
}
