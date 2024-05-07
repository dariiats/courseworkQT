#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include "adminwindow.h"

namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();

private slots:

    void on_pushButton_Login_clicked();

private:
    Ui::SignIn *ui;
    AdminWindow *adminWindow;
};

#endif // SIGNIN_H
