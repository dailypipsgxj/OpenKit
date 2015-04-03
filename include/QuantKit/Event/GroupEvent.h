#ifndef __QUANTKIT_GROUPEVENT_H__
#define __QUANTKIT_GROUPEVENT_H__

#include <QuantKit/quantkit_global.h>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class GroupEventPrivate;

class Group;
class Event;

class QUANTKIT_EXPORT GroupEvent Q_DECL_FINAL : public DataObject
{
public:
	GroupEvent(const Event& obj, const Group& group);
	GroupEvent(const Event& obj, int groupId);
	~GroupEvent();

public:
	Group group() const;
	void setGroup(const Group& value);
	Event obj() const;
	int groupId() const;

private:
	QK_DECLARE_PRIVATE(GroupEvent)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::GroupEvent)

#endif // __QUANTKIT_GROUPEVENT_H__
