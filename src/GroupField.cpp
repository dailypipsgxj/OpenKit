#include <QuantKit/GroupField.h>

#include <QuantKit/Event/Group.h>

namespace QuantKit {

class GroupFieldPrivate : public QSharedData
{
public:
	Group group_0;
	QVariant m_value;
	QString m_name;
	unsigned char m_type;

public:
	GroupFieldPrivate(const QString& name, unsigned char type, const QVariant& value);
	virtual ~GroupFieldPrivate();

public:
	Group getGroup_0() const;
	void setGroup_0(Group value);
	QString name() const { return m_name; }
	unsigned char type() const { return m_type; }
	QVariant value() const { return m_value; }
	void setValue(const QVariant& value);
	virtual GroupFieldPrivate* clone() Q_DECL_OVERRIDE { return new GroupFieldPrivate(*this); }
//private:
	void setName(const QString& value) { m_name = value; }
	void setType(unsigned char value) { m_type = value; }
};

} // namepsace QuantKit


using namespace QuantKit;

GroupFieldPrivate::GroupFieldPrivate(const QString& name, unsigned char type, const QVariant& value)
	: m_value(value)
	, m_name(name)
	, m_type(type)
{
}

GroupFieldPrivate::~GroupFieldPrivate ()
{
}

Group getGroup_0() const
{
	return null;
}
void setGroup_0(Group value)
{
}
void GroupFieldPrivate::setValue(const QVariant& value)
{
	if (m_value != value)
	{
		object value2 = m_value;
		m_value = value;
		group_0.framework().eventServer().OnLog(new GroupUpdate(group_0.id(), m_name, m_type, m_value, value2, GroupUpdateType.FieldUpdated));
	}
}


// Pubic API 

GroupField::GroupField(const QString& name, unsigned char type, const QVariant& value)
	: d_ptr(new GroupFieldPrivate(name, type, value))
{
}

GroupField::~GroupField()
{
}

GroupField::GroupField (const GroupField &other)
	: d_ptr(other.d_ptr)
{
}

GroupField& GroupField::operator=(const GroupField &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool GroupField::operator==(const GroupField &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Group group_0() const
{
	return d_ptr->
	setGroup_0()
}

void setGroup_0(Group value)
{
	d_ptr->group_0(value);
}

QString GroupField::name() const
{
	return d_ptr->name();
}

unsigned char GroupField::type() const
{
	return d_ptr->type();
}

QVariant GroupField::value() const
{
	return d_ptr->value();
}

void GroupField::setValue(const QVariant& value)
{
	d_ptr->setValue(value);
}

QDebug operator<<(QDebug dbg, const GroupField& groupfield)
{
	return dbg << groupfield.toString();
}

