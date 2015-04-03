#include <QuantKit/StatisticsManager.h>

#include <QuantKit/PortfolioStatisticsItemList.h>
#include <QuantKit/Framework.h>
#include "PortfolioStatisticsItem_p.h"

namespace QuantKit {

class StatisticsManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	PortfolioStatisticsItemList m_statistics;

public:
	explicit StatisticsManagerPrivate(const Framework& framework);
	virtual ~StatisticsManagerPrivate();

public:
	PortfolioStatisticsItemList statistics() const { return m_statistics; }
	void add(const PortfolioStatisticsItem& item) { m_statistics.Add(item); }
	PortfolioStatisticsItem clone(int type)
	{
		return (PortfolioStatisticsItem)Activator.CreateInstance(Get(type).GetType());
	}

	QList<PortfolioStatisticsItem> cloneAll();
	bool contains(int type)
	{
		return m_statistics.Contains(type);
	}

	PortfolioStatisticsItem get(int type)
	{
		return m_statistics.GetByType(type);
	}

	void remove(int type) { m_statistics.Remove(type); }
	virtual StatisticsManagerPrivate* clone() Q_DECL_OVERRIDE { return new StatisticsManagerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

StatisticsManagerPrivate::StatisticsManagerPrivate(const Framework& framework)
	: m_framework(framework)
	, m_statistics(new PortfolioStatisticsItemList())
{
		NetProfit item = new NetProfit();
		GrossProfit item2 = new GrossProfit();
		GrossLoss item3 = new GrossLoss();
		Drawdown item4 = new Drawdown();
		DrawdownPercent item5 = new DrawdownPercent();
		AvgDrawdown item6 = new AvgDrawdown();
		AvgDrawdownPercent item7 = new AvgDrawdownPercent();
		MaxDrawdown item8 = new MaxDrawdown();
		MaxDrawdownPercent item9 = new MaxDrawdownPercent();
		ProfitFactor item10 = new ProfitFactor();
		RecoveryFactor item11 = new RecoveryFactor();
		NumOfTrades item12 = new NumOfTrades();
		NumOfWinTrades item13 = new NumOfWinTrades();
		NumOfLossTrades item14 = new NumOfLossTrades();
		ProfitablePercent item15 = new ProfitablePercent();
		TradesPnL item16 = new TradesPnL();
		WinTradesPnL item17 = new WinTradesPnL();
		LossTradesPnL item18 = new LossTradesPnL();
		AvgTrade item19 = new AvgTrade();
		AvgWinTrade item20 = new AvgWinTrade();
		AvgLossTrade item21 = new AvgLossTrade();
		PayoffRatio item22 = new PayoffRatio();
		MaxAdverseExcursion item23 = new MaxAdverseExcursion();
		MaxFavorableExcursion item24 = new MaxFavorableExcursion();
		EndOfTradeDrawdown item25 = new EndOfTradeDrawdown();
		AvgMaxAdverseExcursion item26 = new AvgMaxAdverseExcursion();
		AvgMaxFavorableExcursion item27 = new AvgMaxFavorableExcursion();
		AvgEndOfTradeDrawdown item28 = new AvgEndOfTradeDrawdown();
		ConsecutiveWinTrades item29 = new ConsecutiveWinTrades();
		ConsecutiveLossTrades item30 = new ConsecutiveLossTrades();
		MaxConsecutiveWinTrades item31 = new MaxConsecutiveWinTrades();
		MaxConsecutiveLossTrades item32 = new MaxConsecutiveLossTrades();
		TradesDuration item33 = new TradesDuration();
		AvgTradesDuration item34 = new AvgTradesDuration();
		AnnualReturn item35 = new AnnualReturn();
		DailyReturnPercent item36 = new DailyReturnPercent();
		AnnualReturnPercent item37 = new AnnualReturnPercent();
		AvgDailyReturnPercent item38 = new AvgDailyReturnPercent();
		AvgAnnualReturnPercent item39 = new AvgAnnualReturnPercent();
		DailyReturnPercentStdDev item40 = new DailyReturnPercentStdDev();
		AnnualReturnPercentStdDev item41 = new AnnualReturnPercentStdDev();
		DailyReturnPercentDownsideRisk item42 = new DailyReturnPercentDownsideRisk();
		AnnualReturnPercentDownsideRisk item43 = new AnnualReturnPercentDownsideRisk();
		SharpeRatio item44 = new SharpeRatio();
		SortinoRatio item45 = new SortinoRatio();
		CompoundAnnualGrowthRate item46 = new CompoundAnnualGrowthRate();
		MARRatio item47 = new MARRatio();
		ValueAtRisk item48 = new ValueAtRisk();
		Add(item);
		Add(item2);
		Add(item3);
		Add(item4);
		Add(item5);
		Add(item6);
		Add(item7);
		Add(item8);
		Add(item9);
		Add(item10);
		Add(item11);
		Add(item12);
		Add(item13);
		Add(item14);
		Add(item15);
		Add(item16);
		Add(item17);
		Add(item18);
		Add(item19);
		Add(item20);
		Add(item21);
		Add(item22);
		Add(item23);
		Add(item24);
		Add(item25);
		Add(item26);
		Add(item27);
		Add(item28);
		Add(item29);
		Add(item30);
		Add(item31);
		Add(item32);
		Add(item33);
		Add(item34);
		Add(item35);
		Add(item36);
		Add(item37);
		Add(item38);
		Add(item39);
		Add(item40);
		Add(item41);
		Add(item42);
		Add(item43);
		Add(item44);
		Add(item45);
		Add(item46);
		Add(item47);
		Add(item48);
}

StatisticsManagerPrivate::~StatisticsManagerPrivate ()
{
}

QList<PortfolioStatisticsItem> StatisticsManagerPrivate::cloneAll()
{
	List<PortfolioStatisticsItem> list = new List<PortfolioStatisticsItem>();
	foreach (PortfolioStatisticsItem current in m_statistics)
	{
		PortfolioStatisticsItem item = (PortfolioStatisticsItem)Activator.CreateInstance(current.GetType());
		list.Add(item);
	}
	return list;
}


// Pubic API 

StatisticsManager::StatisticsManager(const Framework& framework)
	: d_ptr(new StatisticsManagerPrivate(framework))
{
}

StatisticsManager::~StatisticsManager()
{
}

StatisticsManager::StatisticsManager (const StatisticsManager &other)
	: d_ptr(other.d_ptr)
{
}

StatisticsManager& StatisticsManager::operator=(const StatisticsManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool StatisticsManager::operator==(const StatisticsManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

PortfolioStatisticsItemList StatisticsManager::statistics() const
{
	return d_ptr->statistics();
}

void StatisticsManager::add(const PortfolioStatisticsItem& item)
{
	d_ptr->add(item);
}

PortfolioStatisticsItem StatisticsManager::clone(int type)
{
	return d_ptr->clone(type);
}

QList<PortfolioStatisticsItem> StatisticsManager::cloneAll()
{
	return d_ptr->cloneAll();
}

bool StatisticsManager::contains(int type)
{
	return d_ptr->contains(type);
}

PortfolioStatisticsItem StatisticsManager::get(int type)
{
	return d_ptr->get(type);
}

void StatisticsManager::remove(int type)
{
	d_ptr->remove(type);
}

QDebug operator<<(QDebug dbg, const StatisticsManager& statisticsmanager)
{
	return dbg << statisticsmanager.toString();
}

