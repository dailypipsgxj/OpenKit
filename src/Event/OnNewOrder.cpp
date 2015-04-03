#include <QuantKit/Event/OnNewOrder.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnNewOrderPrivate : public EventPrivate
{
public:
	Order m_order;

public:
	explicit OnNewOrderPrivate(const Order& order);
	virtual ~OnNewOrderPrivate();

public:
	Order getOrder() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnNewOrder; }
	virtual OnNewOrderPrivate* clone() Q_DECL_OVERRIDE { return new OnNewOrderPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnNewOrderPrivate::OnNewOrderPrivate(const Order& order)
	: m_order(order)
{
}

OnNewOrderPrivate::~OnNewOrderPrivate ()
{
}

Order getOrder() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnNewOrder)

OnNewOrder::OnNewOrder(const Order& order)
	: Event(*new OnNewOrderPrivate(order))
{
}

OnNewOrder::~OnNewOrder()
{
}

Order order() const
{
	return d_ptr->
	setOrder()
}


