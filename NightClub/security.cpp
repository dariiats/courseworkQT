#include "security.h"
#include "ui_security.h"

Security::Security(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Security)
{
    ui->setupUi(this);
}

Security::~Security()
{
    delete ui;
}
