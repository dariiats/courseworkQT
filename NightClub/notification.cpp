#include "notification.h"
#include "ui_notification.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "menuforguest.h"

int generalIndex;

Notification::Notification(int Index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notification), index(Index)
{
    ui->setupUi(this);

    generalIndex = index;

    QFile file("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/GuestOrder.txt");

    if(!file.open(QIODevice::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "warning", "file didn't open!!!");
    }

    else
    {
        QString line;
        QString order = "Table #" + QString::number(generalIndex);
        QTextStream in(&file);
        bool actuallyOrder = false;

        while(!in.atEnd())
        {
            line = in.readLine();
            if(line == order)
            {
                actuallyOrder = true;
            }
        }


        if (file.exists())
        {

            if(actuallyOrder)
            {
            if(file.size() != 0)
        {
            ui->listWidget->addItem("Your order is ready! Help Yourself!");
            }
            }
        }
        file.close();
    }

}

Notification::~Notification()
{
    delete ui;
}



void Notification::on_pushButton_clicked()
{
    bool actuallyOrder = false;
    QString order = "Table #" + QString::number(generalIndex);
    QString line;

    QFile guestOrder("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/GuestOrder.txt");
    QFile tempGuestOrder("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/tempGuestOrder.txt");
    QFile generalOrders("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/GeneralOrders.txt");

    if (!guestOrder.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "File isn't opened!");
        return;
    }

    QTextStream inGuest(&guestOrder);

    while (!inGuest.atEnd())
    {
        line = inGuest.readLine();

        if (line == order)
        {
            actuallyOrder = true;
            break;
        }
    }

    guestOrder.close();


    if (actuallyOrder)
    {
        if (!tempGuestOrder.open(QIODevice::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "File isn't opened!");
            return;
        }

        if (!guestOrder.open(QIODevice::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "File isn't opened!");
            return;
        }

        QTextStream inGuest1(&guestOrder);
        QTextStream outTemp(&tempGuestOrder);

        bool copyOrder = true;

        QString line1;

        outTemp << "";

        while (!inGuest1.atEnd())
        {
            line1 = inGuest1.readLine();

            if (line1.startsWith(order))
            {
                copyOrder = false;
            }

            if (line1.startsWith("***"))
            {
                copyOrder = true;
            }

            if (copyOrder)
            {
                if (line1 != "***" && tempGuestOrder.size() != 0)
                {
                    outTemp << line1 << endl;
                }

                if (tempGuestOrder.size() == 0 && line1 != "***")
                {
                    outTemp << line1 << endl;
                }

                if (line1 == "***" && tempGuestOrder.size() != 0)
                {
                    outTemp << endl;
                }
            }
        }

        tempGuestOrder.close();
        guestOrder.close();

        if (!generalOrders.open(QIODevice::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "File isn't opened!");
            return;
        }

        int count = 0;
        QTextStream inGeneral(&generalOrders);
        QString line3;

        while (!inGeneral.atEnd())
        {
            line3 = inGeneral.readLine();
            if (line3.startsWith("Table #"))
            {
                count++;
            }
        }

        generalOrders.close();

        if (!generalOrders.open(QIODevice::Append | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "File isn't opened!");
            return;
        }

        QTextStream outGeneral(&generalOrders);

        if (!guestOrder.open(QIODevice::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "File isn't opened!");
            return;
        }

        QTextStream inGuest2(&guestOrder);

        copyOrder = false;
        QString line4;

        while (!inGuest2.atEnd())
        {
            line4 = inGuest2.readLine();

            if (line4.startsWith(order))
            {
                if (generalOrders.size() == 0)
                {
                    count += 1;
                    outGeneral << "Order #" << count << endl;
                    copyOrder = true;
                }
                else
                {
                    count += 1;
                    outGeneral << endl << "Order #" << count << endl;
                    copyOrder = true;
                }
            }

            if (line4.startsWith("***"))
            {
                copyOrder = false;
            }

            if (copyOrder)
            {
                outGeneral << line4 << endl;
            }
        }

        guestOrder.close();
        generalOrders.close();

        if (!guestOrder.open(QIODevice::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "File isn't opened!");
            return;
        }

        if (!tempGuestOrder.open(QIODevice::ReadOnly| QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "File isn't opened!");
            return;
        }

        QTextStream outGuest(&guestOrder);
        QTextStream inTempGuest(&tempGuestOrder);
        QString line5;

        while(!inTempGuest.atEnd())
        {
            line5 = inTempGuest.readLine();
            outGuest << line5 << endl;
        }

        guestOrder.close();
        tempGuestOrder.close();
    }

    hide();
    MenuForGuest *menuForGuest = new MenuForGuest(this);
    menuForGuest->show();
}
