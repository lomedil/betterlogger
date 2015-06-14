#ifndef _ILOGAPPENDERS_H_
#define _ILOGAPPENDERS_H_

#include <better_globals.h>
#include <QDebug>


BEGIN_NS_BETTER_APPENDERS

class ILogAppender
{
public:
    virtual ~ILogAppender(){}

public:
    virtual void postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg) = 0;
};

END_NS_BETTER_APPENDERS


#endif //_ILOGAPPENDERS_H_
