#include "menuforguest.h"
#include "ui_menuforguest.h"
#include <QMessageBox>
#include "guestwindow.h"
#include "notification.h"
#include <QFile>
#include <QTextStream>

int index2;

bool notification;

MenuForGuest::MenuForGuest(int buttonNumber, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuForGuest), index(buttonNumber)
{

    ui->setupUi(this);
    index2 = index;
    ui->label_2->setText(QString::number(index));

    QFile file("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/GuestOrder.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "warning", "file isn't open!!!!");
    }
       QTextStream in(&file);

       QString numberTable = "Table #" + QString::number(index);

       bool actuallyOrder = false;

           while (!in.atEnd())
           {
               QString line = in.readLine();

               if(line == numberTable)
               {
                   actuallyOrder = true;
               }
           }

       if(file.exists())
       {

           if (actuallyOrder)
           {
               ui->pushButton_notification->setIcon(QIcon(":/StartWindow/Design/Фон/СповіщенняПрисутні.png"));
           }

           else
           {
               ui->pushButton_notification->setIcon(QIcon(":/StartWindow/Design/Фон/bell_1f514.png"));
           }
       }

       file.close();



       }           


MenuForGuest::MenuForGuest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuForGuest)
{
    ui->setupUi(this);

    ui->label_2->setText(QString::number(index2));

    QFile file("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/GuestOrder.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "warning", "file isn't open!!!!");
    }

    else
    {
        QTextStream in(&file);

        QString numberTable = "Table #" + QString::number(index2);

        bool actuallyOrder = false;

            while (!in.atEnd())
            {
                QString line = in.readLine();

                if(line == numberTable)
                {
                    actuallyOrder = true;
                }
            }

        if(file.exists())
        {

            if (actuallyOrder)
            {
                ui->pushButton_notification->setIcon(QIcon(":/StartWindow/Design/Фон/СповіщенняПрисутні.png"));
            }

            else
            {
                ui->pushButton_notification->setIcon(QIcon(":/StartWindow/Design/Фон/bell_1f514.png"));
            }
        }


    }
}

MenuForGuest::~MenuForGuest()
{
    delete ui;
}

int MenuForGuest::ReturnIndexPlace()
{
    return index2;
}

void MenuForGuest::on_pushButton_menu_clicked()
{
    hide();

    if(index2 <= 6)
    {
        menu = new Menu(this);
        menu->show();
    }

    if(index2 > 6)
    {
        barMenu = new BarMenu("bar", this);
        barMenu->show();
    }
}

void MenuForGuest::on_pushButton_exit_clicked()
{
    GuestWindow *guestWindow = new GuestWindow(this);
    hide();
    guestWindow->show();
}




void MenuForGuest::on_pushButton_dance_clicked()
{
    hide();
    danceFloor = new DanceFloor(this);
    danceFloor->show();
}

void MenuForGuest::on_pushButton_callTheWaiter_clicked()
{
    hide();
    waiter = new Waiter(this);
    waiter->show();
}

void MenuForGuest::on_pushButton_response_clicked()
{
    hide();
    response = new Response(this);
    response->show();
}

void MenuForGuest::on_pushButton_notification_clicked()
{
    hide();
    Notification* label = new Notification(index2, this);
    label->show();
}
