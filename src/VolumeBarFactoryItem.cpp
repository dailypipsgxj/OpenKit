#include <QuantKit/VolumeBarFactoryItem.h>

#include <QuantKit/Instrument.h>
#include "DataObject_p.h"
#include "BarFactoryItem_p.h"

namespace QuantKit {

class VolumeBarFactoryItemPrivate : public BarFactoryItemPrivate
{
public:
	VolumeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput);
	VolumeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, const TimeSpan& session1, const TimeSpan& session2);
	virtual ~VolumeBarFactoryItemPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

VolumeBarFactoryItemPrivate::VolumeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput)
	: BarFactoryItemPrivate (instrument, BarType.Volume, barSize, barInput)
{
}

VolumeBarFactoryItemPrivate::VolumeBarFactoryItemPrivate(const Instrument& instrument, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: BarFactoryItemPrivate (instrument, BarType.Tick, barSize, barInput, session1, session2)
{
}

VolumeBarFactoryItemPrivate::~VolumeBarFactoryItemPrivate ()
{
}


// Pubic API 

VolumeBarFactoryItem::VolumeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput)
	: BarFactoryItem(*new VolumeBarFactoryItemPrivate(instrument, barSize, barInput))
{
}

VolumeBarFactoryItem::VolumeBarFactoryItem(const Instrument& instrument, long barSize, BarInput barInput, TimeSpan session1, TimeSpan session2)
	: BarFactoryItem(*new VolumeBarFactoryItemPrivate(instrument, barSize, barInput, session1, session2))
{
}

VolumeBarFactoryItem::~VolumeBarFactoryItem()
{
}


