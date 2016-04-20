#ifndef PLAYER_H
#define PLAYER_H
#include <global.h>
#include <QString>
using namespace std;

class player
{
public:
    player();
    player(QString username, QString score);

    QString getName(){
    return username;
}
private:
    QString username;
    QString score;
};

#endif // PLAYER_H
