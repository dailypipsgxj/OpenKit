#ifndef __QUANTKIT_TIMEBARFACTORYITEM_H__
#define __QUANTKIT_TIMEBARFACTORYITEM_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/BarFactoryItem.h>
#include <QuantKit/BarInput.h>
#include <QuantKit/ClockType.h>

namespace QuantKit {

class TimeBarFactoryItemPrivate;

class Instrument;
class DataObject;

class QUANTKIT_EXPORT TimeBarFactoryItem Q_DECL_FINAL : public BarFactoryItem
{
public:
	TimeBarFactoryItem(const Instrument& instrument, long barSize, ClockType type = ClockType::Local);
	TimeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput = BarInput::Trade, ClockType type = ClockType::Local);
	TimeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	TimeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2);
	~TimeBarFactoryItem();


private:
	QK_DECLARE_PRIVATE(TimeBarFactoryItem)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TimeBarFactoryItem)

#endif // __QUANTKIT_TIMEBARFACTORYITEM_H__
