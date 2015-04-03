#ifndef __QUANTKIT_ORDERMANAGER_H__
#define __QUANTKIT_ORDERMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class OrderManagerPrivate;

class Order;
class Framework;
class OrderServer;
class ExecutionReport;
class ExecutionMessage;
class IdArray;

class QUANTKIT_EXPORT OrderManager
{
public:
	OrderManager(const Framework& framework, const OrderServer& server);
	~OrderManager();

	OrderManager(const OrderManager &other);
	OrderManager& operator=(const OrderManager &other);
	bool operator==(const OrderManager &other) const;
	inline bool operator!=(const OrderManager &other) const { return !(this->operator==(other));  }
public:
	QList<Order> orders() const;
	void cancel(const Order& order);
	void clear();
	void dump();
	void load();
    void register(const Order& order);
	void reject(const Order& order);
	void replace(const Order& order, double price);
	void replace(const Order& order, double price, double stopPx, double qty);
	void send(const Order& order);

private:
	QSharedDataPointer<OrderManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const OrderManager& ordermanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const OrderManager& ordermanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OrderManager)

#endif // __QUANTKIT_ORDERMANAGER_H__
