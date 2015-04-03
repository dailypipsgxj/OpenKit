#ifndef __QUANTKIT_QUOTESTREAMER_H__
#define __QUANTKIT_QUOTESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class QuoteStreamerPrivate;

class QUANTKIT_EXPORT QuoteStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	QuoteStreamer();
	~QuoteStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::QuoteStreamer)

#endif // __QUANTKIT_QUOTESTREAMER_H__
