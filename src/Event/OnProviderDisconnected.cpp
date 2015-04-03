#include <QuantKit/Event/OnProviderDisconnected.h>

#include "Provider_p.h"

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnProviderDisconnectedPrivate : public EventPrivate
{
public:
	unsigned char m_providerId;
	Provider m_provider;

public:
	OnProviderDisconnectedPrivate(const QDateTime& dateTime, unsigned char providerId);
	OnProviderDisconnectedPrivate(const QDateTime& dateTime, const Provider& provider);
	virtual ~OnProviderDisconnectedPrivate();

public:
	unsigned char providerId() const { return m_providerId; }
	Provider provider() const { return m_provider; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnProviderDisconnected;
	}

	virtual OnProviderDisconnectedPrivate* clone() Q_DECL_OVERRIDE { return new OnProviderDisconnectedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnProviderDisconnectedPrivate::OnProviderDisconnectedPrivate(const QDateTime& dateTime, unsigned char providerId)
	: EventPrivate (dateTime)
	, m_providerId(providerId)
{
}

OnProviderDisconnectedPrivate::OnProviderDisconnectedPrivate(const QDateTime& dateTime, const Provider& provider)
	: EventPrivate (dateTime)
	, m_provider(provider)
{
}

OnProviderDisconnectedPrivate::~OnProviderDisconnectedPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnProviderDisconnected)

OnProviderDisconnected::OnProviderDisconnected(const QDateTime& dateTime, unsigned char providerId)
	: Event(*new OnProviderDisconnectedPrivate(dateTime, providerId))
{
}

OnProviderDisconnected::OnProviderDisconnected(const QDateTime& dateTime, const Provider& provider)
	: Event(*new OnProviderDisconnectedPrivate(dateTime, provider))
{
}

OnProviderDisconnected::~OnProviderDisconnected()
{
}

unsigned char OnProviderDisconnected::providerId() const
{
	Q_D(const OnProviderDisconnected);
	return d->providerId();
}

Provider OnProviderDisconnected::provider() const
{
	Q_D(const OnProviderDisconnected);
	return d->provider();
}


