#include <QuantKit/Stop.h>

#include "Strategy_p.h"
#include <QuantKit/Position.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/ObjectTable.h>
#include <QuantKit/Event/Bar.h>
#include <QuantKit/Event/Trade.h>
#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>

namespace QuantKit {

class StopPrivate : public QSharedData
{
public:
	Strategy m_strategy;
	Position m_position;
	Instrument m_instrument;
	bool m_connected;
	StopType m_type;
	StopMode m_mode;
	StopStatus m_status;
	double m_level;
	double m_initPrice;
	double m_currPrice;
	double m_stopPrice;
	double m_fillPrice;
	double m_trailPrice;
	double m_qty;
	PositionSide m_side;
	QDateTime m_creationTime;
	QDateTime m_completionTime;
	bool m_traceOnQuote;
	bool m_traceOnTrade;
	bool m_traceOnBar;
	bool m_traceOnBarOpen;
	bool m_trailOnOpen;
	bool m_trailOnHighLow;
	long m_filterBarSize;
	BarType m_filterBarType;
	StopFillMode m_fillMode;
	ObjectTable m_fields;

public:
	StopPrivate(const Strategy& strategy, const Position& position, const QDateTime& time);
	StopPrivate(const Strategy& strategy, const Position& position, double level, StopType type, StopMode mode) { method_0(); }
	virtual ~StopPrivate();

public:
	Strategy strategy() const { return m_strategy; }
	Position position() const { return m_position; }
	Instrument instrument() const { return m_instrument; }
	bool connected() const { return m_connected; }
	StopType type() const { return m_type; }
	StopMode mode() const { return m_mode; }
	StopStatus status() const { return m_status; }
	double level() const { return m_level; }
	double qty() const { return m_qty; }
	PositionSide side() const { return m_side; }
	QDateTime creationTime() const { return m_creationTime; }
	QDateTime completionTime() const { return m_completionTime; }
	bool traceOnQuote() const { return m_traceOnQuote; }
	void setTraceOnQuote(bool value) { m_traceOnQuote = value; }
	bool traceOnTrade() const { return m_traceOnTrade; }
	void setTraceOnTrade(bool value) { m_traceOnTrade = value; }
	bool traceOnBar() const { return m_traceOnBar; }
	void setTraceOnBar(bool value) { m_traceOnBar = value; }
	bool traceOnBarOpen() const { return m_traceOnBarOpen; }
	void setTraceOnBarOpen(bool value) { m_traceOnBarOpen = value; }
	bool trailOnOpen() const { return m_trailOnOpen; }
	void setTrailOnOpen(bool value) { m_trailOnOpen = value; }
	bool trailOnHighLow() const { return m_trailOnHighLow; }
	void setTrailOnHighLow(bool value) { m_trailOnHighLow = value; }
	long filterBarSize() const { return m_filterBarSize; }
	void setFilterBarSize(long value) { m_filterBarSize = value; }
	BarType filterBarType() const { return m_filterBarType; }
	void setFilterBarType(BarType value) { m_filterBarType = value; }
	StopFillMode fillMode() const { return m_fillMode; }
	void setFillMode(StopFillMode value) { m_fillMode = value; }
	ObjectTable fields() const;
	void cancel();
	void disconnect();
	virtual StopPrivate* clone() Q_DECL_OVERRIDE { return new StopPrivate(*this); }
//private:
	void method_0() { m_connected = true; }
	void method_1();
	void method_7(StopStatus stopStatus);
	void method_8(const QDateTime& dateTime, const QVariant& object);
};

} // namepsace QuantKit


using namespace QuantKit;

StopPrivate::StopPrivate(const Strategy& strategy, const Position& position, const QDateTime& time)
	: m_strategy(strategy)
	, m_position(position)
	, m_instrument(position.instrument())
	, m_type(StopType.Trailing)
	, m_type(StopType.Time)
	, m_mode(StopMode.Percent)
	, m_stopPrice(GetInstrumentPrice())
	, m_qty(position.qty())
	, m_side(position.side())
	, m_creationTime(strategy.global().clock().dateTime())
	, m_completionTime(time)
	, m_traceOnQuote(true)
	, m_traceOnTrade(true)
	, m_traceOnBar(true)
	, m_traceOnBarOpen(true)
	, m_trailOnOpen(true)
	, m_filterBarSize(-1L)
	, m_filterBarType(BarType.Time)
	, m_fillMode(StopFillMode.Stop)
{
		if (m_completionTime > m_creationTime)
		{
			strategy.global().clock().AddReminder(new Reminder(new ReminderCallback(method_8()), m_completionTime, null));
		}
}

StopPrivate::~StopPrivate ()
{
}

ObjectTable StopPrivate::fields() const
{
	if (m_fields == null)
	{
		m_fields = new ObjectTable();
	}
	return m_fields;
}

void StopPrivate::cancel()
{
	if (m_status != StopStatus.Active)
	{
		return;
	}
	Disconnect();
	method_7(StopStatus.Canceled);
}

