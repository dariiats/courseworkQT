#ifndef GUESTWINDOW_H
#define GUESTWINDOW_H

#include <QDialog>
#include "menuforguest.h"

namespace Ui {
class GuestWindow;
}

class GuestWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GuestWindow(QWidget *parent = 0);
    ~GuestWindow();

public slots:
    void tableButtonClicked();

private slots:
    void on_pushButton_exit_clicked();

private:
    Ui::GuestWindow *ui;
    MenuForGuest *menuForGuest;
    MenuForGuest *indexTable;
};

#endif // GUESTWINDOW_H
