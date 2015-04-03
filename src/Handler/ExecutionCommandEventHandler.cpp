#include <QuantKit/ExecutionCommandEventHandler.h>

#include <QuantKit/Event/ExecutionCommand.h>

namespace QuantKit {

class ExecutionCommandEventHandlerPrivate : public QSharedData
{
public:
	ExecutionCommandEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~ExecutionCommandEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const ExecutionCommand& command, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const ExecutionCommand& command) Q_DECL_OVERRIDE;
	virtual ExecutionCommandEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new ExecutionCommandEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ExecutionCommandEventHandlerPrivate::ExecutionCommandEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

ExecutionCommandEventHandlerPrivate::~ExecutionCommandEventHandlerPrivate ()
{
}

IAsyncResult ExecutionCommandEventHandlerPrivate::beginInvoke(const QVariant& sender, const ExecutionCommand& command, const AsyncCallback& callback, const QVariant& object)
{
}

void ExecutionCommandEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void ExecutionCommandEventHandlerPrivate::invoke(const QVariant& sender, const ExecutionCommand& command)
{
}


// Pubic API 

ExecutionCommandEventHandler::ExecutionCommandEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new ExecutionCommandEventHandlerPrivate(object, method))
{
}

ExecutionCommandEventHandler::~ExecutionCommandEventHandler()
{
}

ExecutionCommandEventHandler::ExecutionCommandEventHandler (const ExecutionCommandEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

ExecutionCommandEventHandler& ExecutionCommandEventHandler::operator=(const ExecutionCommandEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ExecutionCommandEventHandler::operator==(const ExecutionCommandEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult ExecutionCommandEventHandler::beginInvoke(const QVariant& sender, const ExecutionCommand& command, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, command, callback, object);
}

void ExecutionCommandEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void ExecutionCommandEventHandler::invoke(const QVariant& sender, const ExecutionCommand& command)
{
	d_ptr->invoke(sender, command);
}

QDebug operator<<(QDebug dbg, const ExecutionCommandEventHandler& executioncommandeventhandler)
{
	return dbg << executioncommandeventhandler.toString();
}

