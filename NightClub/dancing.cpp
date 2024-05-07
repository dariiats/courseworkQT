#include "dancing.h"
#include "ui_dancing.h"
#include <QMediaPlayer>
#include "dancefloor.h"

Dancing::Dancing(QString Song, QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dancing), song(Song)
{
ui->setupUi(this);


player = new QMediaPlayer;
connect(player, &QMediaPlayer::mediaStatusChanged, this, &Dancing::onMediaStatusChanged);
player->setMedia(QUrl::fromLocalFile(song));
player->setVolume(50);

player->play();
}

Dancing::~Dancing()
{
    delete ui;

    delete player;
}


void Dancing::on_pushButton_clicked()
{
    player->stop();
    hide();
    DanceFloor *danceFloor = new DanceFloor(song, this);
    danceFloor->show();
}

void Dancing::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        player->setPosition(0);
    }
}
