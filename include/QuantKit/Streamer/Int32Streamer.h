#ifndef __QUANTKIT_INT32STREAMER_H__
#define __QUANTKIT_INT32STREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class Int32StreamerPrivate;

class QUANTKIT_EXPORT Int32Streamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	Int32Streamer();
	~Int32Streamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Int32Streamer)

#endif // __QUANTKIT_INT32STREAMER_H__
