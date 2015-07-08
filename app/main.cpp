#include <QtCore>
#include <QCoreApplication>

#include <MessageDispatcher.h>
#include <ConsoleAppender.h>
#include <WebSocketAppender.h>
#include <JsonFormatter.h>

#include <TimerMessage.h>


void message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
static better::MessageDispatcher * g_messageDispatchet = 0;

int main(int argn, char **argv)
{
    QCoreApplication app(argn, argv);

    qDebug() << "Init. app";

    better::WebSocketAppender *wsAppender = new better::WebSocketAppender();
    wsAppender->installFormatter(new better::JsonFormatter);

    g_messageDispatchet = new better::MessageDispatcher();
    g_messageDispatchet->addAppender(new better::ConsoleAppender());
    g_messageDispatchet->addAppender(wsAppender);

    qDebug() << "Installing message handler";
    qInstallMessageHandler(&message_handler);

    TimerMessage tm;

    return app.exec();
}


void message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    g_messageDispatchet->postMessage(type, context, msg);
}
