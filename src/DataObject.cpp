#include <QuantKit/DataObject.h>


#include <QuantKit/EventType.h>
#include "DataObject_p.h"

using namespace QuantKit;

DataObjectPrivate::DataObjectPrivate()
{
}

DataObjectPrivate::~DataObjectPrivate ()
{
}


// Pubic API 

DataObject::DataObject()
	: Event(*new DataObjectPrivate)
{
}

DataObject::DataObject(const QDateTime& dateTime)
	: Event(*new DataObjectPrivate(dateTime))
{
}

DataObject::~DataObject()
{
}

DataObject::DataObject (DataObjectPrivate &dd)
	: Event(dd)
{
}


