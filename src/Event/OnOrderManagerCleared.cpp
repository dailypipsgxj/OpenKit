#include <QuantKit/Event/OnOrderManagerCleared.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnOrderManagerClearedPrivate : public EventPrivate
{
public:
	OnOrderManagerClearedPrivate();
	virtual ~OnOrderManagerClearedPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnOrderManagerCleared;
	}

	virtual OnOrderManagerClearedPrivate* clone() Q_DECL_OVERRIDE { return new OnOrderManagerClearedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnOrderManagerClearedPrivate::OnOrderManagerClearedPrivate()
{
}

OnOrderManagerClearedPrivate::~OnOrderManagerClearedPrivate ()
{
}


// Pubic API 

OnOrderManagerCleared::OnOrderManagerCleared()
	: Event(*new OnOrderManagerClearedPrivate)
{
}

OnOrderManagerCleared::~OnOrderManagerCleared()
{
}


