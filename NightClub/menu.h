#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainmenu.h"
#include "barmenu.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_pushButton_Main_clicked();

    void on_pushButton_clicked();

    void on_pushButton_Bar_clicked();

private:
    Ui::Menu *ui;
    MainMenu *mainMenu;
    BarMenu *barMenu;
    int index;
};

#endif // MENU_H
