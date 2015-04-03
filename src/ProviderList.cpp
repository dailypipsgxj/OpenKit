#include <QuantKit/ProviderList.h>

#include <QuantKit/IdArray.h>

namespace QuantKit {

class ProviderListPrivate : public QSharedData
{
public:
	IdArray<IProvider> m_idArray;
	Dictionary<QString,IProvider> m_dictionary;
	QList<IProvider> m_count;

public:
	ProviderListPrivate();
	virtual ~ProviderListPrivate();

public:
	int count() const { return m_count.Count; }
	IProvider item(const QString& name) const { return GetByName(name); }
	void add(const IProvider& provider);
	void clear();
	IProvider getById(int id) { return m_idArray[id]; }
	IProvider getByIndex(int index) { return m_count[index]; }
	IProvider getByName(const QString& name);
	void remove(const IProvider& provider);
	virtual ProviderListPrivate* clone() Q_DECL_OVERRIDE { return new ProviderListPrivate(*this); }
//private:
	IEnumerator system.Collections.IEnumerable.GetEnumerator()
	{
		return m_count.GetEnumerator();
	}

};

} // namepsace QuantKit


using namespace QuantKit;

ProviderListPrivate::ProviderListPrivate()
	: m_idArray(new IdArray<IProvider>(128))
	, m_dictionary(new Dictionary<string, IProvider>())
	, m_count(new QList<IProvider>())
{
}

ProviderListPrivate::~ProviderListPrivate ()
{
}

void ProviderListPrivate::add(const IProvider& provider)
{
	m_count.Add(provider);
	m_idArray[(int)provider.id()] = provider;
	m_dictionary[provider.name()] = provider;
}

void ProviderListPrivate::clear()
{
	m_count.Clear();
	m_idArray.Clear();
	m_dictionary.Clear();
}

IProvider ProviderListPrivate::getByName(const QString& name)
{
	IProvider result;
	m_dictionary.TryGetValue(name, out result);
	return result;
}

void ProviderListPrivate::remove(const IProvider& provider)
{
	m_count.Remove(provider);
	m_idArray.Remove((int)provider.id());
	m_dictionary.Remove(provider.name());
}


// Pubic API 

ProviderList::ProviderList()
	: d_ptr(new ProviderListPrivate)
{
}

ProviderList::~ProviderList()
{
}

ProviderList::ProviderList (const ProviderList &other)
	: d_ptr(other.d_ptr)
{
}

ProviderList& ProviderList::operator=(const ProviderList &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ProviderList::operator==(const ProviderList &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

int ProviderList::count() const
{
	return d_ptr->count();
}

IProvider ProviderList::item(const QString& name) const
{
	return d_ptr->item(name);
}

void ProviderList::add(const IProvider& provider)
{
	d_ptr->add(provider);
}

void ProviderList::clear()
{
	d_ptr->clear();
}

IProvider ProviderList::getById(int id)
{
	return d_ptr->getById(id);
}

IProvider ProviderList::getByIndex(int index)
{
	return d_ptr->getByIndex(index);
}

IProvider ProviderList::getByName(const QString& name)
{
	return d_ptr->getByName(name);
}

void ProviderList::remove(const IProvider& provider)
{
	d_ptr->remove(provider);
}

QDebug operator<<(QDebug dbg, const ProviderList& providerlist)
{
	return dbg << providerlist.toString();
}

