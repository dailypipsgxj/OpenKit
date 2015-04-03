#ifndef __QUANTKIT_GROUPEVENTSTREAMER_H__
#define __QUANTKIT_GROUPEVENTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class GroupEventStreamerPrivate;

class QUANTKIT_EXPORT GroupEventStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	GroupEventStreamer();
	~GroupEventStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupEventStreamer)

#endif // __QUANTKIT_GROUPEVENTSTREAMER_H__
