#ifndef __QUANTKIT_VOLUMEBARFACTORYITEM_H__
#define __QUANTKIT_VOLUMEBARFACTORYITEM_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/BarFactoryItem.h>
#include <QuantKit/BarInput.h>

namespace QuantKit {

class VolumeBarFactoryItemPrivate;

class Instrument;
class DataObject;

class QUANTKIT_EXPORT VolumeBarFactoryItem Q_DECL_FINAL : public BarFactoryItem
{
public:
	VolumeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput = BarInput::Trade);
	VolumeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	~VolumeBarFactoryItem();


private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::VolumeBarFactoryItem)

#endif // __QUANTKIT_VOLUMEBARFACTORYITEM_H__
