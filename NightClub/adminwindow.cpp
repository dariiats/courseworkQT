#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "startwindow.h"
#include <QMessageBox>

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_Workers_clicked()
{
    hide();
    workers = new Workers(this);
    workers->show();
}

void AdminWindow::on_pushButton_Exit_clicked()
{
    hide();
    StartWindow *startWindow = new StartWindow(this);
    startWindow->show();
}

void AdminWindow::on_pushButton_Orders_clicked()
{
    hide();
    orders = new Orders(this);
    orders->show();
}

void AdminWindow::on_pushButton_Reviews_clicked()
{
    hide();
    rewiews = new RewiewsAdmin(this);
    rewiews->show();
}

void AdminWindow::on_pushButton_CallSecurity_clicked()
{

    QMessageBox msgBox;
    msgBox.setStyleSheet("background-color: #333333; color: #FFFFFF;");
    msgBox.setText("<center><b>Security is here!</b></center>");
    msgBox.setWindowTitle("the status of security");

    msgBox.exec();
    msgBox.open();
}
