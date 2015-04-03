#ifndef __QUANTKIT_DATASERIESITERATOR_H__
#define __QUANTKIT_DATASERIESITERATOR_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class DataSeriesIteratorPrivate;

class DataSeries;
class DataObject;

class QUANTKIT_EXPORT DataSeriesIterator
{
public:
	DataSeriesIterator(const DataSeries& series, long index1 = -1, long index2 = -1);
	~DataSeriesIterator();

	DataSeriesIterator(const DataSeriesIterator &other);
	DataSeriesIterator& operator=(const DataSeriesIterator &other);
	bool operator==(const DataSeriesIterator &other) const;
	inline bool operator!=(const DataSeriesIterator &other) const { return !(this->operator==(other));  }
public:
	DataObject getNext();

private:
	QSharedDataPointer<DataSeriesIteratorPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const DataSeriesIterator& dataseriesiterator);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const DataSeriesIterator& dataseriesiterator);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataSeriesIterator)

#endif // __QUANTKIT_DATASERIESITERATOR_H__
