#ifndef DANCEFLOOR_H
#define DANCEFLOOR_H

#include <QDialog>
#include <QMediaPlayer>
#include "dancing.h"
#include "ordermusic.h"

namespace Ui {
class DanceFloor;
}

class DanceFloor : public QDialog
{
    Q_OBJECT
public:
    explicit DanceFloor(QWidget *parent = 0);

    explicit DanceFloor(QString Song, QWidget *parent = 0);

    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    ~DanceFloor();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::DanceFloor *ui;
    QMediaPlayer *player;

    QString song;

    Dancing *dancing;

    OrderMusic *orderMusic;

};

#endif // DANCEFLOOR_H
