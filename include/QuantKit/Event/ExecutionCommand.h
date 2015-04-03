#ifndef __QUANTKIT_EXECUTIONCOMMAND_H__
#define __QUANTKIT_EXECUTIONCOMMAND_H__

#include <QuantKit/quantkit_global.h>
#include <QString>
#include <QDateTime>

#include <QuantKit/ExecutionMessage.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/OrderSide.h>
#include <QuantKit/OrderType.h>
#include <QuantKit/TimeInForce.h>
#include <QuantKit/ExecutionCommandType.h>

namespace QuantKit {

class ExecutionCommandPrivate;

class Portfolio;
class Order;

class QUANTKIT_EXPORT ExecutionCommand Q_DECL_FINAL : public ExecutionMessage
{
public:
	ExecutionCommand();
	ExecutionCommand(ExecutionCommandType type, const Order& order);
	~ExecutionCommand();

public:
	Portfolio portfolio() const;
	int portfolioId() const;
	IExecutionProvider provider() const;
	unsigned char providerId() const;
	unsigned char routeId() const;
	QString OCA() const;
	QString text() const;
	QString account() const;
	QString clientID() const;
	double stopPx() const;
	double price() const;
	OrderSide side() const;
	OrderType ordType() const;
	double qty() const;
	QDateTime transactTime() const;
	TimeInForce timeInForce() const;
	ExecutionCommandType type() const;

private:
	QK_DECLARE_PRIVATE(ExecutionCommand)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ExecutionCommand)

#endif // __QUANTKIT_EXECUTIONCOMMAND_H__
