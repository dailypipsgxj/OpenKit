#include <QuantKit/HistoricalDataEndEventHandler.h>

#include <QuantKit/HistoricalDataEndEventArgs.h>

namespace QuantKit {

class HistoricalDataEndEventHandlerPrivate : public QSharedData
{
public:
	HistoricalDataEndEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~HistoricalDataEndEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const HistoricalDataEndEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const HistoricalDataEndEventArgs& e) Q_DECL_OVERRIDE;
	virtual HistoricalDataEndEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new HistoricalDataEndEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

HistoricalDataEndEventHandlerPrivate::HistoricalDataEndEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

HistoricalDataEndEventHandlerPrivate::~HistoricalDataEndEventHandlerPrivate ()
{
}

IAsyncResult HistoricalDataEndEventHandlerPrivate::beginInvoke(const QVariant& sender, const HistoricalDataEndEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void HistoricalDataEndEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void HistoricalDataEndEventHandlerPrivate::invoke(const QVariant& sender, const HistoricalDataEndEventArgs& e)
{
}


// Pubic API 

HistoricalDataEndEventHandler::HistoricalDataEndEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new HistoricalDataEndEventHandlerPrivate(object, method))
{
}

HistoricalDataEndEventHandler::~HistoricalDataEndEventHandler()
{
}

HistoricalDataEndEventHandler::HistoricalDataEndEventHandler (const HistoricalDataEndEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

HistoricalDataEndEventHandler& HistoricalDataEndEventHandler::operator=(const HistoricalDataEndEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool HistoricalDataEndEventHandler::operator==(const HistoricalDataEndEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult HistoricalDataEndEventHandler::beginInvoke(const QVariant& sender, const HistoricalDataEndEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void HistoricalDataEndEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void HistoricalDataEndEventHandler::invoke(const QVariant& sender, const HistoricalDataEndEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const HistoricalDataEndEventHandler& historicaldataendeventhandler)
{
	return dbg << historicaldataendeventhandler.toString();
}

