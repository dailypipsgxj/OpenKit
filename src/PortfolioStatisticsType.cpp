#include <QuantKit/PortfolioStatisticsType.h>


namespace QuantKit {

class PortfolioStatisticsTypePrivate : public QSharedData
{
public:
	int NetProfit;
	int GrossProfit;
	int GrossLoss;
	int Drawdown;
	int DrawdownPercent;
	int AvgDrawdown;
	int AvgDrawdownPercent;
	int MaxDrawdown;
	int MaxDrawdownPercent;
	int ProfitFactor;
	int RecoveryFactor;
	int NumOfTrades;
	int NumOfWinTrades;
	int NumOfLossTrades;
	int ProfitablePercent;
	int TradesPnL;
	int WinTradesPnL;
	int LossTradesPnL;
	int AvgTrade;
	int AvgWinTrade;
	int AvgLossTrade;
	int PayoffRatio;
	int MaxAdverseExcursion;
	int MaxFavorableExcursion;
	int EndOfTradeDrawdown;
	int AvgMaxAdverseExcursion;
	int AvgMaxFavorableExcursion;
	int AvgEndOfTradeDrawdown;
	int ConsecutiveWinTrades;
	int ConsecutiveLossTrades;
	int MaxConsecutiveWinTrades;
	int MaxConsecutiveLossTrades;
	int TradesDuration;
	int AvgTradesDuration;
	int AnnualReturn;
	int DailyReturnPercent;
	int AnnualReturnPercent;
	int AvgDailyReturnPercent;
	int AvgAnnualReturnPercent;
	int DailyReturnPercentStdDev;
	int AnnualReturnPercentStdDev;
	int DailyDownsideRisk;
	int AnnualDownsideRisk;
	int SharpeRatio;
	int SortinoRatio;
	int CompoundAnnualGrowthRate;
	int MARRatio;
	int ValueAtRisk;

public:
	PortfolioStatisticsTypePrivate();
	virtual ~PortfolioStatisticsTypePrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioStatisticsTypePrivate::PortfolioStatisticsTypePrivate()
{
}

PortfolioStatisticsTypePrivate::~PortfolioStatisticsTypePrivate ()
{
}


// Pubic API 

PortfolioStatisticsType::PortfolioStatisticsType()
	: d_ptr(new PortfolioStatisticsTypePrivate)
{
}

PortfolioStatisticsType::~PortfolioStatisticsType()
{
}

PortfolioStatisticsType::PortfolioStatisticsType (const PortfolioStatisticsType &other)
	: d_ptr(other.d_ptr)
{
}

PortfolioStatisticsType& PortfolioStatisticsType::operator=(const PortfolioStatisticsType &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PortfolioStatisticsType::operator==(const PortfolioStatisticsType &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const PortfolioStatisticsType& portfoliostatisticstype)
{
	return dbg << portfoliostatisticstype.toString();
}

