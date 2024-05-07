#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QDialog>

namespace Ui {
class Notification;
}

class Notification : public QDialog
{
    Q_OBJECT

public:
    explicit Notification(int Index, QWidget *parent = 0);

    void AddNotification(QString notification);
    ~Notification();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Notification *ui;
    QString notification;
    int index;
};

#endif // NOTIFICATION_H
