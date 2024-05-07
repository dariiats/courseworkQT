#include "workers.h"
#include "ui_workers.h"
#include <QColumnView>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include "adminwindow.h"

Workers::Workers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Workers)
{
    ui->setupUi(this);

    QFile fileWaiters("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Waiters.txt");
    QFile fileBartenders("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Bartenders.txt");
    QFile fileCooks("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Cooks.txt");
    QFile fileCleaners("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Cleaners.txt");


    QFont font;

    //waiters
    if(!fileWaiters.open(QIODevice::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "file didn't open!!!");
    }

    QStandardItem *waiters = new QStandardItem("Waiters");

    QTextStream inWaiters(&fileWaiters);

    while (!inWaiters.atEnd())
        {
            QString name = inWaiters.readLine();
            QStandardItem *item = new QStandardItem(name);
            waiters->appendRow(item);
        }

    QStandardItem *add = new QStandardItem("Add new...");

    font.setBold(true);
    add->setFont(font);
    waiters->setFont(font);
    waiters->appendRow(add);

    this->model.appendRow(waiters);

    ui->columnView->setModel(&this->model);

    fileWaiters.close();

   //Bartenders

    if(!fileBartenders.open(QIODevice::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "file didn't open!!!");
    }

    QStandardItem *bartenders = new QStandardItem("Bartenders");

    QTextStream inBartenders(&fileBartenders);

    while (!inBartenders.atEnd())
        {
            QString name = inBartenders.readLine();
            QStandardItem *item = new QStandardItem(name);
            bartenders->appendRow(item);
        }

    add = new QStandardItem("Add new...");

    font.setBold(true);
    add->setFont(font);
    bartenders->setFont(font);

    bartenders->appendRow(add);

    this->model.appendRow(bartenders);

    ui->columnView->setModel(&this->model);

    fileBartenders.close();

    //Cooks

    if(!fileCooks.open(QIODevice::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "file didn't open!!!");
    }

    QStandardItem *cooks = new QStandardItem("Cooks");

    QTextStream inCooks(&fileCooks);

    while (!inCooks.atEnd())
        {
            QString name = inCooks.readLine();
            QStandardItem *item = new QStandardItem(name);
            cooks->appendRow(item);
        }

    add = new QStandardItem("Add new...");

    font.setBold(true);
    add->setFont(font);
    cooks->setFont(font);

    cooks->appendRow(add);

    this->model.appendRow(cooks);

    ui->columnView->setModel(&this->model);

    fileCooks.close();

    //Cleaners

    if(!fileCleaners.open(QIODevice::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "file didn't open!!!");
    }

    QStandardItem *cleaners = new QStandardItem("Cleaners");

    QTextStream inCleaners(&fileCleaners);

    while (!inCleaners.atEnd())
        {
            QString name = inCleaners.readLine();
            QStandardItem *item = new QStandardItem(name);
            cleaners->appendRow(item);
        }

    add = new QStandardItem("Add new...");

    font.setBold(true);
    add->setFont(font);
    cleaners->setFont(font);

    cleaners->appendRow(add);

    this->model.appendRow(cleaners);

    ui->columnView->setModel(&this->model);

    fileCleaners.close();

    // // // // // // // //

   ui->columnView->setModel(&this->model);

   connect(ui->columnView, &QColumnView::clicked, this, &Workers::handleItemClicked);

}

Workers::~Workers()
{
    delete ui;
}

void Workers::handleItemClicked(const QModelIndex &index)
{
    QString itemName = index.data(Qt::DisplayRole).toString();

        // Перевірка, чи натиснуте ім'я працівника
    if(index.parent().isValid())
        {
        if(itemName == "Add new...")
        {
            QString fileName;
            QModelIndex parentIndex = index.parent();

            if(parentIndex.data(Qt::DisplayRole).toString() == "Waiters")
                fileName = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Waiters.txt";
            else if(parentIndex.data(Qt::DisplayRole).toString() == "Bartenders")
                fileName = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Bartenders.txt";
            else if(parentIndex.data(Qt::DisplayRole).toString() == "Cooks")
                fileName = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Cooks.txt";
            else if(parentIndex.data(Qt::DisplayRole).toString() == "Cleaners")
                fileName = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Cleaners.txt";

            hide();
            addWorker = new NewNameWorker(fileName, this);
            addWorker->show();

        }

        else
        {
            // Показати вікно підтвердження
            QMessageBox msgBox;
            msgBox.setStyleSheet("background-color: #333333; color: #FFFFFF;");
            msgBox.setText("Are you sure you want to delete this worker?");
            msgBox.setWindowTitle("Deleting worker");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();

            msgBox.open();

            // Якщо користувач підтвердив видалення, видаляємо ім'я з файлу
            if(ret == QMessageBox::Yes)
            {
                QString workerName = itemName;
                QModelIndex parentIndex = index.parent();
                QString fileName;
                if(parentIndex.data(Qt::DisplayRole).toString() == "Waiters")
                    fileName = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Waiters.txt";
                else if(parentIndex.data(Qt::DisplayRole).toString() == "Bartenders")
                    fileName = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Bartenders.txt";
                else if(parentIndex.data(Qt::DisplayRole).toString() == "Cooks")
                    fileName = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Cooks.txt";
                else if(parentIndex.data(Qt::DisplayRole).toString() == "Cleaners")
                    fileName = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/Cleaners.txt";

                QFile file(fileName);
                if(file.open(QIODevice::ReadWrite | QIODevice::Text))
                {
                    QTextStream stream(&file);
                    QStringList lines;
                    while (!stream.atEnd())
                    {
                        QString line = stream.readLine();
                        if (line != workerName)
                            lines << line;
                    }
                    file.resize(0);
                    stream << lines.join("\n");
                    file.close();
                }

                // Видалити елемент з моделі
                model.removeRow(index.row(), parentIndex);
                hide();
                Workers *workers = new Workers(this);
                workers->show();
            }

        }
    }
}

void Workers::on_pushButton_clicked()
{
    hide();
    AdminWindow *adminWindow = new AdminWindow(this);
    adminWindow->show();
}
