#ifndef __QUANTKIT_EVENTSTREAMER_H__
#define __QUANTKIT_EVENTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class EventStreamerPrivate;

class QUANTKIT_EXPORT EventStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	EventStreamer();
	~EventStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::EventStreamer)

#endif // __QUANTKIT_EVENTSTREAMER_H__
