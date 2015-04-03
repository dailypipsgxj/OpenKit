#include <QuantKit/Event/OnOrderReplaced.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnOrderReplacedPrivate : public EventPrivate
{
public:
	Order m_order;

public:
	explicit OnOrderReplacedPrivate(const Order& order);
	virtual ~OnOrderReplacedPrivate();

public:
	Order getOrder() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnOrderReplaced;
	}

	virtual OnOrderReplacedPrivate* clone() Q_DECL_OVERRIDE { return new OnOrderReplacedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnOrderReplacedPrivate::OnOrderReplacedPrivate(const Order& order)
	: m_order(order)
{
}

OnOrderReplacedPrivate::~OnOrderReplacedPrivate ()
{
}

Order getOrder() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnOrderReplaced)

OnOrderReplaced::OnOrderReplaced(const Order& order)
	: Event(*new OnOrderReplacedPrivate(order))
{
}

OnOrderReplaced::~OnOrderReplaced()
{
}

Order order() const
{
	return d_ptr->
	setOrder()
}


