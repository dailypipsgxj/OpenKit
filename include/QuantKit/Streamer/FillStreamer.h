#ifndef __QUANTKIT_FILLSTREAMER_H__
#define __QUANTKIT_FILLSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class FillStreamerPrivate;

class QUANTKIT_EXPORT FillStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	FillStreamer();
	~FillStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FillStreamer)

#endif // __QUANTKIT_FILLSTREAMER_H__
