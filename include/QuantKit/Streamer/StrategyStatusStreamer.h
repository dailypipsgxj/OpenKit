#ifndef __QUANTKIT_STRATEGYSTATUSSTREAMER_H__
#define __QUANTKIT_STRATEGYSTATUSSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class StrategyStatusStreamerPrivate;

class QUANTKIT_EXPORT StrategyStatusStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	StrategyStatusStreamer();
	~StrategyStatusStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::StrategyStatusStreamer)

#endif // __QUANTKIT_STRATEGYSTATUSSTREAMER_H__
