#ifndef __QUANTKIT_ONLOGGEDIN_H__
#define __QUANTKIT_ONLOGGEDIN_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnLoggedInPrivate;

class QUANTKIT_EXPORT OnLoggedIn Q_DECL_FINAL : public Event
{
public:
	OnLoggedIn();
	explicit OnLoggedIn(const QDateTime& dateTime);
	~OnLoggedIn();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnLoggedIn)

#endif // __QUANTKIT_ONLOGGEDIN_H__
