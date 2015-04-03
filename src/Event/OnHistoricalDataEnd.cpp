#include <QuantKit/Event/OnHistoricalDataEnd.h>

#include <QuantKit/Event/HistoricalDataEnd.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnHistoricalDataEndPrivate : public EventPrivate
{
public:
	HistoricalDataEnd m_historicalDataEnd;

public:
	explicit OnHistoricalDataEndPrivate(const HistoricalDataEnd& end);
	virtual ~OnHistoricalDataEndPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnHistoricalDataEnd;
	}

	virtual OnHistoricalDataEndPrivate* clone() Q_DECL_OVERRIDE { return new OnHistoricalDataEndPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnHistoricalDataEndPrivate::OnHistoricalDataEndPrivate(const HistoricalDataEnd& end)
	: m_historicalDataEnd(end)
{
}

OnHistoricalDataEndPrivate::~OnHistoricalDataEndPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnHistoricalDataEnd)

OnHistoricalDataEnd::OnHistoricalDataEnd(const HistoricalDataEnd& end)
	: Event(*new OnHistoricalDataEndPrivate(end))
{
}

OnHistoricalDataEnd::~OnHistoricalDataEnd()
{
}


