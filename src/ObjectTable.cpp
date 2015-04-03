#include <QuantKit/ObjectTable.h>

#include <QuantKit/IdArray.h>

namespace QuantKit {

class ObjectTablePrivate : public QSharedData
{
public:
	IdArray<QVariant> m_item;

public:
	ObjectTablePrivate();
	virtual ~ObjectTablePrivate();

public:
	int size() const { return m_item.Size; }
	QVariant item(int index) const { return m_item[index]; }
	void setItem(int index, const QVariant& value) { m_item[index] = value; }
	void clear() { m_item.Clear(); }
	void copyTo(const ObjectTable& table) { m_item.CopyTo(table.item()); }
	double getDouble(int index) { return (double)m_item[index]; }
	int getInt(int index) { return (int)m_item[index]; }
	QString getString(int index) { return (string)m_item[index]; }
	void remove(int id) { m_item.Remove(id); }
	virtual ObjectTablePrivate* clone() Q_DECL_OVERRIDE { return new ObjectTablePrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ObjectTablePrivate::ObjectTablePrivate()
	: m_item(new IdArray<object>(10))
{
}

ObjectTablePrivate::~ObjectTablePrivate ()
{
}


// Pubic API 

ObjectTable::ObjectTable()
	: d_ptr(new ObjectTablePrivate)
{
}

ObjectTable::~ObjectTable()
{
}

ObjectTable::ObjectTable (const ObjectTable &other)
	: d_ptr(other.d_ptr)
{
}

ObjectTable& ObjectTable::operator=(const ObjectTable &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ObjectTable::operator==(const ObjectTable &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int ObjectTable::size() const
{
	return d_ptr->size();
}

QVariant ObjectTable::item(int index) const
{
	return d_ptr->item(index);
}

void ObjectTable::setItem(int index, const QVariant& value)
{
	d_ptr->setItem(index, value);
}

void ObjectTable::clear()
{
	d_ptr->clear();
}

void ObjectTable::copyTo(const ObjectTable& table)
{
	d_ptr->copyTo(table);
}

double ObjectTable::getDouble(int index)
{
	return d_ptr->getDouble(index);
}

int ObjectTable::getInt(int index)
{
	return d_ptr->getInt(index);
}

QString ObjectTable::getString(int index)
{
	return d_ptr->getString(index);
}

void ObjectTable::remove(int id)
{
	d_ptr->remove(id);
}

QDebug operator<<(QDebug dbg, const ObjectTable& objecttable)
{
	return dbg << objecttable.toString();
}

