#include <QuantKit/InstrumentDefinitionEventHandler.h>

#include <QuantKit/InstrumentDefinitionEventArgs.h>

namespace QuantKit {

class InstrumentDefinitionEventHandlerPrivate : public QSharedData
{
public:
	InstrumentDefinitionEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~InstrumentDefinitionEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const InstrumentDefinitionEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const InstrumentDefinitionEventArgs& e) Q_DECL_OVERRIDE;
	virtual InstrumentDefinitionEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentDefinitionEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentDefinitionEventHandlerPrivate::InstrumentDefinitionEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

InstrumentDefinitionEventHandlerPrivate::~InstrumentDefinitionEventHandlerPrivate ()
{
}

IAsyncResult InstrumentDefinitionEventHandlerPrivate::beginInvoke(const QVariant& sender, const InstrumentDefinitionEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void InstrumentDefinitionEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void InstrumentDefinitionEventHandlerPrivate::invoke(const QVariant& sender, const InstrumentDefinitionEventArgs& e)
{
}


// Pubic API 

InstrumentDefinitionEventHandler::InstrumentDefinitionEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new InstrumentDefinitionEventHandlerPrivate(object, method))
{
}

InstrumentDefinitionEventHandler::~InstrumentDefinitionEventHandler()
{
}

InstrumentDefinitionEventHandler::InstrumentDefinitionEventHandler (const InstrumentDefinitionEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

InstrumentDefinitionEventHandler& InstrumentDefinitionEventHandler::operator=(const InstrumentDefinitionEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool InstrumentDefinitionEventHandler::operator==(const InstrumentDefinitionEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult InstrumentDefinitionEventHandler::beginInvoke(const QVariant& sender, const InstrumentDefinitionEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void InstrumentDefinitionEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void InstrumentDefinitionEventHandler::invoke(const QVariant& sender, const InstrumentDefinitionEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const InstrumentDefinitionEventHandler& instrumentdefinitioneventhandler)
{
	return dbg << instrumentdefinitioneventhandler.toString();
}

