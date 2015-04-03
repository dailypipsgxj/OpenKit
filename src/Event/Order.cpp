#include <QuantKit/Event/Order.h>

#include <QuantKit/ObjectTable.h>
#include <QuantKit/Event/ExecutionReport.h>
#include <QuantKit/Event/ExecutionCommand.h>
#include "ExecutionMessage_p.h"
#include <QuantKit/Portfolio.h>
#include <QuantKit/Instrument.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OrderPrivate : public DataObjectPrivate
{
public:
	int m_id;
	int m_clOrdId;
	unsigned char m_providerId;
	unsigned char m_routeId;
	int m_instrument;
	int m_portfolioId;
	int m_strategyId;
	QDateTime m_transactTime;
	Instrument m_instrument;
	IExecutionProvider m_provider;
	Portfolio m_portfolio;
	OrderStatus m_status;
	OrderSide m_side;
	OrderType m_type;
	TimeInForce m_timeInForce;
	QDateTime m_expireTime;
	double m_price;
	double m_stopPx;
	double m_avgPx;
	double m_qty;
	double m_cumQty;
	double m_leavesQty;
	QString m_isOCA;
	QString m_text;
	QString m_account;
	QString m_clientID;
	double double_6;
	bool bool_0;
	bool bool_1;
	QList<ExecutionCommand> m_commands;
	QList<ExecutionReport> m_reports;
	QList<ExecutionMessage> m_messages;
	ObjectTable m_item;

public:
	OrderPrivate();
	explicit OrderPrivate(const ExecutionCommand& command);
	OrderPrivate(const IExecutionProvider& provider, const Instrument& instrument, OrderType type, OrderSide side, double qty, double price, double stopPx, TimeInForce timeInForce, const QString& text);
	OrderPrivate(const IExecutionProvider& provider, const Portfolio& portfolio, const Instrument& instrument, OrderType type, OrderSide side, double qty, double price, double stopPx, TimeInForce timeInForce, unsigned char routeId, const QString& text);
	virtual ~OrderPrivate();

public:
	double getDouble_6() const;
	void setDouble_6(double value);

	bool getBool_0() const;
	void setBool_0(bool value);

	bool getBool_1() const;
	void setBool_1(bool value);
	ObjectTable fields() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Order; }
	QList<ExecutionReport> reports() const { return m_reports; }
	void setReports(const QList<ExecutionReport>& value) { m_reports = value; }
	QList<ExecutionCommand> commands() const { return m_commands; }
	void setCommands(const QList<ExecutionCommand>& value) { m_commands = value; }
	QList<ExecutionMessage> messages() const { return m_messages; }
	void setMessages(const QList<ExecutionMessage>& value) { m_messages = value; }
	int id() const { return m_id; }
	void setId(int value) { m_id = value; }
	int clOrdId() const { return m_clOrdId; }
	void setClOrdId(int value) { m_clOrdId = value; }
	Portfolio portfolio() const { return m_portfolio; }
	void setPortfolio(const Portfolio& value) { m_portfolio = value; }
	IExecutionProvider provider() const { return m_provider; }
	void setProvider(const IExecutionProvider& value) { m_provider = value; }
	QString OCA() const { return m_isOCA; }
	void setOCA(const QString& value);
	QString text() const { return m_text; }
	void setText(const QString& value);
	QString account() const { return m_account; }
	void setAccount(const QString& value);
	QString clientID() const { return m_clientID; }
	void setClientID(const QString& value);
	bool isNotSent() const
	{
		return m_status == OrderStatus.NotSent;
	}

	bool isPendingNew() const
	{
		return m_status == OrderStatus.PendingNew;
	}

	bool isNew() const
	{
		return m_status == OrderStatus.New;
	}

	bool isRejected() const
	{
		return m_status == OrderStatus.Rejected;
	}

	bool isPartiallyFilled() const
	{
		return m_status == OrderStatus.PartiallyFilled;
	}

	bool isFilled() const
	{
		return m_status == OrderStatus.Filled;
	}

	bool isPendingCancel() const
	{
		return m_status == OrderStatus.PendingCancel;
	}

	bool isCancelled() const
	{
		return m_status == OrderStatus.Cancelled;
	}

	bool isPendingReplace() const
	{
		return m_status == OrderStatus.PendingReplace;
	}

	bool isReplaced() const
	{
		return m_status == OrderStatus.Replaced;
	}

	bool isDone() const
	{
		return m_status == OrderStatus.Filled || m_status == OrderStatus.Cancelled || m_status == OrderStatus.Rejected;
	}

	bool isOCA() const
	{
		return !string.IsNullOrEmpty(m_isOCA);
	}

	OrderStatus status() const { return m_status; }
	Instrument instrument() const { return m_instrument; }
	void setInstrument(const Instrument& value);
	double stopPx() const { return m_stopPx; }
	void setStopPx(double value);
	double price() const { return m_price; }
	void setPrice(double value);
	OrderSide side() const { return m_side; }
	void setSide(OrderSide value);
	OrderType type() const { return m_type; }
	void setType(OrderType value);
	double qty() const { return m_qty; }
	void setQty(double value);
	double cumQty() const { return m_cumQty; }
	double leavesQty() const { return m_leavesQty; }
	double avgPx() const { return m_avgPx; }
	TimeInForce timeInForce() const { return m_timeInForce; }
	void setTimeInForce(TimeInForce value);
	QDateTime expireTime() const { return m_expireTime; }
	void setExpireTime(const QDateTime& value);
	unsigned char routeId() const { return m_routeId; }
	void setRouteId(unsigned char value);
	QDateTime transactTime() const { return m_transactTime; }
	void setTransactTime(const QDateTime& value) { m_transactTime = value; }
	unsigned char providerId() const { return m_providerId; }
	void setProviderId(unsigned char value) { m_providerId = value; }
	int portfolioId() const { return m_portfolioId; }
	void setPortfolioId(int value) { m_portfolioId = value; }
	int strategyId() const { return m_strategyId; }
	void setStrategyId(int value) { m_strategyId = value; }
	QVariant item(int index) const;
	void setItem(int index, const QVariant& value);
	QString getSideAsString();
	QString getStatusAsString();
	QString getTypeAsString();
	void onExecutionCommand(const ExecutionCommand& command);
	void onExecutionReport(const ExecutionReport& report);
	virtual QString toString() const Q_DECL_OVERRIDE { return "Order"; }
	virtual OrderPrivate* clone() Q_DECL_OVERRIDE { return new OrderPrivate(*this); }
