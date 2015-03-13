#ifndef EVENT_P_H
#define EVENT_P_H

#include <QuantKit/Event.h>
#include <QSharedDataPointer>
#include <QSharedData>

namespace QuantKit {

class QUANTKIT_EXPORT EventPrivate : public QSharedData
{

public:
    EventPrivate() : QSharedData(), m_entryDate(QDateTime::currentDateTime()) {}
    explicit EventPrivate(const QDateTime& dateTime) : QSharedData(), m_entryDate(dateTime) {}
    EventPrivate(const EventPrivate& other) : QSharedData(other), m_entryDate(other.m_entryDate) {}
    virtual ~EventPrivate() {}

public:
    QDateTime dateTime() const { return m_entryDate; }
    void setDateTime(const QDateTime& dateTime) { m_entryDate = dateTime; }

public:
    virtual unsigned char typeId() const = 0;
    virtual EventPrivate* clone() = 0;

protected:
    QDateTime m_entryDate;
};

class QUANTKIT_EXPORT DataObjectPrivate : public EventPrivate
{
public:
    DataObjectPrivate(const QDateTime& dateTime) : EventPrivate(dateTime) {}
    DataObjectPrivate(const DataObjectPrivate& other) : EventPrivate(other) {}
    virtual ~DataObjectPrivate() {}
};

} // namespace QuantKit

template<> QuantKit::EventPrivate *QSharedDataPointer<QuantKit::EventPrivate>::clone();

#endif // EVENT_P_H

