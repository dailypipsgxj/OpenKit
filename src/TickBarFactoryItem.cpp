#include <QuantKit/TickBarFactoryItem.h>

#include <QuantKit/Instrument.h>
#include "DataObject_p.h"
#include "BarFactoryItem_p.h"

namespace QuantKit {

class TickBarFactoryItemPrivate : public BarFactoryItemPrivate
{
public:
	TickBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput);
	TickBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	virtual ~TickBarFactoryItemPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

TickBarFactoryItemPrivate::TickBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput)
	: BarFactoryItemPrivate (instrument, BarType.Tick, barSize, barInput)
{
}

TickBarFactoryItemPrivate::TickBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: BarFactoryItemPrivate (instrument, BarType.Tick, barSize, barInput, session1, session2)
{
}

TickBarFactoryItemPrivate::~TickBarFactoryItemPrivate ()
{
}


// Pubic API 

TickBarFactoryItem::TickBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput)
	: BarFactoryItem(*new TickBarFactoryItemPrivate(instrument, barSize, barInput))
{
}

TickBarFactoryItem::TickBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: BarFactoryItem(*new TickBarFactoryItemPrivate(instrument, barSize, barInput, session1, session2))
{
}

TickBarFactoryItem::~TickBarFactoryItem()
{
}


