#ifndef __QUANTKIT_INSTRUMENTSTREAMER_H__
#define __QUANTKIT_INSTRUMENTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class InstrumentStreamerPrivate;

class QUANTKIT_EXPORT InstrumentStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	InstrumentStreamer();
	~InstrumentStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::InstrumentStreamer)

#endif // __QUANTKIT_INSTRUMENTSTREAMER_H__
