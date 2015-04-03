#ifndef __QUANTKIT_ASKSTREAMER_H__
#define __QUANTKIT_ASKSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class AskStreamerPrivate;

class QUANTKIT_EXPORT AskStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	AskStreamer();
	~AskStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AskStreamer)

#endif // __QUANTKIT_ASKSTREAMER_H__
