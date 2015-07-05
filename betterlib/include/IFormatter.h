#ifndef _IFORMATTER_H_
#define _IFORMATTER_H_

#include <better_globals.h>
#include <QDebug>
#include <QString>
#include <BundleFormatter.h>

BEGIN_NS_BETTER

class IFormatter
{
public:
    virtual ~IFormatter(){}

    virtual QString format(QtMsgType type, const QMessageLogContext &context, const QString &msg) = 0;

    virtual BundleFormatter createBundle() = 0;

protected:
    static BundleFormatter createMessageBundle(IFormatter *formatter){ return better::BundleFormatter(formatter); }
};


END_NS_BETTER


#endif //_IFORMATTER_H_
