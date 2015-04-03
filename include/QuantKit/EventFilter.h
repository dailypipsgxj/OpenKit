#ifndef __QUANTKIT_EVENTFILTER_H__
#define __QUANTKIT_EVENTFILTER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class EventFilterPrivate;

class Framework;
class Event;

class QUANTKIT_EXPORT EventFilter
{
public:
	explicit EventFilter(const Framework& framework);
	~EventFilter();

	EventFilter(const EventFilter &other);
	EventFilter& operator=(const EventFilter &other);
	bool operator==(const EventFilter &other) const;
	inline bool operator!=(const EventFilter &other) const { return !(this->operator==(other));  }
public:
	Event filter(const Event& e);

private:
	QSharedDataPointer<EventFilterPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventFilter& eventfilter);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventFilter& eventfilter);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventFilter)

#endif // __QUANTKIT_EVENTFILTER_H__
