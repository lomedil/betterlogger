#include <JsonFormatter.h>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

BEGIN_NS_BETTER

JsonFormatter::JsonFormatter()
{  }

JsonFormatter::~JsonFormatter()
{  }

QString JsonFormatter::messageTypeString(QtMsgType type)
{
    switch (type) {
    case QtDebugMsg:    return "debug";
    case QtWarningMsg:  return "warning";
    case QtFatalMsg:    return "fatal";
    case QtCriticalMsg: return "critical";
    default:            return "unknown";
    }
}

QString JsonFormatter::format(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QJsonObject jsonObject;

    jsonObject.insert("type", QJsonValue(messageTypeString(type)));
    jsonObject.insert("message", QJsonValue(msg));

    QJsonObject jsonContext;
    jsonContext.insert("category", QJsonValue(context.category));
    jsonContext.insert("file", QJsonValue(context.file));
    jsonContext.insert("function", QJsonValue(context.function));
    jsonContext.insert("line", QJsonValue(context.line));
    jsonContext.insert("version", QJsonValue(context.version));

    jsonObject.insert("context", QJsonValue(jsonContext));

    return QJsonDocument(jsonObject).toJson(QJsonDocument::Compact);
}


END_NS_BETTER

