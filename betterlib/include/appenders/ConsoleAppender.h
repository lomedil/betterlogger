#ifndef _CONSOLEAPPENDER_H_
#define _CONSOLEAPPENDER_H_

#include <better_globals.h>
#include <appenders/BaseAppender.h>

BEGIN_NS_BETTER_APPENDERS

class ConsoleAppender : public BaseAppender
{
public:
    ConsoleAppender();

    // ILogAppender interface
public:
    void postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
};

END_NS_BETTER_APPENDERS


#endif //_CONSOLEAPPENDER_H_
