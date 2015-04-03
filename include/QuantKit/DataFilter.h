#ifndef __QUANTKIT_DATAFILTER_H__
#define __QUANTKIT_DATAFILTER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class DataFilterPrivate;

class Framework;
class DataObject;
class Instrument;
class Bid;
class Ask;
class Trade;

class QUANTKIT_EXPORT DataFilter
{
public:
	explicit DataFilter(const Framework& framework);
	~DataFilter();

	DataFilter(const DataFilter &other);
	DataFilter& operator=(const DataFilter &other);
	bool operator==(const DataFilter &other) const;
	inline bool operator!=(const DataFilter &other) const { return !(this->operator==(other));  }
public:
	DataObject filter(const DataObject& obj);

private:
	QSharedDataPointer<DataFilterPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataFilter& datafilter);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataFilter& datafilter);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataFilter)

#endif // __QUANTKIT_DATAFILTER_H__
