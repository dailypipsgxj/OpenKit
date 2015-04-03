#ifndef __QUANTKIT_ONHEARTBEAT_H__
#define __QUANTKIT_ONHEARTBEAT_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnHeartbeatPrivate;

class QUANTKIT_EXPORT OnHeartbeat Q_DECL_FINAL : public Event
{
public:
	OnHeartbeat();
	explicit OnHeartbeat(const QDateTime& dateTime);
	~OnHeartbeat();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnHeartbeat)

#endif // __QUANTKIT_ONHEARTBEAT_H__
