#include "player.h"

player::player()
{
    username = "";
    score = "0";
}
player::player(QString name, QString score){
    username = name;
    score = score;
}
