#ifndef __QUANTKIT_GROUPUPDATEEVENTHANDLER_H__
#define __QUANTKIT_GROUPUPDATEEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class GroupUpdateEventHandlerPrivate;

class GroupUpdateEventAgrs;

class QUANTKIT_EXPORT GroupUpdateEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	GroupUpdateEventHandler(const QVariant& object, IntPtr method);
	~GroupUpdateEventHandler();

	GroupUpdateEventHandler(const GroupUpdateEventHandler &other);
	GroupUpdateEventHandler& operator=(const GroupUpdateEventHandler &other);
	bool operator==(const GroupUpdateEventHandler &other) const;
	inline bool operator!=(const GroupUpdateEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const GroupUpdateEventAgrs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const GroupUpdateEventAgrs& args);

private:
	QSharedDataPointer<GroupUpdateEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const GroupUpdateEventHandler& groupupdateeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const GroupUpdateEventHandler& groupupdateeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupUpdateEventHandler)

#endif // __QUANTKIT_GROUPUPDATEEVENTHANDLER_H__
