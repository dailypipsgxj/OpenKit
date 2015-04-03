#ifndef __QUANTKIT_BIDSTREAMER_H__
#define __QUANTKIT_BIDSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class BidStreamerPrivate;

class QUANTKIT_EXPORT BidStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	BidStreamer();
	~BidStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BidStreamer)

#endif // __QUANTKIT_BIDSTREAMER_H__
