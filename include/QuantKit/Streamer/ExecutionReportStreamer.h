#ifndef __QUANTKIT_EXECUTIONREPORTSTREAMER_H__
#define __QUANTKIT_EXECUTIONREPORTSTREAMER_H__

#include <QuantKit/quantkit_global.h>
#include <QVariant>
#include <QByteArray>

#include <QuantKit/ObjectStreamer.h>

namespace QuantKit {

class ExecutionReportStreamerPrivate;

class QUANTKIT_EXPORT ExecutionReportStreamer Q_DECL_FINAL : public ObjectStreamer
{
public:
	ExecutionReportStreamer();
	~ExecutionReportStreamer();

public:

private:
};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::ExecutionReportStreamer)

#endif // __QUANTKIT_EXECUTIONREPORTSTREAMER_H__
