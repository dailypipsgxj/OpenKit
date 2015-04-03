#include <QuantKit/RangeBarFactoryItem.h>

#include <QuantKit/Instrument.h>
#include "DataObject_p.h"
#include "BarFactoryItem_p.h"

namespace QuantKit {

class RangeBarFactoryItemPrivate : public BarFactoryItemPrivate
{
public:
	RangeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput);
	RangeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	virtual ~RangeBarFactoryItemPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

RangeBarFactoryItemPrivate::RangeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput)
	: BarFactoryItemPrivate (instrument, BarType.Range, barSize, barInput)
{
}

RangeBarFactoryItemPrivate::RangeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: BarFactoryItemPrivate (instrument, BarType.Tick, barSize, barInput, session1, session2)
{
}

RangeBarFactoryItemPrivate::~RangeBarFactoryItemPrivate ()
{
}


// Pubic API 

RangeBarFactoryItem::RangeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput)
	: BarFactoryItem(*new RangeBarFactoryItemPrivate(instrument, barSize, barInput))
{
}

RangeBarFactoryItem::RangeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: BarFactoryItem(*new RangeBarFactoryItemPrivate(instrument, barSize, barInput, session1, session2))
{
}

RangeBarFactoryItem::~RangeBarFactoryItem()
{
}


