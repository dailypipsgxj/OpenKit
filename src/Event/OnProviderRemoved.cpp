#include <QuantKit/Event/OnProviderRemoved.h>

#include "Provider_p.h"

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnProviderRemovedPrivate : public EventPrivate
{
public:
	Provider m_provider;

public:
	explicit OnProviderRemovedPrivate(const Provider& provider);
	virtual ~OnProviderRemovedPrivate();

public:
	Provider getProvider() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnProviderRemoved;
	}

	virtual OnProviderRemovedPrivate* clone() Q_DECL_OVERRIDE { return new OnProviderRemovedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnProviderRemovedPrivate::OnProviderRemovedPrivate(const Provider& provider)
	: m_provider(provider)
{
}

OnProviderRemovedPrivate::~OnProviderRemovedPrivate ()
{
}

Provider getProvider() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnProviderRemoved)

OnProviderRemoved::OnProviderRemoved(const Provider& provider)
	: Event(*new OnProviderRemovedPrivate(provider))
{
}

OnProviderRemoved::~OnProviderRemoved()
{
}

Provider provider() const
{
	return d_ptr->
	setProvider()
}


