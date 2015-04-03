#ifndef __QUANTKIT_ORDERMANAGERCLEAREDEVENTHANDLER_H__
#define __QUANTKIT_ORDERMANAGERCLEAREDEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class OrderManagerClearedEventHandlerPrivate;

class OnOrderManagerCleared;

class QUANTKIT_EXPORT OrderManagerClearedEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	OrderManagerClearedEventHandler(const QVariant& object, IntPtr method);
	~OrderManagerClearedEventHandler();

	OrderManagerClearedEventHandler(const OrderManagerClearedEventHandler &other);
	OrderManagerClearedEventHandler& operator=(const OrderManagerClearedEventHandler &other);
	bool operator==(const OrderManagerClearedEventHandler &other) const;
	inline bool operator!=(const OrderManagerClearedEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const OnOrderManagerCleared& data, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const OnOrderManagerCleared& data);

private:
	QSharedDataPointer<OrderManagerClearedEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const OrderManagerClearedEventHandler& ordermanagerclearedeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const OrderManagerClearedEventHandler& ordermanagerclearedeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OrderManagerClearedEventHandler)

#endif // __QUANTKIT_ORDERMANAGERCLEAREDEVENTHANDLER_H__
