#ifndef __QUANTKIT_ONORDERREPLACED_H__
#define __QUANTKIT_ONORDERREPLACED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnOrderReplacedPrivate;

class Order;

class QUANTKIT_EXPORT OnOrderReplaced Q_DECL_FINAL : public Event
{
public:
	explicit OnOrderReplaced(const Order& order);
	~OnOrderReplaced();

public:
	Order order() const;

private:
	QK_DECLARE_PRIVATE(OnOrderReplaced)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnOrderReplaced)

#endif // __QUANTKIT_ONORDERREPLACED_H__
