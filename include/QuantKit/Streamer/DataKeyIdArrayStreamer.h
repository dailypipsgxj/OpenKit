#ifndef __QUANTKIT_DATAKEYIDARRAYSTREAMER_H__
#define __QUANTKIT_DATAKEYIDARRAYSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class DataKeyIdArrayStreamerPrivate;

class QUANTKIT_EXPORT DataKeyIdArrayStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	DataKeyIdArrayStreamer();
	~DataKeyIdArrayStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataKeyIdArrayStreamer)

#endif // __QUANTKIT_DATAKEYIDARRAYSTREAMER_H__
