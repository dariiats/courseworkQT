#ifndef RESPONSE_H
#define RESPONSE_H

#include <QDialog>

namespace Ui {
class Response;
}

class Response : public QDialog
{
    Q_OBJECT

public:
    explicit Response(QWidget *parent = 0);
    ~Response();

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_clicked();

private:
    Ui::Response *ui;
};

#endif // RESPONSE_H
