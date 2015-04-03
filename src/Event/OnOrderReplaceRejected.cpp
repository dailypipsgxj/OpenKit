#include <QuantKit/Event/OnOrderReplaceRejected.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnOrderReplaceRejectedPrivate : public EventPrivate
{
public:
	Order order_0;

public:
	explicit OnOrderReplaceRejectedPrivate(const Order& order);
	virtual ~OnOrderReplaceRejectedPrivate();

public:
	Order getOrder_0() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnOrderReplaceRejected;
	}

	virtual OnOrderReplaceRejectedPrivate* clone() Q_DECL_OVERRIDE { return new OnOrderReplaceRejectedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnOrderReplaceRejectedPrivate::OnOrderReplaceRejectedPrivate(const Order& order)
	: order_0(order)
{
}

OnOrderReplaceRejectedPrivate::~OnOrderReplaceRejectedPrivate ()
{
}

Order getOrder_0() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnOrderReplaceRejected)

OnOrderReplaceRejected::OnOrderReplaceRejected(const Order& order)
	: Event(*new OnOrderReplaceRejectedPrivate(order))
{
}

OnOrderReplaceRejected::~OnOrderReplaceRejected()
{
}

Order order_0() const
{
	return d_ptr->
	setOrder_0()
}


