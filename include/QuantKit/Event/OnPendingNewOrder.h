#ifndef __QUANTKIT_ONPENDINGNEWORDER_H__
#define __QUANTKIT_ONPENDINGNEWORDER_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnPendingNewOrderPrivate;

class Order;

class QUANTKIT_EXPORT OnPendingNewOrder Q_DECL_FINAL : public Event
{
public:
	explicit OnPendingNewOrder(const Order& order);
	~OnPendingNewOrder();

public:
	Order order() const;

private:
	QK_DECLARE_PRIVATE(OnPendingNewOrder)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnPendingNewOrder)

#endif // __QUANTKIT_ONPENDINGNEWORDER_H__
