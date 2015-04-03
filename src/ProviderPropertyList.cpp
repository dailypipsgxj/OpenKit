#include <QuantKit/ProviderPropertyList.h>


namespace QuantKit {

class ProviderPropertyListPrivate : public QSharedData
{
public:
	Dictionary<QString,QString> m_dictionary;

public:
	ProviderPropertyListPrivate();
	virtual ~ProviderPropertyListPrivate();

public:
	QString getStringValue(const QString& name, const QString& defaultValue);
	void setValue(const QString& name, const QString& value) { m_dictionary[name] = value; }
	virtual ProviderPropertyListPrivate* clone() Q_DECL_OVERRIDE { return new ProviderPropertyListPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ProviderPropertyListPrivate::ProviderPropertyListPrivate()
	: m_dictionary(new Dictionary<string, string>())
{
}

ProviderPropertyListPrivate::~ProviderPropertyListPrivate ()
{
}

QString ProviderPropertyListPrivate::getStringValue(const QString& name, const QString& defaultValue)
{
	string result;
	if (!m_dictionary.TryGetValue(name, out result))
	{
		return defaultValue;
	}
	return result;
}


// Pubic API 

ProviderPropertyList::ProviderPropertyList()
	: d_ptr(new ProviderPropertyListPrivate)
{
}

ProviderPropertyList::~ProviderPropertyList()
{
}

ProviderPropertyList::ProviderPropertyList (const ProviderPropertyList &other)
	: d_ptr(other.d_ptr)
{
}

ProviderPropertyList& ProviderPropertyList::operator=(const ProviderPropertyList &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ProviderPropertyList::operator==(const ProviderPropertyList &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString ProviderPropertyList::getStringValue(const QString& name, const QString& defaultValue)
{
	return d_ptr->getStringValue(name, defaultValue);
}

void ProviderPropertyList::setValue(const QString& name, const QString& value)
{
	d_ptr->setValue(name, value);
}

QDebug operator<<(QDebug dbg, const ProviderPropertyList& providerpropertylist)
{
	return dbg << providerpropertylist.toString();
}

