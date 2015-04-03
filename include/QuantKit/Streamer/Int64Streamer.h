#ifndef __QUANTKIT_INT64STREAMER_H__
#define __QUANTKIT_INT64STREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class Int64StreamerPrivate;

class QUANTKIT_EXPORT Int64Streamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	Int64Streamer();
	~Int64Streamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Int64Streamer)

#endif // __QUANTKIT_INT64STREAMER_H__
