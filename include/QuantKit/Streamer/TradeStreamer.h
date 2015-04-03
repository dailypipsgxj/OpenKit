#ifndef __QUANTKIT_TRADESTREAMER_H__
#define __QUANTKIT_TRADESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class TradeStreamerPrivate;

class QUANTKIT_EXPORT TradeStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	TradeStreamer();
	~TradeStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::TradeStreamer)

#endif // __QUANTKIT_TRADESTREAMER_H__
