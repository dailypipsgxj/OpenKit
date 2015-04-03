#include <QuantKit/Event/HistoricalDataEnd.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class HistoricalDataEndPrivate : public EventPrivate
{
public:
	QString m_requestId;
	RequestResult m_result;
	QString m_text;

public:
	HistoricalDataEndPrivate();
	virtual ~HistoricalDataEndPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::HistoricalDataEnd;
	}

	QString requestId() const { return m_requestId; }
	void setRequestId(const QString& value) { m_requestId = value; }
	RequestResult result() const { return m_result; }
	void setResult(RequestResult value) { m_result = value; }
	QString text() const { return m_text; }
	void setText(const QString& value) { m_text = value; }
	virtual HistoricalDataEndPrivate* clone() Q_DECL_OVERRIDE { return new HistoricalDataEndPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

HistoricalDataEndPrivate::HistoricalDataEndPrivate()
{
}

HistoricalDataEndPrivate::~HistoricalDataEndPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(HistoricalDataEnd)

HistoricalDataEnd::HistoricalDataEnd()
	: Event(*new HistoricalDataEndPrivate)
{
}

HistoricalDataEnd::~HistoricalDataEnd()
{
}

QString HistoricalDataEnd::requestId() const
{
	Q_D(const HistoricalDataEnd);
	return d->requestId();
}

void HistoricalDataEnd::setRequestId(const QString& value)
{
	Q_D(HistoricalDataEnd);
	d->setRequestId(value);
}

RequestResult HistoricalDataEnd::result() const
{
	Q_D(const HistoricalDataEnd);
	return d->result();
}

void HistoricalDataEnd::setResult(RequestResult value)
{
	Q_D(HistoricalDataEnd);
	d->setResult(value);
}

QString HistoricalDataEnd::text() const
{
	Q_D(const HistoricalDataEnd);
	return d->text();
}

void HistoricalDataEnd::setText(const QString& value)
{
	Q_D(HistoricalDataEnd);
	d->setText(value);
}


