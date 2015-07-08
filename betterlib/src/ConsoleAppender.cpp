#include <ConsoleAppender.h>
#include <QTextStream>

BEGIN_NS_BETTER

ConsoleAppender::ConsoleAppender()
{

}

void ConsoleAppender::postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QTextStream ts(stdout);
    ts << qPrintable(hasFormatter()? formatter()->format(type, context, msg) : msg);
}



END_NS_BETTER
