#include <QuantKit/AccountDataFieldList.h>

#include <QuantKit/AccountDataField.h>

namespace QuantKit {

class AccountDataFieldListPrivate : public QSharedData
{
public:
	Dictionary<QString,Dictionary<QString,QVariant>> dictionary_0;

public:
	AccountDataFieldListPrivate();
	virtual ~AccountDataFieldListPrivate();

public:
	QVariant item(const QString& name, const QString& currency) const;
	QVariant item(const QString& name) const
	{
		return this[name, string.Empty];
	}

	void add(const QString& name, const QString& currency, const QVariant& value);
	void add(const QString& name, const QVariant& value)
	{
		Add(name, string.Empty, value);
	}

	void clear() { dictionary_0.Clear(); }
	AccountDataField toArray();
	virtual AccountDataFieldListPrivate* clone() Q_DECL_OVERRIDE { return new AccountDataFieldListPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AccountDataFieldListPrivate::AccountDataFieldListPrivate()
	: dictionary_0(new Dictionary<string, Dictionary<string, object>>())
{
}

AccountDataFieldListPrivate::~AccountDataFieldListPrivate ()
{
}

QVariant AccountDataFieldListPrivate::item(const QString& name, const QString& currency) const
{
	Dictionary<string, object> dictionary;
	if (!dictionary_0.TryGetValue(name, out dictionary))
	{
		return null;
	}
	object result;
	if (dictionary.TryGetValue(currency, out result))
	{
		return result;
	}
	return null;
}

void AccountDataFieldListPrivate::add(const QString& name, const QString& currency, const QVariant& value)
{
	Dictionary<string, object> dictionary;
	if (!dictionary_0.TryGetValue(name, out dictionary))
	{
		dictionary = new Dictionary<string, object>();
		dictionary_0.Add(name, dictionary);
	}
	dictionary.Add(currency, value);
}

AccountDataField AccountDataFieldListPrivate::toArray()
{
	List<AccountDataField> list = new List<AccountDataField>();
	foreach (KeyValuePair<string, Dictionary<string, object>> current in dictionary_0)
	{
		foreach (KeyValuePair<string, object> current2 in current.Value)
		{
			list.Add(new AccountDataField(current.Key, current2.Key, current2.Value));
		}
	}
	return list.ToArray();
}


// Pubic API 

AccountDataFieldList::AccountDataFieldList()
	: d_ptr(new AccountDataFieldListPrivate)
{
}

AccountDataFieldList::~AccountDataFieldList()
{
}

AccountDataFieldList::AccountDataFieldList (const AccountDataFieldList &other)
	: d_ptr(other.d_ptr)
{
}

AccountDataFieldList& AccountDataFieldList::operator=(const AccountDataFieldList &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool AccountDataFieldList::operator==(const AccountDataFieldList &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QVariant AccountDataFieldList::item(const QString& name, const QString& currency) const
{
	return d_ptr->item(name, currency);
}

QVariant AccountDataFieldList::item(const QString& name) const
{
	return d_ptr->item(name);
}

void AccountDataFieldList::add(const QString& name, const QString& currency, const QVariant& value)
{
	d_ptr->add(name, currency, value);
}

void AccountDataFieldList::add(const QString& name, const QVariant& value)
{
	d_ptr->add(name, value);
}

void AccountDataFieldList::clear()
{
	d_ptr->clear();
}

AccountDataField AccountDataFieldList::toArray()
{
	return d_ptr->toArray();
}

QDebug operator<<(QDebug dbg, const AccountDataFieldList& accountdatafieldlist)
{
	return dbg << accountdatafieldlist.toString();
}

