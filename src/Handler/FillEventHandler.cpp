#include <QuantKit/FillEventHandler.h>

#include <QuantKit/Event/OnFill.h>

namespace QuantKit {

class FillEventHandlerPrivate : public QSharedData
{
public:
	FillEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~FillEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const OnFill& fill, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const OnFill& fill) Q_DECL_OVERRIDE;
	virtual FillEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new FillEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

FillEventHandlerPrivate::FillEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

FillEventHandlerPrivate::~FillEventHandlerPrivate ()
{
}

IAsyncResult FillEventHandlerPrivate::beginInvoke(const QVariant& sender, const OnFill& fill, const AsyncCallback& callback, const QVariant& object)
{
}

void FillEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void FillEventHandlerPrivate::invoke(const QVariant& sender, const OnFill& fill)
{
}


// Pubic API 

FillEventHandler::FillEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new FillEventHandlerPrivate(object, method))
{
}

FillEventHandler::~FillEventHandler()
{
}

FillEventHandler::FillEventHandler (const FillEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

FillEventHandler& FillEventHandler::operator=(const FillEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool FillEventHandler::operator==(const FillEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult FillEventHandler::beginInvoke(const QVariant& sender, const OnFill& fill, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, fill, callback, object);
}

void FillEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void FillEventHandler::invoke(const QVariant& sender, const OnFill& fill)
{
	d_ptr->invoke(sender, fill);
}

QDebug operator<<(QDebug dbg, const FillEventHandler& filleventhandler)
{
	return dbg << filleventhandler.toString();
}

