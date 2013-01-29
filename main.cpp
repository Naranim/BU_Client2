#include <QtGui/QApplication>
#include "mainwindow.h"
#include "clientmaster.h"
#include "login.h"
#include "myfile.h"
#include <QCryptographicHash>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString response = "/home/ciemny/:1241231\n/ala/makota/:o241oj>>>";
    QString folders = response.split(">>>")[0];
    QString files = response.split(">>>")[1];
    QStringList foldersList = folders.split("\n");
    QStringList filesList = (files.split("\n"));
    for(int i = 0; i < foldersList.size(); ++i) qDebug() << " > " << foldersList[i].split(":")[0] << foldersList[i].split(":")[1];//L1->append(qMakePair(foldersList[i].split(":")[0], foldersList[i].split(":")[1]);
    //for(int i = 0; i < filesList.size(); ++i) L1->append(qMakePair(filesList[i].split(":")[0], filesList[i].split(":")[1]);
//    ClientMaster * clientMaster = new ClientMaster("127.0.0.1", 8090);
//    MainWindow * mw = new MainWindow(clientMaster);
//    mw->show();

//    MainWindow * mainWindow = new MainWindow(clientMaster);
//    Login * l = new Login(mainWindow, clientMaster);
//    l->show();
//    mainWindow->show();
    return a.exec();
}
