#ifndef __QUANTKIT_ONLOGIN_H__
#define __QUANTKIT_ONLOGIN_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnLoginPrivate;

class QUANTKIT_EXPORT OnLogin Q_DECL_FINAL : public Event
{
public:
	OnLogin();
	explicit OnLogin(const QDateTime& dateTime);
	~OnLogin();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnLogin)

#endif // __QUANTKIT_ONLOGIN_H__
