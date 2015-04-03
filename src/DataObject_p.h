#ifndef __QUANTKIT_DATAOBJECT_PRIVATE_H__
#define __QUANTKIT_DATAOBJECT_PRIVATE_H__

#include <QuantKit/DataObject.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class DataObjectPrivate : public EventPrivate
{
public:
	DataObjectPrivate();
	explicit DataObjectPrivate(const QDateTime& dateTime) { m_entryDate = dateTime; }
	virtual ~DataObjectPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::DataObject; }
};

} // namepsace QuantKit

#endif // __QUANTKIT_DATAOBJECT_PRIVATE_H__
