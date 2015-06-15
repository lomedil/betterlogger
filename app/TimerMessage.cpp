#include <TimerMessage.h>
#include <QDebug>

TimerMessage::TimerMessage(QObject *parent) :
    QObject(parent),
    m_pTimer(new QTimer(this)),
    m_counter(0)
{
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(printCounter()) );

    m_pTimer->setInterval(1000);
    m_pTimer->start();
}

void TimerMessage::printCounter()
{
    print(QString("Message counter # %1").arg(m_counter++));
    if(m_counter >= 1024)
        m_counter = 0;
}

void TimerMessage::print(const QString &msg)
{
    qDebug() << qPrintable(msg);
}
