#include <QuantKit/TradeEventHandler.h>

#include <QuantKit/Event/Trade.h>

namespace QuantKit {

class TradeEventHandlerPrivate : public QSharedData
{
public:
	TradeEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~TradeEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const Trade& trade, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const Trade& trade) Q_DECL_OVERRIDE;
	virtual TradeEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new TradeEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TradeEventHandlerPrivate::TradeEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

TradeEventHandlerPrivate::~TradeEventHandlerPrivate ()
{
}

IAsyncResult TradeEventHandlerPrivate::beginInvoke(const QVariant& sender, const Trade& trade, const AsyncCallback& callback, const QVariant& object)
{
}

void TradeEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void TradeEventHandlerPrivate::invoke(const QVariant& sender, const Trade& trade)
{
}


// Pubic API 

TradeEventHandler::TradeEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new TradeEventHandlerPrivate(object, method))
{
}

TradeEventHandler::~TradeEventHandler()
{
}

TradeEventHandler::TradeEventHandler (const TradeEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

TradeEventHandler& TradeEventHandler::operator=(const TradeEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool TradeEventHandler::operator==(const TradeEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult TradeEventHandler::beginInvoke(const QVariant& sender, const Trade& trade, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, trade, callback, object);
}

void TradeEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void TradeEventHandler::invoke(const QVariant& sender, const Trade& trade)
{
	d_ptr->invoke(sender, trade);
}

QDebug operator<<(QDebug dbg, const TradeEventHandler& tradeeventhandler)
{
	return dbg << tradeeventhandler.toString();
}

