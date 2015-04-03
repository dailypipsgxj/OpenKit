#include <QuantKit/InstrumentDefinitionEndEventHandler.h>

#include <QuantKit/InstrumentDefinitionEndEventArgs.h>

namespace QuantKit {

class InstrumentDefinitionEndEventHandlerPrivate : public QSharedData
{
public:
	InstrumentDefinitionEndEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~InstrumentDefinitionEndEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const InstrumentDefinitionEndEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const InstrumentDefinitionEndEventArgs& e) Q_DECL_OVERRIDE;
	virtual InstrumentDefinitionEndEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentDefinitionEndEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentDefinitionEndEventHandlerPrivate::InstrumentDefinitionEndEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

InstrumentDefinitionEndEventHandlerPrivate::~InstrumentDefinitionEndEventHandlerPrivate ()
{
}

IAsyncResult InstrumentDefinitionEndEventHandlerPrivate::beginInvoke(const QVariant& sender, const InstrumentDefinitionEndEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void InstrumentDefinitionEndEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void InstrumentDefinitionEndEventHandlerPrivate::invoke(const QVariant& sender, const InstrumentDefinitionEndEventArgs& e)
{
}


// Pubic API 

InstrumentDefinitionEndEventHandler::InstrumentDefinitionEndEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new InstrumentDefinitionEndEventHandlerPrivate(object, method))
{
}

InstrumentDefinitionEndEventHandler::~InstrumentDefinitionEndEventHandler()
{
}

InstrumentDefinitionEndEventHandler::InstrumentDefinitionEndEventHandler (const InstrumentDefinitionEndEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

InstrumentDefinitionEndEventHandler& InstrumentDefinitionEndEventHandler::operator=(const InstrumentDefinitionEndEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool InstrumentDefinitionEndEventHandler::operator==(const InstrumentDefinitionEndEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult InstrumentDefinitionEndEventHandler::beginInvoke(const QVariant& sender, const InstrumentDefinitionEndEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void InstrumentDefinitionEndEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void InstrumentDefinitionEndEventHandler::invoke(const QVariant& sender, const InstrumentDefinitionEndEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const InstrumentDefinitionEndEventHandler& instrumentdefinitionendeventhandler)
{
	return dbg << instrumentdefinitionendeventhandler.toString();
}

