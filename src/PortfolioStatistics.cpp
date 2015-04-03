#include <QuantKit/PortfolioStatistics.h>

#include <QuantKit/Portfolio.h>
#include <QuantKit/PortfolioStatisticsItemList.h>
#include "PortfolioStatisticsItem_p.h"
#include <QuantKit/Event/Fill.h>
#include <QuantKit/Transaction.h>
#include <QuantKit/Position.h>
#include <QuantKit/IdArray.h>
#include <QuantKit/TradeDetector.h>

namespace QuantKit {

class PortfolioStatisticsPrivate : public QSharedData
{
public:
	Portfolio portfolio_0;
	IdArray<TradeDetector> m_idArray;
	PortfolioStatisticsItemList m_items;
	IdArray<QList<int>> idArray_1;

public:
	explicit PortfolioStatisticsPrivate(const Portfolio& portfolio);
	virtual ~PortfolioStatisticsPrivate();

public:
	PortfolioStatisticsItemList items() const { return m_items; }
	void add(const PortfolioStatisticsItem& item);
	PortfolioStatisticsItem get(int type)
	{
		return m_items.GetByType(type);
	}

	virtual PortfolioStatisticsPrivate* clone() Q_DECL_OVERRIDE { return new PortfolioStatisticsPrivate(*this); }
//private:
	void method_2(const QVariant& sender, const EventArgs1& e);
};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioStatisticsPrivate::PortfolioStatisticsPrivate(const Portfolio& portfolio)
	: portfolio_0(portfolio)
	, m_idArray(new IdArray<TradeDetector>(10000))
	, m_items(new PortfolioStatisticsItemList())
	, idArray_1(new IdArray<QList<int>>(1000))
{
		List<PortfolioStatisticsItem> list = portfolio.clock().statisticsManager().CloneAll();
		foreach (PortfolioStatisticsItem current in list)
		{
			Add(current);
		}
}

PortfolioStatisticsPrivate::~PortfolioStatisticsPrivate ()
{
}

void PortfolioStatisticsPrivate::add(const PortfolioStatisticsItem& item)
{
	if (item.statistics() != null)
	{
		Console.WriteLine("PortfolioStatistics::Add Error. Item already belongs to other statistics " + item);
		return;
	}
	item.setStatistics() = this;
	item.setClock() = portfolio_0;
	m_items.Add(item);
	item.OnInit();
}

void PortfolioStatisticsPrivate::method_2(const QVariant& sender, const EventArgs1& e)
{
	TradeInfo trade = e.method_0();
	foreach (PortfolioStatisticsItem current in m_items)
	{
		current.OnRoundTrip(trade);
	}
}


// Pubic API 

PortfolioStatistics::PortfolioStatistics(const Portfolio& portfolio)
	: d_ptr(new PortfolioStatisticsPrivate(portfolio))
{
}

PortfolioStatistics::~PortfolioStatistics()
{
}

PortfolioStatistics::PortfolioStatistics (const PortfolioStatistics &other)
	: d_ptr(other.d_ptr)
{
}

PortfolioStatistics& PortfolioStatistics::operator=(const PortfolioStatistics &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PortfolioStatistics::operator==(const PortfolioStatistics &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

PortfolioStatisticsItemList PortfolioStatistics::items() const
{
	return d_ptr->items();
}

void PortfolioStatistics::add(const PortfolioStatisticsItem& item)
{
	d_ptr->add(item);
}

PortfolioStatisticsItem PortfolioStatistics::get(int type)
{
	return d_ptr->get(type);
}

QDebug operator<<(QDebug dbg, const PortfolioStatistics& portfoliostatistics)
{
	return dbg << portfoliostatistics.toString();
}

