#ifndef __QUANTKIT_STRATEGYLIST_H__
#define __QUANTKIT_STRATEGYLIST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class StrategyListPrivate;

class Strategy;
class IdArray;

class QUANTKIT_EXPORT StrategyList
{
public:
	StrategyList();
	~StrategyList();

	StrategyList(const StrategyList &other);
	StrategyList& operator=(const StrategyList &other);
	bool operator==(const StrategyList &other) const;
	inline bool operator!=(const StrategyList &other) const { return !(this->operator==(other));  }
public:
	int count() const;
	Strategy item(int index) const;
	void setItem(int index, const Strategy& value);
	void add(const Strategy& strategy);
	void clear();
	bool contains(const Strategy& strategy);
	bool contains(int id);
	Strategy getById(int id);
	Strategy getByIndex(int index);
	void remove(const Strategy& strategy);

private:
	QSharedDataPointer<StrategyListPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const StrategyList& strategylist);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const StrategyList& strategylist);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::StrategyList)

#endif // __QUANTKIT_STRATEGYLIST_H__
