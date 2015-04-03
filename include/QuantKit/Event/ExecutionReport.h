#ifndef __QUANTKIT_EXECUTIONREPORT_H__
#define __QUANTKIT_EXECUTIONREPORT_H__

#include <QuantKit/quantkit_global.h>
#include <QString>

#include <QuantKit/ExecutionMessage.h>
#include <QuantKit/ExecType.h>
#include <QuantKit/OrderType.h>
#include <QuantKit/OrderSide.h>
#include <QuantKit/TimeInForce.h>
#include <QuantKit/OrderStatus.h>

namespace QuantKit {

class ExecutionReportPrivate;


class QUANTKIT_EXPORT ExecutionReport Q_DECL_FINAL : public ExecutionMessage
{
public:
	ExecutionReport();
	~ExecutionReport();

public:
	unsigned char currencyId() const;
	void setCurrencyId(unsigned char value);
	ExecType execType() const;
	void setExecType(ExecType value);
	OrderType ordType() const;
	void setOrdType(OrderType value);
	OrderSide side() const;
	void setSide(OrderSide value);
	TimeInForce timeInForce() const;
	void setTimeInForce(TimeInForce value);
	OrderStatus ordStatus() const;
	void setOrdStatus(OrderStatus value);
	double lastPx() const;
	void setLastPx(double value);
	double avgPx() const;
	void setAvgPx(double value);
	double ordQty() const;
	void setOrdQty(double value);
	double cumQty() const;
	void setCumQty(double value);
	double lastQty() const;
	void setLastQty(double value);
	double leavesQty() const;
	void setLeavesQty(double value);
	double price() const;
	void setPrice(double value);
	double stopPx() const;
	void setStopPx(double value);
	double commission() const;
	void setCommission(double value);
	QString text() const;
	void setText(const QString& value);

private:
	QK_DECLARE_PRIVATE(ExecutionReport)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ExecutionReport)

#endif // __QUANTKIT_EXECUTIONREPORT_H__
