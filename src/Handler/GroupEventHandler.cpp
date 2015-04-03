#include <QuantKit/GroupEventHandler.h>

#include <QuantKit/GroupEventAgrs.h>

namespace QuantKit {

class GroupEventHandlerPrivate : public QSharedData
{
public:
	GroupEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~GroupEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const GroupEventAgrs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const GroupEventAgrs& args) Q_DECL_OVERRIDE;
	virtual GroupEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new GroupEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupEventHandlerPrivate::GroupEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

GroupEventHandlerPrivate::~GroupEventHandlerPrivate ()
{
}

IAsyncResult GroupEventHandlerPrivate::beginInvoke(const QVariant& sender, const GroupEventAgrs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void GroupEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void GroupEventHandlerPrivate::invoke(const QVariant& sender, const GroupEventAgrs& args)
{
}


// Pubic API 

GroupEventHandler::GroupEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new GroupEventHandlerPrivate(object, method))
{
}

GroupEventHandler::~GroupEventHandler()
{
}

GroupEventHandler::GroupEventHandler (const GroupEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

GroupEventHandler& GroupEventHandler::operator=(const GroupEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool GroupEventHandler::operator==(const GroupEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult GroupEventHandler::beginInvoke(const QVariant& sender, const GroupEventAgrs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void GroupEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void GroupEventHandler::invoke(const QVariant& sender, const GroupEventAgrs& args)
{
	d_ptr->invoke(sender, args);
}

QDebug operator<<(QDebug dbg, const GroupEventHandler& groupeventhandler)
{
	return dbg << groupeventhandler.toString();
}

