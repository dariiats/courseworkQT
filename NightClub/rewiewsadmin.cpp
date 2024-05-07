#include "rewiewsadmin.h"
#include "ui_rewiewsadmin.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "adminwindow.h"

RewiewsAdmin::RewiewsAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RewiewsAdmin)
{
    ui->setupUi(this);

    QFile file("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/reviews.txt");

    if(!file.open(QIODevice::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "file didn't open!!!");
    }

    QTextStream in(&file);

    QString rewiews = in.readAll();
    ui->plainTextEdit->setPlainText(rewiews);

    file.close();
}

RewiewsAdmin::~RewiewsAdmin()
{
    delete ui;
}

void RewiewsAdmin::on_pushButton_clicked()
{
    hide();
    AdminWindow *admin = new AdminWindow(this);
    admin->show();
}
