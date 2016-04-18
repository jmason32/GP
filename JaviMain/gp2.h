#ifndef GP2_H
#define GP2_H

#include <QMainWindow>

namespace Ui {
class gp2;
}

class gp2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit gp2(QWidget *parent = 0);
    ~gp2();

private:
    Ui::gp2 *ui;
};

#endif // GP2_H
