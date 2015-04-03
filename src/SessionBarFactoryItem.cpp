#include <QuantKit/SessionBarFactoryItem.h>

#include <QuantKit/Instrument.h>
#include "DataObject_p.h"
#include "BarFactoryItem_p.h"

namespace QuantKit {

class SessionBarFactoryItemPrivate : public BarFactoryItemPrivate
{
public:
	ClockType clockType_0;

public:
	SessionBarFactoryItemPrivate(const Instrument& instrument, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	SessionBarFactoryItemPrivate(const Instrument& instrument, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2);
	virtual ~SessionBarFactoryItemPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

SessionBarFactoryItemPrivate::SessionBarFactoryItemPrivate(const Instrument& instrument, BarInput barInput, TimeSpan session1, TimeSpan session2)
{
}

SessionBarFactoryItemPrivate::SessionBarFactoryItemPrivate(const Instrument& instrument, BarInput barInput, ClockType type, TimeSpan session1, TimeSpan session2)
	: clockType_0(type)
{
}

SessionBarFactoryItemPrivate::~SessionBarFactoryItemPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(SessionBarFactoryItem)

SessionBarFactoryItem::SessionBarFactoryItem(const Instrument& instrument, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: BarFactoryItem(*new SessionBarFactoryItemPrivate(instrument, barInput, session1, session2))
{
}

SessionBarFactoryItem::SessionBarFactoryItem(const Instrument& instrument, BarInput barInput, ClockType type, TimeSpan session1, TimeSpan session2)
	: BarFactoryItem(*new SessionBarFactoryItemPrivate(instrument, barInput, type, session1, session2))
{
}

SessionBarFactoryItem::~SessionBarFactoryItem()
{
}


