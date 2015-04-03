#ifndef __QUANTKIT_ONSUBSCRIBESTREAMER_H__
#define __QUANTKIT_ONSUBSCRIBESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class OnSubscribeStreamerPrivate;

class QUANTKIT_EXPORT OnSubscribeStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	OnSubscribeStreamer();
	~OnSubscribeStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnSubscribeStreamer)

#endif // __QUANTKIT_ONSUBSCRIBESTREAMER_H__
