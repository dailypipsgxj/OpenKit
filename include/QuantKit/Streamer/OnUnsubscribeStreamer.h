#ifndef __QUANTKIT_ONUNSUBSCRIBESTREAMER_H__
#define __QUANTKIT_ONUNSUBSCRIBESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class OnUnsubscribeStreamerPrivate;

class QUANTKIT_EXPORT OnUnsubscribeStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	OnUnsubscribeStreamer();
	~OnUnsubscribeStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnUnsubscribeStreamer)

#endif // __QUANTKIT_ONUNSUBSCRIBESTREAMER_H__
