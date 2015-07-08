#include <BundleFormatter.h>
#include <IFormatter.h>

BEGIN_NS_BETTER

class BundleFormatterPrivate
{
public:
    QStringList     entries;
    IFormatter      *pFormatter;
    QString         header;
    QString         footer;
    QString         separator;
};


BundleFormatter::BundleFormatter(IFormatter *formatter) :
    d(new BundleFormatterPrivate)
{
    d->pFormatter = formatter;
}

BundleFormatter::BundleFormatter()
{  }

BundleFormatter::BundleFormatter(const BundleFormatter &other) :
    d(other.d)
{

}

void BundleFormatter::setHeader(const QString &header)
{
    d->header = header;
}

void BundleFormatter::setFooter(const QString &footer)
{
    d->footer = footer;
}

void BundleFormatter::setSeparator(const QString &separator)
{
    d->separator = separator;
}

bool BundleFormatter::isValid() const
{
    return !d.isNull();
}

int BundleFormatter::count() const
{
    return d->entries.count();
}

int BundleFormatter::addMessage(QtMsgType type, const QMessageLogContext &context, const QString msg)
{
    d->entries.append(d->pFormatter->format(type, context, msg));
    return count();
}

QString BundleFormatter::toString() const
{
    QString output = d->header;
    output += d->entries.join(d->separator);
    output += d->footer;
    return output;
}


END_NS_BETTER
