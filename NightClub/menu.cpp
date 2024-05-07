#include "menu.h"
#include "ui_menu.h"
#include "menuforguest.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}


Menu::~Menu()
{
    delete ui;
}



void Menu::on_pushButton_Main_clicked()
{
    hide();
    mainMenu = new MainMenu(this);
    mainMenu->show();
}

void Menu::on_pushButton_clicked()
{
    MenuForGuest *menuForGuest = new MenuForGuest(this);
    hide();
    menuForGuest->show();
}

void Menu::on_pushButton_Bar_clicked()
{
    hide();
    barMenu = new BarMenu("table", this);
    barMenu->show();
}
