#include <QuantKit/ExecutionMessage.h>

#include <QuantKit/Event/Order.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/ObjectTable.h>

#include <QuantKit/EventType.h>
#include "ExecutionMessage_p.h"

using namespace QuantKit;

ExecutionMessagePrivate::ExecutionMessagePrivate()
{
}

ExecutionMessagePrivate::~ExecutionMessagePrivate ()
{
}

void ExecutionMessagePrivate::setOrder(const Order& value)
{
	m_order = value;
	m_orderId = m_order.id();
}

void ExecutionMessagePrivate::setInstrument(const Instrument& value)
{
	m_instrument = value;
	m_instrumentId = m_instrument.id();
}

QVariant ExecutionMessagePrivate::item(int index) const
{
	if (m_item == null)
	{
		return null;
	}
	return m_item[index];
}

void ExecutionMessagePrivate::setItem(int index, const QVariant& value)
{
	if (m_item == null)
	{
		m_item = new ObjectTable();
	}
	m_item[index] = value;
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(ExecutionMessage)

ExecutionMessage::ExecutionMessage()
	: DataObject(*new ExecutionMessagePrivate)
{
}

ExecutionMessage::~ExecutionMessage()
{
}

ExecutionMessage::ExecutionMessage (ExecutionMessagePrivate &dd)
	: DataObject(dd)
{
}

int ExecutionMessage::id() const
{
	Q_D(const ExecutionMessage);
	return d->id();
}

Order ExecutionMessage::order() const
{
	Q_D(const ExecutionMessage);
	return d->order();
}

void ExecutionMessage::setOrder(const Order& value)
{
	Q_D(ExecutionMessage);
	d->setOrder(value);
}

int ExecutionMessage::orderId() const
{
	Q_D(const ExecutionMessage);
	return d->orderId();
}

void ExecutionMessage::setOrderId(int value)
{
	Q_D(ExecutionMessage);
	d->setOrderId(value);
}

Instrument ExecutionMessage::instrument() const
{
	Q_D(const ExecutionMessage);
	return d->instrument();
}

void ExecutionMessage::setInstrument(const QSharedPointer<Instrument> &value)
{
	Q_D(ExecutionMessage);
	d->setInstrument(value);
}

int ExecutionMessage::instrumentId() const
{
	Q_D(const ExecutionMessage);
	return d->instrumentId();
}

QVariant ExecutionMessage::item(int index) const
{
	Q_D(const ExecutionMessage);
	return d->item(index);
}

void ExecutionMessage::setItem(int index, const QVariant& value)
{
	Q_D(ExecutionMessage);
	d->setItem(index, value);
}


