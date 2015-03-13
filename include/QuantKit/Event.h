#ifndef __QUANTKIT_EVENT_H__
#define __QUANTKIT_EVENT_H__

#include <QDateTime>
#include <QDebug>
#include <QuantKit/EventType.h>

namespace QuantKit {

class EventPrivate;

class QUANTKIT_EXPORT Event
{
public:
    Event(const Event& other);
    Event& operator=(const Event& other);
    virtual ~Event();

    void swap(Event &other) { d_ptr.swap(other.d_ptr); }

    bool operator==(const Event& other) const { return d_ptr == other.d_ptr; }
    inline bool operator!=(const Event& other) const { return !(this->operator==(other));}

public:
    QDateTime dateTime() const;
    void setDateTime(const QDateTime& dateTime);

    unsigned char typeId() const;
    //QString toString() const;

protected:
    explicit Event(EventPrivate& dd);
    QSharedDataPointer<EventPrivate> d_ptr;
    friend QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Event& e);

private:
    QK_DECLARE_PRIVATE(Event)
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Event& e);

class DataObjectPrivate;

class QUANTKIT_EXPORT DataObject : public Event
{
protected:
    DataObject(DataObjectPrivate& dd);
};


} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Event)
Q_DECLARE_SHARED(QuantKit::DataObject)

#endif // __QUANTKIT_EVENT_H__
