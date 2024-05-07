#ifndef ORDERS_H
#define ORDERS_H

#include <QDialog>

namespace Ui {
class Orders;
}

class Orders : public QDialog
{
    Q_OBJECT

public:
    explicit Orders(QWidget *parent = 0);
    ~Orders();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Orders *ui;
};

#endif // ORDERS_H
