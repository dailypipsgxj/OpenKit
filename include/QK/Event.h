#ifndef __QUANTKIT_EVENT_H__
#define __QUANTKIT_EVENT_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QuantKit/EventType.h>

namespace QuantKit {

class QUANTKIT_EXPORT Event
{
public:
    Event() {}
    Event(const QDateTime& dateTime) : m_dateTime(dateTime) {}
    virtual ~Event() {}

    Event(const Event& other) : m_dateTime(other.m_dateTime) {}
    Event& operator=(const Event& other) { m_dateTime = other.m_dateTime; return *this; }

public:
    virtual unsigned char typeId() const { return EventType::Event; }

    QDateTime dateTime() const { return m_dateTime; }
    void setDateTime(const QDateTime& dateTime) { m_dateTime = dateTime; }

protected:
    QDateTime m_dateTime;
};

class QUANTKIT_EXPORT DataObject : public Event
{
    virtual unsigned char typeId() const override { return EventType::DataObject; }
};

} // namespace QuantKit

#endif // __QUANTKIT_EVENT_H__
