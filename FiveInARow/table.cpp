#include "table.h"
#include <QHeaderView>
#include <qcolor.h>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>
#include <QMediaPlayer>
#include <QMediaPlaylist>


Table::Table(QWidget *parent):QTableWidget(parent)
{

//настройки для таблицы
setRowCount(RowAndColumn);
setColumnCount(RowAndColumn);
setFixedSize(1024,720);
//Картинка background
setStyleSheet("border-image: url(:/texture/fon(2).png)");



setEditTriggers(QAbstractItemView::NoEditTriggers);
setSelectionMode(QAbstractItemView::NoSelection);

verticalHeader()->setVisible(false);
horizontalHeader()->setVisible(false);

verticalHeader()->setDefaultSectionSize(70);
horizontalHeader()->setDefaultSectionSize(70);


//настройка иконок
setIconSize(QSize (65,65));


QIcon iconB(":icon/1.png");
QIcon iconR(":icon/2.png");
QIcon iconY(":icon/3.png");


//Подключение Ходов,Счета,"+",прибавление счета
connect(this,&Table::ShowStep,(Widget*)this->parent(),&Widget::stepsChanged);
connect(this,&Table::ShowScore,(Widget*)this->parent(),&Widget::ScoreChanged);


connect(this,&Table::ShowPlusToScoreNow,(Widget*)this->parent(),&Widget::PlusToScoreNowChanged);


srand(time(NULL));


//1- Синий; 2-Красный; 3-Желтый
//-1,-2,-3, - удалить
//Инициализация таблицы


for (int i = 0; i < RowAndColumn; i++)
    for (int j = 0; j < RowAndColumn; j++)
    {

     GO:
     QTableWidgetItem *item = new QTableWidgetItem();
     int random =rand() % Colors +1;
     if (random == 1)
     {
         cell[i][j]=1;
         if (((cell[i][j] != cell[i-1][j]) || (cell[i][j] != cell[i-2][j]) || (cell[i][j] != cell[i-3][j]))
         &&((cell[i][j] != cell[i][j-1]) || (cell[i][j] != cell[i][j-2]) || (cell[i][j] != cell[i][j-3])))
         {

                item->setIcon(iconB);
                item->setBackgroundColor(QColor(0,0,255,ALFAforBackgraound));
          }
        else   {
             cell[i][j]=0;
            goto GO;
         }

    }
    else if (random == 2)
    {
         cell[i][j]=2;
         if (((cell[i][j] != cell[i-1][j]) || (cell[i][j] != cell[i-2][j]) || (cell[i][j] != cell[i-3][j]))
         &&((cell[i][j] != cell[i][j-1]) || (cell[i][j] != cell[i][j-2]) || (cell[i][j] != cell[i][j-3])))
        {

            item->setIcon(iconR);
            item->setBackgroundColor(QColor(255,0,0,ALFAforBackgraound));
        }
         else   {
              cell[i][j]=0;
             goto GO;
          }

    }
   else if (random == 3)
    {
          cell[i][j]=3;
         if (((cell[i][j] != cell[i-1][j]) || (cell[i][j] != cell[i-2][j]) || (cell[i][j] != cell[i-3][j]))
         &&((cell[i][j] != cell[i][j-1]) || (cell[i][j] != cell[i][j-2]) || (cell[i][j] != cell[i][j-3])))
        {

            item->setIcon(iconY);
            item->setBackgroundColor(QColor(255, 255, 0,ALFAforBackgraound));
        }
         else   {
              cell[i][j]=0;
             goto GO;
          }

    }
  setItem( i, j, item );



    }

}



