#ifndef _IFORMATTER_H_
#define _IFORMATTER_H_

#include <better_globals.h>
#include <QDebug>
#include <QString>

BEGIN_NS_BETTER

class IFormatter
{
public:
    virtual ~IFormatter(){}

    virtual QString format(QtMsgType type, const QMessageLogContext &context, const QString &msg) = 0;
};


END_NS_BETTER


#endif //_IFORMATTER_H_
