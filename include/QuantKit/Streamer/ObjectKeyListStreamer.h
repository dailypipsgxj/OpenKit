#ifndef __QUANTKIT_OBJECTKEYLISTSTREAMER_H__
#define __QUANTKIT_OBJECTKEYLISTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class ObjectKeyListStreamerPrivate;

class QUANTKIT_EXPORT ObjectKeyListStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	ObjectKeyListStreamer();
	~ObjectKeyListStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ObjectKeyListStreamer)

#endif // __QUANTKIT_OBJECTKEYLISTSTREAMER_H__
