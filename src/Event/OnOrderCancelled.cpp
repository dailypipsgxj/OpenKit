#include <QuantKit/Event/OnOrderCancelled.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnOrderCancelledPrivate : public EventPrivate
{
public:
	Order m_order;

public:
	explicit OnOrderCancelledPrivate(const Order& order);
	virtual ~OnOrderCancelledPrivate();

public:
	Order getOrder() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnOrderCancelled;
	}

	virtual OnOrderCancelledPrivate* clone() Q_DECL_OVERRIDE { return new OnOrderCancelledPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnOrderCancelledPrivate::OnOrderCancelledPrivate(const Order& order)
	: m_order(order)
{
}

OnOrderCancelledPrivate::~OnOrderCancelledPrivate ()
{
}

Order getOrder() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnOrderCancelled)

OnOrderCancelled::OnOrderCancelled(const Order& order)
	: Event(*new OnOrderCancelledPrivate(order))
{
}

OnOrderCancelled::~OnOrderCancelled()
{
}

Order order() const
{
	return d_ptr->
	setOrder()
}


