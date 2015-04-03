#ifndef __QUANTKIT_ONORDERCANCELLED_H__
#define __QUANTKIT_ONORDERCANCELLED_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnOrderCancelledPrivate;

class Order;

class QUANTKIT_EXPORT OnOrderCancelled Q_DECL_FINAL : public Event
{
public:
	explicit OnOrderCancelled(const Order& order);
	~OnOrderCancelled();

public:
	Order order() const;

private:
	QK_DECLARE_PRIVATE(OnOrderCancelled)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnOrderCancelled)

#endif // __QUANTKIT_ONORDERCANCELLED_H__
