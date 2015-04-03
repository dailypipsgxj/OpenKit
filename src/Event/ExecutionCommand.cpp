#include <QuantKit/Event/ExecutionCommand.h>

#include <QuantKit/Portfolio.h>
#include <QuantKit/Event/Order.h>

#include "ExecutionMessage_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class ExecutionCommandPrivate : public ExecutionMessagePrivate
{
public:
	ExecutionCommandType m_type;
	unsigned char m_providerId;
	unsigned char m_routeId;
	int m_portfolioId;
	QDateTime m_transactTime;
	IExecutionProvider m_provider;
	Portfolio m_portfolio;
	OrderSide m_side;
	OrderType m_ordType;
	TimeInForce m_timeInForce;
	double m_price;
	double m_stopPx;
	double m_qty;
	QString m_OCA;
	QString m_text;
	QString m_account;
	QString m_clientID;

public:
	ExecutionCommandPrivate();
	ExecutionCommandPrivate(ExecutionCommandType type, const Order& order);
	virtual ~ExecutionCommandPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::ExecutionCommand;
	}

	Portfolio portfolio() const { return m_portfolio; }
	int portfolioId() const { return m_portfolioId; }
	IExecutionProvider provider() const { return m_provider; }
	unsigned char providerId() const { return m_providerId; }
	unsigned char routeId() const { return m_routeId; }
	QString OCA() const { return m_OCA; }
	QString text() const { return m_text; }
	QString account() const { return m_account; }
	QString clientID() const { return m_clientID; }
	double stopPx() const { return m_stopPx; }
	double price() const { return m_price; }
	OrderSide side() const { return m_side; }
	OrderType ordType() const { return m_ordType; }
	double qty() const { return m_qty; }
	QDateTime transactTime() const { return m_transactTime; }
	TimeInForce timeInForce() const { return m_timeInForce; }
	ExecutionCommandType type() const { return m_type; }
	virtual ExecutionCommandPrivate* clone() Q_DECL_OVERRIDE { return new ExecutionCommandPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ExecutionCommandPrivate::ExecutionCommandPrivate()
	: m_OCA("")
	, m_text("")
{
}

ExecutionCommandPrivate::ExecutionCommandPrivate(ExecutionCommandType type, const Order& order)
	: m_type(type)
	, m_providerId(order.providerId())
	, m_routeId(order.routeId())
	, m_portfolioId(order.portfolioId())
	, m_transactTime(order.transactTime())
	, m_provider(order.provider())
	, m_portfolio(order.portfolio())
	, m_side(order.side())
	, m_ordType(order.type())
	, m_timeInForce(order.timeInForce())
	, m_price(order.price())
	, m_stopPx(order.stopPx())
	, m_qty(order.qty())
	, m_OCA("")
	, m_OCA(order.isOCA())
	, m_text("")
	, m_text(order.text())
	, m_account(order.account())
	, m_clientID(order.clientID())
{
		m_order = order;
		m_id = order.id();
		m_instrumentId = order.instrument();
		m_entryDate = order.entryDate();
		m_instrument = order.instrument();
}

ExecutionCommandPrivate::~ExecutionCommandPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(ExecutionCommand)

ExecutionCommand::ExecutionCommand()
	: ExecutionMessage(*new ExecutionCommandPrivate)
{
}

ExecutionCommand::ExecutionCommand(ExecutionCommandType type, const Order& order)
	: ExecutionMessage(*new ExecutionCommandPrivate(type, order))
{
}

ExecutionCommand::~ExecutionCommand()
{
}

Portfolio ExecutionCommand::portfolio() const
{
	Q_D(const ExecutionCommand);
	return d->portfolio();
}

int ExecutionCommand::portfolioId() const
{
	Q_D(const ExecutionCommand);
	return d->portfolioId();
}

IExecutionProvider ExecutionCommand::provider() const
{
	Q_D(const ExecutionCommand);
	return d->provider();
}

unsigned char ExecutionCommand::providerId() const
{
	Q_D(const ExecutionCommand);
	return d->providerId();
}

unsigned char ExecutionCommand::routeId() const
{
	Q_D(const ExecutionCommand);
	return d->routeId();
}

QString ExecutionCommand::OCA() const
{
	Q_D(const ExecutionCommand);
	return d->OCA();
}

QString ExecutionCommand::text() const
{
	Q_D(const ExecutionCommand);
	return d->text();
}

QString ExecutionCommand::account() const
{
	Q_D(const ExecutionCommand);
	return d->account();
}

QString ExecutionCommand::clientID() const
{
	Q_D(const ExecutionCommand);
	return d->clientID();
}

double ExecutionCommand::stopPx() const
{
	Q_D(const ExecutionCommand);
	return d->stopPx();
}

double ExecutionCommand::price() const
{
	Q_D(const ExecutionCommand);
	return d->price();
}

OrderSide ExecutionCommand::side() const
{
	Q_D(const ExecutionCommand);
	return d->side();
}

OrderType ExecutionCommand::ordType() const
{
	Q_D(const ExecutionCommand);
	return d->ordType();
}

double ExecutionCommand::qty() const
{
	Q_D(const ExecutionCommand);
	return d->qty();
}

QDateTime ExecutionCommand::transactTime() const
{
	Q_D(const ExecutionCommand);
	return d->transactTime();
}

TimeInForce ExecutionCommand::timeInForce() const
{
	Q_D(const ExecutionCommand);
	return d->timeInForce();
}

ExecutionCommandType ExecutionCommand::type() const
{
	Q_D(const ExecutionCommand);
	return d->type();
}


