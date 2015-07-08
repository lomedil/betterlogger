#ifndef _JSONFORMATTER_H_
#define _JSONFORMATTER_H_


#include <better_globals.h>
#include <IFormatter.h>

BEGIN_NS_BETTER

class JsonFormatter : public IFormatter
{
public:
    JsonFormatter();
    virtual ~JsonFormatter();

private:
    static QString messageTypeString(QtMsgType type);

    // IFormatter interface
public:
    QString format(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    BundleFormatter createBundle();
};


END_NS_BETTER

#endif //_JSONFORMATTER_H_
