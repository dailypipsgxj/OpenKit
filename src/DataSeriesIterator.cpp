#include <QuantKit/DataSeriesIterator.h>

#include "DataSeries_p.h"
#include "DataObject_p.h"

namespace QuantKit {

class DataSeriesIteratorPrivate : public QSharedData
{
public:
	DataSeries dataSeries_0;
	long long_0;
	long long_1;
	long long_2;

public:
	DataSeriesIteratorPrivate(const DataSeries& series, long index1, long index2);
	virtual ~DataSeriesIteratorPrivate();

public:
	DataObject getNext();
	virtual DataSeriesIteratorPrivate* clone() Q_DECL_OVERRIDE { return new DataSeriesIteratorPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataSeriesIteratorPrivate::DataSeriesIteratorPrivate(const DataSeries& series, long index1, long index2)
	: dataSeries_0(series)
	, long_0(0L)
	, long_0(index1)
	, long_1(series.count() - 1L)
	, long_1(index2)
	, long_2(index1)
{
		if (index1 == -1L)
		{
		}
		else
		{
		}
		if (index2 == -1L)
		{
		}
		else
		{
		}
}

DataSeriesIteratorPrivate::~DataSeriesIteratorPrivate ()
{
}

DataObject DataSeriesIteratorPrivate::getNext()
{
	if (long_2 > long_1)
	{
		return null;
	}
	DataSeries arg_2F_0 = dataSeries_0;
	long index;
	long_2 = (index = long_2) + 1L;
	return arg_2F_0.Get(index);
}


// Pubic API 

DataSeriesIterator::DataSeriesIterator(const DataSeries& series, long index1, long index2)
	: d_ptr(new DataSeriesIteratorPrivate(series, index1, index2))
{
}

DataSeriesIterator::~DataSeriesIterator()
{
}

DataSeriesIterator::DataSeriesIterator (const DataSeriesIterator &other)
	: d_ptr(other.d_ptr)
{
}

DataSeriesIterator& DataSeriesIterator::operator=(const DataSeriesIterator &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataSeriesIterator::operator==(const DataSeriesIterator &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

DataObject DataSeriesIterator::getNext()
{
	return d_ptr->getNext();
}

QDebug operator<<(QDebug dbg, const DataSeriesIterator& dataseriesiterator)
{
	return dbg << dataseriesiterator.toString();
}

