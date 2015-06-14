#include <MessageDispatcher.h>

BEGIN_NS_BETTER

MessageDispatcher::MessageDispatcher()
{

}

void MessageDispatcher::addAppender(appenders::ILogAppender *appender)
{
    if(m_appenders.contains(appender)) return;

    m_appenders << appender;
}

void MessageDispatcher::postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    const int n = m_appenders.count();
    for(int i = 0; i < n; ++i)
    {
        m_appenders[i]->postMessage(type, context, msg);
    }
}


END_NS_BETTER


