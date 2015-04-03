#include <QuantKit/Global.h>


namespace QuantKit {

class GlobalPrivate : public QSharedData
{
public:
	Dictionary<QString,QVariant> m_item;

public:
	GlobalPrivate();
	virtual ~GlobalPrivate();

public:
	int count() const { return m_item.Count; }
	QVariant item(const QString& key) const { return m_item[key]; }
	void setItem(const QString& key, const QVariant& value) { m_item[key] = value; }
	void add(const QString& key, const QVariant& obj) { m_item.Add(key, obj); }
	void clear() { m_item.Clear(); }
	bool containsKey(const QString& key)
	{
		return m_item.ContainsKey(key);
	}

	bool containsValue(const QVariant& obj)
	{
		return m_item.ContainsValue(obj);
	}

	double getDouble(const QString& key) { return (double)m_item[key]; }
	int getInt(const QString& key) { return (int)m_item[key]; }
	QString getString(const QString& key) { return (string)m_item[key]; }
	void remove(const QString& key) { m_item.Remove(key); }
	virtual GlobalPrivate* clone() Q_DECL_OVERRIDE { return new GlobalPrivate(*this); }
//private:
	IEnumerator system.Collections.IEnumerable.GetEnumerator()
	{
		return m_item.Values.GetEnumerator();
	}

};

} // namepsace QuantKit


using namespace QuantKit;

GlobalPrivate::GlobalPrivate()
	: m_item(new Dictionary<string, object>())
{
}

GlobalPrivate::~GlobalPrivate ()
{
}


// Pubic API 

Global::Global()
	: d_ptr(new GlobalPrivate)
{
}

Global::~Global()
{
}

Global::Global (const Global &other)
	: d_ptr(other.d_ptr)
{
}

Global& Global::operator=(const Global &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Global::operator==(const Global &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int Global::count() const
{
	return d_ptr->count();
}

QVariant Global::item(const QString& key) const
{
	return d_ptr->item(key);
}

void Global::setItem(const QString& key, const QVariant& value)
{
	d_ptr->setItem(key, value);
}

void Global::add(const QString& key, const QVariant& obj)
{
	d_ptr->add(key, obj);
}

void Global::clear()
{
	d_ptr->clear();
}

bool Global::containsKey(const QString& key)
{
	return d_ptr->containsKey(key);
}

bool Global::containsValue(const QVariant& obj)
{
	return d_ptr->containsValue(obj);
}

double Global::getDouble(const QString& key)
{
	return d_ptr->getDouble(key);
}

int Global::getInt(const QString& key)
{
	return d_ptr->getInt(key);
}

QString Global::getString(const QString& key)
{
	return d_ptr->getString(key);
}

void Global::remove(const QString& key)
{
	d_ptr->remove(key);
}

QDebug operator<<(QDebug dbg, const Global& global)
{
	return dbg << global.toString();
}

