#include <WebSocketAppender.h>
#include <QWebSocket>

BEGIN_NS_BETTER_APPENDERS



WebSocketAppender::WebSocketAppender(QObject *parent) :
    QObject(parent)
{
    m_pServer = new QWebSocketServer(QLatin1String("Better Websocket"),
                                     QWebSocketServer::NonSecureMode,
                                     this);
    connect(m_pServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()) );
    m_pServer->listen(QHostAddress::Any, 1234);
}

WebSocketAppender::~WebSocketAppender()
{
    m_pServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void WebSocketAppender::onNewConnection()
{
    QWebSocket *socket = m_pServer->nextPendingConnection();
    Q_ASSERT(socket);

    connect(socket, SIGNAL(disconnected()), this, SLOT(removeClient()) );

    m_clients << socket;
}

void WebSocketAppender::removeClient()
{
    QWebSocket *socket = qobject_cast<QWebSocket*>(sender());

    m_clients.removeOne(socket);
}

void WebSocketAppender::postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    const int n = m_clients.count();
    for(int i = 0; i < n; ++i)
    {
        m_clients[i]->sendTextMessage(msg);
    }
}



END_NS_BETTER_APPENDERS
