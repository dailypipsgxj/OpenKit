#include <QuantKit/InstrumentEventHandler.h>

#include <QuantKit/InstrumentEventArgs.h>

namespace QuantKit {

class InstrumentEventHandlerPrivate : public QSharedData
{
public:
	InstrumentEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~InstrumentEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const InstrumentEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const InstrumentEventArgs& e) Q_DECL_OVERRIDE;
	virtual InstrumentEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentEventHandlerPrivate::InstrumentEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

InstrumentEventHandlerPrivate::~InstrumentEventHandlerPrivate ()
{
}

IAsyncResult InstrumentEventHandlerPrivate::beginInvoke(const QVariant& sender, const InstrumentEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void InstrumentEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void InstrumentEventHandlerPrivate::invoke(const QVariant& sender, const InstrumentEventArgs& e)
{
}


// Pubic API 

InstrumentEventHandler::InstrumentEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new InstrumentEventHandlerPrivate(object, method))
{
}

InstrumentEventHandler::~InstrumentEventHandler()
{
}

InstrumentEventHandler::InstrumentEventHandler (const InstrumentEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

InstrumentEventHandler& InstrumentEventHandler::operator=(const InstrumentEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool InstrumentEventHandler::operator==(const InstrumentEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult InstrumentEventHandler::beginInvoke(const QVariant& sender, const InstrumentEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void InstrumentEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void InstrumentEventHandler::invoke(const QVariant& sender, const InstrumentEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const InstrumentEventHandler& instrumenteventhandler)
{
	return dbg << instrumenteventhandler.toString();
}

