#include <appenders/ConsoleAppender.h>
#include <QTextStream>

BEGIN_NS_BETTER_APPENDERS

ConsoleAppender::ConsoleAppender()
{

}

void ConsoleAppender::postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QTextStream ts(stdout);
    ts << qPrintable(msg);
}



END_NS_BETTER_APPENDERS
