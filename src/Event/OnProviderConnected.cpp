#include <QuantKit/Event/OnProviderConnected.h>

#include "Provider_p.h"

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnProviderConnectedPrivate : public EventPrivate
{
public:
	unsigned char m_providerId;
	Provider m_provider;

public:
	OnProviderConnectedPrivate(const QDateTime& dateTime, unsigned char providerId);
	OnProviderConnectedPrivate(const QDateTime& dateTime, const Provider& provider);
	virtual ~OnProviderConnectedPrivate();

public:
	unsigned char providerId() const { return m_providerId; }
	Provider provider() const { return m_provider; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnProviderConnected;
	}

	virtual OnProviderConnectedPrivate* clone() Q_DECL_OVERRIDE { return new OnProviderConnectedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnProviderConnectedPrivate::OnProviderConnectedPrivate(const QDateTime& dateTime, unsigned char providerId)
	: EventPrivate (dateTime)
	, m_providerId(providerId)
{
}

OnProviderConnectedPrivate::OnProviderConnectedPrivate(const QDateTime& dateTime, const Provider& provider)
	: EventPrivate (dateTime)
	, m_provider(provider)
{
}

OnProviderConnectedPrivate::~OnProviderConnectedPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnProviderConnected)

OnProviderConnected::OnProviderConnected(const QDateTime& dateTime, unsigned char providerId)
	: Event(*new OnProviderConnectedPrivate(dateTime, providerId))
{
}

OnProviderConnected::OnProviderConnected(const QDateTime& dateTime, const Provider& provider)
	: Event(*new OnProviderConnectedPrivate(dateTime, provider))
{
}

OnProviderConnected::~OnProviderConnected()
{
}

unsigned char OnProviderConnected::providerId() const
{
	Q_D(const OnProviderConnected);
	return d->providerId();
}

Provider OnProviderConnected::provider() const
{
	Q_D(const OnProviderConnected);
	return d->provider();
}


