#include "guestwindow.h"
#include "ui_guestwindow.h"
#include <QMessageBox>
#include "startwindow.h"

GuestWindow::GuestWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuestWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_place1, SIGNAL(clicked()), this, SLOT(tableButtonClicked()));
    connect(ui->pushButton_place3, SIGNAL(clicked()), this, SLOT(tableButtonClicked()));
    connect(ui->pushButton_place4, SIGNAL(clicked()), this, SLOT(tableButtonClicked()));

    connect(ui->pushButton_place7, SIGNAL(clicked()), this, SLOT(tableButtonClicked()));
    connect(ui->pushButton_place9, SIGNAL(clicked()), this, SLOT(tableButtonClicked()));
    connect(ui->pushButton_place10, SIGNAL(clicked()), this, SLOT(tableButtonClicked()));
}

GuestWindow::~GuestWindow()
{
    delete ui;
}

void GuestWindow::tableButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    int index = -1;
    if (button) {
        QString buttonText = button->text();
        index = buttonText.remove("Place ").toInt();
    }
    hide();
    menuForGuest = new MenuForGuest(index, this);
    menuForGuest->show();
}

void GuestWindow::on_pushButton_exit_clicked()
{
    hide();
    StartWindow *startWindow = new StartWindow(this);
    startWindow->show();
}

