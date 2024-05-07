#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include "guestwindow.h"
#include "signin.h"
#include <QMainWindow>

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    void on_pushButton_Guest_clicked();

    void on_pushButton_Admin_clicked();

private:
    Ui::StartWindow *ui;
    GuestWindow *guestWindow;
    SignIn *signin;
};

#endif // STARTWINDOW_H
