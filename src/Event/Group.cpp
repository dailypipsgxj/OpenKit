#include <QuantKit/Event/Group.h>

#include <QuantKit/GroupField.h>
#include <QuantKit/Framework.h>
#include <QuantKit/Event/GroupEvent.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class GroupPrivate : public DataObjectPrivate
{
public:
	int m_id;
	QString m_name;
	Dictionary<QString,GroupField> m_fields;
	Framework m_framework;
	QList<GroupEvent> m_events;

public:
	explicit GroupPrivate(const QString& name);
	virtual ~GroupPrivate();

public:
	int id() const { return m_id; }
	QString name() const { return m_name; }
	Dictionary<QString,GroupField> fields() const { return m_fields; }
	Framework framework() const { return m_framework; }
	void setFramework(const Framework& value) { m_framework = value; }
	QList<GroupEvent> events() const { return m_events; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::Group; }
	void add(const QString& name, unsigned char type, const QVariant& value)
	{
		method_0(new GroupField(name, type, value));
	}

	void add(const QString& name, const Color& color)
	{
		method_0(new GroupField(name, 156, color));
	}

	void add(const QString& name, const QString& value)
	{
		method_0(new GroupField(name, 150, value));
	}

	void add(const QString& name, int value)
	{
		method_0(new GroupField(name, 152, value));
	}

	void add(const QString& name, bool value)
	{
		method_0(new GroupField(name, 155, value));
	}

	void add(const QString& name, const QDateTime& dateTime)
	{
		method_0(new GroupField(name, 153, dateTime));
	}

	void onNewGroupEvent(const GroupEvent& groupEvent) { m_events.Add(groupEvent); }
	void remove(const QString& fieldName) { m_fields.Remove(fieldName); }
	virtual GroupPrivate* clone() Q_DECL_OVERRIDE { return new GroupPrivate(*this); }
//private:
	void setName(const QString& value) { m_name = value; }
	void setFields(const Dictionary<QString,GroupField>& value) { m_fields = value; }
	void setEvents(const QList<GroupEvent>& value) { m_events = value; }
	void method_0(const GroupField& groupField);
};

} // namepsace QuantKit


using namespace QuantKit;

GroupPrivate::GroupPrivate(const QString& name)
	: m_name(name)
	, m_fields(new Dictionary<string, GroupField>())
	, m_events(new QList<GroupEvent>())
{
}

GroupPrivate::~GroupPrivate ()
{
}

void GroupPrivate::method_0(const GroupField& groupField)
{
	m_fields[groupField.name()] = groupField;
	groupField.setGroup_0() = this;
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(Group)

Group::Group(const QString& name)
	: DataObject(*new GroupPrivate(name))
{
}

Group::~Group()
{
}

int Group::id() const
{
	Q_D(const Group);
	return d->id();
}

QString Group::name() const
{
	Q_D(const Group);
	return d->name();
}

Dictionary<QString,GroupField> Group::fields() const
{
	Q_D(const Group);
	return d->fields();
}

Framework Group::framework() const
{
	Q_D(const Group);
	return d->framework();
}

void Group::setFramework(const Framework& value)
{
	Q_D(Group);
	d->setFramework(value);
}

QList<GroupEvent> Group::events() const
{
	Q_D(const Group);
	return d->events();
}

void Group::add(const QString& name, unsigned char type, const QVariant& value)
{
	Q_D(Group);
	d->add(name, type, value);
}

void Group::add(const QString& name, Color color)
{
	Q_D(Group);
	d->add(name, color);
}

void Group::add(const QString& name, const QString& value)
{
	Q_D(Group);
	d->add(name, value);
}

void Group::add(const QString& name, int value)
{
	Q_D(Group);
	d->add(name, value);
}

void Group::add(const QString& name, bool value)
{
	Q_D(Group);
	d->add(name, value);
}

void Group::add(const QString& name, const QDateTime& dateTime)
{
	Q_D(Group);
	d->add(name, dateTime);
}

void Group::onNewGroupEvent(const GroupEvent& groupEvent)
{
	Q_D(Group);
	d->onNewGroupEvent(groupEvent);
}

void Group::remove(const QString& fieldName)
{
	Q_D(Group);
	d->remove(fieldName);
}


