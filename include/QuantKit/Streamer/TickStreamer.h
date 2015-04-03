#ifndef __QUANTKIT_TICKSTREAMER_H__
#define __QUANTKIT_TICKSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class TickStreamerPrivate;

class QUANTKIT_EXPORT TickStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	TickStreamer();
	~TickStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TickStreamer)

#endif // __QUANTKIT_TICKSTREAMER_H__
