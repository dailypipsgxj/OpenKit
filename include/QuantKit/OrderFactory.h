#ifndef __QUANTKIT_ORDERFACTORY_H__
#define __QUANTKIT_ORDERFACTORY_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class OrderFactoryPrivate;

class Order;
class ExecutionCommand;
class ExecutionReport;
class IdArray;

class QUANTKIT_EXPORT OrderFactory
{
public:
	OrderFactory();
	~OrderFactory();

	OrderFactory(const OrderFactory &other);
	OrderFactory& operator=(const OrderFactory &other);
	bool operator==(const OrderFactory &other) const;
	inline bool operator!=(const OrderFactory &other) const { return !(this->operator==(other));  }
public:
	Order onExecutionCommand(const ExecutionCommand& command);
	Order onExecutionReport(const ExecutionReport& report);
	void reset();

private:
	QSharedDataPointer<OrderFactoryPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const OrderFactory& orderfactory);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const OrderFactory& orderfactory);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OrderFactory)

#endif // __QUANTKIT_ORDERFACTORY_H__
