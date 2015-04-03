#ifndef __QUANTKIT_ONSENDORDER_H__
#define __QUANTKIT_ONSENDORDER_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnSendOrderPrivate;

class Order;

class QUANTKIT_EXPORT OnSendOrder Q_DECL_FINAL : public Event
{
public:
	explicit OnSendOrder(const Order& order);
	~OnSendOrder();

public:
	Order order() const;

private:
	QK_DECLARE_PRIVATE(OnSendOrder)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnSendOrder)

#endif // __QUANTKIT_ONSENDORDER_H__
