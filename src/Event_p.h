#ifndef __QUANTKIT_EVENT_PRIVATE_H__
#define __QUANTKIT_EVENT_PRIVATE_H__

#include <QuantKit/Event.h>

#include <QSharedData>

#include <QuantKit/EventType.h>

namespace QuantKit {

class EventPrivate : public QSharedData
{
public:
	QDateTime m_entryDate;

public:
	EventPrivate();
	explicit EventPrivate(const QDateTime& dateTime);
	virtual ~EventPrivate();

public:
	QDateTime dateTime() const { return m_entryDate; }
	void setDateTime(const QDateTime& value) { m_entryDate = value; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Event; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "Event"; }
};

} // namepsace QuantKit

#endif // __QUANTKIT_EVENT_PRIVATE_H__
