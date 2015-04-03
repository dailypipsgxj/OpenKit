#ifndef __QUANTKIT_DATASERIESSTREAMER_H__
#define __QUANTKIT_DATASERIESSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class DataSeriesStreamerPrivate;

class QUANTKIT_EXPORT DataSeriesStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	DataSeriesStreamer();
	~DataSeriesStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataSeriesStreamer)

#endif // __QUANTKIT_DATASERIESSTREAMER_H__
