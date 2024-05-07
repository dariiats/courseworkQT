#ifndef ORDERMUSIC_H
#define ORDERMUSIC_H

#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class OrderMusic;
}

class OrderMusic : public QDialog
{
    Q_OBJECT

public slots:
    void onItemClicked(QListWidgetItem *item);
public:
    explicit OrderMusic(QWidget *parent = 0);
    ~OrderMusic();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OrderMusic *ui;
};

#endif // ORDERMUSIC_H
