#include "response.h"
#include "ui_response.h"
#include <QFile>
#include <QTextStream>
#include "menuforguest.h"
#include <QMessageBox>
#include <QDate>

Response::Response(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Response)
{
    ui->setupUi(this);
}

Response::~Response()
{
    delete ui;
}

void Response::on_pushButton_send_clicked()
{
    QFile file("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/reviews.txt");

    if(!file.open(QIODevice::Append|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "file didn't open!!!");
    }

    else
    {
        QDate currentDate = QDate::currentDate();
        QString date = currentDate.toString("dd.MM.yyyy");

        QTextStream out(&file);
        QString name = ui->lineEdit_name->text();
        QString review = ui->plainTextEdit_response->toPlainText();

        out << "Name: " << name << endl << "Review: " << review << endl << "Date: " << date << endl << endl;

        QMessageBox msgBox;
        msgBox.setStyleSheet("background-color: #333333; color: #FFFFFF;");
        msgBox.setText("Your review has been processed successfully!");
        msgBox.setWindowTitle("the status of the response");
        msgBox.exec();
        msgBox.open();
        file.close();
    }

    hide();
    MenuForGuest *menuForGuest = new MenuForGuest(this);
    menuForGuest->show();
}

void Response::on_pushButton_clicked()
{
    hide();
    MenuForGuest *menuForGuest = new MenuForGuest(this);
    menuForGuest->show();
}