//Клик мыши и смена элементов(полная)
void Table::mousePressEvent(QMouseEvent *event)
{
    QIcon iconB(":icon/1.png");
    QIcon iconR(":icon/2.png");
    QIcon iconY(":icon/3.png");
    int static color;

    QTableWidgetItem *item = new QTableWidgetItem();
    QTableWidgetItem *itemchange =  itemAt(event->pos());
   if (Old_Row == -1)
   {
            if (itemchange != 0)
            {
                if (event->button()==Qt::LeftButton)
                {
                    Old_Row=itemchange->row();
                    Old_Column=itemchange->column();
                    //qDebug().nospace()<<Old_Row<<Old_Column;



                     QPixmap pixmapY = iconY.pixmap(QSize(55, 55));
                    color = cell[Old_Row][Old_Column];//1-blue 2-Red 3-yellow

                    if(color  == 1) {
                        for(int a=65;a>55;a--){
                          QPixmap pixmapB = iconB.pixmap(QSize(a, a));
                        item->setIcon(pixmapB);
                        item->setBackgroundColor(QColor(0,0,255,ALFAforBackgraound));
                        waitMS(15);
                        }
                        }
                    else if (color == 2)
                    {
                        for(int a=65;a>55;a--){
                            QPixmap pixmapR = iconR.pixmap(QSize(a, a));
                        item->setIcon(pixmapR);
                        item->setBackgroundColor(QColor(255,0,0,ALFAforBackgraound));
                        waitMS(15);
                        }
                    }
                    else if (color == 3)
                    {
                        for(int a=65;a>55;a--){
                            QPixmap pixmapY = iconY.pixmap(QSize(a, a));
                        item->setIcon(pixmapY);
                        item->setBackgroundColor(QColor(255, 255, 0,ALFAforBackgraound));
                        waitMS(15);
                        }
                    }
                    setItem(Old_Row, Old_Column, item );
                }
            }
    }
   else
   {
       if (event->button()==Qt::LeftButton)
       {
           if ((Old_Row != itemchange->row()) || (Old_Column != itemchange->column()))
           {
               if(color  == 1) {
                   item->setIcon(iconB);
                   item->setBackgroundColor(QColor(0,0,255,ALFAforBackgraound));
               }
               else if (color == 2)
               {
                   item->setIcon(iconR);
                   item->setBackgroundColor(QColor(255,0,0,ALFAforBackgraound));
               }
               else if (color == 3)
               {
                   item->setIcon(iconY);
                   item->setBackgroundColor(QColor(255, 255, 0,ALFAforBackgraound));
               }
                setItem(Old_Row, Old_Column, item );



               QIcon icon1=this->item(Old_Row,Old_Column)->icon();
               this->item(Old_Row,Old_Column)->setIcon(itemchange->icon());
               itemchange->setIcon(icon1);

               QColor color1=this->item(Old_Row,Old_Column)->backgroundColor();               
               this->item(Old_Row,Old_Column)->setBackgroundColor(itemchange->backgroundColor());               
               itemchange->setBackgroundColor(color1);

               int NewRow = itemchange->row();
               int NewColumn =itemchange->column();
               int NewIntCell= cell[NewRow][NewColumn];
               cell[NewRow][NewColumn]=cell[Old_Row][Old_Column];
               cell[Old_Row][Old_Column] =NewIntCell;

               Steps++;
               ShowStep(Steps);

               Old_Row=-1;
               Old_Column=-1;
               CheckFive();





            }
           else
           {
           Old_Row=-1;
           Old_Column=-1;
           }
       }
   }
}

//Вывод в дебаг всей таблицы
void Table::Out()
{
    qDebug()<<endl;
    for (int i = 0; i < RowAndColumn; i++)
    {
       qDebug().nospace()<<cell[i][0]<<", "<<cell[i][1]<<", "<<cell[i][2]<<", "<<cell[i][3]<<", "<<cell[i][4]<<", "<<
                                             cell[i][5]<<", "<<cell[i][6]<<", "<<cell[i][7]<<", "<<cell[i][8]<<", "<<cell[i][9];
    }
}

void Table::wait250ms(){
QEventLoop loop;
QTimer::singleShot(250, &loop, SLOT(quit()));
loop.exec();
}

