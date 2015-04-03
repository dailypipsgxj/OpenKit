#ifndef __QUANTKIT_ONORDERDONE_H__
#define __QUANTKIT_ONORDERDONE_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnOrderDonePrivate;

class Order;

class QUANTKIT_EXPORT OnOrderDone Q_DECL_FINAL : public Event
{
public:
	explicit OnOrderDone(const Order& order);
	~OnOrderDone();

public:
	Order order() const;

private:
	QK_DECLARE_PRIVATE(OnOrderDone)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnOrderDone)

#endif // __QUANTKIT_ONORDERDONE_H__
