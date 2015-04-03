#ifndef __QUANTKIT_PROVIDERERRORSTREAMER_H__
#define __QUANTKIT_PROVIDERERRORSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class ProviderErrorStreamerPrivate;

class QUANTKIT_EXPORT ProviderErrorStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	ProviderErrorStreamer();
	~ProviderErrorStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ProviderErrorStreamer)

#endif // __QUANTKIT_PROVIDERERRORSTREAMER_H__
