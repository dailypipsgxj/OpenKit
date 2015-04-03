#include <QuantKit/Event/GroupEvent.h>

#include <QuantKit/Event/Group.h>
#include "Event_p.h"

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class GroupEventPrivate : public DataObjectPrivate
{
public:
	Group m_group;
	Event m_obj;
	int m_groupId;

public:
	GroupEventPrivate(const Event& obj, const Group& group);
	GroupEventPrivate(const Event& obj, int groupId);
	virtual ~GroupEventPrivate();

public:
	Group group() const { return m_group; }
	void setGroup(const Group& value) { m_group = value; }
	Event obj() const { return m_obj; }
	int groupId() const { return m_groupId; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::GroupEvent; }
	virtual GroupEventPrivate* clone() Q_DECL_OVERRIDE { return new GroupEventPrivate(*this); }
//private:
	void setObj(const Event& value) { m_obj = value; }
	void setGroupId(int value) { m_groupId = value; }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupEventPrivate::GroupEventPrivate(const Event& obj, const Group& group)
	: m_group(group)
	, m_obj(obj)
	, m_groupId(group.id())
	, m_groupId(-1)
{
		if (group != null)
		{
			return;
		}
}

GroupEventPrivate::GroupEventPrivate(const Event& obj, int groupId)
	: m_obj(obj)
	, m_groupId(groupId)
{
}

GroupEventPrivate::~GroupEventPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(GroupEvent)

GroupEvent::GroupEvent(const Event& obj, const Group& group)
	: DataObject(*new GroupEventPrivate(obj, group))
{
}

GroupEvent::GroupEvent(const Event& obj, int groupId)
	: DataObject(*new GroupEventPrivate(obj, groupId))
{
}

GroupEvent::~GroupEvent()
{
}

Group GroupEvent::group() const
{
	Q_D(const GroupEvent);
	return d->group();
}

void GroupEvent::setGroup(const Group& value)
{
	Q_D(GroupEvent);
	d->setGroup(value);
}

Event GroupEvent::obj() const
{
	Q_D(const GroupEvent);
	return d->obj();
}

int GroupEvent::groupId() const
{
	Q_D(const GroupEvent);
	return d->groupId();
}


