#include <QuantKit/Event/GroupUpdate.h>

#include "DataObject_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class GroupUpdatePrivate : public DataObjectPrivate
{
public:
	int m_groupId;
	QString m_fieldName;
	GroupUpdateType m_updateType;
	unsigned char m_fieldType;
	QVariant m_value;
	QVariant m_oldValue;

public:
	GroupUpdatePrivate(int groupId, const QString& fieldName, unsigned char fieldType, const QVariant& value, const QVariant& oldValue, GroupUpdateType updateType);
	virtual ~GroupUpdatePrivate();

public:
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::GroupUpdate; }
	int groupId() const { return m_groupId; }
	QString fieldName() const { return m_fieldName; }
	GroupUpdateType updateType() const { return m_updateType; }
	unsigned char fieldType() const { return m_fieldType; }
	QVariant value() const { return m_value; }
	QVariant oldValue() const { return m_oldValue; }
	virtual GroupUpdatePrivate* clone() Q_DECL_OVERRIDE { return new GroupUpdatePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupUpdatePrivate::GroupUpdatePrivate(int groupId, const QString& fieldName, unsigned char fieldType, const QVariant& value, const QVariant& oldValue, GroupUpdateType updateType)
	: m_groupId(groupId)
	, m_fieldName(fieldName)
	, m_updateType(updateType)
	, m_fieldType(fieldType)
	, m_value(value)
	, m_oldValue(oldValue)
{
}

GroupUpdatePrivate::~GroupUpdatePrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(GroupUpdate)

GroupUpdate::GroupUpdate(int groupId, const QString& fieldName, unsigned char fieldType, const QVariant& value, const QVariant& oldValue, GroupUpdateType updateType)
	: DataObject(*new GroupUpdatePrivate(groupId, fieldName, fieldType, value, oldValue, updateType))
{
}

GroupUpdate::~GroupUpdate()
{
}

int GroupUpdate::groupId() const
{
	Q_D(const GroupUpdate);
	return d->groupId();
}

QString GroupUpdate::fieldName() const
{
	Q_D(const GroupUpdate);
	return d->fieldName();
}

GroupUpdateType GroupUpdate::updateType() const
{
	Q_D(const GroupUpdate);
	return d->updateType();
}

unsigned char GroupUpdate::fieldType() const
{
	Q_D(const GroupUpdate);
	return d->fieldType();
}

QVariant GroupUpdate::value() const
{
	Q_D(const GroupUpdate);
	return d->value();
}

QVariant GroupUpdate::oldValue() const
{
	Q_D(const GroupUpdate);
	return d->oldValue();
}


