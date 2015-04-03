#ifndef __QUANTKIT_LEVEL2STREAMER_H__
#define __QUANTKIT_LEVEL2STREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class Level2StreamerPrivate;

class QUANTKIT_EXPORT Level2Streamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	Level2Streamer();
	~Level2Streamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Level2Streamer)

#endif // __QUANTKIT_LEVEL2STREAMER_H__
