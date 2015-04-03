#ifndef __QUANTKIT_FREEKEYLISTSTREAMER_H__
#define __QUANTKIT_FREEKEYLISTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class FreeKeyListStreamerPrivate;

class QUANTKIT_EXPORT FreeKeyListStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	FreeKeyListStreamer();
	~FreeKeyListStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FreeKeyListStreamer)

#endif // __QUANTKIT_FREEKEYLISTSTREAMER_H__
