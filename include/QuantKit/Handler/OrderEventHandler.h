#ifndef __QUANTKIT_ORDEREVENTHANDLER_H__
#define __QUANTKIT_ORDEREVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class OrderEventHandlerPrivate;

class Order;

class QUANTKIT_EXPORT OrderEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	OrderEventHandler(const QVariant& object, IntPtr method);
	~OrderEventHandler();

	OrderEventHandler(const OrderEventHandler &other);
	OrderEventHandler& operator=(const OrderEventHandler &other);
	bool operator==(const OrderEventHandler &other) const;
	inline bool operator!=(const OrderEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const Order& Order, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const Order& Order);

private:
	QSharedDataPointer<OrderEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const OrderEventHandler& ordereventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const OrderEventHandler& ordereventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OrderEventHandler)

#endif // __QUANTKIT_ORDEREVENTHANDLER_H__
