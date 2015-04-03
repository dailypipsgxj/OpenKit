#ifndef __QUANTKIT_TIMESERIESITEMSTREAMER_H__
#define __QUANTKIT_TIMESERIESITEMSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class TimeSeriesItemStreamerPrivate;

class QUANTKIT_EXPORT TimeSeriesItemStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	TimeSeriesItemStreamer();
	~TimeSeriesItemStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TimeSeriesItemStreamer)

#endif // __QUANTKIT_TIMESERIESITEMSTREAMER_H__
