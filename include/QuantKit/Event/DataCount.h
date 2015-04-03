#ifndef __QUANTKIT_DATACOUNT_H__
#define __QUANTKIT_DATACOUNT_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/Event.h>

namespace QuantKit {

class DataCountPrivate;

class QUANTKIT_EXPORT DataCount Q_DECL_FINAL : public Event
{
public:
	DataCount();
	explicit DataCount(const QDateTime& dateTime);
	explicit DataCount(int instrumentId);
	~DataCount();


private:
	QK_DECLARE_PRIVATE(DataCount)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataCount)

#endif // __QUANTKIT_DATACOUNT_H__