void StopPrivate::disconnect()
{
	if (m_type == StopType.Time)
	{
		m_strategy.global().clock().RemoveReminder(new ReminderCallback(method_8()), m_completionTime);
		return;
	}
	m_connected = false;
}

void StopPrivate::method_1()
{
	if (m_currPrice == 0.0)
	{
		return;
	}
	switch (m_side)
	{
		case PositionSide.Long:
			if (m_currPrice <= m_stopPrice)
			{
				Disconnect();
				method_7(StopStatus.Executed);
				return;
			}
			if (m_type == StopType.Trailing && m_trailPrice > m_initPrice)
			{
				m_stopPrice = GetStopPrice();
				return;
			}
			break;
		case PositionSide.Short:
			if (m_currPrice >= m_stopPrice)
			{
				Disconnect();
				method_7(StopStatus.Executed);
				return;
			}
			if (m_type == StopType.Trailing && m_trailPrice < m_initPrice)
			{
				m_stopPrice = GetStopPrice();
			}
			break;
		default:
			return;
	}
}

void StopPrivate::method_7(StopStatus stopStatus)
{
	m_status = stopStatus;
	m_completionTime = m_strategy.global().clock().dateTime();
	m_strategy.OnStopStatusChanged_(this);
}

void StopPrivate::method_8(const QDateTime& dateTime, const QVariant& object)
{
	m_stopPrice = GetInstrumentPrice();
	method_7(StopStatus.Executed);
}


// Pubic API 

Stop::Stop(const Strategy& strategy, const Position& position, const QDateTime& time)
	: d_ptr(new StopPrivate(strategy, position, time))
{
}

Stop::Stop(const Strategy& strategy, const Position& position, double level, StopType type, StopMode mode)
	: d_ptr(new StopPrivate(strategy, position, level, type, mode))
{
}

Stop::~Stop()
{
}

Stop::Stop (const Stop &other)
	: d_ptr(other.d_ptr)
{
}

Stop& Stop::operator=(const Stop &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Stop::operator==(const Stop &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Strategy Stop::strategy() const
{
	return d_ptr->strategy();
}

Position Stop::position() const
{
	return d_ptr->position();
}

Instrument Stop::instrument() const
{
	return d_ptr->instrument();
}

bool Stop::connected() const
{
	return d_ptr->connected();
}

StopType Stop::type() const
{
	return d_ptr->type();
}

StopMode Stop::mode() const
{
	return d_ptr->mode();
}

StopStatus Stop::status() const
{
	return d_ptr->status();
}

double Stop::level() const
{
	return d_ptr->level();
}

double Stop::qty() const
{
	return d_ptr->qty();
}

PositionSide Stop::side() const
{
	return d_ptr->side();
}

QDateTime Stop::creationTime() const
{
	return d_ptr->creationTime();
}

QDateTime Stop::completionTime() const
{
	return d_ptr->completionTime();
}

bool Stop::traceOnQuote() const
{
	return d_ptr->traceOnQuote();
}

void Stop::setTraceOnQuote(bool value)
{
	d_ptr->setTraceOnQuote(value);
}

bool Stop::traceOnTrade() const
{
	return d_ptr->traceOnTrade();
}

void Stop::setTraceOnTrade(bool value)
{
	d_ptr->setTraceOnTrade(value);
}

bool Stop::traceOnBar() const
{
	return d_ptr->traceOnBar();
}

void Stop::setTraceOnBar(bool value)
{
	d_ptr->setTraceOnBar(value);
}

bool Stop::traceOnBarOpen() const
{
	return d_ptr->traceOnBarOpen();
}

void Stop::setTraceOnBarOpen(bool value)
{
	d_ptr->setTraceOnBarOpen(value);
}

bool Stop::trailOnOpen() const
{
	return d_ptr->trailOnOpen();
}

void Stop::setTrailOnOpen(bool value)
{
	d_ptr->setTrailOnOpen(value);
}

bool Stop::trailOnHighLow() const
{
	return d_ptr->trailOnHighLow();
}

void Stop::setTrailOnHighLow(bool value)
{
	d_ptr->setTrailOnHighLow(value);
}

long Stop::filterBarSize() const
{
	return d_ptr->filterBarSize();
}

void Stop::setFilterBarSize(long value)
{
	d_ptr->setFilterBarSize(value);
}

BarType Stop::filterBarType() const
{
	return d_ptr->filterBarType();
}

void Stop::setFilterBarType(BarType value)
{
	d_ptr->setFilterBarType(value);
}

StopFillMode Stop::fillMode() const
{
	return d_ptr->fillMode();
}

void Stop::setFillMode(StopFillMode value)
{
	d_ptr->setFillMode(value);
}

ObjectTable Stop::fields() const
{
	return d_ptr->fields();
}

void Stop::cancel()
{
	d_ptr->cancel();
}

void Stop::disconnect()
{
	d_ptr->disconnect();
}

QDebug operator<<(QDebug dbg, const Stop& stop)
{
	return dbg << stop.toString();
}

