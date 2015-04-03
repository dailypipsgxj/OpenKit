#ifndef __QUANTKIT_BARFILTERITEM_H__
#define __QUANTKIT_BARFILTERITEM_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

#include <QuantKit/BarType.h>

namespace QuantKit {

class BarFilterItemPrivate;

class QUANTKIT_EXPORT BarFilterItem
{
public:
	BarFilterItem(BarType barType, long barSize);
	~BarFilterItem();

	BarFilterItem(const BarFilterItem &other);
	BarFilterItem& operator=(const BarFilterItem &other);
	bool operator==(const BarFilterItem &other) const;
	inline bool operator!=(const BarFilterItem &other) const { return !(this->operator==(other));  }
public:
	BarType barType() const;
	void setBarType(BarType value);
	long barSize() const;
	void setBarSize(long value);

private:
	QSharedDataPointer<BarFilterItemPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const BarFilterItem& barfilteritem);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const BarFilterItem& barfilteritem);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BarFilterItem)

#endif // __QUANTKIT_BARFILTERITEM_H__
