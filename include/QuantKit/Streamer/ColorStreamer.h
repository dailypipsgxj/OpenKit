#ifndef __QUANTKIT_COLORSTREAMER_H__
#define __QUANTKIT_COLORSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class ColorStreamerPrivate;

class QUANTKIT_EXPORT ColorStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	ColorStreamer();
	~ColorStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ColorStreamer)

#endif // __QUANTKIT_COLORSTREAMER_H__
