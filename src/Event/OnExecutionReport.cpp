#include <QuantKit/Event/OnExecutionReport.h>

#include <QuantKit/Event/ExecutionReport.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnExecutionReportPrivate : public EventPrivate
{
public:
	ExecutionReport m_executionReport;

public:
	explicit OnExecutionReportPrivate(const ExecutionReport& report);
	virtual ~OnExecutionReportPrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnExecutionReport;
	}

	virtual OnExecutionReportPrivate* clone() Q_DECL_OVERRIDE { return new OnExecutionReportPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnExecutionReportPrivate::OnExecutionReportPrivate(const ExecutionReport& report)
	: m_executionReport(report)
{
}

OnExecutionReportPrivate::~OnExecutionReportPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnExecutionReport)

OnExecutionReport::OnExecutionReport(const ExecutionReport& report)
	: Event(*new OnExecutionReportPrivate(report))
{
}

OnExecutionReport::~OnExecutionReport()
{
}


