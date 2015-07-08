#include <WebSocketAppender.h>
#include <QWebSocket>

BEGIN_NS_BETTER



WebSocketAppender::WebSocketAppender(QObject *parent) :
    QObject(parent)
{
    m_pMutex = new QMutex();
    m_pTimer = new QTimer(this);
    m_pTimer->setInterval(1000);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(pushBundle()) );

    m_pServer = new QWebSocketServer(QLatin1String("Better Websocket"),
                                     QWebSocketServer::NonSecureMode,
                                     this);
    connect(m_pServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()) );

    m_pTimer->start();
    m_pServer->listen(QHostAddress::Any, 1234);
}

WebSocketAppender::~WebSocketAppender()
{
    m_pTimer->stop();
    m_pServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
    delete m_pMutex;
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

void WebSocketAppender::pushBundle()
{
    if(!m_nextBundle.isValid() || m_nextBundle.count() == 0) return;

    QString data = m_nextBundle.toString();

    pushMessage(data);

    resetBundleFormatter();
}

void WebSocketAppender::onFormatterChanged()
{
    resetBundleFormatter();
}

void WebSocketAppender::resetBundleFormatter()
{
    if(hasFormatter())
    {
        QMutexLocker locker(m_pMutex);
        m_nextBundle = formatter()->createBundle();
    }
}

void WebSocketAppender::pushMessage(const QString &message)
{
    const int n = m_clients.count();
    for(int i = 0; i < n; ++i)
    {
        m_clients[i]->sendTextMessage(message);
    }
}

void WebSocketAppender::postMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(m_nextBundle.isValid())
    {
        QMutexLocker locker(m_pMutex);
        m_nextBundle.addMessage(type, context, msg);
    }
    else
    {
        pushMessage(msg);
    }
}


END_NS_BETTER
