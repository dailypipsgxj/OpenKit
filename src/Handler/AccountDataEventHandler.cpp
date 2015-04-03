#include <QuantKit/AccountDataEventHandler.h>

#include <QuantKit/AccountDataEventArgs.h>

namespace QuantKit {

class AccountDataEventHandlerPrivate : public QSharedData
{
public:
	AccountDataEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~AccountDataEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const AccountDataEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const AccountDataEventArgs& e) Q_DECL_OVERRIDE;
	virtual AccountDataEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new AccountDataEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AccountDataEventHandlerPrivate::AccountDataEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

AccountDataEventHandlerPrivate::~AccountDataEventHandlerPrivate ()
{
}

IAsyncResult AccountDataEventHandlerPrivate::beginInvoke(const QVariant& sender, const AccountDataEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void AccountDataEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void AccountDataEventHandlerPrivate::invoke(const QVariant& sender, const AccountDataEventArgs& e)
{
}


// Pubic API 

AccountDataEventHandler::AccountDataEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new AccountDataEventHandlerPrivate(object, method))
{
}

AccountDataEventHandler::~AccountDataEventHandler()
{
}

AccountDataEventHandler::AccountDataEventHandler (const AccountDataEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

AccountDataEventHandler& AccountDataEventHandler::operator=(const AccountDataEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool AccountDataEventHandler::operator==(const AccountDataEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult AccountDataEventHandler::beginInvoke(const QVariant& sender, const AccountDataEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void AccountDataEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void AccountDataEventHandler::invoke(const QVariant& sender, const AccountDataEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const AccountDataEventHandler& accountdataeventhandler)
{
	return dbg << accountdataeventhandler.toString();
}

