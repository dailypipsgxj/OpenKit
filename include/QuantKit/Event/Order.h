#ifndef __QUANTKIT_ORDER_H__
#define __QUANTKIT_ORDER_H__

#include <QuantKit/quantkit_global.h>
#include <QList>
#include <QString>
#include <QDateTime>
#include <QVariant>

#include <QuantKit/DataObject.h>
#include <QuantKit/IExecutionProvider.h>
#include <QuantKit/OrderStatus.h>
#include <QuantKit/OrderSide.h>
#include <QuantKit/OrderType.h>
#include <QuantKit/TimeInForce.h>

namespace QuantKit {

class OrderPrivate;

class ObjectTable;
class ExecutionReport;
class ExecutionCommand;
class ExecutionMessage;
class Portfolio;
class Instrument;

class QUANTKIT_EXPORT Order Q_DECL_FINAL : public DataObject
{
public:
	Order();
	explicit Order(const ExecutionCommand& command);
	Order(const IExecutionProvider& provider, const Instrument& instrument, OrderType type, OrderSide side, double qty, double price = 0, double stopPx = 0, TimeInForce timeInForce = TimeInForce::Day, const QString& text = "");
	Order(const IExecutionProvider& provider, const Portfolio& portfolio, const Instrument& instrument, OrderType type, OrderSide side, double qty, double price = 0, double stopPx = 0, TimeInForce timeInForce = TimeInForce::Day, unsigned char routeId = 0, const QString& text = "");
	~Order();

public:
	double double_6() const;
	void setDouble_6(double value);

	bool bool_0() const;
	void setBool_0(bool value);

	bool bool_1() const;
	void setBool_1(bool value);
	ObjectTable fields() const;
	QList<ExecutionReport> reports() const;
	void setReports(const QList<ExecutionReport>& value);
	QList<ExecutionCommand> commands() const;
	void setCommands(const QList<ExecutionCommand>& value);
	QList<ExecutionMessage> messages() const;
	void setMessages(const QList<ExecutionMessage>& value);
	int id() const;
	void setId(int value);
	int clOrdId() const;
	void setClOrdId(int value);
	Portfolio portfolio() const;
	void setPortfolio(const Portfolio& value);
	IExecutionProvider provider() const;
	void setProvider(const IExecutionProvider& value);
	QString OCA() const;
	void setOCA(const QString& value);
	QString text() const;
	void setText(const QString& value);
	QString account() const;
	void setAccount(const QString& value);
	QString clientID() const;
	void setClientID(const QString& value);
	bool isNotSent() const;
	bool isPendingNew() const;
	bool isNew() const;
	bool isRejected() const;
	bool isPartiallyFilled() const;
	bool isFilled() const;
	bool isPendingCancel() const;
	bool isCancelled() const;
	bool isPendingReplace() const;
	bool isReplaced() const;
	bool isDone() const;
	bool isOCA() const;
	OrderStatus status() const;
	Instrument instrument() const;
	void setInstrument(const Instrument& value);
	double stopPx() const;
	void setStopPx(double value);
	double price() const;
	void setPrice(double value);
	OrderSide side() const;
	void setSide(OrderSide value);
	OrderType type() const;
	void setType(OrderType value);
	double qty() const;
	void setQty(double value);
	double cumQty() const;
	double leavesQty() const;
	double avgPx() const;
	TimeInForce timeInForce() const;
	void setTimeInForce(TimeInForce value);
	QDateTime expireTime() const;
	void setExpireTime(const QDateTime& value);
	unsigned char routeId() const;
	void setRouteId(unsigned char value);
	QDateTime transactTime() const;
	void setTransactTime(const QDateTime& value);
	unsigned char providerId() const;
	void setProviderId(unsigned char value);
	int portfolioId() const;
	void setPortfolioId(int value);
	int strategyId() const;
	void setStrategyId(int value);
	QVariant item(int index) const;
	void setItem(int index, const QVariant& value);
	QString getSideAsString();
	QString getStatusAsString();
	QString getTypeAsString();
	void onExecutionCommand(const ExecutionCommand& command);
	void onExecutionReport(const ExecutionReport& report);

private:
	QK_DECLARE_PRIVATE(Order)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Order)

#endif // __QUANTKIT_ORDER_H__
