#include <appenders/BaseAppender.h>

BEGIN_NS_BETTER_APPENDERS


BaseAppender::BaseAppender() :
    m_pFormatter(0)
{

}

BaseAppender::~BaseAppender()
{  }

bool BaseAppender::hasFormatter() const
{
    return m_pFormatter != 0;
}

IFormatter *BaseAppender::formatter()
{
    return m_pFormatter;
}

void BaseAppender::installFormatter(IFormatter *formatter)
{
    m_pFormatter = formatter;
    onFormatterChanged();
}


END_NS_BETTER_APPENDERS
