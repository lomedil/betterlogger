#ifndef _BASEAPPENDER_H_
#define _BASEAPPENDER_H_


#include <better_globals.h>
#include <ILogAppender.h>

BEGIN_NS_BETTER_APPENDERS

class BaseAppender : public ILogAppender
{
public:
    BaseAppender();
    virtual ~BaseAppender();

public:
    bool hasFormatter() const;
    IFormatter *formatter();

private:
    IFormatter      *m_pFormatter;

protected:
    virtual void onFormatterChanged(){}

// ILogAppender interface
public:
    void installFormatter(IFormatter *formatter);
};

END_NS_BETTER_APPENDERS


#endif //_BASEAPPENDER_H_
