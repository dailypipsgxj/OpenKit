#ifndef __QUANTKIT_ONORDERREPLACEREJECTED_H__
#define __QUANTKIT_ONORDERREPLACEREJECTED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnOrderReplaceRejectedPrivate;

class Order;

class QUANTKIT_EXPORT OnOrderReplaceRejected Q_DECL_FINAL : public Event
{
public:
	explicit OnOrderReplaceRejected(const Order& order);
	~OnOrderReplaceRejected();

public:
	Order order_0() const;

private:
	QK_DECLARE_PRIVATE(OnOrderReplaceRejected)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnOrderReplaceRejected)

#endif // __QUANTKIT_ONORDERREPLACEREJECTED_H__
