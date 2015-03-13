#include <QuantKit/Event.h>
#include <QuantKit/Event_p.h>

using namespace QuantKit;

// Event Public API

Event::Event(const Event& other)
    : d_ptr(other.d_ptr)
{
}

Event& Event::operator=(const Event& other)
{
    d_ptr = other.d_ptr;
    return *this;
}

Event::Event(EventPrivate& dd)
    : d_ptr(&dd)
{
}

Event::~Event()
{
}

QDateTime Event::dateTime() const
{
    return d_ptr->dateTime();
}

void Event::setDateTime(const QDateTime &dateTime)
{
    d_ptr->setDateTime(dateTime);
}

unsigned char Event::typeId() const
{
    return d_ptr->typeId();
}

QDebug QuantKit::operator<<(QDebug dbg, const Event& e)
{
    dbg.nospace()  <<e.typeId() << " " << e.dateTime();
    return dbg.space();
}

// Define template for derived classes to reimplement
// so QSharedDataPointer clone() works correctly
template<> EventPrivate *QSharedDataPointer<EventPrivate>::clone()
{
    return d->clone();
}

// DataObject Public API

DataObject::DataObject(DataObjectPrivate &dd)
    : Event(dd)
{
}
