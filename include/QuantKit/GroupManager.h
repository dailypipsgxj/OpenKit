#ifndef __QUANTKIT_GROUPMANAGER_H__
#define __QUANTKIT_GROUPMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QSharedDataPointer>

namespace QuantKit {

class GroupManagerPrivate;

class Framework;
class IdArray;
class Group;
class GroupEvent;

class QUANTKIT_EXPORT GroupManager
{
public:
	explicit GroupManager(const Framework& framework);
	~GroupManager();

	GroupManager(const GroupManager &other);
	GroupManager& operator=(const GroupManager &other);
	bool operator==(const GroupManager &other) const;
	inline bool operator!=(const GroupManager &other) const { return !(this->operator==(other));  }
public:
	IdArray<Group> groups() const;
	QList<Group> groupList() const;
	void add(const Group& group);
	void clear();

private:
	QSharedDataPointer<GroupManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const GroupManager& groupmanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const GroupManager& groupmanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupManager)

#endif // __QUANTKIT_GROUPMANAGER_H__
