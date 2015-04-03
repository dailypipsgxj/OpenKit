#include <QuantKit/TransactionEventHandler.h>

#include <QuantKit/Event/OnTransaction.h>

namespace QuantKit {

class TransactionEventHandlerPrivate : public QSharedData
{
public:
	TransactionEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~TransactionEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const OnTransaction& transaction, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const OnTransaction& transaction) Q_DECL_OVERRIDE;
	virtual TransactionEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new TransactionEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TransactionEventHandlerPrivate::TransactionEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

TransactionEventHandlerPrivate::~TransactionEventHandlerPrivate ()
{
}

IAsyncResult TransactionEventHandlerPrivate::beginInvoke(const QVariant& sender, const OnTransaction& transaction, const AsyncCallback& callback, const QVariant& object)
{
}

void TransactionEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void TransactionEventHandlerPrivate::invoke(const QVariant& sender, const OnTransaction& transaction)
{
}


// Pubic API 

TransactionEventHandler::TransactionEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new TransactionEventHandlerPrivate(object, method))
{
}

TransactionEventHandler::~TransactionEventHandler()
{
}

TransactionEventHandler::TransactionEventHandler (const TransactionEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

TransactionEventHandler& TransactionEventHandler::operator=(const TransactionEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool TransactionEventHandler::operator==(const TransactionEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult TransactionEventHandler::beginInvoke(const QVariant& sender, const OnTransaction& transaction, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, transaction, callback, object);
}

void TransactionEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void TransactionEventHandler::invoke(const QVariant& sender, const OnTransaction& transaction)
{
	d_ptr->invoke(sender, transaction);
}

QDebug operator<<(QDebug dbg, const TransactionEventHandler& transactioneventhandler)
{
	return dbg << transactioneventhandler.toString();
}

