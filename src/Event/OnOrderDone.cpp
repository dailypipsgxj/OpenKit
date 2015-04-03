#include <QuantKit/Event/OnOrderDone.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnOrderDonePrivate : public EventPrivate
{
public:
	Order m_order;

public:
	explicit OnOrderDonePrivate(const Order& order);
	virtual ~OnOrderDonePrivate();

public:
	Order getOrder() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnOrderDone; }
	virtual OnOrderDonePrivate* clone() Q_DECL_OVERRIDE { return new OnOrderDonePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnOrderDonePrivate::OnOrderDonePrivate(const Order& order)
	: m_order(order)
{
}

OnOrderDonePrivate::~OnOrderDonePrivate ()
{
}

Order getOrder() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnOrderDone)

OnOrderDone::OnOrderDone(const Order& order)
	: Event(*new OnOrderDonePrivate(order))
{
}

OnOrderDone::~OnOrderDone()
{
}

Order order() const
{
	return d_ptr->
	setOrder()
}


