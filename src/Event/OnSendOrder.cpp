#include <QuantKit/Event/OnSendOrder.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnSendOrderPrivate : public EventPrivate
{
public:
	Order m_order;

public:
	explicit OnSendOrderPrivate(const Order& order);
	virtual ~OnSendOrderPrivate();

public:
	Order getOrder() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnSendOrder; }
	virtual OnSendOrderPrivate* clone() Q_DECL_OVERRIDE { return new OnSendOrderPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnSendOrderPrivate::OnSendOrderPrivate(const Order& order)
	: m_order(order)
{
}

OnSendOrderPrivate::~OnSendOrderPrivate ()
{
}

Order getOrder() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnSendOrder)

OnSendOrder::OnSendOrder(const Order& order)
	: Event(*new OnSendOrderPrivate(order))
{
}

OnSendOrder::~OnSendOrder()
{
}

Order order() const
{
	return d_ptr->
	setOrder()
}


