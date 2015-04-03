#ifndef __QUANTKIT_ONNEWORDER_H__
#define __QUANTKIT_ONNEWORDER_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnNewOrderPrivate;

class Order;

class QUANTKIT_EXPORT OnNewOrder Q_DECL_FINAL : public Event
{
public:
	explicit OnNewOrder(const Order& order);
	~OnNewOrder();

public:
	Order order() const;

private:
	QK_DECLARE_PRIVATE(OnNewOrder)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnNewOrder)

#endif // __QUANTKIT_ONNEWORDER_H__
