#include <QuantKit/Tick.h>


#include <QuantKit/EventType.h>
#include "Tick_p.h"

using namespace QuantKit;

TickPrivate::TickPrivate()
{
}

TickPrivate::TickPrivate(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
	: DataObjectPrivate (dateTime)
	, m_providerId(providerId)
	, m_instrumentId(instrumentId)
	, m_price(price)
	, m_size(size)
{
}

TickPrivate::TickPrivate(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
	: DataObjectPrivate (dateTime)
	, m_exchangeDateTime(exchangeDateTime)
	, m_providerId(providerId)
	, m_instrumentId(instrumentId)
	, m_price(price)
	, m_size(size)
{
}

TickPrivate::~TickPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Tick)

Tick::Tick()
	: DataObject(*new TickPrivate)
{
}

Tick::Tick(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
	: DataObject(*new TickPrivate(dateTime, providerId, instrumentId, price, size))
{
}

Tick::Tick(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
	: DataObject(*new TickPrivate(dateTime, exchangeDateTime, providerId, instrumentId, price, size))
{
}

Tick::~Tick()
{
}

Tick::Tick (TickPrivate &dd)
	: DataObject(dd)
{
}

unsigned char Tick::providerId() const
{
	Q_D(const Tick);
	return d->providerId();
}

void Tick::setProviderId(unsigned char value)
{
	Q_D(Tick);
	d->setProviderId(value);
}

int Tick::instrumentId() const
{
	Q_D(const Tick);
	return d->instrumentId();
}

void Tick::setInstrumentId(int value)
{
	Q_D(Tick);
	d->setInstrumentId(value);
}

double Tick::price() const
{
	Q_D(const Tick);
	return d->price();
}

void Tick::setPrice(double value)
{
	Q_D(Tick);
	d->setPrice(value);
}

int Tick::size() const
{
	Q_D(const Tick);
	return d->size();
}

void Tick::setSize(int value)
{
	Q_D(Tick);
	d->setSize(value);
}

QDateTime Tick::exchangeDateTime() const
{
	Q_D(const Tick);
	return d->exchangeDateTime();
}

void Tick::setExchangeDateTime(const QDateTime& value)
{
	Q_D(Tick);
	d->setExchangeDateTime(value);
}


