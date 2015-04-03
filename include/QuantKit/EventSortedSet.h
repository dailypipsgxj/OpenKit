#ifndef __QUANTKIT_EVENTSORTEDSET_H__
#define __QUANTKIT_EVENTSORTEDSET_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class EventSortedSetPrivate;

class Event;

class QUANTKIT_EXPORT EventSortedSet
{
public:
	EventSortedSet();
	~EventSortedSet();

	EventSortedSet(const EventSortedSet &other);
	EventSortedSet& operator=(const EventSortedSet &other);
	bool operator==(const EventSortedSet &other) const;
	inline bool operator!=(const EventSortedSet &other) const { return !(this->operator==(other));  }
public:
	QString name() const;
	void setName(const QString& value);
	QString description() const;
	void setDescription(const QString& value);
	int count() const;
	Event item(int index) const;
	void add(const Event& e);
	void clear();

private:
	QSharedDataPointer<EventSortedSetPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const EventSortedSet& eventsortedset);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const EventSortedSet& eventsortedset);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventSortedSet)

#endif // __QUANTKIT_EVENTSORTEDSET_H__
