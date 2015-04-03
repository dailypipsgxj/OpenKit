#ifndef __QUANTKIT_LEVEL2SNAPSHOTSTREAMER_H__
#define __QUANTKIT_LEVEL2SNAPSHOTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class Level2SnapshotStreamerPrivate;

class QUANTKIT_EXPORT Level2SnapshotStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	Level2SnapshotStreamer();
	~Level2SnapshotStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Level2SnapshotStreamer)

#endif // __QUANTKIT_LEVEL2SNAPSHOTSTREAMER_H__
