#ifndef __QUANTKIT_ONLOGINSTREAMER_H__
#define __QUANTKIT_ONLOGINSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class OnLoginStreamerPrivate;

class QUANTKIT_EXPORT OnLoginStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	OnLoginStreamer();
	~OnLoginStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnLoginStreamer)

#endif // __QUANTKIT_ONLOGINSTREAMER_H__
