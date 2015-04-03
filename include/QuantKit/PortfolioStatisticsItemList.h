#ifndef __QUANTKIT_PORTFOLIOSTATISTICSITEMLIST_H__
#define __QUANTKIT_PORTFOLIOSTATISTICSITEMLIST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class PortfolioStatisticsItemListPrivate;

class PortfolioStatisticsItem;
class IdArray;

class QUANTKIT_EXPORT PortfolioStatisticsItemList
{
public:
	PortfolioStatisticsItemList();
	~PortfolioStatisticsItemList();

	PortfolioStatisticsItemList(const PortfolioStatisticsItemList &other);
	PortfolioStatisticsItemList& operator=(const PortfolioStatisticsItemList &other);
	bool operator==(const PortfolioStatisticsItemList &other) const;
	inline bool operator!=(const PortfolioStatisticsItemList &other) const { return !(this->operator==(other));  }
public:
	int count() const;
	PortfolioStatisticsItem item(int index) const;
	void add(const PortfolioStatisticsItem& item);
	void clear();
	bool contains(int type);
	PortfolioStatisticsItem getByIndex(int index);
	PortfolioStatisticsItem getByType(int type);
	void remove(int type);

private:
	QSharedDataPointer<PortfolioStatisticsItemListPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const PortfolioStatisticsItemList& portfoliostatisticsitemlist);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const PortfolioStatisticsItemList& portfoliostatisticsitemlist);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PortfolioStatisticsItemList)

#endif // __QUANTKIT_PORTFOLIOSTATISTICSITEMLIST_H__