//private:
	void method_0();
};

} // namepsace QuantKit


using namespace QuantKit;

OrderPrivate::OrderPrivate()
	: m_id(-1)
	, m_clOrdId(-1)
	, m_isOCA("")
	, m_text("")
	, m_commands(new QList<ExecutionCommand>())
	, m_reports(new QList<ExecutionReport>())
	, m_messages(new QList<ExecutionMessage>())
{
}

OrderPrivate::OrderPrivate(const ExecutionCommand& command)
	: m_id(-1)
	, m_id(command.orderId())
	, m_clOrdId(-1)
	, m_providerId(command.providerId())
	, m_routeId(command.routeId())
	, m_instrument(command.instrumentId())
	, m_portfolioId(command.portfolioId())
	, m_transactTime(command.transactTime())
	, m_side(command.side())
	, m_type(command.ordType())
	, m_timeInForce(command.timeInForce())
	, m_price(command.price())
	, m_stopPx(command.stopPx())
	, m_qty(command.qty())
	, m_isOCA("")
	, m_text("")
	, m_text(command.text())
	, m_account(command.account())
	, m_clientID(command.clientID())
{
		if (command.type() != ExecutionCommandType.Send)
		{
			throw new Exception("Order::Order Can not create order from execution command of type different than Send : " + command.type());
		}
		m_entryDate = command.entryDate();
}

OrderPrivate::OrderPrivate(const IExecutionProvider& provider, const Instrument& instrument, OrderType type, OrderSide side, double qty, double price, double stopPx, TimeInForce timeInForce, const QString& text)
	: m_providerId(provider.id())
	, m_instrument(instrument)
	, m_instrument(instrument.id())
	, m_provider(provider)
	, m_portfolio(null)
	, m_side(side)
	, m_type(type)
	, m_timeInForce(timeInForce)
	, m_price(price)
	, m_stopPx(stopPx)
	, m_qty(qty)
	, m_text(text)
{
		Class81.pxBq5K7zXLUvm();
		.ctor();
}

OrderPrivate::OrderPrivate(const IExecutionProvider& provider, const Portfolio& portfolio, const Instrument& instrument, OrderType type, OrderSide side, double qty, double price, double stopPx, TimeInForce timeInForce, unsigned char routeId, const QString& text)
	: m_providerId(provider.id())
	, m_routeId(routeId)
	, m_instrument(instrument)
	, m_instrument(instrument.id())
	, m_portfolioId(portfolio.id())
	, m_provider(provider)
	, m_portfolio(portfolio)
	, m_side(side)
	, m_type(type)
	, m_timeInForce(timeInForce)
	, m_price(price)
	, m_stopPx(stopPx)
	, m_qty(qty)
	, m_text(text)
{
		Class81.pxBq5K7zXLUvm();
		.ctor();
}

