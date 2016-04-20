#ifndef STATSCREEN_H
#define STATSCREEN_H

#include <QDialog>

namespace Ui {
class statScreen;
}

class statScreen : public QDialog
{
    Q_OBJECT

public:
    explicit statScreen(QWidget *parent = 0);
    ~statScreen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::statScreen *ui;
};

#endif // STATSCREEN_H
