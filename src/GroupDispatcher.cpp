#include <QuantKit/GroupDispatcher.h>

#include <QuantKit/Framework.h>
#include <QuantKit/FrameworkEventArgs.h>
#include <QuantKit/GroupUpdateEventAgrs.h>
#include <QuantKit/GroupEventEventAgrs.h>
#include <QuantKit/GroupEventAgrs.h>
#include <QuantKit/Event/Group.h>
#include <QuantKit/IdArray.h>

namespace QuantKit {

class GroupDispatcherPrivate : public QSharedData
{
public:
	Framework m_framework;
	IdArray<QList<IGroupListener>> m_idArray;
	QList<IGroupListener> list_0;
	Dictionary<IGroupListener,QList<int>> m_dictionary;

public:
	explicit GroupDispatcherPrivate(const Framework& framework);
	virtual ~GroupDispatcherPrivate();

public:
	void addListener(const IGroupListener& listener);
	void removeListener(const IGroupListener& listener);
	virtual GroupDispatcherPrivate* clone() Q_DECL_OVERRIDE { return new GroupDispatcherPrivate(*this); }
//private:
	void method_0(const QVariant& sender, const FrameworkEventArgs& e);
	void method_1(const QVariant& object, const GroupUpdateEventAgrs& groupUpdateEventAgrs);
	void method_2(const QVariant& object, const GroupEventEventAgrs& groupEventEventAgrs);
	void method_3(const QVariant& object, const GroupEventAgrs& groupEventAgrs);
	void method_4(const IGroupListener& igroupListener, const Group& group);
};

} // namepsace QuantKit


using namespace QuantKit;

GroupDispatcherPrivate::GroupDispatcherPrivate(const Framework& framework)
	: m_framework(framework)
	, m_idArray(new IdArray<QList<IGroupListener>>(1000))
	, list_0(new QList<IGroupListener>())
	, m_dictionary(new Dictionary<IGroupListener, QList<int>>())
{
		framework.eventManager().dispatcher().addNewGroup() += new GroupEventHandler(method_3());
		framework.eventManager().dispatcher().addNewGroupEvent() += new GroupEventEventHandler(method_2());
		framework.eventManager().dispatcher().addNewGroupUpdate() += new GroupUpdateEventHandler(method_1());
		framework.eventManager().dispatcher().addFrameworkCleared() += new FrameworkEventHandler(method_0());
}

GroupDispatcherPrivate::~GroupDispatcherPrivate ()
{
}

void GroupDispatcherPrivate::addListener(const IGroupListener& listener)
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		list_0.Add(listener);
		m_dictionary[listener] = new List<int>();
		for (int i = 0; i < m_framework.groupManager().groupList().Count; i++)
		{
			method_4(listener, m_framework.groupManager().groupList()[i]);
		}
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

void GroupDispatcherPrivate::removeListener(const IGroupListener& listener)
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		list_0.Remove(listener);
		foreach (int current in m_dictionary[listener])
		{
			m_idArray[current].Remove(listener);
		}
		m_dictionary.Remove(listener);
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

void GroupDispatcherPrivate::method_0(const QVariant& sender, const FrameworkEventArgs& e)
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		foreach (IGroupListener current in list_0)
		{
			current.queue().Enqueue(new OnFrameworkCleared(e.framework()));
		}
		m_idArray.Clear();
		foreach (List<int> current2 in m_dictionary.Values)
		{
			current2.Clear();
		}
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

void GroupDispatcherPrivate::method_1(const QVariant& object, const GroupUpdateEventAgrs& groupUpdateEventAgrs)
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		if (groupUpdateEventAgrs.groupUpdate().groupId() != -1)
		{
			List<IGroupListener> list = m_idArray[groupUpdateEventAgrs.groupUpdate().groupId()];
			if (list != null)
			{
				foreach (IGroupListener current in list)
				{
					current.OnNewGroupUpdate(groupUpdateEventAgrs.groupUpdate());
				}
			}
		}
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

void GroupDispatcherPrivate::method_2(const QVariant& object, const GroupEventEventAgrs& groupEventEventAgrs)
{
	bool flag = false;
	try
	{
		Monitor.Enter(this, ref flag);
		if (groupEventEventAgrs.groupEvent().group() != null)
		{
			Group group = m_framework.groupManager().groups()[groupEventEventAgrs.groupEvent().group().id()];
			if (group != null)
			{
				group.OnNewGroupEvent(groupEventEventAgrs.groupEvent());
				List<IGroupListener> list = m_idArray[groupEventEventAgrs.groupEvent().group().id()];
				if (list != null)
				{
					foreach (IGroupListener current in list)
					{
						current.queue().Enqueue(groupEventEventAgrs.groupEvent());
					}
				}
			}
		}
	}
	finally
	{
		if (flag)
		{
			Monitor.Exit(this);
		}
	}
}

void GroupDispatcherPrivate::method_3(const QVariant& object, const GroupEventAgrs& groupEventAgrs)
{
	foreach (IGroupListener current in list_0)
	{
		method_4(current, groupEventAgrs.group());
	}
}

void GroupDispatcherPrivate::method_4(const IGroupListener& igroupListener, const Group& group)
{
	if (igroupListener.OnNewGroup(group))
	{
		List<IGroupListener> list = m_idArray[group.id()];
		if (list == null)
		{
			list = new List<IGroupListener>();
			m_idArray[group.id()] = list;
		}
		m_dictionary[igroupListener].Add(group.id());
		list.Add(igroupListener);
		foreach (GroupEvent current in group.events())
		{
			igroupListener.queue().Enqueue(current);
		}
	}
}


// Pubic API 

GroupDispatcher::GroupDispatcher(const Framework& framework)
	: d_ptr(new GroupDispatcherPrivate(framework))
{
}

GroupDispatcher::~GroupDispatcher()
{
}

GroupDispatcher::GroupDispatcher (const GroupDispatcher &other)
	: d_ptr(other.d_ptr)
{
}

GroupDispatcher& GroupDispatcher::operator=(const GroupDispatcher &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool GroupDispatcher::operator==(const GroupDispatcher &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

void GroupDispatcher::addListener(const IGroupListener& listener)
{
	d_ptr->addListener(listener);
}

void GroupDispatcher::removeListener(const IGroupListener& listener)
{
	d_ptr->removeListener(listener);
}

QDebug operator<<(QDebug dbg, const GroupDispatcher& groupdispatcher)
{
	return dbg << groupdispatcher.toString();
}

