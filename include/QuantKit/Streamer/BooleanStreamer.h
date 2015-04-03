#ifndef __QUANTKIT_BOOLEANSTREAMER_H__
#define __QUANTKIT_BOOLEANSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class BooleanStreamerPrivate;

class QUANTKIT_EXPORT BooleanStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	BooleanStreamer();
	~BooleanStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::BooleanStreamer)

#endif // __QUANTKIT_BOOLEANSTREAMER_H__
