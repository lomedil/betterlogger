#ifndef _WEBSOCKETAPPENDER_H_
#define _WEBSOCKETAPPENDER_H_

#include <better_globals.h>
#include <QtCore>
#include <QWebSocketServer>
#include <BaseAppender.h>

BEGIN_NS_BETTER


class WebSocketAppender : public QObject, public BaseAppender
{
    Q_OBJECT
public:
    explicit WebSocketAppender(QObject *parent = 0);
    virtual ~WebSocketAppender();

private:
    QWebSocketServer        *m_pServer;
    QList<QWebSocket*>      m_clients;
    BundleFormatter         m_nextBundle;
    QTimer                  *m_pTimer;
    QMutex                  *m_pMutex;

private slots:
    void onNewConnection();
    void removeClient();
    void pushBundle();

protected:
    void onFormatterChanged(); // override

private:
    void resetBundleFormatter();
    void pushMessage(const QString &message);


    // ILogAppender interface
public:
    void postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
};

END_NS_BETTER

#endif //_WEBSOCKETAPPENDER_H_
