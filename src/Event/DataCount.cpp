#include <QuantKit/Event/DataCount.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class DataCountPrivate : public EventPrivate
{
public:
	int m_instrumentId;
	int m_bid;
	int m_ask;
	int m_trade;
	int m_level2;

public:
	DataCountPrivate();
	explicit DataCountPrivate(const QDateTime& dateTime);
	explicit DataCountPrivate(int instrumentId);
	virtual ~DataCountPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

DataCountPrivate::DataCountPrivate()
{
}

DataCountPrivate::DataCountPrivate(const QDateTime& dateTime)
	: EventPrivate (dateTime)
{
}

DataCountPrivate::DataCountPrivate(int instrumentId)
	: m_instrumentId(instrumentId)
{
}

DataCountPrivate::~DataCountPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(DataCount)

DataCount::DataCount()
	: Event(*new DataCountPrivate)
{
}

DataCount::DataCount(const QDateTime& dateTime)
	: Event(*new DataCountPrivate(dateTime))
{
}

DataCount::DataCount(int instrumentId)
	: Event(*new DataCountPrivate(instrumentId))
{
}

DataCount::~DataCount()
{
}


