#ifndef TABLE_H
#define TABLE_H
#include <QTableWidget>
#include <QMouseEvent>
#include <Widget.h>
#include <QObject>

class Table: public QTableWidget
{
    Q_OBJECT
 signals:
    void ShowStep(int);
    void ShowScore(int);
    void ShowPlusToScoreNow(int);
    void ShowPlus(int);

 private:
    int Old_Row=-1;
    int Old_Column=-1;    
    int static const RowAndColumn = 10;
    int unsigned Colors = 3;
    int cell[RowAndColumn+4][RowAndColumn+4];
    int Steps=0;
    int const ALFAforBackgraound = 20;
    float Score=0.;
    float StepMultiplicationFactor = 1.;
    float PlusToScoreNow=0;
    bool HaveFiveOrMore;
    int PlusToScore=50;
    void wait250ms();
    void waitMS(int ms);
    void animationWillBeDeleted(int i,int j,bool left,int N);
    void Delete();
    void ShowingScore();






public:
    Table(QWidget *parent = 0);



    void mousePressEvent(QMouseEvent*event);
    void Out();
    void CheckFive();
    void CheackCross(int i, int j,bool vertic, int N);
    void Down();

};

#endif // TABLE_H
