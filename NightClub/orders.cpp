#include "orders.h"
#include "ui_orders.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "adminwindow.h"

Orders::Orders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Orders)
{
    ui->setupUi(this);

    QFile currentOrders("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/GuestOrder.txt");
    QFile completedOrders("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/GeneralOrders.txt");

    if(!currentOrders.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "File isn't open!!!");
    }

    if(!completedOrders.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "File isn't open!!!");
    }

    QTextStream inCurrent(&currentOrders);
    QString current = inCurrent.readAll();
    ui->plainTextEdit_Current->setPlainText(current);

    currentOrders.close();

    QTextStream inCompleted(&completedOrders);
    QString completed = inCompleted.readAll();
    ui->plainTextEdit_Completed->setPlainText(completed);

    completedOrders.close();
}

Orders::~Orders()
{
    delete ui;
}

void Orders::on_pushButton_clicked()
{
    hide();
    AdminWindow *admin = new AdminWindow(this);
    admin->show();
}
