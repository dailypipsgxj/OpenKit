#ifndef __QUANTKIT_GROUPEVENTHANDLER_H__
#define __QUANTKIT_GROUPEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class GroupEventHandlerPrivate;

class GroupEventAgrs;

class QUANTKIT_EXPORT GroupEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	GroupEventHandler(const QVariant& object, IntPtr method);
	~GroupEventHandler();

	GroupEventHandler(const GroupEventHandler &other);
	GroupEventHandler& operator=(const GroupEventHandler &other);
	bool operator==(const GroupEventHandler &other) const;
	inline bool operator!=(const GroupEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const GroupEventAgrs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const GroupEventAgrs& args);

private:
	QSharedDataPointer<GroupEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const GroupEventHandler& groupeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const GroupEventHandler& groupeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupEventHandler)

#endif // __QUANTKIT_GROUPEVENTHANDLER_H__
