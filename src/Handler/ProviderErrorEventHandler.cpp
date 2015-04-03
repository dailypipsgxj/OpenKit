#include <QuantKit/ProviderErrorEventHandler.h>

#include <QuantKit/ProviderErrorEventArgs.h>

namespace QuantKit {

class ProviderErrorEventHandlerPrivate : public QSharedData
{
public:
	ProviderErrorEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~ProviderErrorEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const ProviderErrorEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const ProviderErrorEventArgs& e) Q_DECL_OVERRIDE;
	virtual ProviderErrorEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new ProviderErrorEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ProviderErrorEventHandlerPrivate::ProviderErrorEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

ProviderErrorEventHandlerPrivate::~ProviderErrorEventHandlerPrivate ()
{
}

IAsyncResult ProviderErrorEventHandlerPrivate::beginInvoke(const QVariant& sender, const ProviderErrorEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void ProviderErrorEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void ProviderErrorEventHandlerPrivate::invoke(const QVariant& sender, const ProviderErrorEventArgs& e)
{
}


// Pubic API 

ProviderErrorEventHandler::ProviderErrorEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new ProviderErrorEventHandlerPrivate(object, method))
{
}

ProviderErrorEventHandler::~ProviderErrorEventHandler()
{
}

ProviderErrorEventHandler::ProviderErrorEventHandler (const ProviderErrorEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

ProviderErrorEventHandler& ProviderErrorEventHandler::operator=(const ProviderErrorEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ProviderErrorEventHandler::operator==(const ProviderErrorEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult ProviderErrorEventHandler::beginInvoke(const QVariant& sender, const ProviderErrorEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void ProviderErrorEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void ProviderErrorEventHandler::invoke(const QVariant& sender, const ProviderErrorEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const ProviderErrorEventHandler& providererroreventhandler)
{
	return dbg << providererroreventhandler.toString();
}

