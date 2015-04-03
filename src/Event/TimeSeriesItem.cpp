#include <QuantKit/Event/TimeSeriesItem.h>


#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class TimeSeriesItemPrivate : public DataObjectPrivate
{
public:
	double m_value;

public:
	TimeSeriesItemPrivate();
	TimeSeriesItemPrivate(const QDateTime& dateTime, double value) { m_entryDate = dateTime; }
	virtual ~TimeSeriesItemPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::TimeSeriesItem;
	}

	double value() const { return m_value; }
	virtual TimeSeriesItemPrivate* clone() Q_DECL_OVERRIDE { return new TimeSeriesItemPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TimeSeriesItemPrivate::TimeSeriesItemPrivate()
{
}

TimeSeriesItemPrivate::~TimeSeriesItemPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(TimeSeriesItem)

TimeSeriesItem::TimeSeriesItem()
	: DataObject(*new TimeSeriesItemPrivate)
{
}

TimeSeriesItem::TimeSeriesItem(const QDateTime& dateTime, double value)
	: DataObject(*new TimeSeriesItemPrivate(dateTime, value))
{
}

TimeSeriesItem::~TimeSeriesItem()
{
}

double TimeSeriesItem::value() const
{
	Q_D(const TimeSeriesItem);
	return d->value();
}


