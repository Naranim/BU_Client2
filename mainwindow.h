#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clientmaster.h"
#include "clientslave.h"

#include <QMainWindow>
#include <QStringList>
#include <QList>
#include <QPair>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(ClientMaster * clientMaster, QWidget *parent = 0);
    ~MainWindow();
    void init();
    
private:
    Ui::MainWindow *ui;
    ClientMaster * clientMaster;
    QList<QPair<QString, QString> > * serverFolders;
    QList<QPair<QString, QString> > * serverFiles;
    QList<QPair<QString, QString> > * localFiles;


private slots:
    void refreshButtonPressed();


};

#endif // MAINWINDOW_H
