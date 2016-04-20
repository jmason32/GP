#ifndef GLOBAL_H
#define GLOBAL_H
#include "player.h"
#include <string>
#include <QString>

class global
{
public:
    global();
    global(QString username, QString score);
private:
    QString username;
    QString score;
     int tempScore;
    QString password;
};

#endif // GLOBAL_H
