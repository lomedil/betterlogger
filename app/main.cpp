#include <QtCore>
#include <QCoreApplication>

#include <MessageDispatcher.h>
#include <appenders/ConsoleAppender.h>

#include <TimerMessage.h>


void message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
static better::MessageDispatcher * g_messageDispatchet = 0;

int main(int argn, char **argv)
{
    QCoreApplication app(argn, argv);

    qDebug() << "Init. app";

    g_messageDispatchet = new better::MessageDispatcher();
    g_messageDispatchet->addAppender(new better::appenders::ConsoleAppender());

    qDebug() << "Installing message handler";
    qInstallMessageHandler(&message_handler);

    TimerMessage tm;

    return app.exec();
}


void message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    g_messageDispatchet->postMessage(type, context, msg);
}
