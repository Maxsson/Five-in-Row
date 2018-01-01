#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QObject>


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
    //QLabel *BackGroundImg;
    QLabel *RightImg;






public  slots:
    void stepsChanged(int newSteps);
    void ScoreChanged(float newScore);
    void PlusToScoreNowChanged(float newPlusToScoreNow);

};

#endif // WIDGET_H
