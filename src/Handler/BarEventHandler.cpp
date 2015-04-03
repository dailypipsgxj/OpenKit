#include <QuantKit/BarEventHandler.h>

#include <QuantKit/Event/Bar.h>

namespace QuantKit {

class BarEventHandlerPrivate : public QSharedData
{
public:
	BarEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~BarEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const Bar& bar, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const Bar& bar) Q_DECL_OVERRIDE;
	virtual BarEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new BarEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BarEventHandlerPrivate::BarEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

BarEventHandlerPrivate::~BarEventHandlerPrivate ()
{
}

IAsyncResult BarEventHandlerPrivate::beginInvoke(const QVariant& sender, const Bar& bar, const AsyncCallback& callback, const QVariant& object)
{
}

void BarEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void BarEventHandlerPrivate::invoke(const QVariant& sender, const Bar& bar)
{
}


// Pubic API 

BarEventHandler::BarEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new BarEventHandlerPrivate(object, method))
{
}

BarEventHandler::~BarEventHandler()
{
}

BarEventHandler::BarEventHandler (const BarEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

BarEventHandler& BarEventHandler::operator=(const BarEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool BarEventHandler::operator==(const BarEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult BarEventHandler::beginInvoke(const QVariant& sender, const Bar& bar, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, bar, callback, object);
}

void BarEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void BarEventHandler::invoke(const QVariant& sender, const Bar& bar)
{
	d_ptr->invoke(sender, bar);
}

QDebug operator<<(QDebug dbg, const BarEventHandler& bareventhandler)
{
	return dbg << bareventhandler.toString();
}