OrderPrivate::~OrderPrivate ()
{
}

double getDouble_6() const
{
	return 0;
}
void setDouble_6(double value)
{
}

bool getBool_0() const
{
	return false;
}
void setBool_0(bool value)
{
}

bool getBool_1() const
{
	return false;
}
void setBool_1(bool value)
{
}
ObjectTable OrderPrivate::fields() const
{
	if (m_item == null)
	{
		m_item = new ObjectTable();
	}
	return m_item;
}

void OrderPrivate::setOCA(const QString& value)
{
	method_0();
	m_isOCA = value;
}

void OrderPrivate::setText(const QString& value)
{
	method_0();
	m_text = value;
}

void OrderPrivate::setAccount(const QString& value)
{
	method_0();
	m_account = value;
}

void OrderPrivate::setClientID(const QString& value)
{
	method_0();
	m_clientID = value;
}

void OrderPrivate::setInstrument(const Instrument& value)
{
	m_instrument = value;
	m_instrument = m_instrument.id();
}

void OrderPrivate::setStopPx(double value)
{
	method_0();
	m_stopPx = value;
}

void OrderPrivate::setPrice(double value)
{
	method_0();
	m_price = value;
}

void OrderPrivate::setSide(OrderSide value)
{
	method_0();
	m_side = value;
}

void OrderPrivate::setType(OrderType value)
{
	method_0();
	m_type = value;
}

void OrderPrivate::setQty(double value)
{
	method_0();
	m_qty = value;
}

void OrderPrivate::setTimeInForce(TimeInForce value)
{
	method_0();
	m_timeInForce = value;
}

void OrderPrivate::setExpireTime(const QDateTime& value)
{
	method_0();
	m_expireTime = value;
}

void OrderPrivate::setRouteId(unsigned char value)
{
	method_0();
	m_routeId = value;
}

QVariant OrderPrivate::item(int index) const
{
	if (m_item == null)
	{
		return null;
	}
	return m_item[index];
}

void OrderPrivate::setItem(int index, const QVariant& value)
{
	if (m_item == null)
	{
		m_item = new ObjectTable();
	}
	m_item[index] = value;
}

QString OrderPrivate::getSideAsString()
{
	switch (m_side)
	{
		case OrderSide.Buy:
			return "Buy";
		case OrderSide.Sell:
			return "Sell";
		default:
			return "Undefined";
	}
}

QString OrderPrivate::getStatusAsString()
{
	switch (m_status)
	{
		case OrderStatus.NotSent:
			return "NotSent";
		case OrderStatus.PendingNew:
			return "PendingNew";
		case OrderStatus.New:
			return "New";
		case OrderStatus.Rejected:
			return "Rejected";
		case OrderStatus.PartiallyFilled:
			return "PartiallyFilled";
		case OrderStatus.Filled:
			return "Filled";
		case OrderStatus.PendingCancel:
			return "PendingCancel";
		case OrderStatus.Cancelled:
			return "Cancelled";
		case OrderStatus.PendingReplace:
			return "PendingReplace";
		case OrderStatus.Replaced:
			return "Replaced";
	}
	return "Undefined";
}

QString OrderPrivate::getTypeAsString()
{
	switch (m_type)
	{
		case OrderType.Market:
			return "Market";
		case OrderType.Stop:
			return "Stop";
		case OrderType.Limit:
			return "Limit";
		case OrderType.StopLimit:
			return "StopLimit";
		default:
			return "Undefined";
	}
}

void OrderPrivate::onExecutionCommand(const ExecutionCommand& command)
{
	m_commands.Add(command);
	m_messages.Add(command);
}

void OrderPrivate::onExecutionReport(const ExecutionReport& report)
{
	m_status = report.ordStatus();
	if (report.execType() == ExecType.ExecTrade)
	{
		m_avgPx = (m_avgPx * m_cumQty + report.lastPx() * report.lastQty()) / (m_cumQty + report.lastQty());
	}
	m_cumQty = report.cumQty();
	m_leavesQty = report.leavesQty();
	if (report.execType() == ExecType.ExecReplace)
	{
		m_type = report.ordType();
		m_price = report.price();
		m_stopPx = report.stopPx();
		m_qty = report.ordQty();
	}
	m_reports.Add(report);
	m_messages.Add(report);
}

