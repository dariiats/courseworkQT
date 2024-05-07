#ifndef WORKERS_H
#define WORKERS_H

#include <QDialog>
#include <QStandardItemModel>

#include "newnameworker.h"

namespace Ui {
class Workers;
}

class Workers : public QDialog
{
    Q_OBJECT

public:
    explicit Workers(QWidget *parent = 0);
    ~Workers();

public slots:
    void handleItemClicked(const QModelIndex &index);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Workers *ui;

    QStandardItemModel model;

    NewNameWorker *addWorker;
};

#endif // WORKERS_H
