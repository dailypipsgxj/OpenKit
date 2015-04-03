#include <QuantKit/Event/OnFrameworkCleared.h>

#include <QuantKit/Framework.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnFrameworkClearedPrivate : public EventPrivate
{
public:
	Framework m_framework;

public:
	explicit OnFrameworkClearedPrivate(const Framework& framework);
	virtual ~OnFrameworkClearedPrivate();

public:
	Framework getFramework() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnFrameworkCleared;
	}

	virtual OnFrameworkClearedPrivate* clone() Q_DECL_OVERRIDE { return new OnFrameworkClearedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnFrameworkClearedPrivate::OnFrameworkClearedPrivate(const Framework& framework)
	: m_framework(framework)
{
}

OnFrameworkClearedPrivate::~OnFrameworkClearedPrivate ()
{
}

Framework getFramework() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnFrameworkCleared)

OnFrameworkCleared::OnFrameworkCleared(const Framework& framework)
	: Event(*new OnFrameworkClearedPrivate(framework))
{
}

OnFrameworkCleared::~OnFrameworkCleared()
{
}

Framework framework() const
{
	return d_ptr->
	setFramework()
}