void OrderPrivate::method_0()
{
	if (m_status != OrderStatus.NotSent)
	{
		throw new InvalidOperationException("Cannot perform an operation, because order is already sent.");
	}
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Order)

Order::Order()
	: DataObject(*new OrderPrivate)
{
}

Order::Order(const ExecutionCommand& command)
	: DataObject(*new OrderPrivate(command))
{
}

Order::Order(const IExecutionProvider& provider, const Instrument& instrument, OrderType type, OrderSide side, double qty, double price, double stopPx, TimeInForce timeInForce, const QString& text)
	: DataObject(*new OrderPrivate(provider, instrument, type, side, qty, price, stopPx, timeInForce, text))
{
}

Order::Order(const IExecutionProvider& provider, const Portfolio& portfolio, const Instrument& instrument, OrderType type, OrderSide side, double qty, double price, double stopPx, TimeInForce timeInForce, unsigned char routeId, const QString& text)
	: DataObject(*new OrderPrivate(provider, portfolio, instrument, type, side, qty, price, stopPx, timeInForce, routeId, text))
{
}

Order::~Order()
{
}

double double_6() const
{
	return d_ptr->
	setDouble_6()
}

void setDouble_6(double value)
{
	d_ptr->double_6(value);
}

bool bool_0() const
{
	return d_ptr->
	setBool_0()
}

void setBool_0(bool value)
{
	d_ptr->bool_0(value);
}

bool bool_1() const
{
	return d_ptr->
	setBool_1()
}

void setBool_1(bool value)
{
	d_ptr->bool_1(value);
}

ObjectTable Order::fields() const
{
	Q_D(const Order);
	return d->fields();
}

QList<ExecutionReport> Order::reports() const
{
	Q_D(const Order);
	return d->reports();
}

void Order::setReports(const QList<ExecutionReport>& value)
{
	Q_D(Order);
	d->setReports(value);
}

QList<ExecutionCommand> Order::commands() const
{
	Q_D(const Order);
	return d->commands();
}

void Order::setCommands(const QList<ExecutionCommand>& value)
{
	Q_D(Order);
	d->setCommands(value);
}

QList<ExecutionMessage> Order::messages() const
{
	Q_D(const Order);
	return d->messages();
}

void Order::setMessages(const QList<ExecutionMessage>& value)
{
	Q_D(Order);
	d->setMessages(value);
}

int Order::id() const
{
	Q_D(const Order);
	return d->id();
}

void Order::setId(int value)
{
	Q_D(Order);
	d->setId(value);
}

int Order::clOrdId() const
{
	Q_D(const Order);
	return d->clOrdId();
}

void Order::setClOrdId(int value)
{
	Q_D(Order);
	d->setClOrdId(value);
}

Portfolio Order::portfolio() const
{
	Q_D(const Order);
	return d->portfolio();
}

void Order::setPortfolio(const Portfolio& value)
{
	Q_D(Order);
	d->setPortfolio(value);
}

IExecutionProvider Order::provider() const
{
	Q_D(const Order);
	return d->provider();
}

void Order::setProvider(const IExecutionProvider& value)
{
	Q_D(Order);
	d->setProvider(value);
}

QString Order::OCA() const
{
	Q_D(const Order);
	return d->OCA();
}

void Order::setOCA(const QString& value)
{
	Q_D(Order);
	d->setOCA(value);
}

QString Order::text() const
{
	Q_D(const Order);
	return d->text();
}

void Order::setText(const QString& value)
{
	Q_D(Order);
	d->setText(value);
}

QString Order::account() const
{
	Q_D(const Order);
	return d->account();
}

void Order::setAccount(const QString& value)
{
	Q_D(Order);
	d->setAccount(value);
}

QString Order::clientID() const
{
	Q_D(const Order);
	return d->clientID();
}

void Order::setClientID(const QString& value)
{
	Q_D(Order);
	d->setClientID(value);
}

bool Order::isNotSent() const
{
	Q_D(const Order);
	return d->isNotSent();
}

bool Order::isPendingNew() const
{
	Q_D(const Order);
	return d->isPendingNew();
}

bool Order::isNew() const
{
	Q_D(const Order);
	return d->isNew();
}

bool Order::isRejected() const
{
	Q_D(const Order);
	return d->isRejected();
}

