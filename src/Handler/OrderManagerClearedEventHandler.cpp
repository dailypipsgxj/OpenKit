#include <QuantKit/OrderManagerClearedEventHandler.h>

#include <QuantKit/Event/OnOrderManagerCleared.h>

namespace QuantKit {

class OrderManagerClearedEventHandlerPrivate : public QSharedData
{
public:
	OrderManagerClearedEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~OrderManagerClearedEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const OnOrderManagerCleared& data, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const OnOrderManagerCleared& data) Q_DECL_OVERRIDE;
	virtual OrderManagerClearedEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new OrderManagerClearedEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OrderManagerClearedEventHandlerPrivate::OrderManagerClearedEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

OrderManagerClearedEventHandlerPrivate::~OrderManagerClearedEventHandlerPrivate ()
{
}

IAsyncResult OrderManagerClearedEventHandlerPrivate::beginInvoke(const QVariant& sender, const OnOrderManagerCleared& data, const AsyncCallback& callback, const QVariant& object)
{
}

void OrderManagerClearedEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void OrderManagerClearedEventHandlerPrivate::invoke(const QVariant& sender, const OnOrderManagerCleared& data)
{
}


// Pubic API 

OrderManagerClearedEventHandler::OrderManagerClearedEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new OrderManagerClearedEventHandlerPrivate(object, method))
{
}

OrderManagerClearedEventHandler::~OrderManagerClearedEventHandler()
{
}

OrderManagerClearedEventHandler::OrderManagerClearedEventHandler (const OrderManagerClearedEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

OrderManagerClearedEventHandler& OrderManagerClearedEventHandler::operator=(const OrderManagerClearedEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool OrderManagerClearedEventHandler::operator==(const OrderManagerClearedEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult OrderManagerClearedEventHandler::beginInvoke(const QVariant& sender, const OnOrderManagerCleared& data, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, data, callback, object);
}

void OrderManagerClearedEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void OrderManagerClearedEventHandler::invoke(const QVariant& sender, const OnOrderManagerCleared& data)
{
	d_ptr->invoke(sender, data);
}

QDebug operator<<(QDebug dbg, const OrderManagerClearedEventHandler& ordermanagerclearedeventhandler)
{
	return dbg << ordermanagerclearedeventhandler.toString();
}

