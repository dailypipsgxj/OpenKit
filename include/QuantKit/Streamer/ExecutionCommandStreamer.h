#ifndef __QUANTKIT_EXECUTIONCOMMANDSTREAMER_H__
#define __QUANTKIT_EXECUTIONCOMMANDSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class ExecutionCommandStreamerPrivate;

class QUANTKIT_EXPORT ExecutionCommandStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	ExecutionCommandStreamer();
	~ExecutionCommandStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ExecutionCommandStreamer)

#endif // __QUANTKIT_EXECUTIONCOMMANDSTREAMER_H__
