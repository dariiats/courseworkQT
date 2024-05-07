#ifndef REWIEWSADMIN_H
#define REWIEWSADMIN_H

#include <QDialog>

namespace Ui {
class RewiewsAdmin;
}

class RewiewsAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit RewiewsAdmin(QWidget *parent = 0);
    ~RewiewsAdmin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RewiewsAdmin *ui;
};

#endif // REWIEWSADMIN_H
