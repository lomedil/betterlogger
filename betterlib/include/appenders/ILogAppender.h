#ifndef _ILOGAPPENDERS_H_
#define _ILOGAPPENDERS_H_

#include <better_globals.h>
#include <QDebug>
#include <IFormatter.h>


BEGIN_NS_BETTER_APPENDERS

class ILogAppender
{
public:
    virtual ~ILogAppender(){}

public:
    virtual void postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg) = 0;

    virtual void installFormatter(IFormatter *formatter) = 0;
};

END_NS_BETTER_APPENDERS


#endif //_ILOGAPPENDERS_H_
