#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

public slots:
    void ChoosenItems();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainMenu *ui;
    int index;
};

#endif // MAINMENU_H
