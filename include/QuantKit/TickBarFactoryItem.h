#ifndef __QUANTKIT_TICKBARFACTORYITEM_H__
#define __QUANTKIT_TICKBARFACTORYITEM_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/BarFactoryItem.h>
#include <QuantKit/BarInput.h>

namespace QuantKit {

class TickBarFactoryItemPrivate;

class Instrument;
class DataObject;

class QUANTKIT_EXPORT TickBarFactoryItem Q_DECL_FINAL : public BarFactoryItem
{
public:
	TickBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput = BarInput::Trade);
	TickBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	~TickBarFactoryItem();


private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TickBarFactoryItem)

#endif // __QUANTKIT_TICKBARFACTORYITEM_H__
