#ifndef __QUANTKIT_LEVEL2UPDATESTREAMER_H__
#define __QUANTKIT_LEVEL2UPDATESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class Level2UpdateStreamerPrivate;

class QUANTKIT_EXPORT Level2UpdateStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	Level2UpdateStreamer();
	~Level2UpdateStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Level2UpdateStreamer)

#endif // __QUANTKIT_LEVEL2UPDATESTREAMER_H__
