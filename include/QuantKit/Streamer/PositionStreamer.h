#ifndef __QUANTKIT_POSITIONSTREAMER_H__
#define __QUANTKIT_POSITIONSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class PositionStreamerPrivate;

class QUANTKIT_EXPORT PositionStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	PositionStreamer();
	~PositionStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::PositionStreamer)

#endif // __QUANTKIT_POSITIONSTREAMER_H__
