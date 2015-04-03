#ifndef __QUANTKIT_TIMESPANSTREAMER_H__
#define __QUANTKIT_TIMESPANSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class TimeSpanStreamerPrivate;

class QUANTKIT_EXPORT TimeSpanStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	TimeSpanStreamer();
	~TimeSpanStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TimeSpanStreamer)

#endif // __QUANTKIT_TIMESPANSTREAMER_H__
