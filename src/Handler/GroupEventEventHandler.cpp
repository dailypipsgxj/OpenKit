#include <QuantKit/GroupEventEventHandler.h>

#include <QuantKit/GroupEventEventAgrs.h>

namespace QuantKit {

class GroupEventEventHandlerPrivate : public QSharedData
{
public:
	GroupEventEventHandlerPrivate(const QVariant& object, IntPtr method);
	virtual ~GroupEventEventHandlerPrivate();

public:
	virtual IAsyncResult beginInvoke(const QVariant& sender, const GroupEventEventAgrs& args, const AsyncCallback& callback, const QVariant& object) Q_DECL_OVERRIDE;
	virtual void endInvoke(const IAsyncResult& result) Q_DECL_OVERRIDE;
	virtual void invoke(const QVariant& sender, const GroupEventEventAgrs& args) Q_DECL_OVERRIDE;
	virtual GroupEventEventHandlerPrivate* clone() Q_DECL_OVERRIDE { return new GroupEventEventHandlerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupEventEventHandlerPrivate::GroupEventEventHandlerPrivate(const QVariant& object, IntPtr method)
{
}

GroupEventEventHandlerPrivate::~GroupEventEventHandlerPrivate ()
{
}

IAsyncResult GroupEventEventHandlerPrivate::beginInvoke(const QVariant& sender, const GroupEventEventAgrs& args, const AsyncCallback& callback, const QVariant& object)
{
}

void GroupEventEventHandlerPrivate::endInvoke(const IAsyncResult& result)
{
}

void GroupEventEventHandlerPrivate::invoke(const QVariant& sender, const GroupEventEventAgrs& args)
{
}


// Pubic API 

GroupEventEventHandler::GroupEventEventHandler(const QVariant& object, IntPtr method)
	: d_ptr(new GroupEventEventHandlerPrivate(object, method))
{
}

GroupEventEventHandler::~GroupEventEventHandler()
{
}

GroupEventEventHandler::GroupEventEventHandler (const GroupEventEventHandler &other)
	: d_ptr(other.d_ptr)
{
}

GroupEventEventHandler& GroupEventEventHandler::operator=(const GroupEventEventHandler &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool GroupEventEventHandler::operator==(const GroupEventEventHandler &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IAsyncResult GroupEventEventHandler::beginInvoke(const QVariant& sender, const GroupEventEventAgrs& args, const AsyncCallback& callback, const QVariant& object)
{
	return d_ptr->beginInvoke(sender, args, callback, object);
}

void GroupEventEventHandler::endInvoke(const IAsyncResult& result)
{
	d_ptr->endInvoke(result);
}

void GroupEventEventHandler::invoke(const QVariant& sender, const GroupEventEventAgrs& args)
{
	d_ptr->invoke(sender, args);
}

QDebug operator<<(QDebug dbg, const GroupEventEventHandler& groupeventeventhandler)
{
	return dbg << groupeventeventhandler.toString();
}

