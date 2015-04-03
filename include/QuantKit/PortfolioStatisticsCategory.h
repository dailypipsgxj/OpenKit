#ifndef __QUANTKIT_PORTFOLIOSTATISTICSCATEGORY_H__
#define __QUANTKIT_PORTFOLIOSTATISTICSCATEGORY_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class PortfolioStatisticsCategoryPrivate;

class QUANTKIT_EXPORT PortfolioStatisticsCategory
{
public:
	PortfolioStatisticsCategory();
	~PortfolioStatisticsCategory();

	PortfolioStatisticsCategory(const PortfolioStatisticsCategory &other);
	PortfolioStatisticsCategory& operator=(const PortfolioStatisticsCategory &other);
	bool operator==(const PortfolioStatisticsCategory &other) const;
	inline bool operator!=(const PortfolioStatisticsCategory &other) const { return !(this->operator==(other));  }

private:
	QSharedDataPointer<PortfolioStatisticsCategoryPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const PortfolioStatisticsCategory& portfoliostatisticscategory);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PortfolioStatisticsCategory& portfoliostatisticscategory);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioStatisticsCategory)

#endif // __QUANTKIT_PORTFOLIOSTATISTICSCATEGORY_H__
