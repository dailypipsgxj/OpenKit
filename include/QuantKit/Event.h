#ifndef __QUANTKIT_EVENT_H__
#define __QUANTKIT_EVENT_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class EventPrivate;

class QUANTKIT_EXPORT Event
{
public:
	Event();
	explicit Event(const QDateTime& dateTime);
	~Event();

	Event(const Event &other);
	Event& operator=(const Event &other);
#ifdef Q_COMPILER_RVALUE_REFS
    Event &operator=(Event &&other) { swap(other); return *this; }
#endif

    void swap(Event& other) { d.swap(other.d); }

	bool operator==(const Event &other) const;
	inline bool operator!=(const Event &other) const { return !(this->operator==(other));  }
public:
	QDateTime dateTime() const;
	void setDateTime(const QDateTime& value);
	unsigned char typeId() const;
	QString toString() const;

protected:
	Event(EventPrivate& dd);
    QSharedDataPointer<EventPrivate> d;

private:
	friend QDebug operator<<(QDebug dbg, const Event& event);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Event& event);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Event)

#endif // __QUANTKIT_EVENT_H__
