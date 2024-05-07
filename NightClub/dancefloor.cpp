#include "dancefloor.h"
#include "ui_dancefloor.h"
#include <QMediaPlayer>
#include "menuforguest.h"

QString song2;

DanceFloor::DanceFloor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DanceFloor)
{
    ui->setupUi(this);

    player = new QMediaPlayer;
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &DanceFloor::onMediaStatusChanged);
    song2 = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Design/music/feels-like-a-party-short-2-version-175323.mp3";
    player->setMedia(QUrl::fromLocalFile(song2));
    player->setVolume(50);

    player->play();

}

DanceFloor::DanceFloor(QString Song, QWidget *parent):
    QDialog(parent),
    ui(new Ui::DanceFloor), song(Song)
{
    ui->setupUi(this);

    song2 = song;
    player = new QMediaPlayer;
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &DanceFloor::onMediaStatusChanged);
    player->setMedia(QUrl::fromLocalFile(song2));
    player->setVolume(50);

    player->play();

}

DanceFloor::~DanceFloor()
{
    delete ui;
    delete player;
}

void DanceFloor::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        player->setPosition(0);
    }
}

void DanceFloor::on_pushButton_clicked()
{
    hide();
    player->stop();
    dancing = new Dancing(song2, this);
    dancing->show();
}

void DanceFloor::on_pushButton_2_clicked()
{
    hide();
    player->stop();
    orderMusic = new OrderMusic(this);
    orderMusic->show();
}

void DanceFloor::on_pushButton_3_clicked()
{
    hide();
    player->stop();
    MenuForGuest *menuForGuest = new MenuForGuest(this);
    menuForGuest->show();
}
