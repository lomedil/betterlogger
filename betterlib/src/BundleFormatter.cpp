#include <MessageBundle.h>
#include <IFormatter.h>

BEGIN_NS_BETTER

class BundleFormatterPrivate
{
public:
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

BundleFormatter::BundleFormatter(const BundleFormatter &other) :
    QStringList(other),
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

int BundleFormatter::addMessage(QtMsgType type, const QMessageLogContext &context, const QString msg)
{
    this->append(d->pFormatter->format(type, context, msg));
    return this->count();
}

QString BundleFormatter::toString() const
{
    QString output = d->header;
    output += this->join(d->separator);
    output += d->footer;
    return output;
}


END_NS_BETTER
