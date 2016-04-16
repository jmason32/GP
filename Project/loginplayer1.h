#ifndef LOGINPLAYER1_H
#define LOGINPLAYER1_H

#include <QDialog>

namespace Ui {
class loginPlayer1;
}

class loginPlayer1 : public QDialog
{
    Q_OBJECT

public:
    explicit loginPlayer1(QWidget *parent = 0);
    ~loginPlayer1();

private:
    Ui::loginPlayer1 *ui;
};

#endif // LOGINPLAYER1_H
