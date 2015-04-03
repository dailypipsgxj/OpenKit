#ifndef __QUANTKIT_PORTFOLIOSTATISTICS_H__
#define __QUANTKIT_PORTFOLIOSTATISTICS_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class PortfolioStatisticsPrivate;

class Portfolio;
class PortfolioStatisticsItemList;
class PortfolioStatisticsItem;
class Fill;
class Transaction;
class Position;
class IdArray;
class TradeDetector;

class QUANTKIT_EXPORT PortfolioStatistics
{
public:
	explicit PortfolioStatistics(const Portfolio& portfolio);
	~PortfolioStatistics();

	PortfolioStatistics(const PortfolioStatistics &other);
	PortfolioStatistics& operator=(const PortfolioStatistics &other);
	bool operator==(const PortfolioStatistics &other) const;
	inline bool operator!=(const PortfolioStatistics &other) const { return !(this->operator==(other));  }
public:
	PortfolioStatisticsItemList items() const;
	void add(const PortfolioStatisticsItem& item);
	PortfolioStatisticsItem get(int type);

private:
	QSharedDataPointer<PortfolioStatisticsPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const PortfolioStatistics& portfoliostatistics);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PortfolioStatistics& portfoliostatistics);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioStatistics)

#endif // __QUANTKIT_PORTFOLIOSTATISTICS_H__
