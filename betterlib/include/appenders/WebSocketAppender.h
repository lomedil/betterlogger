#ifndef _WEBSOCKETAPPENDER_H_
#define _WEBSOCKETAPPENDER_H_

#include <better_globals.h>
#include <QtCore>
#include <QWebSocketServer>
#include <appenders/BaseAppender.h>

BEGIN_NS_BETTER_APPENDERS


class WebSocketAppender : public QObject, public BaseAppender
{
    Q_OBJECT
public:
    explicit WebSocketAppender(QObject *parent = 0);
    virtual ~WebSocketAppender();

private:
    QWebSocketServer        *m_pServer;
    QList<QWebSocket*>      m_clients;

private slots:
    void onNewConnection();
    void removeClient();


    // ILogAppender interface
public:
    void postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
};

END_NS_BETTER_APPENDERS

#endif //_WEBSOCKETAPPENDER_H_
