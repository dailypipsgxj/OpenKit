#include <QuantKit/OrderEventHandler.h>

#include <QuantKit/Event/Order.h>

namespace QuantKit {

class OrderEventHandlerPrivate : public QSharedData
{
public:
	OrderEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~OrderEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const Order& Order, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const Order& Order) Q_DECL_OVERRIDE;
	virtual OrderEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new OrderEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OrderEventHandlerPrivate::OrderEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

OrderEventHandlerPrivate::~OrderEventHandlerPrivate ()
{
}

IAsyncResult OrderEventHandlerPrivate::beginInvoke(const Order& Order, const AsyncCallback& callback, const QVariant& object)
{
}

void OrderEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void OrderEventHandlerPrivate::invoke(const Order& Order)
{
}


// Pubic API 

OrderEventHandler::OrderEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new OrderEventHandlerPrivate(object, method))
{
}

OrderEventHandler::~OrderEventHandler()
{
}

OrderEventHandler::OrderEventHandler (const OrderEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

OrderEventHandler& OrderEventHandler::operator=(const OrderEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool OrderEventHandler::operator==(const OrderEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult OrderEventHandler::beginInvoke(const Order& Order, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(Order, callback, object);
}

void OrderEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void OrderEventHandler::invoke(const Order& Order)
{
	d_ptr->invoke(Order);
}

QDebug operator<<(QDebug dbg, const OrderEventHandler& ordereventhandler)
{
	return dbg << ordereventhandler.toString();
}

