#ifndef __QUANTKIT_DATAOBJECT_H__
#define __QUANTKIT_DATAOBJECT_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class DataObjectPrivate;


class QUANTKIT_EXPORT DataObject : public Event
{
public:
	DataObject();
	explicit DataObject(const QDateTime& dateTime);
	~DataObject();

public:

protected:
	DataObject(DataObjectPrivate& dd);

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataObject)

#endif // __QUANTKIT_DATAOBJECT_H__
