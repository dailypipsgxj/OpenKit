#include <QuantKit/AskEventHandler.h>

#include <QuantKit/Event/Ask.h>

namespace QuantKit {

class AskEventHandlerPrivate : public QSharedData
{
public:
	AskEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~AskEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const Ask& ask, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const Ask& ask) Q_DECL_OVERRIDE;
	virtual AskEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new AskEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AskEventHandlerPrivate::AskEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

AskEventHandlerPrivate::~AskEventHandlerPrivate ()
{
}

IAsyncResult AskEventHandlerPrivate::beginInvoke(const QVariant& sender, const Ask& ask, const AsyncCallback& callback, const QVariant& object)
{
}

void AskEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void AskEventHandlerPrivate::invoke(const QVariant& sender, const Ask& ask)
{
}


// Pubic API 

AskEventHandler::AskEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new AskEventHandlerPrivate(object, method))
{
}

AskEventHandler::~AskEventHandler()
{
}

AskEventHandler::AskEventHandler (const AskEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

AskEventHandler& AskEventHandler::operator=(const AskEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool AskEventHandler::operator==(const AskEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult AskEventHandler::beginInvoke(const QVariant& sender, const Ask& ask, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, ask, callback, object);
}

void AskEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void AskEventHandler::invoke(const QVariant& sender, const Ask& ask)
{
	d_ptr->invoke(sender, ask);
}

QDebug operator<<(QDebug dbg, const AskEventHandler& askeventhandler)
{
	return dbg << askeventhandler.toString();
}

