#ifndef __QUANTKIT_ONLOGINREJECTED_H__
#define __QUANTKIT_ONLOGINREJECTED_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnLoginRejectedPrivate;

class QUANTKIT_EXPORT OnLoginRejected Q_DECL_FINAL : public Event
{
public:
	OnLoginRejected();
	explicit OnLoginRejected(const QDateTime& dateTime);
	~OnLoginRejected();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnLoginRejected)

#endif // __QUANTKIT_ONLOGINREJECTED_H__
