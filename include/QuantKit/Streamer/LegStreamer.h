#ifndef __QUANTKIT_LEGSTREAMER_H__
#define __QUANTKIT_LEGSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class LegStreamerPrivate;

class QUANTKIT_EXPORT LegStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	LegStreamer();
	~LegStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::LegStreamer)

#endif // __QUANTKIT_LEGSTREAMER_H__
