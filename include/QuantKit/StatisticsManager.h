#ifndef __QUANTKIT_STATISTICSMANAGER_H__
#define __QUANTKIT_STATISTICSMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class StatisticsManagerPrivate;

class PortfolioStatisticsItemList;
class Framework;
class PortfolioStatisticsItem;

class QUANTKIT_EXPORT StatisticsManager
{
public:
	explicit StatisticsManager(const Framework& framework);
	~StatisticsManager();

	StatisticsManager(const StatisticsManager &other);
	StatisticsManager& operator=(const StatisticsManager &other);
	bool operator==(const StatisticsManager &other) const;
	inline bool operator!=(const StatisticsManager &other) const { return !(this->operator==(other));  }
public:
	PortfolioStatisticsItemList statistics() const;
	void add(const PortfolioStatisticsItem& item);
	PortfolioStatisticsItem clone(int type);
	QList<PortfolioStatisticsItem> cloneAll();
	bool contains(int type);
	PortfolioStatisticsItem get(int type);
	void remove(int type);

private:
	QSharedDataPointer<StatisticsManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const StatisticsManager& statisticsmanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const StatisticsManager& statisticsmanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::StatisticsManager)

#endif // __QUANTKIT_STATISTICSMANAGER_H__
