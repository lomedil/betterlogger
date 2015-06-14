#include <QtCore>
#include <QCoreApplication>

#include <MessageDispatcher.h>


void message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
static better::MessageDispatcher * g_messageDispatchet = 0;

int main(int argn, char **argv)
{
    QCoreApplication app(argn, argv);


    g_messageDispatchet = new better::MessageDispatcher();

    qInstallMessageHandler(&message_handler);

    return app.exec();
}


void message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    g_messageDispatchet->postMessage(type, context, msg);
}
