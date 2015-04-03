#ifndef __QUANTKIT_CHARSTREAMER_H__
#define __QUANTKIT_CHARSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class CharStreamerPrivate;

class QUANTKIT_EXPORT CharStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	CharStreamer();
	~CharStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::CharStreamer)

#endif // __QUANTKIT_CHARSTREAMER_H__
