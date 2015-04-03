#ifndef __QUANTKIT_PORTFOLIOSTATISTICSTYPE_H__
#define __QUANTKIT_PORTFOLIOSTATISTICSTYPE_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class PortfolioStatisticsTypePrivate;

class QUANTKIT_EXPORT PortfolioStatisticsType
{
public:
	PortfolioStatisticsType();
	~PortfolioStatisticsType();

	PortfolioStatisticsType(const PortfolioStatisticsType &other);
	PortfolioStatisticsType& operator=(const PortfolioStatisticsType &other);
	bool operator==(const PortfolioStatisticsType &other) const;
	inline bool operator!=(const PortfolioStatisticsType &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<PortfolioStatisticsTypePrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const PortfolioStatisticsType& portfoliostatisticstype);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PortfolioStatisticsType& portfoliostatisticstype);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioStatisticsType)

#endif // __QUANTKIT_PORTFOLIOSTATISTICSTYPE_H__
