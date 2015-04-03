#ifndef __QUANTKIT_ONORDERFILLED_H__
#define __QUANTKIT_ONORDERFILLED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnOrderFilledPrivate;

class Order;

class QUANTKIT_EXPORT OnOrderFilled Q_DECL_FINAL : public Event
{
public:
	explicit OnOrderFilled(const Order& order);
	~OnOrderFilled();

public:
	Order order() const;

private:
	QK_DECLARE_PRIVATE(OnOrderFilled)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnOrderFilled)

#endif // __QUANTKIT_ONORDERFILLED_H__
