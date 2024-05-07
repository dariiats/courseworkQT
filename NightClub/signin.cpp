#include "signin.h"
#include "ui_signin.h"
#include <QMessageBox>

SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
}

SignIn::~SignIn()
{
    delete ui;
}


void SignIn::on_pushButton_Login_clicked()
{
    QString password = ui->lineEdit_Password->text();

    if(password == "1234")
    {
        hide();
        adminWindow = new AdminWindow(this);
        adminWindow->show();
    }

    else
    {
        QMessageBox::warning(this, "Login", "Your password is incorrect!");
    }
}
