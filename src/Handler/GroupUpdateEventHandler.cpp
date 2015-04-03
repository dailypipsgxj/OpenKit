#include <QuantKit/GroupUpdateEventHandler.h>

#include <QuantKit/GroupUpdateEventAgrs.h>

namespace QuantKit {

class GroupUpdateEventHandlerPrivate : public QSharedData
{
public:
	GroupUpdateEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~GroupUpdateEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const GroupUpdateEventAgrs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const GroupUpdateEventAgrs& args) Q_DECL_OVERRIDE;
	virtual GroupUpdateEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new GroupUpdateEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupUpdateEventHandlerPrivate::GroupUpdateEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

GroupUpdateEventHandlerPrivate::~GroupUpdateEventHandlerPrivate ()
{
}

IAsyncResult GroupUpdateEventHandlerPrivate::beginInvoke(const QVariant& sender, const GroupUpdateEventAgrs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void GroupUpdateEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void GroupUpdateEventHandlerPrivate::invoke(const QVariant& sender, const GroupUpdateEventAgrs& args)
{
}


// Pubic API 

GroupUpdateEventHandler::GroupUpdateEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new GroupUpdateEventHandlerPrivate(object, method))
{
}

GroupUpdateEventHandler::~GroupUpdateEventHandler()
{
}

GroupUpdateEventHandler::GroupUpdateEventHandler (const GroupUpdateEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

GroupUpdateEventHandler& GroupUpdateEventHandler::operator=(const GroupUpdateEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool GroupUpdateEventHandler::operator==(const GroupUpdateEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult GroupUpdateEventHandler::beginInvoke(const QVariant& sender, const GroupUpdateEventAgrs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void GroupUpdateEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void GroupUpdateEventHandler::invoke(const QVariant& sender, const GroupUpdateEventAgrs& args)
{
	d_ptr->invoke(sender, args);
}

QDebug operator<<(QDebug dbg, const GroupUpdateEventHandler& groupupdateeventhandler)
{
	return dbg << groupupdateeventhandler.toString();
}

