#ifndef __QUANTKIT_ONORDERREJECTED_H__
#define __QUANTKIT_ONORDERREJECTED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnOrderRejectedPrivate;

class Order;

class QUANTKIT_EXPORT OnOrderRejected Q_DECL_FINAL : public Event
{
public:
	explicit OnOrderRejected(const Order& order);
	~OnOrderRejected();

public:
	Order order_0() const;

private:
	QK_DECLARE_PRIVATE(OnOrderRejected)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnOrderRejected)

#endif // __QUANTKIT_ONORDERREJECTED_H__
