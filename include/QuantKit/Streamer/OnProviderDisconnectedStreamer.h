#ifndef __QUANTKIT_ONPROVIDERDISCONNECTEDSTREAMER_H__
#define __QUANTKIT_ONPROVIDERDISCONNECTEDSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class OnProviderDisconnectedStreamerPrivate;

class QUANTKIT_EXPORT OnProviderDisconnectedStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	OnProviderDisconnectedStreamer();
	~OnProviderDisconnectedStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnProviderDisconnectedStreamer)

#endif // __QUANTKIT_ONPROVIDERDISCONNECTEDSTREAMER_H__
