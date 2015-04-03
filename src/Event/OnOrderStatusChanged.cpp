#include <QuantKit/Event/OnOrderStatusChanged.h>

#include <QuantKit/Event/Order.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnOrderStatusChangedPrivate : public EventPrivate
{
public:
	Order m_order;

public:
	explicit OnOrderStatusChangedPrivate(const Order& order);
	virtual ~OnOrderStatusChangedPrivate();

public:
	Order getOrder() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnOrderStatusChanged;
	}

	virtual OnOrderStatusChangedPrivate* clone() Q_DECL_OVERRIDE { return new OnOrderStatusChangedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnOrderStatusChangedPrivate::OnOrderStatusChangedPrivate(const Order& order)
	: m_order(order)
{
}

OnOrderStatusChangedPrivate::~OnOrderStatusChangedPrivate ()
{
}

Order getOrder() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnOrderStatusChanged)

OnOrderStatusChanged::OnOrderStatusChanged(const Order& order)
	: Event(*new OnOrderStatusChangedPrivate(order))
{
}

OnOrderStatusChanged::~OnOrderStatusChanged()
{
}

Order order() const
{
	return d_ptr->
	setOrder()
}


