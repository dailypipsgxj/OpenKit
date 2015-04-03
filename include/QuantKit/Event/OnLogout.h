#ifndef __QUANTKIT_ONLOGOUT_H__
#define __QUANTKIT_ONLOGOUT_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnLogoutPrivate;

class QUANTKIT_EXPORT OnLogout Q_DECL_FINAL : public Event
{
public:
	OnLogout();
	explicit OnLogout(const QDateTime& dateTime);
	~OnLogout();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnLogout)

#endif // __QUANTKIT_ONLOGOUT_H__
