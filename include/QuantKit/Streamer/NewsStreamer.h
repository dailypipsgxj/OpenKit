#ifndef __QUANTKIT_NEWSSTREAMER_H__
#define __QUANTKIT_NEWSSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class NewsStreamerPrivate;

class QUANTKIT_EXPORT NewsStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	NewsStreamer();
	~NewsStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::NewsStreamer)

#endif // __QUANTKIT_NEWSSTREAMER_H__
