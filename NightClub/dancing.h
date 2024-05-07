#ifndef DANCING_H
#define DANCING_H

#include <QDialog>
#include <QMediaPlayer>
namespace Ui {
class Dancing;
}

class Dancing : public QDialog
{
    Q_OBJECT

public:
    explicit Dancing(QWidget *parent = 0);
    explicit Dancing(QString song, QWidget *parent = 0);
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

    ~Dancing();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dancing *ui;
    QString song;

    QMediaPlayer *player;
};

#endif // DANCING_H
