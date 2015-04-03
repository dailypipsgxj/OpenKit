#ifndef __QUANTKIT_ONPROVIDERCONNECTEDSTREAMER_H__
#define __QUANTKIT_ONPROVIDERCONNECTEDSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class OnProviderConnectedStreamerPrivate;

class QUANTKIT_EXPORT OnProviderConnectedStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	OnProviderConnectedStreamer();
	~OnProviderConnectedStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnProviderConnectedStreamer)

#endif // __QUANTKIT_ONPROVIDERCONNECTEDSTREAMER_H__
