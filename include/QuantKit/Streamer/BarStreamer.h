#ifndef __QUANTKIT_BARSTREAMER_H__
#define __QUANTKIT_BARSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class BarStreamerPrivate;

class QUANTKIT_EXPORT BarStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	BarStreamer();
	~BarStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BarStreamer)

#endif // __QUANTKIT_BARSTREAMER_H__
