#include <QuantKit/Event/OnProviderAdded.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnProviderAddedPrivate : public EventPrivate
{
public:
	IProvider m_iprovider;

public:
	explicit OnProviderAddedPrivate(const IProvider& provider);
	virtual ~OnProviderAddedPrivate();

public:
	IProvider getIprovider() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnProviderAdded;
	}

	virtual OnProviderAddedPrivate* clone() Q_DECL_OVERRIDE { return new OnProviderAddedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnProviderAddedPrivate::OnProviderAddedPrivate(const IProvider& provider)
	: m_iprovider(provider)
{
}

OnProviderAddedPrivate::~OnProviderAddedPrivate ()
{
}

IProvider getIprovider() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnProviderAdded)

OnProviderAdded::OnProviderAdded(const IProvider& provider)
	: Event(*new OnProviderAddedPrivate(provider))
{
}

OnProviderAdded::~OnProviderAdded()
{
}

IProvider iprovider() const
{
	return d_ptr->
	setIprovider()
}


