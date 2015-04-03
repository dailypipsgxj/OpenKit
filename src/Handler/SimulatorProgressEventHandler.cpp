#include <QuantKit/SimulatorProgressEventHandler.h>

#include <QuantKit/SimulatorProgressEventArgs.h>

namespace QuantKit {

class SimulatorProgressEventHandlerPrivate : public QSharedData
{
public:
	SimulatorProgressEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~SimulatorProgressEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const SimulatorProgressEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const SimulatorProgressEventArgs& e) Q_DECL_OVERRIDE;
	virtual SimulatorProgressEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new SimulatorProgressEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

SimulatorProgressEventHandlerPrivate::SimulatorProgressEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

SimulatorProgressEventHandlerPrivate::~SimulatorProgressEventHandlerPrivate ()
{
}

IAsyncResult SimulatorProgressEventHandlerPrivate::beginInvoke(const QVariant& sender, const SimulatorProgressEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void SimulatorProgressEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void SimulatorProgressEventHandlerPrivate::invoke(const QVariant& sender, const SimulatorProgressEventArgs& e)
{
}


// Pubic API 

SimulatorProgressEventHandler::SimulatorProgressEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new SimulatorProgressEventHandlerPrivate(object, method))
{
}

SimulatorProgressEventHandler::~SimulatorProgressEventHandler()
{
}

SimulatorProgressEventHandler::SimulatorProgressEventHandler (const SimulatorProgressEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

SimulatorProgressEventHandler& SimulatorProgressEventHandler::operator=(const SimulatorProgressEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool SimulatorProgressEventHandler::operator==(const SimulatorProgressEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult SimulatorProgressEventHandler::beginInvoke(const QVariant& sender, const SimulatorProgressEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void SimulatorProgressEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void SimulatorProgressEventHandler::invoke(const QVariant& sender, const SimulatorProgressEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const SimulatorProgressEventHandler& simulatorprogresseventhandler)
{
	return dbg << simulatorprogresseventhandler.toString();
}

