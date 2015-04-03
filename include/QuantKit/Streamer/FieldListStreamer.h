#ifndef __QUANTKIT_FIELDLISTSTREAMER_H__
#define __QUANTKIT_FIELDLISTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class FieldListStreamerPrivate;

class QUANTKIT_EXPORT FieldListStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	FieldListStreamer();
	~FieldListStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::FieldListStreamer)

#endif // __QUANTKIT_FIELDLISTSTREAMER_H__
