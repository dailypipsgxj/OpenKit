#ifndef __QUANTKIT_ONORDERSTATUSCHANGED_H__
#define __QUANTKIT_ONORDERSTATUSCHANGED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnOrderStatusChangedPrivate;

class Order;

class QUANTKIT_EXPORT OnOrderStatusChanged Q_DECL_FINAL : public Event
{
public:
	explicit OnOrderStatusChanged(const Order& order);
	~OnOrderStatusChanged();

public:
	Order order() const;

private:
	QK_DECLARE_PRIVATE(OnOrderStatusChanged)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnOrderStatusChanged)

#endif // __QUANTKIT_ONORDERSTATUSCHANGED_H__
