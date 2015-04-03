#ifndef __QUANTKIT_DATAOBJECTSTREAMER_H__
#define __QUANTKIT_DATAOBJECTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class DataObjectStreamerPrivate;

class QUANTKIT_EXPORT DataObjectStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	DataObjectStreamer();
	~DataObjectStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::DataObjectStreamer)

#endif // __QUANTKIT_DATAOBJECTSTREAMER_H__
