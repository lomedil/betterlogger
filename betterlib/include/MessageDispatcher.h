#ifndef _MESSAGEDISPATCHER_H_
#define _MESSAGEDISPATCHER_H_


#include <better_globals.h>
#include <QString>
#include <QList>
#include <QDebug>
#include <ILogAppender.h>


BEGIN_NS_BETTER

class MessageDispatcher
{
public:
    MessageDispatcher();

private:
    QList<ILogAppender*> m_appenders;

public:
    void addAppender(ILogAppender *appender);
    void postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
};

END_NS_BETTER


#endif //_MESSAGEDISPATCHER_H_
