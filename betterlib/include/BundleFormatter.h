#ifndef _BUNDLEFORMATTER_H_
#define _BUNDLEFORMATTER_H_

#include <better_globals.h>
#include <QStringList>
#include <QSharedPointer>


BEGIN_NS_BETTER

// Fwd-decl
class IFormatter;
class BundleFormatterPrivate;

class BundleFormatter
{
public:
    BundleFormatter(); // invalid
    BundleFormatter(const BundleFormatter &other);

private:
    BundleFormatter(IFormatter *formatter);


public:
    void setHeader(const QString &header);
    void setFooter(const QString &footer);
    void setSeparator(const QString &separator);

public:
    bool isValid() const;
    int count() const;
    int addMessage(QtMsgType type, const QMessageLogContext &context, const QString msg);

    QString toString() const;


private:
    QSharedPointer<BundleFormatterPrivate>  d;

    friend class IFormatter;

};

END_NS_BETTER

#endif //_BUNDLEFORMATTER_H_
