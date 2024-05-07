#include "ordermusic.h"
#include "ui_ordermusic.h"
#include "dancefloor.h"

OrderMusic::OrderMusic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderMusic)
{
    ui->setupUi(this);

    QString item1 = "Song1";
    QString item2 = "Song2";
    QString item3 = "Song3";

    ui->listWidget->addItem(item1);
    ui->listWidget->addItem(item2);
    ui->listWidget->addItem(item3);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));

}

OrderMusic::~OrderMusic()
{
    delete ui;
}

void OrderMusic::onItemClicked(QListWidgetItem *item)
{
    hide();
    QString Song;

    QString itemName = item->text();
       if(itemName == "Song1")
       {
           Song = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Design/music/dance-energetic-party-128762.mp3";
       }

       else if(itemName == "Song2")
       {
           Song = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Design/music/playful-musical-rhythms-for-short-video-vlogging-life-hacks-23-second-193221.mp3";
       }

       else if(itemName == "Song3")
       {
           Song = "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/NightClub/Design/music/slap-house-dance-background-music-133371.mp3";
       }

       DanceFloor *danceFloor = new DanceFloor(Song, this);
       danceFloor->show();
}

void OrderMusic::on_pushButton_clicked()
{
    hide();
    DanceFloor *danceFloor = new DanceFloor(this);
    danceFloor->show();
}
