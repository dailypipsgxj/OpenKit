#include <QuantKit/ProviderEventHandler.h>

#include <QuantKit/ProviderEventArgs.h>

namespace QuantKit {

class ProviderEventHandlerPrivate : public QSharedData
{
public:
	ProviderEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~ProviderEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const ProviderEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const ProviderEventArgs& e) Q_DECL_OVERRIDE;
	virtual ProviderEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new ProviderEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ProviderEventHandlerPrivate::ProviderEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

ProviderEventHandlerPrivate::~ProviderEventHandlerPrivate ()
{
}

IAsyncResult ProviderEventHandlerPrivate::beginInvoke(const QVariant& sender, const ProviderEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void ProviderEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void ProviderEventHandlerPrivate::invoke(const QVariant& sender, const ProviderEventArgs& e)
{
}


// Pubic API 

ProviderEventHandler::ProviderEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new ProviderEventHandlerPrivate(object, method))
{
}

ProviderEventHandler::~ProviderEventHandler()
{
}

ProviderEventHandler::ProviderEventHandler (const ProviderEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

ProviderEventHandler& ProviderEventHandler::operator=(const ProviderEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ProviderEventHandler::operator==(const ProviderEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult ProviderEventHandler::beginInvoke(const QVariant& sender, const ProviderEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void ProviderEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void ProviderEventHandler::invoke(const QVariant& sender, const ProviderEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const ProviderEventHandler& providereventhandler)
{
	return dbg << providereventhandler.toString();
}

