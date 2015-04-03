#include <QuantKit/DataFilter.h>

#include <QuantKit/Framework.h>
#include "DataObject_p.h"
#include <QuantKit/Instrument.h>
#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/Trade.h>

namespace QuantKit {

class DataFilterPrivate : public QSharedData
{
public:
	Framework m_framework;
	Instrument instrument_0;
	Bid bid_0;
	Ask ask_0;
	Trade trade_0;

public:
	explicit DataFilterPrivate(const Framework& framework);
	virtual ~DataFilterPrivate();

public:
	virtual DataObject filter(const DataObject& obj) Q_DECL_OVERRIDE { return obj; }
	virtual DataFilterPrivate* clone() Q_DECL_OVERRIDE { return new DataFilterPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

DataFilterPrivate::DataFilterPrivate(const Framework& framework)
	: m_framework(framework)
{
}

DataFilterPrivate::~DataFilterPrivate ()
{
}


// Pubic API 

DataFilter::DataFilter(const Framework& framework)
	: d_ptr(new DataFilterPrivate(framework))
{
}

DataFilter::~DataFilter()
{
}

DataFilter::DataFilter (const DataFilter &other)
	: d_ptr(other.d_ptr)
{
}

DataFilter& DataFilter::operator=(const DataFilter &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool DataFilter::operator==(const DataFilter &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

DataObject DataFilter::filter(const DataObject& obj)
{
	return d_ptr->filter(obj);
}

QDebug operator<<(QDebug dbg, const DataFilter& datafilter)
{
	return dbg << datafilter.toString();
}

