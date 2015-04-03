#include <QuantKit/Event/OnUnsubscribe.h>

#include <QuantKit/Instrument.h>
#include <QuantKit/InstrumentList.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnUnsubscribePrivate : public EventPrivate
{
public:
	QString m_symbol;
	InstrumentList m_instrumentList;
	Instrument m_instrument;

public:
	OnUnsubscribePrivate();
	explicit OnUnsubscribePrivate(const QString& symbol);
	explicit OnUnsubscribePrivate(const InstrumentList& instruments);
	explicit OnUnsubscribePrivate(const Instrument& instrument);
	virtual ~OnUnsubscribePrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnUnsubscribe;
	}

	QString symbol() const { return m_symbol; }
	Instrument instrument() const { return m_instrument; }
	virtual OnUnsubscribePrivate* clone() Q_DECL_OVERRIDE { return new OnUnsubscribePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnUnsubscribePrivate::OnUnsubscribePrivate()
{
}

OnUnsubscribePrivate::OnUnsubscribePrivate(const QString& symbol)
	: m_symbol(symbol)
{
}

OnUnsubscribePrivate::OnUnsubscribePrivate(const InstrumentList& instruments)
	: m_instrumentList(instruments)
{
}

OnUnsubscribePrivate::OnUnsubscribePrivate(const Instrument& instrument)
	: m_instrument(instrument)
{
}

OnUnsubscribePrivate::~OnUnsubscribePrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnUnsubscribe)

OnUnsubscribe::OnUnsubscribe()
	: Event(*new OnUnsubscribePrivate)
{
}

OnUnsubscribe::OnUnsubscribe(const QString& symbol)
	: Event(*new OnUnsubscribePrivate(symbol))
{
}

OnUnsubscribe::OnUnsubscribe(const InstrumentList& instruments)
	: Event(*new OnUnsubscribePrivate(instruments))
{
}

OnUnsubscribe::OnUnsubscribe(const Instrument& instrument)
	: Event(*new OnUnsubscribePrivate(instrument))
{
}

OnUnsubscribe::~OnUnsubscribe()
{
}

QString OnUnsubscribe::symbol() const
{
	Q_D(const OnUnsubscribe);
	return d->symbol();
}

Instrument OnUnsubscribe::instrument() const
{
	Q_D(const OnUnsubscribe);
	return d->instrument();
}


