#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPushButton>
#include <QCheckBox>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



private:
    Ui::Widget *ui;
    QLabel *Steps;
    QLabel *LabelSteps;
    QLabel *Score;
    QLabel *LabelScore;
    QLabel *PlusToScoreNow;
    QLabel *RightImg;
    QMediaPlayer * m_Fon;
    QMediaPlaylist * m_PlaylistFon;
    QCheckBox  *CBMusic;






signals:void MusicChanged(bool SoundsMusic);

public  slots:
    void stepsChanged(int newSteps);
    void ScoreChanged(float newScore);
    void PlusToScoreNowChanged(float newPlusToScoreNow);
    void Music(bool On);






};

#endif // WIDGET_H
