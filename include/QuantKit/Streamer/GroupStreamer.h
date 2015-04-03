#ifndef __QUANTKIT_GROUPSTREAMER_H__
#define __QUANTKIT_GROUPSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class GroupStreamerPrivate;

class QUANTKIT_EXPORT GroupStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	GroupStreamer();
	~GroupStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupStreamer)

#endif // __QUANTKIT_GROUPSTREAMER_H__
