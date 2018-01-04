#include "widget.h"
#include "table.h"
#include <QPalette>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <qapplication.h>
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{






Table *table = new Table (this);


setFixedSize(1024,720);





//Музыка
m_Fon = new QMediaPlayer(this);
m_PlaylistFon = new QMediaPlaylist(m_Fon);
m_Fon->setPlaylist(m_PlaylistFon);
//Плейлист относительный.
m_PlaylistFon->addMedia(QUrl(QApplication::applicationDirPath() +"./music/BONES - 8. Dirt.wav"));
m_PlaylistFon->addMedia(QUrl(QApplication::applicationDirPath() +"./music/Bones  Drip-133 - WeWillBeRightHere.wav"));
m_PlaylistFon->addMedia(QUrl(QApplication::applicationDirPath() +"./music/Bones  Dylan Ross - TheIvy.wav"));
m_PlaylistFon->addMedia(QUrl(QApplication::applicationDirPath() +"./music/BONES - Kale (Feat. Eddy Baker).mp3"));
m_PlaylistFon->addMedia(QUrl(QApplication::applicationDirPath() +"./music/BONES - PleaseHangUpAndTryAgain.wav"));
m_PlaylistFon->addMedia(QUrl(QApplication::applicationDirPath() +"./music/BONES - Sixteen.wav"));
m_PlaylistFon->addMedia(QUrl(QApplication::applicationDirPath() +"./music/BONES - TheHealingFields.mp3"));
m_PlaylistFon->setPlaybackMode(QMediaPlaylist::Random );
m_Fon->play();

//Кнопка "Настроки"
QPushButton *btnSettings = new QPushButton("Настройки", this);
btnSettings->resize(100,25);
btnSettings->move(900, 680);
btnSettings->show();


//Изображение справа
RightImg=new QLabel(this);
QPixmap pix1( ":/texture/Anime boy.png" );
RightImg->setPixmap( pix1 );
RightImg->move(720, 0);
RightImg->resize(pix1.size() );
RightImg->show();




//Сколько сделано ходов(число)
Steps =new QLabel(this);
Steps->move(740, 52);
Steps->resize(100,100);
Steps->setText("0");
QFont font1 = Steps->font();
font1.setPixelSize(15);
Steps->setFont(font1);

//Надпись "Ход"
LabelSteps =new QLabel(this);
LabelSteps->move(710, 51);
LabelSteps->setText("Ход: ");
LabelSteps->resize(100,100);
QFont font2 = LabelSteps->font();
font2.setPixelSize(15);
LabelSteps->setFont(font2);


//Счет(число)
Score =new QLabel(this);
Score->move(750, 72);
Score->resize(45,100);
Score->setText("0");
QFont font3 = Score->font();
font3.setPixelSize(15);
Score->setFont(font3);

//Надпись "Счет"
LabelScore =new QLabel(this);
LabelScore->move(710, 71);
LabelScore->setText("Счет:  ");
LabelScore->resize(100,100);
QFont font4 = LabelScore->font();
font4.setPixelSize(15);
LabelScore->setFont(font4);

//Сколько прибавлять после хода(число)
PlusToScoreNow =new QLabel(this);
PlusToScoreNow->move(740, 87);
PlusToScoreNow->resize(100,100);
PlusToScoreNow->setText("");
QFont font5 = Steps->font();
font5.setPixelSize(15);
QPalette palette;
srand(time(NULL));
float r=0;
float g=0;
float b=0;
//while(r+g+b<430)
{
r=rand() % 255;
g=rand() % 255;
b=rand() % 255;
}
//QBrush brush(QColor(r, g, b, 255));
QBrush brush(QColor(0,0,255, 255));
brush.setStyle(Qt::SolidPattern);
palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
PlusToScoreNow->setPalette(palette);
PlusToScoreNow->setFont(font5);


}



void Widget::stepsChanged(int newSteps)
{


    Steps->setText(QString::number(newSteps));
}


void Widget::PlusToScoreNowChanged(float newPlusToScoreNow)
{
    if(newPlusToScoreNow!=0)
    {

        PlusToScoreNow->setText("+"+QString::number(newPlusToScoreNow));
    }
    else
    {

        PlusToScoreNow->setText("");
    }

}
void Widget::ScoreChanged(float newScore)
{
    Score->setText(QString::number(newScore));
}



Widget::~Widget()
{

}

