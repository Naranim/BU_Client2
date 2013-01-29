#include "myfile.h"
#include <QFile>
#include <QByteArray>
#include <QProcess>


myFile::myFile() {

}

QString myFile::getMD5(QString path) {
    QProcess qp;
    qp.start("md5sum " + path);
    qp.waitForReadyRead();
    QString ret = qp.readAllStandardOutput();
    return ret.split(" ")[0];
}

void myFile::qstringToChar(const QString s, char * c) {

}
