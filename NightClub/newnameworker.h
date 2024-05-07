#ifndef NEWNAMEWORKER_H
#define NEWNAMEWORKER_H

#include <QDialog>

namespace Ui {
class NewNameWorker;
}

class NewNameWorker : public QDialog
{
    Q_OBJECT

public:
    explicit NewNameWorker(QString NewWorkerName, QWidget *parent = 0);
    ~NewNameWorker();

private slots:
    void on_pushButton_Register_clicked();

    void on_pushButton_Return_clicked();

private:
    Ui::NewNameWorker *ui;

    QString newWorkerName;
};

#endif // NEWNAMEWORKER_H
