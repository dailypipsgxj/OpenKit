#include <QuantKit/Event/OnPendingNewOrder.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnPendingNewOrderPrivate : public EventPrivate
{
public:
	Order m_order;

public:
	explicit OnPendingNewOrderPrivate(const Order& order);
	virtual ~OnPendingNewOrderPrivate();

public:
	Order getOrder() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnPendingNewOrder;
	}

	virtual OnPendingNewOrderPrivate* clone() Q_DECL_OVERRIDE { return new OnPendingNewOrderPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnPendingNewOrderPrivate::OnPendingNewOrderPrivate(const Order& order)
	: m_order(order)
{
}

OnPendingNewOrderPrivate::~OnPendingNewOrderPrivate ()
{
}

Order getOrder() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnPendingNewOrder)

OnPendingNewOrder::OnPendingNewOrder(const Order& order)
	: Event(*new OnPendingNewOrderPrivate(order))
{
}

OnPendingNewOrder::~OnPendingNewOrder()
{
}

Order order() const
{
	return d_ptr->
	setOrder()
}


