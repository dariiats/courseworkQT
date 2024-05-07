#include "newnameworker.h"
#include "ui_newnameworker.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "workers.h"

QString worker;

NewNameWorker::NewNameWorker(QString NewWorkerName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewNameWorker), newWorkerName(NewWorkerName)
{
    worker = newWorkerName;
    ui->setupUi(this);
}

NewNameWorker::~NewNameWorker()
{
    delete ui;
}

void NewNameWorker::on_pushButton_Register_clicked()
{
    QString newWorkerName = ui->lineEdit->text();

    QFile file(worker);

    if(!file.open(QIODevice::Append|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "file didn't open!!!");
    }


    else if(newWorkerName.size())
    {
        QTextStream out(&file);

        if(file.size() == 0)
        {
           out << newWorkerName;
        }

        else
        {
            out << endl << newWorkerName;
        }

        file.close();

        QMessageBox msgBox;
        msgBox.setStyleSheet("background-color: #333333; color: #FFFFFF;");
        msgBox.setText("The new worker has been added successfully!");
        msgBox.setWindowTitle("the status of the new worker");

        msgBox.exec();
        msgBox.open();
    }

    hide();
    Workers* workers = new Workers(this);
    workers->show();
}

void NewNameWorker::on_pushButton_Return_clicked()
{
    hide();
    Workers* workers = new Workers(this);
    workers->show();
}
