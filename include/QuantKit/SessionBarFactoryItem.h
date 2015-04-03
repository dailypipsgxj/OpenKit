#ifndef __QUANTKIT_SESSIONBARFACTORYITEM_H__
#define __QUANTKIT_SESSIONBARFACTORYITEM_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>

#include <QuantKit/BarFactoryItem.h>
#include <QuantKit/BarInput.h>
#include <QuantKit/ClockType.h>

namespace QuantKit {

class SessionBarFactoryItemPrivate;

class Instrument;
class DataObject;

class QUANTKIT_EXPORT SessionBarFactoryItem Q_DECL_FINAL : public BarFactoryItem
{
public:
	SessionBarFactoryItem(const Instrument& instrument, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	SessionBarFactoryItem(const Instrument& instrument, BarInput barInput, ClockType type, const TimeSpan& session1, const TimeSpan& session2);
	~SessionBarFactoryItem();


private:
	QK_DECLARE_PRIVATE(SessionBarFactoryItem)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::SessionBarFactoryItem)

#endif // __QUANTKIT_SESSIONBARFACTORYITEM_H__
