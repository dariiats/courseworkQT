#ifndef MENUFORGUEST_H
#define MENUFORGUEST_H

#include <QDialog>
#include "menu.h"
#include "barmenu.h"
#include "dancefloor.h"
#include "waiter.h"
#include "response.h"

namespace Ui {
class MenuForGuest;
}

class MenuForGuest : public QDialog
{    
    Q_OBJECT

public:
    explicit MenuForGuest(int Index, QWidget *parent);
    explicit MenuForGuest(QWidget *parent);

    ~MenuForGuest();

    int ReturnIndexPlace();

private slots:

    void on_pushButton_menu_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_dance_clicked();

    void on_pushButton_callTheWaiter_clicked();

    void on_pushButton_response_clicked();

    void on_pushButton_notification_clicked();

private:
    Ui::MenuForGuest *ui;
    Menu *menu;
    BarMenu *barMenu;
    int index;
    DanceFloor *danceFloor;
    Waiter *waiter;
    Response *response;

};

#endif // MENUFORGUEST_H