bool Order::isPartiallyFilled() const
{
	Q_D(const Order);
	return d->isPartiallyFilled();
}

bool Order::isFilled() const
{
	Q_D(const Order);
	return d->isFilled();
}

bool Order::isPendingCancel() const
{
	Q_D(const Order);
	return d->isPendingCancel();
}

bool Order::isCancelled() const
{
	Q_D(const Order);
	return d->isCancelled();
}

bool Order::isPendingReplace() const
{
	Q_D(const Order);
	return d->isPendingReplace();
}

bool Order::isReplaced() const
{
	Q_D(const Order);
	return d->isReplaced();
}

bool Order::isDone() const
{
	Q_D(const Order);
	return d->isDone();
}

bool Order::isOCA() const
{
	Q_D(const Order);
	return d->isOCA();
}

OrderStatus Order::status() const
{
	Q_D(const Order);
	return d->status();
}

Instrument Order::instrument() const
{
	Q_D(const Order);
	return d->instrument();
}

void Order::setInstrument(const Instrument& value)
{
	Q_D(Order);
	d->setInstrument(value);
}

double Order::stopPx() const
{
	Q_D(const Order);
	return d->stopPx();
}

void Order::setStopPx(double value)
{
	Q_D(Order);
	d->setStopPx(value);
}

double Order::price() const
{
	Q_D(const Order);
	return d->price();
}

void Order::setPrice(double value)
{
	Q_D(Order);
	d->setPrice(value);
}

OrderSide Order::side() const
{
	Q_D(const Order);
	return d->side();
}

void Order::setSide(OrderSide value)
{
	Q_D(Order);
	d->setSide(value);
}

OrderType Order::type() const
{
	Q_D(const Order);
	return d->type();
}

void Order::setType(OrderType value)
{
	Q_D(Order);
	d->setType(value);
}

double Order::qty() const
{
	Q_D(const Order);
	return d->qty();
}

void Order::setQty(double value)
{
	Q_D(Order);
	d->setQty(value);
}

double Order::cumQty() const
{
	Q_D(const Order);
	return d->cumQty();
}

double Order::leavesQty() const
{
	Q_D(const Order);
	return d->leavesQty();
}

double Order::avgPx() const
{
	Q_D(const Order);
	return d->avgPx();
}

TimeInForce Order::timeInForce() const
{
	Q_D(const Order);
	return d->timeInForce();
}

void Order::setTimeInForce(TimeInForce value)
{
	Q_D(Order);
	d->setTimeInForce(value);
}

QDateTime Order::expireTime() const
{
	Q_D(const Order);
	return d->expireTime();
}

void Order::setExpireTime(const QDateTime& value)
{
	Q_D(Order);
	d->setExpireTime(value);
}

unsigned char Order::routeId() const
{
	Q_D(const Order);
	return d->routeId();
}

void Order::setRouteId(unsigned char value)
{
	Q_D(Order);
	d->setRouteId(value);
}

QDateTime Order::transactTime() const
{
	Q_D(const Order);
	return d->transactTime();
}

void Order::setTransactTime(const QDateTime& value)
{
	Q_D(Order);
	d->setTransactTime(value);
}

unsigned char Order::providerId() const
{
	Q_D(const Order);
	return d->providerId();
}

void Order::setProviderId(unsigned char value)
{
	Q_D(Order);
	d->setProviderId(value);
}

int Order::portfolioId() const
{
	Q_D(const Order);
	return d->portfolioId();
}

void Order::setPortfolioId(int value)
{
	Q_D(Order);
	d->setPortfolioId(value);
}

int Order::strategyId() const
{
	Q_D(const Order);
	return d->strategyId();
}

void Order::setStrategyId(int value)
{
	Q_D(Order);
	d->setStrategyId(value);
}

QVariant Order::item(int index) const
{
	Q_D(const Order);
	return d->item(index);
}

void Order::setItem(int index, const QVariant& value)
{
	Q_D(Order);
	d->setItem(index, value);
}

QString Order::getSideAsString()
{
	Q_D(Order);
	return d->getSideAsString();
}

QString Order::getStatusAsString()
{
	Q_D(Order);
	return d->getStatusAsString();
}

QString Order::getTypeAsString()
{
	Q_D(Order);
	return d->getTypeAsString();
}

void Order::onExecutionCommand(const ExecutionCommand& command)
{
	Q_D(Order);
	d->onExecutionCommand(command);
}

void Order::onExecutionReport(const ExecutionReport& report)
{
	Q_D(Order);
	d->onExecutionReport(report);
}


