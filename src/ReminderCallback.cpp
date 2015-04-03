#include <QuantKit/ReminderCallback.h>


namespace QuantKit {

class ReminderCallbackPrivate : public QSharedData
{
public:
	ReminderCallbackPrivate(const QVariant& object, IntPtr method);
	virtual ~ReminderCallbackPrivate();

public:
	virtual IAsyncResult beginInvoke(const QDateTime& dateTime, const QVariant& data, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QDateTime& dateTime, const QVariant& data) Q_DECL_OVERRIDE;
	virtual ReminderCallbackPrivate* clone() Q_DECL_OVERRIDE { return new ReminderCallbackPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ReminderCallbackPrivate::ReminderCallbackPrivate(const QVariant& object, IntPtr method)
{
}

ReminderCallbackPrivate::~ReminderCallbackPrivate ()
{
}

IAsyncResult ReminderCallbackPrivate::beginInvoke(const QDateTime& dateTime, const QVariant& data, const AsyncCallback& callback, const QVariant& object)
{
}

void ReminderCallbackPrivate::endInvoke(const IAsyncResult& result)
{
}

void ReminderCallbackPrivate::invoke(const QDateTime& dateTime, const QVariant& data)
{
}


// Pubic API 

ReminderCallback::ReminderCallback(const QVariant& object, IntPtr method)
	: d_ptr(new ReminderCallbackPrivate(object, method))
{
}

ReminderCallback::~ReminderCallback()
{
}

ReminderCallback::ReminderCallback (const ReminderCallback &other)
	: d_ptr(other.d_ptr)
{
}

ReminderCallback& ReminderCallback::operator=(const ReminderCallback &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ReminderCallback::operator==(const ReminderCallback &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult ReminderCallback::beginInvoke(const QDateTime& dateTime, const QVariant& data, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(dateTime, data, callback, object);
}

void ReminderCallback::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void ReminderCallback::invoke(const QDateTime& dateTime, const QVariant& data)
{
	d_ptr->invoke(dateTime, data);
}

QDebug operator<<(QDebug dbg, const ReminderCallback& remindercallback)
{
	return dbg << remindercallback.toString();
}

