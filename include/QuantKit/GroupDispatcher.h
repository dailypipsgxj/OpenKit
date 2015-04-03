#ifndef __QUANTKIT_GROUPDISPATCHER_H__
#define __QUANTKIT_GROUPDISPATCHER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QVariant>
#include <QList>
#include <Dictionary>
#include <QSharedDataPointer>

#include <QuantKit/IGroupListener.h>

namespace QuantKit {

class GroupDispatcherPrivate;

class Framework;
class FrameworkEventArgs;
class GroupUpdateEventAgrs;
class GroupEventEventAgrs;
class GroupEventAgrs;
class Group;
class IdArray;

class QUANTKIT_EXPORT GroupDispatcher
{
public:
	explicit GroupDispatcher(const Framework& framework);
	~GroupDispatcher();

	GroupDispatcher(const GroupDispatcher &other);
	GroupDispatcher& operator=(const GroupDispatcher &other);
	bool operator==(const GroupDispatcher &other) const;
	inline bool operator!=(const GroupDispatcher &other) const { return !(this->operator==(other));  }
public:
	void addListener(const IGroupListener& listener);
	void removeListener(const IGroupListener& listener);

private:
	QSharedDataPointer<GroupDispatcherPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const GroupDispatcher& groupdispatcher);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const GroupDispatcher& groupdispatcher);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupDispatcher)

#endif // __QUANTKIT_GROUPDISPATCHER_H__
