#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "workers.h"
#include "orders.h"
#include "rewiewsadmin.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

private slots:
    void on_pushButton_Workers_clicked();

    void on_pushButton_Exit_clicked();

    void on_pushButton_Orders_clicked();

    void on_pushButton_Reviews_clicked();

    void on_pushButton_CallSecurity_clicked();

private:
    Ui::AdminWindow *ui;
    Workers *workers;

    Orders *orders;

    RewiewsAdmin *rewiews;
};

#endif // ADMINWINDOW_H
