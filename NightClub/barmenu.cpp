#include "barmenu.h"
#include "ui_barmenu.h"
#include "menuforguest.h"
#include <QMessageBox>
#include "menu.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>

BarMenu::BarMenu(QString Place, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BarMenu), place(Place)
{
    ui->setupUi(this);
    connect(ui->pushButton_Cola, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_Juice, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_PinkGirl, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_ShugarDaddy, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_Tea, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_Vodka, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_Whiskey, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
}

BarMenu::~BarMenu()
{
    delete ui;
}

void BarMenu::ChoosenItems()
{
    QFile file("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/GuestOrder.txt");

    QString itemName;

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {

        if (button == ui->pushButton_Cola) {
                    itemName = "Cola";
                } else if (button == ui->pushButton_Juice) {
                    itemName = "Juice";
                } else if (button == ui->pushButton_PinkGirl) {
                    itemName = "Pink Girl";
                } else if (button == ui->pushButton_ShugarDaddy) {
                    itemName = "Sugar Daddy";
                } else if (button == ui->pushButton_Tea) {
                    itemName = "Tea";
                } else if (button == ui->pushButton_Vodka) {
                    itemName = "Vodka";
                } else if (button == ui->pushButton_Whiskey) {
                    itemName = "Whiskey";
                }

        MenuForGuest menuForGuest(this);
        int index = menuForGuest.ReturnIndexPlace();

        if(!file.open(QIODevice::Append|QFile::Text))
        {
            QMessageBox::warning(this, "warning", "file didn't open!!!");
        }

        QTextStream out(&file);

            if(file.size() != 0)
            {
            out << "***" << endl << "Table #" << index << endl;
            }
            else
            {
                out << "Table #" << index << endl;
            }

         out << itemName << endl;
    }

    QMessageBox msgBox;
    msgBox.setStyleSheet("background-color: #333333; color: #FFFFFF;");
    msgBox.setText("Your order has been processed successfully!");
    msgBox.setWindowTitle("the status of the order");

    msgBox.exec();
    msgBox.open();
    file.close();

    }



void BarMenu::on_pushButton_Exit_clicked()
{
    if(place == "bar")
    {
    MenuForGuest *menuForGuest = new MenuForGuest(this);
    hide();
    menuForGuest->show();
    }

    else
    {
        Menu *menu = new Menu(this);
        hide();
        menu->show();
    }
}