void Table::waitMS(int ms){
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, SLOT(quit()));
    loop.exec();
}
//
void Table::CheackCross(int i, int j,bool left, int N)
{
    bool HaveCross = false;
    int color = cell [i][j];

    if(left == true)
    {
         for (int k=i;k<i+N;k++)
         {
             int vertic =1;
             int verticMinus =-1;
             while ((color == cell[k][j+vertic])&& (cell[k][j+vertic] >0) )
             {
                    vertic++;
             }
             while ((color == cell[k][j+verticMinus])&& (cell[k][j+verticMinus] >0) )
             {
                    verticMinus--;
             }
             if(vertic-verticMinus>5)
             {
                 PlusToScore=(vertic-verticMinus)*50;
                 //PlusToScore+=100.;
                 HaveCross=true;
                 animationWillBeDeleted(k,j+verticMinus+1, false, vertic-verticMinus-1);
                 ShowingScore();
                 PlusToScore=0;
             }
         }
    }
    else
    {
        for (int k=j;k<j+N;k++)
        {
            int horiz =1;
            int horizMinus =-1;
            while ((color == cell[i+horiz][k])&& (cell[i+horiz][k] >0) )
            {
                   horiz++;
            }
            while ((color == cell[i+horizMinus][k])&& (cell[i+horizMinus][k] >0) )
            {
                   horizMinus--;
            }
            if(horiz-horizMinus>5)
            {
                PlusToScore=(horiz-horizMinus)*50;
                //PlusToScore+=100.;
                HaveCross=true;
                animationWillBeDeleted(i+horizMinus+1,k, true, horiz-horizMinus-1);
                ShowingScore();
                PlusToScore=0;
            }
        }
    }

}


//Проверка на пять в ряд и удаление
//UPD:Проверка на >=5 и удаление
void Table::CheckFive()
{
    HaveFiveOrMore=false;
    for (int i = 0; i < RowAndColumn; i++)
        for (int j = 0; j < RowAndColumn; j++)
        {
            PlusToScore=0;
            int vert =1;
            int horiz =1;
               while ((cell[i][j] == cell[i+horiz][j])&& (cell[i+ horiz][j] >0) )
               {
                      horiz++;
               }

               if(horiz>4){

                   PlusToScore=horiz*20;
                   HaveFiveOrMore=true;
                   CheackCross( i,  j, true,  horiz);
                   animationWillBeDeleted(i, j, true, horiz);
                   ShowingScore();
                   PlusToScore=0;
               }

                while ((cell[i][j] == cell[i][j+vert]) && (cell[i][j+vert] >0))
                {
                       vert++;
                }

                if(vert>4){
                    PlusToScore=vert*20;
                    HaveFiveOrMore=true;
                    animationWillBeDeleted(i, j, false, vert);
                    ShowingScore();}
        }

if(HaveFiveOrMore==true)
{
    Delete();
}
else
{
    PlusToScoreNow=0;
    //waitMS(1000);
    ShowingScore();
    //waitMS(1000);
}
}


void Table::ShowingScore(){
if(HaveFiveOrMore==true){

    Score+=(PlusToScore*StepMultiplicationFactor);
    ShowScore(Score);
    PlusToScoreNow+=(PlusToScore*StepMultiplicationFactor);

    StepMultiplicationFactor+=0.5;
}
else{
    PlusToScore=0;
    PlusToScoreNow=0;
    StepMultiplicationFactor=1.;
}
ShowPlusToScoreNow(PlusToScoreNow);
}


