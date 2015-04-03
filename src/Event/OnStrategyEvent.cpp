#include <QuantKit/Event/OnStrategyEvent.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnStrategyEventPrivate : public EventPrivate
{
public:
	QVariant object_0;

public:
	explicit OnStrategyEventPrivate(const QVariant& data);
	virtual ~OnStrategyEventPrivate();

public:
	QVariant getObject_0() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnStrategyEvent;
	}

	virtual OnStrategyEventPrivate* clone() Q_DECL_OVERRIDE { return new OnStrategyEventPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnStrategyEventPrivate::OnStrategyEventPrivate(const QVariant& data)
	: object_0(data)
{
}

OnStrategyEventPrivate::~OnStrategyEventPrivate ()
{
}

QVariant getObject_0() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnStrategyEvent)

OnStrategyEvent::OnStrategyEvent(const QVariant& data)
	: Event(*new OnStrategyEventPrivate(data))
{
}

OnStrategyEvent::~OnStrategyEvent()
{
}

QVariant object_0() const
{
	return d_ptr->
	setObject_0()
}


