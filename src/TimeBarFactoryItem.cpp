#include <QuantKit/TimeBarFactoryItem.h>

#include <QuantKit/Instrument.h>
#include "DataObject_p.h"
#include "BarFactoryItem_p.h"

namespace QuantKit {

class TimeBarFactoryItemPrivate : public BarFactoryItemPrivate
{
public:
	ClockType m_clockType;

public:
	TimeBarFactoryItemPrivate(const Instrument& instrument, long barSize, ClockType type);
	TimeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, ClockType type);
	TimeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	TimeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2);
	virtual ~TimeBarFactoryItemPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

TimeBarFactoryItemPrivate::TimeBarFactoryItemPrivate(const Instrument& instrument, long barSize, ClockType type)
	: BarFactoryItemPrivate (instrument, BarType.Time, barSize, BarInput.Trade)
	, m_clockType(type)
{
}

TimeBarFactoryItemPrivate::TimeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, ClockType type)
	: BarFactoryItemPrivate (instrument, BarType.Time, barSize, barInput)
	, m_clockType(type)
{
}

TimeBarFactoryItemPrivate::TimeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: BarFactoryItemPrivate (instrument, BarType.Tick, barSize, barInput, session1, session2)
{
}

TimeBarFactoryItemPrivate::TimeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, ClockType type, TimeSpan session1, TimeSpan session2)
	: BarFactoryItemPrivate (instrument, BarType.Time, barSize, barInput, session1, session2)
	, m_clockType(type)
{
}

TimeBarFactoryItemPrivate::~TimeBarFactoryItemPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(TimeBarFactoryItem)

TimeBarFactoryItem::TimeBarFactoryItem(const Instrument& instrument, long barSize, ClockType type)
	: BarFactoryItem(*new TimeBarFactoryItemPrivate(instrument, barSize, type))
{
}

TimeBarFactoryItem::TimeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, ClockType type)
	: BarFactoryItem(*new TimeBarFactoryItemPrivate(instrument, barSize, barInput, type))
{
}

TimeBarFactoryItem::TimeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: BarFactoryItem(*new TimeBarFactoryItemPrivate(instrument, barSize, barInput, session1, session2))
{
}

TimeBarFactoryItem::TimeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, ClockType type, TimeSpan session1, TimeSpan session2)
	: BarFactoryItem(*new TimeBarFactoryItemPrivate(instrument, barSize, barInput, type, session1, session2))
{
}

TimeBarFactoryItem::~TimeBarFactoryItem()
{
}


