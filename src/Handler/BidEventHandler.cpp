#include <QuantKit/BidEventHandler.h>

#include <QuantKit/Event/Bid.h>

namespace QuantKit {

class BidEventHandlerPrivate : public QSharedData
{
public:
	BidEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~BidEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const Bid& bid, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const Bid& bid) Q_DECL_OVERRIDE;
	virtual BidEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new BidEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

BidEventHandlerPrivate::BidEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

BidEventHandlerPrivate::~BidEventHandlerPrivate ()
{
}

IAsyncResult BidEventHandlerPrivate::beginInvoke(const QVariant& sender, const Bid& bid, const AsyncCallback& callback, const QVariant& object)
{
}

void BidEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void BidEventHandlerPrivate::invoke(const QVariant& sender, const Bid& bid)
{
}


// Pubic API 

BidEventHandler::BidEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new BidEventHandlerPrivate(object, method))
{
}

BidEventHandler::~BidEventHandler()
{
}

BidEventHandler::BidEventHandler (const BidEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

BidEventHandler& BidEventHandler::operator=(const BidEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool BidEventHandler::operator==(const BidEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult BidEventHandler::beginInvoke(const QVariant& sender, const Bid& bid, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, bid, callback, object);
}

void BidEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void BidEventHandler::invoke(const QVariant& sender, const Bid& bid)
{
	d_ptr->invoke(sender, bid);
}

QDebug operator<<(QDebug dbg, const BidEventHandler& bideventhandler)
{
	return dbg << bideventhandler.toString();
}

