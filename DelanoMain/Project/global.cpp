#include "global.h"
#include <QString>
#include <string>
global::global()
{
    username= "";
    score = "0";
    password = "";
    tempScore = 0;
}
global::global(QString name, QString score){
    username = name;
    score = score;
}
