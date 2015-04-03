#include <QuantKit/Event/ExecutionReport.h>


#include "ExecutionMessage_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class ExecutionReportPrivate : public ExecutionMessagePrivate
{
public:
	unsigned char m_currencyId;
	ExecType m_execType;
	OrderType m_ordType;
	OrderSide m_side;
	TimeInForce m_timeInForce;
	OrderStatus m_ordStatus;
	double m_lastPx;
	double m_avgPx;
	double m_ordQty;
	double m_cumQty;
	double m_lastQty;
	double m_leavesQty;
	double m_price;
	double m_stopPx;
	double m_commission;
	QString m_text;

public:
	ExecutionReportPrivate();
	virtual ~ExecutionReportPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::ExecutionReport;
	}

	unsigned char currencyId() const { return m_currencyId; }
	void setCurrencyId(unsigned char value) { m_currencyId = value; }
	ExecType execType() const { return m_execType; }
	void setExecType(ExecType value) { m_execType = value; }
	OrderType ordType() const { return m_ordType; }
	void setOrdType(OrderType value) { m_ordType = value; }
	OrderSide side() const { return m_side; }
	void setSide(OrderSide value) { m_side = value; }
	TimeInForce timeInForce() const { return m_timeInForce; }
	void setTimeInForce(TimeInForce value) { m_timeInForce = value; }
	OrderStatus ordStatus() const { return m_ordStatus; }
	void setOrdStatus(OrderStatus value) { m_ordStatus = value; }
	double lastPx() const { return m_lastPx; }
	void setLastPx(double value) { m_lastPx = value; }
	double avgPx() const { return m_avgPx; }
	void setAvgPx(double value) { m_avgPx = value; }
	double ordQty() const { return m_ordQty; }
	void setOrdQty(double value) { m_ordQty = value; }
	double cumQty() const { return m_cumQty; }
	void setCumQty(double value) { m_cumQty = value; }
	double lastQty() const { return m_lastQty; }
	void setLastQty(double value) { m_lastQty = value; }
	double leavesQty() const { return m_leavesQty; }
	void setLeavesQty(double value) { m_leavesQty = value; }
	double price() const { return m_price; }
	void setPrice(double value) { m_price = value; }
	double stopPx() const { return m_stopPx; }
	void setStopPx(double value) { m_stopPx = value; }
	double commission() const { return m_commission; }
	void setCommission(double value) { m_commission = value; }
	QString text() const { return m_text; }
	void setText(const QString& value) { m_text = value; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "ExecutionReport"; }
	virtual ExecutionReportPrivate* clone() Q_DECL_OVERRIDE { return new ExecutionReportPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ExecutionReportPrivate::ExecutionReportPrivate()
	: m_text(string.Empty)
{
}

ExecutionReportPrivate::~ExecutionReportPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(ExecutionReport)

ExecutionReport::ExecutionReport()
	: ExecutionMessage(*new ExecutionReportPrivate)
{
}

ExecutionReport::~ExecutionReport()
{
}

unsigned char ExecutionReport::currencyId() const
{
	Q_D(const ExecutionReport);
	return d->currencyId();
}

void ExecutionReport::setCurrencyId(unsigned char value)
{
	Q_D(ExecutionReport);
	d->setCurrencyId(value);
}

ExecType ExecutionReport::execType() const
{
	Q_D(const ExecutionReport);
	return d->execType();
}

void ExecutionReport::setExecType(ExecType value)
{
	Q_D(ExecutionReport);
	d->setExecType(value);
}

OrderType ExecutionReport::ordType() const
{
	Q_D(const ExecutionReport);
	return d->ordType();
}

void ExecutionReport::setOrdType(OrderType value)
{
	Q_D(ExecutionReport);
	d->setOrdType(value);
}

OrderSide ExecutionReport::side() const
{
	Q_D(const ExecutionReport);
	return d->side();
}

void ExecutionReport::setSide(OrderSide value)
{
	Q_D(ExecutionReport);
	d->setSide(value);
}

TimeInForce ExecutionReport::timeInForce() const
{
	Q_D(const ExecutionReport);
	return d->timeInForce();
}

void ExecutionReport::setTimeInForce(TimeInForce value)
{
	Q_D(ExecutionReport);
	d->setTimeInForce(value);
}

OrderStatus ExecutionReport::ordStatus() const
{
	Q_D(const ExecutionReport);
	return d->ordStatus();
}

void ExecutionReport::setOrdStatus(OrderStatus value)
{
	Q_D(ExecutionReport);
	d->setOrdStatus(value);
}

double ExecutionReport::lastPx() const
{
	Q_D(const ExecutionReport);
	return d->lastPx();
}

void ExecutionReport::setLastPx(double value)
{
	Q_D(ExecutionReport);
	d->setLastPx(value);
}

double ExecutionReport::avgPx() const
{
	Q_D(const ExecutionReport);
	return d->avgPx();
}

void ExecutionReport::setAvgPx(double value)
{
	Q_D(ExecutionReport);
	d->setAvgPx(value);
}

double ExecutionReport::ordQty() const
{
	Q_D(const ExecutionReport);
	return d->ordQty();
}

void ExecutionReport::setOrdQty(double value)
{
	Q_D(ExecutionReport);
	d->setOrdQty(value);
}

double ExecutionReport::cumQty() const
{
	Q_D(const ExecutionReport);
	return d->cumQty();
}

void ExecutionReport::setCumQty(double value)
{
	Q_D(ExecutionReport);
	d->setCumQty(value);
}

double ExecutionReport::lastQty() const
{
	Q_D(const ExecutionReport);
	return d->lastQty();
}

void ExecutionReport::setLastQty(double value)
{
	Q_D(ExecutionReport);
	d->setLastQty(value);
}

double ExecutionReport::leavesQty() const
{
	Q_D(const ExecutionReport);
	return d->leavesQty();
}

void ExecutionReport::setLeavesQty(double value)
{
	Q_D(ExecutionReport);
	d->setLeavesQty(value);
}

double ExecutionReport::price() const
{
	Q_D(const ExecutionReport);
	return d->price();
}

void ExecutionReport::setPrice(double value)
{
	Q_D(ExecutionReport);
	d->setPrice(value);
}

double ExecutionReport::stopPx() const
{
	Q_D(const ExecutionReport);
	return d->stopPx();
}

void ExecutionReport::setStopPx(double value)
{
	Q_D(ExecutionReport);
	d->setStopPx(value);
}

double ExecutionReport::commission() const
{
	Q_D(const ExecutionReport);
	return d->commission();
}

void ExecutionReport::setCommission(double value)
{
	Q_D(ExecutionReport);
	d->setCommission(value);
}

QString ExecutionReport::text() const
{
	Q_D(const ExecutionReport);
	return d->text();
}

void ExecutionReport::setText(const QString& value)
{
	Q_D(ExecutionReport);
	d->setText(value);
}


