#ifndef __QUANTKIT_OBJECTTABLESTREAMER_H__
#define __QUANTKIT_OBJECTTABLESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class ObjectTableStreamerPrivate;

class QUANTKIT_EXPORT ObjectTableStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	ObjectTableStreamer();
	~ObjectTableStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ObjectTableStreamer)

#endif // __QUANTKIT_OBJECTTABLESTREAMER_H__
