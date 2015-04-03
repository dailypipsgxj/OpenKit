#include <QuantKit/PositionEventHandler.h>

#include <QuantKit/PositionEventArgs.h>

namespace QuantKit {

class PositionEventHandlerPrivate : public QSharedData
{
public:
	PositionEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~PositionEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const PositionEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const PositionEventArgs& e) Q_DECL_OVERRIDE;
	virtual PositionEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new PositionEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

PositionEventHandlerPrivate::PositionEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

PositionEventHandlerPrivate::~PositionEventHandlerPrivate ()
{
}

IAsyncResult PositionEventHandlerPrivate::beginInvoke(const QVariant& sender, const PositionEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void PositionEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void PositionEventHandlerPrivate::invoke(const QVariant& sender, const PositionEventArgs& e)
{
}


// Pubic API 

PositionEventHandler::PositionEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new PositionEventHandlerPrivate(object, method))
{
}

PositionEventHandler::~PositionEventHandler()
{
}

PositionEventHandler::PositionEventHandler (const PositionEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

PositionEventHandler& PositionEventHandler::operator=(const PositionEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool PositionEventHandler::operator==(const PositionEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult PositionEventHandler::beginInvoke(const QVariant& sender, const PositionEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void PositionEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void PositionEventHandler::invoke(const QVariant& sender, const PositionEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const PositionEventHandler& positioneventhandler)
{
	return dbg << positioneventhandler.toString();
}

