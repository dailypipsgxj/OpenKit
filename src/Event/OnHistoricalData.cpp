#include <QuantKit/Event/OnHistoricalData.h>

#include <QuantKit/Event/HistoricalData.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnHistoricalDataPrivate : public EventPrivate
{
public:
	HistoricalData OfwgzekeqT;

public:
	explicit OnHistoricalDataPrivate(const HistoricalData& data);
	virtual ~OnHistoricalDataPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnHistoricalData;
	}

	virtual OnHistoricalDataPrivate* clone() Q_DECL_OVERRIDE { return new OnHistoricalDataPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnHistoricalDataPrivate::OnHistoricalDataPrivate(const HistoricalData& data)
	: OfwgzekeqT(data)
{
}

OnHistoricalDataPrivate::~OnHistoricalDataPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnHistoricalData)

OnHistoricalData::OnHistoricalData(const HistoricalData& data)
	: Event(*new OnHistoricalDataPrivate(data))
{
}

OnHistoricalData::~OnHistoricalData()
{
}


