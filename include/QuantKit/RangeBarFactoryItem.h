#ifndef __QUANTKIT_RANGEBARFACTORYITEM_H__
#define __QUANTKIT_RANGEBARFACTORYITEM_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/BarFactoryItem.h>
#include <QuantKit/BarInput.h>

namespace QuantKit {

class RangeBarFactoryItemPrivate;

class Instrument;
class DataObject;

class QUANTKIT_EXPORT RangeBarFactoryItem Q_DECL_FINAL : public BarFactoryItem
{
public:
	RangeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput = BarInput::Trade);
	RangeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	~RangeBarFactoryItem();


private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::RangeBarFactoryItem)

#endif // __QUANTKIT_RANGEBARFACTORYITEM_H__
