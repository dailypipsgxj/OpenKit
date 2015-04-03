#ifndef __QUANTKIT_DOUBLESTREAMER_H__
#define __QUANTKIT_DOUBLESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class DoubleStreamerPrivate;

class QUANTKIT_EXPORT DoubleStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	DoubleStreamer();
	~DoubleStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DoubleStreamer)

#endif // __QUANTKIT_DOUBLESTREAMER_H__
