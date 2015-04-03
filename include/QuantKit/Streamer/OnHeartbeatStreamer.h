#ifndef __QUANTKIT_ONHEARTBEATSTREAMER_H__
#define __QUANTKIT_ONHEARTBEATSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class OnHeartbeatStreamerPrivate;

class QUANTKIT_EXPORT OnHeartbeatStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	OnHeartbeatStreamer();
	~OnHeartbeatStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnHeartbeatStreamer)

#endif // __QUANTKIT_ONHEARTBEATSTREAMER_H__