void Table::animationWillBeDeleted(int i,int j,bool left,int N){
    HaveFiveOrMore=true;
    QIcon iconBm(":icon/1--.png");
    QIcon iconRm(":icon/2--.png");
    QIcon iconYm(":icon/3--.png");
    if(left==true){
            if(cell[i][j] == 1 || cell[i][j] == -1){for (int l=0; l<N; l++){QTableWidgetItem *item1 = new QTableWidgetItem();item1->setIcon(iconBm);item1->setBackgroundColor(QColor(0,0,255,ALFAforBackgraound));setItem( i+l, j, item1 ); cell[i+l][j]=-1;}}
            if(cell[i][j] == 2 || cell[i][j] == -2){for (int l=0; l<N; l++){QTableWidgetItem *item1 = new QTableWidgetItem();item1->setIcon(iconRm);item1->setBackgroundColor(QColor(255,0,0,ALFAforBackgraound));setItem( i+l, j, item1 );cell[i+l][j]=-2;}}
            if(cell[i][j] == 3 || cell[i][j] == -3){for (int l=0; l<N; l++){QTableWidgetItem *item1 = new QTableWidgetItem();item1->setIcon(iconYm);item1->setBackgroundColor(QColor(255, 255, 0,ALFAforBackgraound));setItem( i+l, j, item1 );cell[i+l][j]=-3;}}
    }
    else
    {
            if(cell[i][j] == 1 || cell[i][j] == -1){for (int l=0; l<N; l++){QTableWidgetItem *item1 = new QTableWidgetItem();item1->setIcon(iconBm);item1->setBackgroundColor(QColor(0,0,255,ALFAforBackgraound));setItem( i, j+l, item1 );cell[i][j+l]=-1;}}
            if(cell[i][j] == 2 || cell[i][j] == -2){for (int l=0; l<N; l++){QTableWidgetItem *item1 = new QTableWidgetItem();item1->setIcon(iconRm);item1->setBackgroundColor(QColor(255,0,0,ALFAforBackgraound));setItem( i, j+l, item1 );cell[i][j+l]=-2;}}
            if(cell[i][j] == 3 || cell[i][j] == -3){for (int l=0; l<N; l++){QTableWidgetItem *item1 = new QTableWidgetItem();item1->setIcon(iconYm);item1->setBackgroundColor(QColor(255, 255, 0,ALFAforBackgraound));setItem( i, j+l, item1 );cell[i][j+l]=-3;}}
    }
    wait250ms();



    //Delete();
}

void Table::Delete(){


    for (int i = 0; i < RowAndColumn; i++)
        for (int j = 0; j < RowAndColumn; j++){
            if(cell[i][j]<0){
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setBackgroundColor(QColor(90, 0, 157,140));
            setItem( i, j, item );
            cell[i][j]= 0;
            }

        }
    Down();
    }

//"Падение" на пустые клетки(+появление новых элементов)
void Table::Down()
{
    srand(time(NULL));
    for (int i = 0; i < RowAndColumn; i++)
        for (int j = 0; j < RowAndColumn; j++)
        {
            if (this->item(i,j)->backgroundColor()==QColor(90, 0, 157,140))
            {
                int p=i;
                while (p>0)
                {
                QTableWidgetItem *item = new QTableWidgetItem();
                QIcon icon1=this->item(p-1,j)->icon();
                item->setIcon(icon1);

                QColor color1=this->item(p-1,j)->backgroundColor();
                item->setBackgroundColor(color1);

                cell[p][j]=cell[p-1][j];
                setItem(p,j,item);

                p--;
                }
                if(p == 0)
                {

                    QTableWidgetItem *item = new QTableWidgetItem();
                    int random =rand() % Colors +1;
                    if (random == 1)
                    {
                        cell[0][j]=1;
                        QIcon iconB(":icon/1.png");
                        item->setIcon(iconB);
                        item->setBackgroundColor(QColor(0,0,255,ALFAforBackgraound));
                     }
                    else if (random == 2)
                    {
                        cell[0][j]=2;
                        QIcon iconR(":icon/2.png");
                        item->setIcon(iconR);
                        item->setBackgroundColor(QColor(255,0,0,ALFAforBackgraound));
                      }
                  else if (random == 3)
                   {
                        cell[0][j]=3;
                        QIcon iconY(":icon/3.png");
                        item->setIcon(iconY);
                        item->setBackgroundColor(QColor(255, 255, 0,ALFAforBackgraound));
                       }
                      setItem(0, j, item );

                }
                wait250ms();
                }

        }
    //Увеличенный коэфицент прибавки к очкам при исчезновение больше 1 раза.
    if(HaveFiveOrMore==true)
          CheckFive();

}






