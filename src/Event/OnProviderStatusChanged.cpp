#include <QuantKit/Event/OnProviderStatusChanged.h>

#include "Provider_p.h"

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnProviderStatusChangedPrivate : public EventPrivate
{
public:
	Provider rboVjhqyRm;

public:
	explicit OnProviderStatusChangedPrivate(const Provider& provider);
	virtual ~OnProviderStatusChangedPrivate();

public:
	Provider getRboVjhqyRm() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnProviderStatusChanged;
	}

	virtual OnProviderStatusChangedPrivate* clone() Q_DECL_OVERRIDE { return new OnProviderStatusChangedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnProviderStatusChangedPrivate::OnProviderStatusChangedPrivate(const Provider& provider)
	: rboVjhqyRm(provider)
{
}

OnProviderStatusChangedPrivate::~OnProviderStatusChangedPrivate ()
{
}

Provider getRboVjhqyRm() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnProviderStatusChanged)

OnProviderStatusChanged::OnProviderStatusChanged(const Provider& provider)
	: Event(*new OnProviderStatusChangedPrivate(provider))
{
}

OnProviderStatusChanged::~OnProviderStatusChanged()
{
}

Provider rboVjhqyRm() const
{
	return d_ptr->
	setRboVjhqyRm()
}


