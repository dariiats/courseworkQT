#ifndef SECURITY_H
#define SECURITY_H

#include <QDialog>

namespace Ui {
class Security;
}

class Security : public QDialog
{
    Q_OBJECT

public:
    explicit Security(QWidget *parent = 0);
    ~Security();

private:
    Ui::Security *ui;
};

#endif // SECURITY_H
