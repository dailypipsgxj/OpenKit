#include <QuantKit/Event/OnOrderRejected.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnOrderRejectedPrivate : public EventPrivate
{
public:
	Order order_0;

public:
	explicit OnOrderRejectedPrivate(const Order& order);
	virtual ~OnOrderRejectedPrivate();

public:
	Order getOrder_0() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnOrderRejected;
	}

	virtual OnOrderRejectedPrivate* clone() Q_DECL_OVERRIDE { return new OnOrderRejectedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnOrderRejectedPrivate::OnOrderRejectedPrivate(const Order& order)
	: order_0(order)
{
}

OnOrderRejectedPrivate::~OnOrderRejectedPrivate ()
{
}

Order getOrder_0() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnOrderRejected)

OnOrderRejected::OnOrderRejected(const Order& order)
	: Event(*new OnOrderRejectedPrivate(order))
{
}

OnOrderRejected::~OnOrderRejected()
{
}

Order order_0() const
{
	return d_ptr->
	setOrder_0()
}


