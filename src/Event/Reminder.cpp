#include <QuantKit/Event/Reminder.h>

#include <QuantKit/Clock.h>
#include <QuantKit/ReminderCallback.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class ReminderPrivate : public DataObjectPrivate
{
public:
	Clock m_clock;
	ReminderCallback m_callback;
	QVariant m_data;

public:
	ReminderPrivate(const ReminderCallback& callback, const QDateTime& dateTime, const QVariant& data);
	virtual ~ReminderPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Reminder; }
	Clock clock() const { return m_clock; }
	ReminderCallback callback() const { return m_callback; }
	QVariant data() const { return m_data; }
	void setData(const QVariant& value) { m_data = value; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "Reminder"; }
	virtual ReminderPrivate* clone() Q_DECL_OVERRIDE { return new ReminderPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ReminderPrivate::ReminderPrivate(const ReminderCallback& callback, const QDateTime& dateTime, QVariant data)
	: DataObjectPrivate (dateTime)
	, m_callback(callback)
	, m_data(data)
{
}

ReminderPrivate::~ReminderPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Reminder)

Reminder::Reminder(const ReminderCallback& callback, const QDateTime& dateTime, QVariant data)
	: DataObject(*new ReminderPrivate(callback, dateTime, data))
{
}

Reminder::~Reminder()
{
}

Clock Reminder::clock() const
{
	Q_D(const Reminder);
	return d->clock();
}

ReminderCallback Reminder::callback() const
{
	Q_D(const Reminder);
	return d->callback();
}

QVariant Reminder::data() const
{
	Q_D(const Reminder);
	return d->data();
}

void Reminder::setData(const QVariant& value)
{
	Q_D(Reminder);
	d->setData(value);
}


