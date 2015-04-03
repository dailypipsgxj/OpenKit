#include <QuantKit/GroupManager.h>

#include <QuantKit/Framework.h>
#include <QuantKit/IdArray.h>
#include <QuantKit/Event/Group.h>
#include <QuantKit/Event/GroupEvent.h>

namespace QuantKit {

class GroupManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	int int_0;
	IdArray<Group> m_groups;
	QList<Group> m_groupList;

public:
	explicit GroupManagerPrivate(const Framework& framework) { Clear(); }
	virtual ~GroupManagerPrivate();

public:
	IdArray<Group> groups() const { return m_groups; }
	QList<Group> groupList() const { return m_groupList; }
	void add(const Group& group);
	void clear();
	virtual GroupManagerPrivate* clone() Q_DECL_OVERRIDE { return new GroupManagerPrivate(*this); }
//private:
	void setGroups(const IdArray<Group>& value) { m_groups = value; }
	void setGroupList(const QList<Group>& value) { m_groupList = value; }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupManagerPrivate::~GroupManagerPrivate ()
{
}

void GroupManagerPrivate::add(const Group& group)
{
	group.setId() = Interlocked.Increment(ref int_0);
	m_groups.Add(group.id(), group);
	m_groupList.Add(group);
	group.setFramework() = m_framework;
	m_framework.eventServer().OnLog(group);
}

void GroupManagerPrivate::clear()
{
	m_groups.Clear();
	m_groupList.Clear();
	int_0 = 0;
}


// Pubic API 

GroupManager::GroupManager(const Framework& framework)
	: d_ptr(new GroupManagerPrivate(framework))
{
}

GroupManager::~GroupManager()
{
}

GroupManager::GroupManager (const GroupManager &other)
	: d_ptr(other.d_ptr)
{
}

GroupManager& GroupManager::operator=(const GroupManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool GroupManager::operator==(const GroupManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

IdArray<Group> GroupManager::groups() const
{
	return d_ptr->groups();
}

QList<Group> GroupManager::groupList() const
{
	return d_ptr->groupList();
}

void GroupManager::add(const Group& group)
{
	d_ptr->add(group);
}

void GroupManager::clear()
{
	d_ptr->clear();
}

QDebug operator<<(QDebug dbg, const GroupManager& groupmanager)
{
	return dbg << groupmanager.toString();
}

