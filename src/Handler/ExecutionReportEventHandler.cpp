#include <QuantKit/ExecutionReportEventHandler.h>

#include <QuantKit/Event/ExecutionReport.h>

namespace QuantKit {

class ExecutionReportEventHandlerPrivate : public QSharedData
{
public:
	ExecutionReportEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~ExecutionReportEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const ExecutionReport& report, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const ExecutionReport& report) Q_DECL_OVERRIDE;
	virtual ExecutionReportEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new ExecutionReportEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ExecutionReportEventHandlerPrivate::ExecutionReportEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

ExecutionReportEventHandlerPrivate::~ExecutionReportEventHandlerPrivate ()
{
}

IAsyncResult ExecutionReportEventHandlerPrivate::beginInvoke(const QVariant& sender, const ExecutionReport& report, const AsyncCallback& callback, const QVariant& object)
{
}

void ExecutionReportEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void ExecutionReportEventHandlerPrivate::invoke(const QVariant& sender, const ExecutionReport& report)
{
}


// Pubic API 

ExecutionReportEventHandler::ExecutionReportEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new ExecutionReportEventHandlerPrivate(object, method))
{
}

ExecutionReportEventHandler::~ExecutionReportEventHandler()
{
}

ExecutionReportEventHandler::ExecutionReportEventHandler (const ExecutionReportEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

ExecutionReportEventHandler& ExecutionReportEventHandler::operator=(const ExecutionReportEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ExecutionReportEventHandler::operator==(const ExecutionReportEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult ExecutionReportEventHandler::beginInvoke(const QVariant& sender, const ExecutionReport& report, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, report, callback, object);
}

void ExecutionReportEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void ExecutionReportEventHandler::invoke(const QVariant& sender, const ExecutionReport& report)
{
	d_ptr->invoke(sender, report);
}

QDebug operator<<(QDebug dbg, const ExecutionReportEventHandler& executionreporteventhandler)
{
	return dbg << executionreporteventhandler.toString();
}

