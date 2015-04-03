#include <QuantKit/Event/OnOrderFilled.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnOrderFilledPrivate : public EventPrivate
{
public:
	Order m_order;

public:
	explicit OnOrderFilledPrivate(const Order& order);
	virtual ~OnOrderFilledPrivate();

public:
	Order getOrder() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnOrderFilled;
	}

	virtual OnOrderFilledPrivate* clone() Q_DECL_OVERRIDE { return new OnOrderFilledPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnOrderFilledPrivate::OnOrderFilledPrivate(const Order& order)
	: m_order(order)
{
}

OnOrderFilledPrivate::~OnOrderFilledPrivate ()
{
}

Order getOrder() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnOrderFilled)

OnOrderFilled::OnOrderFilled(const Order& order)
	: Event(*new OnOrderFilledPrivate(order))
{
}

OnOrderFilled::~OnOrderFilled()
{
}

Order order() const
{
	return d_ptr->
	setOrder()
}


