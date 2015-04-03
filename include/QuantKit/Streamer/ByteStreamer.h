#ifndef __QUANTKIT_BYTESTREAMER_H__
#define __QUANTKIT_BYTESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class ByteStreamerPrivate;

class QUANTKIT_EXPORT ByteStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	ByteStreamer();
	~ByteStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ByteStreamer)

#endif // __QUANTKIT_BYTESTREAMER_H__
