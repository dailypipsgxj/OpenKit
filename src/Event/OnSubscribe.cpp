#include <QuantKit/Event/OnSubscribe.h>

#include <QuantKit/Instrument.h>
#include <QuantKit/InstrumentList.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnSubscribePrivate : public EventPrivate
{
public:
	QString m_symbol;
	Instrument m_instrument;
	InstrumentList m_instrumentList;
	QDateTime dateTime_0;
	QDateTime dateTime_1;

public:
	OnSubscribePrivate();
	explicit OnSubscribePrivate(const QString& symbol);
	explicit OnSubscribePrivate(const InstrumentList& instruments);
	explicit OnSubscribePrivate(const Instrument& instrument);
	OnSubscribePrivate(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2);
	virtual ~OnSubscribePrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnSubscribe; }
	QString symbol() const { return m_symbol; }
	Instrument instrument() const { return m_instrument; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "OnSubscribe"; }
	virtual OnSubscribePrivate* clone() Q_DECL_OVERRIDE { return new OnSubscribePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnSubscribePrivate::OnSubscribePrivate()
{
}

OnSubscribePrivate::OnSubscribePrivate(const QString& symbol)
	: m_symbol(symbol)
{
}

OnSubscribePrivate::OnSubscribePrivate(const InstrumentList& instruments)
	: m_instrumentList(instruments)
	, dateTime_0(DateTime.MinValue)
	, dateTime_1(DateTime.MaxValue)
{
}

OnSubscribePrivate::OnSubscribePrivate(const Instrument& instrument)
	: m_instrument(instrument)
	, dateTime_0(DateTime.MinValue)
	, dateTime_1(DateTime.MaxValue)
{
}

OnSubscribePrivate::OnSubscribePrivate(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
	: m_instrument(instrument)
	, dateTime_0(dateTime1)
	, dateTime_1(dateTime2)
{
}

OnSubscribePrivate::~OnSubscribePrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnSubscribe)

OnSubscribe::OnSubscribe()
	: Event(*new OnSubscribePrivate)
{
}

OnSubscribe::OnSubscribe(const QString& symbol)
	: Event(*new OnSubscribePrivate(symbol))
{
}

OnSubscribe::OnSubscribe(const InstrumentList& instruments)
	: Event(*new OnSubscribePrivate(instruments))
{
}

OnSubscribe::OnSubscribe(const Instrument& instrument)
	: Event(*new OnSubscribePrivate(instrument))
{
}

OnSubscribe::OnSubscribe(const Instrument& instrument, const QDateTime& dateTime1, const QDateTime& dateTime2)
	: Event(*new OnSubscribePrivate(instrument, dateTime1, dateTime2))
{
}

OnSubscribe::~OnSubscribe()
{
}

QString OnSubscribe::symbol() const
{
	Q_D(const OnSubscribe);
	return d->symbol();
}

Instrument OnSubscribe::instrument() const
{
	Q_D(const OnSubscribe);
	return d->instrument();
}


