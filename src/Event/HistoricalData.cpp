#include <QuantKit/Event/HistoricalData.h>

#include "DataObject_p.h"

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class HistoricalDataPrivate : public EventPrivate
{
public:
	QString m_requestId;
	int m_totalNum;
	DataObject m_objects;

public:
	HistoricalDataPrivate();
	virtual ~HistoricalDataPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::HistoricalData;
	}

	QString requestId() const { return m_requestId; }
	void setRequestId(const QString& value) { m_requestId = value; }
	int totalNum() const { return m_totalNum; }
	void setTotalNum(int value) { m_totalNum = value; }
	DataObject objects() const { return m_objects; }
	void setObjects(const DataObject& value) { m_objects = value; }
	virtual HistoricalDataPrivate* clone() Q_DECL_OVERRIDE { return new HistoricalDataPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

HistoricalDataPrivate::HistoricalDataPrivate()
{
}

HistoricalDataPrivate::~HistoricalDataPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(HistoricalData)

HistoricalData::HistoricalData()
	: Event(*new HistoricalDataPrivate)
{
}

HistoricalData::~HistoricalData()
{
}

QString HistoricalData::requestId() const
{
	Q_D(const HistoricalData);
	return d->requestId();
}

void HistoricalData::setRequestId(const QString& value)
{
	Q_D(HistoricalData);
	d->setRequestId(value);
}

int HistoricalData::totalNum() const
{
	Q_D(const HistoricalData);
	return d->totalNum();
}

void HistoricalData::setTotalNum(int value)
{
	Q_D(HistoricalData);
	d->setTotalNum(value);
}

DataObject HistoricalData::objects() const
{
	Q_D(const HistoricalData);
	return d->objects();
}

void HistoricalData::setObjects(DataObject value)
{
	Q_D(HistoricalData);
	d->setObjects(value);
}


