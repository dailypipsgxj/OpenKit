#ifndef __QUANTKIT_ONEXECUTIONREPORT_H__
#define __QUANTKIT_ONEXECUTIONREPORT_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/Event.h>

namespace QuantKit {

class OnExecutionReportPrivate;

class ExecutionReport;

class QUANTKIT_EXPORT OnExecutionReport Q_DECL_FINAL : public Event
{
public:
	explicit OnExecutionReport(const ExecutionReport& report);
	~OnExecutionReport();

public:

private:
	QK_DECLARE_PRIVATE(OnExecutionReport)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::OnExecutionReport)

#endif // __QUANTKIT_ONEXECUTIONREPORT_H__
