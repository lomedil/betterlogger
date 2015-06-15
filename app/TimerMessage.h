#ifndef _TIMERMESSAGE_H_
#define _TIMERMESSAGE_H_

#include <QtCore>

class TimerMessage : public QObject
{
    Q_OBJECT
public:
    TimerMessage(QObject *parent = 0);

private:
    QTimer      *m_pTimer;
    uint        m_counter;

public slots:
    void printCounter();
    void print(const QString &msg);
};


#endif //_TIMERMESSAGE_H_
