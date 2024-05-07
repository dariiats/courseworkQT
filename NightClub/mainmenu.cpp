#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "QMessageBox"
#include "menu.h"
#include <QFile>
#include <QTextStream>
#include "notification.h"
#include "menuforguest.h"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    connect(ui->pushButton_BigBoy, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_BloodKLion, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_Ceasar, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_LittlePrince, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_SpicyGirl, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_TigerPrawn, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_TomYam, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
    connect(ui->pushButton_WhiteAngel, SIGNAL(clicked()), this, SLOT(ChoosenItems()));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::ChoosenItems()
{
    QFile file("C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Файли/GuestOrder.txt");

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {

        QString itemName;

        if (button == ui->pushButton_BigBoy) {
                    itemName = "Big Boy";
                } else if (button == ui->pushButton_BloodKLion) {
                    itemName = "Blood Lion";
                } else if (button == ui->pushButton_Ceasar) {
                    itemName = "Ceasar";
                } else if (button == ui->pushButton_LittlePrince) {
                    itemName = "Little Prince";
                } else if (button == ui->pushButton_SpicyGirl) {
                    itemName = "Spicy Girl";
                } else if (button == ui->pushButton_TigerPrawn) {
                    itemName = "Tiger Prawn";
                } else if (button == ui->pushButton_TomYam) {
                    itemName = "Tom Yam";
                } else if (button == ui->pushButton_WhiteAngel) {
                    itemName = "White Angel";
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



void MainMenu::on_pushButton_clicked()
{
    Menu *menu = new Menu(this);
    hide();
    menu->show();
}
