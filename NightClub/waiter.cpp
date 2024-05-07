#include "waiter.h"
#include "ui_waiter.h"
#include "menuforguest.h"

Waiter::Waiter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Waiter)
{
    ui->setupUi(this);
}

Waiter::~Waiter()
{
    delete ui;
}

void Waiter::on_pushButton_clicked()
{
    hide();
    menu = new Menu(this);
    menu->show();
}

void Waiter::on_pushButton_2_clicked()
{
   hide();
   MenuForGuest *menuForGuest = new MenuForGuest(this);
   menuForGuest->show();
}
