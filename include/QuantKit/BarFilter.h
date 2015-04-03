#ifndef __QUANTKIT_BARFILTER_H__
#define __QUANTKIT_BARFILTER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QSharedDataPointer>

#include <QuantKit/BarType.h>

namespace QuantKit {

class BarFilterPrivate;

class BarFilterItem;

class QUANTKIT_EXPORT BarFilter
{
public:
	BarFilter();
	~BarFilter();

	BarFilter(const BarFilter &other);
	BarFilter& operator=(const BarFilter &other);
	bool operator==(const BarFilter &other) const;
	inline bool operator!=(const BarFilter &other) const { return !(this->operator==(other));  }
public:
	QList<BarFilterItem> items() const;
	int count() const;
	void add(BarType barType, long barSize);
	void clear();
	bool contains(BarType barType, long barSize);

private:
	QSharedDataPointer<BarFilterPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const BarFilter& barfilter);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const BarFilter& barfilter);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BarFilter)

#endif // __QUANTKIT_BARFILTER_H__
