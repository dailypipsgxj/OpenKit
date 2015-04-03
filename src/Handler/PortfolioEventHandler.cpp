#include <QuantKit/PortfolioEventHandler.h>

#include <QuantKit/PortfolioEventArgs.h>

namespace QuantKit {

class PortfolioEventHandlerPrivate : public QSharedData
{
public:
	PortfolioEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~PortfolioEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const PortfolioEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const PortfolioEventArgs& e) Q_DECL_OVERRIDE;
	virtual PortfolioEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new PortfolioEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

PortfolioEventHandlerPrivate::PortfolioEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

PortfolioEventHandlerPrivate::~PortfolioEventHandlerPrivate ()
{
}

IAsyncResult PortfolioEventHandlerPrivate::beginInvoke(const QVariant& sender, const PortfolioEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void PortfolioEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void PortfolioEventHandlerPrivate::invoke(const QVariant& sender, const PortfolioEventArgs& e)
{
}


// Pubic API 

PortfolioEventHandler::PortfolioEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new PortfolioEventHandlerPrivate(object, method))
{
}

PortfolioEventHandler::~PortfolioEventHandler()
{
}

PortfolioEventHandler::PortfolioEventHandler (const PortfolioEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

PortfolioEventHandler& PortfolioEventHandler::operator=(const PortfolioEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PortfolioEventHandler::operator==(const PortfolioEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult PortfolioEventHandler::beginInvoke(const QVariant& sender, const PortfolioEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void PortfolioEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void PortfolioEventHandler::invoke(const QVariant& sender, const PortfolioEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const PortfolioEventHandler& portfolioeventhandler)
{
	return dbg << portfolioeventhandler.toString();
}

