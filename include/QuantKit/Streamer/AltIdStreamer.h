#ifndef __QUANTKIT_ALTIDSTREAMER_H__
#define __QUANTKIT_ALTIDSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class AltIdStreamerPrivate;

class QUANTKIT_EXPORT AltIdStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	AltIdStreamer();
	~AltIdStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AltIdStreamer)

#endif // __QUANTKIT_ALTIDSTREAMER_H__
