#include <QuantKit/PortfolioStatisticsItem.h>

#include "TimeSeries_p.h"
#include <QuantKit/Clock.h>
#include <QuantKit/Event/Fill.h>
#include <QuantKit/Transaction.h>
#include <QuantKit/Position.h>
#include <QuantKit/TradeInfo.h>
#include <QuantKit/Portfolio.h>
#include <QuantKit/PortfolioStatistics.h>
#include "PortfolioStatisticsItem_p.h"

using namespace QuantKit;

PortfolioStatisticsItemPrivate::PortfolioStatisticsItemPrivate()
	: m_totalValues(new TimeSeries(name(), ""))
	, m_longValues(new TimeSeries(name() + " Long", ""))
	, m_shortValues(new TimeSeries(name() + " Short", ""))
{
}

PortfolioStatisticsItemPrivate::~PortfolioStatisticsItemPrivate ()
{
}

PortfolioStatistics getStatistics() const
{
	return null;
}
void setStatistics(PortfolioStatistics value)
{
}
//protected
void PortfolioStatisticsItemPrivate::emit()
{
	if (statistics != null)
	{
		statistics.method_9(this);
		if (m_clock.parent() != null)
		{
			statistics.method_10(m_clock, this);
		}
	}
}

void PortfolioStatisticsItemPrivate::onClear()
{
}

void PortfolioStatisticsItemPrivate::onEquity(double equity)
{
}

void PortfolioStatisticsItemPrivate::onFill(const Fill& fill)
{
}

void PortfolioStatisticsItemPrivate::onInit()
{
}

void PortfolioStatisticsItemPrivate::onPositionChanged(const Position& position)
{
}

void PortfolioStatisticsItemPrivate::onPositionClosed(const Position& position)
{
}

void PortfolioStatisticsItemPrivate::onPositionOpened(const Position& position)
{
}

void PortfolioStatisticsItemPrivate::onRoundTrip(const TradeInfo& trade)
{
}

void PortfolioStatisticsItemPrivate::onStatistics(const PortfolioStatisticsItem& statistics)
{
}

void PortfolioStatisticsItemPrivate::onStatistics(const Portfolio& portfolio, const PortfolioStatisticsItem& statistics)
{
}

void PortfolioStatisticsItemPrivate::onTransaction(const Transaction& transaction)
{
}


// Pubic API 

PortfolioStatisticsItem::PortfolioStatisticsItem()
	: d_ptr(new PortfolioStatisticsItemPrivate)
{
}

PortfolioStatisticsItem::~PortfolioStatisticsItem()
{
}

PortfolioStatisticsItem::PortfolioStatisticsItem (PortfolioStatisticsItemPrivate &dd)
	: d_ptr(&dd)
{
}

PortfolioStatisticsItem::PortfolioStatisticsItem (const PortfolioStatisticsItem &other)
	: d_ptr(other.d_ptr)
{
}

PortfolioStatisticsItem& PortfolioStatisticsItem::operator=(const PortfolioStatisticsItem &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PortfolioStatisticsItem::operator==(const PortfolioStatisticsItem &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

PortfolioStatistics statistics() const
{
	return d_ptr->
	setStatistics()
}

void setStatistics(PortfolioStatistics value)
{
	d_ptr->statistics(value);
}

int PortfolioStatisticsItem::type() const
{
	return d_ptr->type();
}

QString PortfolioStatisticsItem::name() const
{
	return d_ptr->name();
}

QString PortfolioStatisticsItem::format() const
{
	return d_ptr->format();
}

QString PortfolioStatisticsItem::description() const
{
	return d_ptr->description();
}

QString PortfolioStatisticsItem::category() const
{
	return d_ptr->category();
}

bool PortfolioStatisticsItem::show() const
{
	return d_ptr->show();
}

double PortfolioStatisticsItem::totalValue() const
{
	return d_ptr->totalValue();
}

double PortfolioStatisticsItem::longValue() const
{
	return d_ptr->longValue();
}

double PortfolioStatisticsItem::shortValue() const
{
	return d_ptr->shortValue();
}

TimeSeries PortfolioStatisticsItem::totalValues() const
{
	return d_ptr->totalValues();
}

TimeSeries PortfolioStatisticsItem::longValues() const
{
	return d_ptr->longValues();
}

TimeSeries PortfolioStatisticsItem::shortValues() const
{
	return d_ptr->shortValues();
}

Clock PortfolioStatisticsItem::clock() const
{
	return d_ptr->clock();
}

void PortfolioStatisticsItem::subscribe(int itemType)
{
	d_ptr->subscribe(itemType);
}

void PortfolioStatisticsItem::unsubscribe(int itemType)
{
	d_ptr->unsubscribe(itemType);
}

QDebug operator<<(QDebug dbg, const PortfolioStatisticsItem& portfoliostatisticsitem)
{
	return dbg << portfoliostatisticsitem.toString();
}

