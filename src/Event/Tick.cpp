#include <QuantKit/Event/Tick.h>
#include <QuantKit/Event/Tick_p.h>

using namespace QuantKit;

QK_IMPLEMENTATION_PRIVATE(Tick)

Tick::Tick(TickPrivate &dd)
    : DataObject(dd)
{
}

QDateTime Tick::exchangeDateTime() const
{
    Q_D(const Tick);
    return d->exchangeDateTime();
}

void Tick::setExchangeDateTime(const QDateTime& dateTime)
{
    Q_D(Tick);
    d->setExchangeDateTime(dateTime);
}

unsigned char Tick::providerId() const
{
    Q_D(const Tick);
    return d->providerId();
}

void Tick::setProviderId(unsigned char providerId)
{
    Q_D(Tick);
    d->setProviderId(providerId);
}

unsigned char Tick::instrumentId() const
{
    Q_D(const Tick);
    return d->instrumentId();
}

void Tick::setInstrumentId(unsigned char instrumentId)
{
    Q_D(Tick);
    d->setInstrumentId(instrumentId);
}

double Tick::price() const
{
    Q_D(const Tick);
    return d->price();
}
void Tick::setPrice(double price)
{
    Q_D(Tick);
    d->setPrice(price);
}

int Tick::size() const
{
    Q_D(const Tick);
    return d->size();
}

void Tick::setSize(int size)
{
    Q_D(Tick);
    d->setSize(size);
}
