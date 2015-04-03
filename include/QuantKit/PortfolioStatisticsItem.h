#ifndef __QUANTKIT_PORTFOLIOSTATISTICSITEM_H__
#define __QUANTKIT_PORTFOLIOSTATISTICSITEM_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class PortfolioStatisticsItemPrivate;

class TimeSeries;
class Clock;
class Fill;
class Transaction;
class Position;
class TradeInfo;
class Portfolio;
class PortfolioStatistics;

class QUANTKIT_EXPORT PortfolioStatisticsItem
{
public:
	PortfolioStatisticsItem();
	~PortfolioStatisticsItem();

	PortfolioStatisticsItem(const PortfolioStatisticsItem &other);
	PortfolioStatisticsItem& operator=(const PortfolioStatisticsItem &other);
	bool operator==(const PortfolioStatisticsItem &other) const;
	inline bool operator!=(const PortfolioStatisticsItem &other) const { return !(this->operator==(other));  }
public:
	PortfolioStatistics statistics() const;
	void setStatistics(PortfolioStatistics value);
	int type() const;
	QString name() const;
	QString format() const;
	QString description() const;
	QString category() const;
	bool show() const;
	double totalValue() const;
	double longValue() const;
	double shortValue() const;
	TimeSeries totalValues() const;
	TimeSeries longValues() const;
	TimeSeries shortValues() const;
	Clock clock() const;
	void subscribe(int itemType);
	void unsubscribe(int itemType);

protected:
	PortfolioStatisticsItem(PortfolioStatisticsItemPrivate& dd);
	QSharedDataPointer<PortfolioStatisticsItemPrivate> d_ptr;

private:
	friend QDebug operator<<(QDebug dbg, const PortfolioStatisticsItem& portfoliostatisticsitem);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PortfolioStatisticsItem& portfoliostatisticsitem);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioStatisticsItem)

#endif // __QUANTKIT_PORTFOLIOSTATISTICSITEM_H__
