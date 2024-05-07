#ifndef WAITER_H
#define WAITER_H

#include <QDialog>
#include <menu.h>

namespace Ui {
class Waiter;
}

class Waiter : public QDialog
{
    Q_OBJECT

public:
    explicit Waiter(QWidget *parent = 0);
    ~Waiter();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Waiter *ui;
    Menu *menu;
};

#endif // WAITER_H
