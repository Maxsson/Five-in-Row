#ifndef UPD_H
#define UPD_H

#include <QWidget>
#include <QLabel>
class Upd : public QWidget
{
    Q_OBJECT
public:
    explicit Upd(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *LabelSteps;
};

#endif // UPD_H
