#ifndef __QUANTKIT_EVENTQUEUEID_H__
#define __QUANTKIT_EVENTQUEUEID_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class EventQueueIdPrivate;

class QUANTKIT_EXPORT EventQueueId
{
public:
	EventQueueId();
	~EventQueueId();

	EventQueueId(const EventQueueId &other);
	EventQueueId& operator=(const EventQueueId &other);
	bool operator==(const EventQueueId &other) const;
	inline bool operator!=(const EventQueueId &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<EventQueueIdPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventQueueId& eventqueueid);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventQueueId& eventqueueid);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventQueueId)

#endif // __QUANTKIT_EVENTQUEUEID_H__
