#include <QuantKit/HistoricalDataEventHandler.h>

#include <QuantKit/HistoricalDataEventArgs.h>

namespace QuantKit {

class HistoricalDataEventHandlerPrivate : public QSharedData
{
public:
	HistoricalDataEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~HistoricalDataEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const HistoricalDataEventArgs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const HistoricalDataEventArgs& e) Q_DECL_OVERRIDE;
	virtual HistoricalDataEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new HistoricalDataEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

HistoricalDataEventHandlerPrivate::HistoricalDataEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

HistoricalDataEventHandlerPrivate::~HistoricalDataEventHandlerPrivate ()
{
}

IAsyncResult HistoricalDataEventHandlerPrivate::beginInvoke(const QVariant& sender, const HistoricalDataEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void HistoricalDataEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void HistoricalDataEventHandlerPrivate::invoke(const QVariant& sender, const HistoricalDataEventArgs& e)
{
}


// Pubic API 

HistoricalDataEventHandler::HistoricalDataEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new HistoricalDataEventHandlerPrivate(object, method))
{
}

HistoricalDataEventHandler::~HistoricalDataEventHandler()
{
}

HistoricalDataEventHandler::HistoricalDataEventHandler (const HistoricalDataEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

HistoricalDataEventHandler& HistoricalDataEventHandler::operator=(const HistoricalDataEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool HistoricalDataEventHandler::operator==(const HistoricalDataEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult HistoricalDataEventHandler::beginInvoke(const QVariant& sender, const HistoricalDataEventArgs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void HistoricalDataEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void HistoricalDataEventHandler::invoke(const QVariant& sender, const HistoricalDataEventArgs& e)
{
	d_ptr->invoke(sender, e);
}

QDebug operator<<(QDebug dbg, const HistoricalDataEventHandler& historicaldataeventhandler)
{
	return dbg << historicaldataeventhandler.toString();
}

