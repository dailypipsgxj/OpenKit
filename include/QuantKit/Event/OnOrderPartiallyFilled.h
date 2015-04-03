#ifndef __QUANTKIT_ONORDERPARTIALLYFILLED_H__
#define __QUANTKIT_ONORDERPARTIALLYFILLED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnOrderPartiallyFilledPrivate;

class Order;

class QUANTKIT_EXPORT OnOrderPartiallyFilled Q_DECL_FINAL : public Event
{
public:
	explicit OnOrderPartiallyFilled(const Order& order);
	~OnOrderPartiallyFilled();

public:
	Order order() const;

private:
	QK_DECLARE_PRIVATE(OnOrderPartiallyFilled)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnOrderPartiallyFilled)

#endif // __QUANTKIT_ONORDERPARTIALLYFILLED_H__
