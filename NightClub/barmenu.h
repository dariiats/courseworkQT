#ifndef BARMENU_H
#define BARMENU_H

#include <QDialog>

namespace Ui {
class BarMenu;
}

class BarMenu : public QDialog
{
    Q_OBJECT

public:
    explicit BarMenu(QString place, QWidget *parent = 0);
    ~BarMenu();

public slots:
    void ChoosenItems();

private slots:
    void on_pushButton_Exit_clicked();

private:
    Ui::BarMenu *ui;
    QString place;
    int index;
};

#endif // BARMENU_H
