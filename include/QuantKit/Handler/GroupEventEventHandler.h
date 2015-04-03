#ifndef __QUANTKIT_GROUPEVENTEVENTHANDLER_H__
#define __QUANTKIT_GROUPEVENTEVENTHANDLER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <IAsyncResult>
#include <AsyncCallback>
#include <QSharedDataPointer>

namespace QuantKit {

class GroupEventEventHandlerPrivate;

class GroupEventEventAgrs;

class QUANTKIT_EXPORT GroupEventEventHandler Q_DECL_FINAL : public MulticastDelegate
{
public:
	GroupEventEventHandler(const QVariant& object, IntPtr method);
	~GroupEventEventHandler();

	GroupEventEventHandler(const GroupEventEventHandler &other);
	GroupEventEventHandler& operator=(const GroupEventEventHandler &other);
	bool operator==(const GroupEventEventHandler &other) const;
	inline bool operator!=(const GroupEventEventHandler &other) const { return !(this->operator==(other));  }
public:
	IAsyncResult beginInvoke(const QVariant& sender, const GroupEventEventAgrs& args, const AsyncCallback& callback, const QVariant& object);
	void endInvoke(const IAsyncResult& result);
	void invoke(const QVariant& sender, const GroupEventEventAgrs& args);

private:
	QSharedDataPointer<GroupEventEventHandlerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const GroupEventEventHandler& groupeventeventhandler);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const GroupEventEventHandler& groupeventeventhandler);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupEventEventHandler)

#endif // __QUANTKIT_GROUPEVENTEVENTHANDLER_H__
