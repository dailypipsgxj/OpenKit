#ifndef __QUANTKIT_IGROUPLISTENER_H__
#define __QUANTKIT_IGROUPLISTENER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>

namespace QuantKit {

class Group;
class GroupEvent;
class GroupUpdate;
class PermanentQueue;
class Event;

class QUANTKIT_EXPORT IGroupListener
{
public:
	virtual PermanentQueue<Event> queue() const = 0;
	virtual bool onNewGroup(const Group& group) = 0;
	virtual void onNewGroupEvent(const GroupEvent& groupEvent) = 0;
	virtual void onNewGroupUpdate(const GroupUpdate& groupUpdate) = 0;
};

} // namespace QuantKit

#endif // __QUANTKIT_IGROUPLISTENER_H__
