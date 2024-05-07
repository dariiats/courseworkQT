#include "startwindow.h"
#include "ui_startwindow.h"
#include "signin.h"
#include <QPixmap>

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
   }

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_Guest_clicked()
{
    hide();
    guestWindow = new GuestWindow(this);
    guestWindow->show();
}

void StartWindow::on_pushButton_Admin_clicked()
{
    hide();
    signin = new SignIn(this);
    signin->show();
}
