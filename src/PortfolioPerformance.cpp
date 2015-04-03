#include <QuantKit/PortfolioPerformance.h>

#include "TimeSeries_p.h"
#include <QuantKit/Portfolio.h>

namespace QuantKit {

class PortfolioPerformancePrivate : public QSharedData
{
public:
	EventHandler eventHandler_0;
	Portfolio portfolio_0;
	QDateTime dateTime_0;
	double double_0;
	double double_1;
	double double_2;
	TimeSeries m_equitySeries;
	TimeSeries m_drawdownSeries;

public:
	explicit PortfolioPerformancePrivate(const Portfolio& portfolio);
	virtual ~PortfolioPerformancePrivate();

public:
	TimeSeries equitySeries() const { return m_equitySeries; }
	TimeSeries drawdownSeries() const { return m_drawdownSeries; }
	void addUpdated(const EventHandler& value);
	void removeUpdated(const EventHandler& value);
	void reset();
	void update();
	virtual PortfolioPerformancePrivate* clone() Q_DECL_OVERRIDE { return new PortfolioPerformancePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioPerformancePrivate::PortfolioPerformancePrivate(const Portfolio& portfolio)
	: portfolio_0(portfolio)
	, m_equitySeries(new TimeSeries("Equity", "Equity"))
	, m_drawdownSeries(new TimeSeries("Drawdown", "Drawdown"))
{
}

PortfolioPerformancePrivate::~PortfolioPerformancePrivate ()
{
}

void PortfolioPerformancePrivate::addUpdated(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_0;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Combine(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_0, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void PortfolioPerformancePrivate::removeUpdated(const EventHandler& value)
{
	EventHandler eventHandler = eventHandler_0;
	EventHandler eventHandler2;
	do
	{
		eventHandler2 = eventHandler;
		EventHandler value2 = (EventHandler)Delegate.Remove(eventHandler2, value);
		eventHandler = Interlocked.CompareExchange<EventHandler>(ref eventHandler_0, value2, eventHandler2);
	}
	while (eventHandler != eventHandler2);
}

void PortfolioPerformancePrivate::reset()
{
	double_1 = 0.0;
	double_2 = -1.7976931348623157E+308;
}

void PortfolioPerformancePrivate::update()
{
	dateTime_0 = portfolio_0.clock().clock().dateTime();
	double value = portfolio_0.value();
	if (double_0 == value)
	{
		return;
	}
	double_0 = value;
	if (double_0 > double_2)
	{
		double_2 = double_0;
		double_1 = 0.0;
	}
	else
	{
		double_1 = double_2 - double_0;
	}
	m_equitySeries.Add(dateTime_0, double_0);
	m_drawdownSeries.Add(dateTime_0, double_1);
	portfolio_0.statistics().method_4(double_0);
	if (eventHandler_0 != null)
	{
		eventHandler_0(this, EventArgs.Empty);
	}
	if (portfolio_0.parent() != null)
	{
		portfolio_0.parent().performance().Update();
	}
}


// Pubic API 

PortfolioPerformance::PortfolioPerformance(const Portfolio& portfolio)
	: d_ptr(new PortfolioPerformancePrivate(portfolio))
{
}

PortfolioPerformance::~PortfolioPerformance()
{
}

PortfolioPerformance::PortfolioPerformance (const PortfolioPerformance &other)
	: d_ptr(other.d_ptr)
{
}

PortfolioPerformance& PortfolioPerformance::operator=(const PortfolioPerformance &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PortfolioPerformance::operator==(const PortfolioPerformance &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

TimeSeries PortfolioPerformance::equitySeries() const
{
	return d_ptr->equitySeries();
}

TimeSeries PortfolioPerformance::drawdownSeries() const
{
	return d_ptr->drawdownSeries();
}

void PortfolioPerformance::addUpdated(const EventHandler& value)
{
	d_ptr->addUpdated(value);
}

void PortfolioPerformance::removeUpdated(const EventHandler& value)
{
	d_ptr->removeUpdated(value);
}

void PortfolioPerformance::reset()
{
	d_ptr->reset();
}

void PortfolioPerformance::update()
{
	d_ptr->update();
}

QDebug operator<<(QDebug dbg, const PortfolioPerformance& portfolioperformance)
{
	return dbg << portfolioperformance.toString();
}

