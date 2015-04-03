#ifndef __QUANTKIT_GROUPUPDATESTREAMER_H__
#define __QUANTKIT_GROUPUPDATESTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class GroupUpdateStreamerPrivate;

class QUANTKIT_EXPORT GroupUpdateStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	GroupUpdateStreamer();
	~GroupUpdateStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupUpdateStreamer)

#endif // __QUANTKIT_GROUPUPDATESTREAMER_H__
