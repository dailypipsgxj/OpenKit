#include <QuantKit/Event/OnOrderPartiallyFilled.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnOrderPartiallyFilledPrivate : public EventPrivate
{
public:
	Order m_order;

public:
	explicit OnOrderPartiallyFilledPrivate(const Order& order);
	virtual ~OnOrderPartiallyFilledPrivate();

public:
	Order getOrder() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnOrderPartiallyFilled;
	}

	virtual OnOrderPartiallyFilledPrivate* clone() Q_DECL_OVERRIDE { return new OnOrderPartiallyFilledPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnOrderPartiallyFilledPrivate::OnOrderPartiallyFilledPrivate(const Order& order)
	: m_order(order)
{
}

OnOrderPartiallyFilledPrivate::~OnOrderPartiallyFilledPrivate ()
{
}

Order getOrder() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnOrderPartiallyFilled)

OnOrderPartiallyFilled::OnOrderPartiallyFilled(const Order& order)
	: Event(*new OnOrderPartiallyFilledPrivate(order))
{
}

OnOrderPartiallyFilled::~OnOrderPartiallyFilled()
{
}

Order order() const
{
	return d_ptr->
	setOrder()
}


