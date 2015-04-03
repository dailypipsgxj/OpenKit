#ifndef __QUANTKIT_PORTFOLIOPERFORMANCE_H__
#define __QUANTKIT_PORTFOLIOPERFORMANCE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QDateTime>
#include <QSharedDataPointer>

namespace QuantKit {

class PortfolioPerformancePrivate;

class TimeSeries;
class Portfolio;

class QUANTKIT_EXPORT PortfolioPerformance
{
public:
	explicit PortfolioPerformance(const Portfolio& portfolio);
	~PortfolioPerformance();

	PortfolioPerformance(const PortfolioPerformance &other);
	PortfolioPerformance& operator=(const PortfolioPerformance &other);
	bool operator==(const PortfolioPerformance &other) const;
	inline bool operator!=(const PortfolioPerformance &other) const { return !(this->operator==(other));  }
public:
	TimeSeries equitySeries() const;
	TimeSeries drawdownSeries() const;
	void addUpdated(const EventHandler& value);
	void removeUpdated(const EventHandler& value);
	void reset();
	void update();

private:
	QSharedDataPointer<PortfolioPerformancePrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const PortfolioPerformance& portfolioperformance);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PortfolioPerformance& portfolioperformance);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioPerformance)

#endif // __QUANTKIT_PORTFOLIOPERFORMANCE_H__
