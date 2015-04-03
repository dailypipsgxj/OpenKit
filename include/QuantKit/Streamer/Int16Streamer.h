#ifndef __QUANTKIT_INT16STREAMER_H__
#define __QUANTKIT_INT16STREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class Int16StreamerPrivate;

class QUANTKIT_EXPORT Int16Streamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	Int16Streamer();
	~Int16Streamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Int16Streamer)

#endif // __QUANTKIT_INT16STREAMER_H__
