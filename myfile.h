#ifndef MYFILE_H
#define MYFILE_H
#include <QString>

class myFile
{
public:
    myFile();
    static QString getMD5(QString path);
    static void qstringToChar(const QString, char *);
};

#endif // MYFILE_H
