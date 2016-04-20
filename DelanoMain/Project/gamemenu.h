#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QDialog>

namespace Ui {
class gameMenu;
}

class gameMenu : public QDialog
{
    Q_OBJECT

public:
    explicit gameMenu(QWidget *parent = 0);
    ~gameMenu();

private slots:
    void on_historyButton_clicked();

    void on_scienceButton_clicked();

    void on_musicButton_clicked();

    void on_sportsButton_clicked();

    void on_artsButton_clicked();

private:
    Ui::gameMenu *ui;
};

#endif // GAMEMENU_H
