#ifndef __QUANTKIT_ONLOGGEDOUT_H__
#define __QUANTKIT_ONLOGGEDOUT_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnLoggedOutPrivate;

class QUANTKIT_EXPORT OnLoggedOut Q_DECL_FINAL : public Event
{
public:
	OnLoggedOut();
	explicit OnLoggedOut(const QDateTime& dateTime);
	~OnLoggedOut();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnLoggedOut)

#endif // __QUANTKIT_ONLOGGEDOUT_H__
