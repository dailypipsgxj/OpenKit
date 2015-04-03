#include <QuantKit/FrameworkEventHandler.h>

#include <QuantKit/FrameworkEventArgs.h>

namespace QuantKit {

class FrameworkEventHandlerPrivate : public QSharedData
{
public:
	FrameworkEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~FrameworkEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const FrameworkEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const FrameworkEventArgs& e) Q_DECL_OVERRIDE;
	virtual FrameworkEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new FrameworkEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FrameworkEventHandlerPrivate::FrameworkEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

FrameworkEventHandlerPrivate::~FrameworkEventHandlerPrivate ()
{
}

IAsyncResult FrameworkEventHandlerPrivate::beginInvoke(const QVariant& sender, const FrameworkEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void FrameworkEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void FrameworkEventHandlerPrivate::invoke(const QVariant& sender, const FrameworkEventArgs& e)
{
}


// Pubic API 

FrameworkEventHandler::FrameworkEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new FrameworkEventHandlerPrivate(object, method))
{
}

FrameworkEventHandler::~FrameworkEventHandler()
{
}

FrameworkEventHandler::FrameworkEventHandler (const FrameworkEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

FrameworkEventHandler& FrameworkEventHandler::operator=(const FrameworkEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool FrameworkEventHandler::operator==(const FrameworkEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult FrameworkEventHandler::beginInvoke(const QVariant& sender, const FrameworkEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void FrameworkEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void FrameworkEventHandler::invoke(const QVariant& sender, const FrameworkEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const FrameworkEventHandler& frameworkeventhandler)
{
	return dbg << frameworkeventhandler.toString();
}

