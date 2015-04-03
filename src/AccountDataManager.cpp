#include <QuantKit/AccountDataManager.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Event/AccountData.h>
#include <QuantKit/AccountDataSnapshot.h>
#include <QuantKit/AccountDataFieldList.h>

namespace QuantKit {

class AccountDataManagerPrivate : public QSharedData
{
public:
	Framework m_framework;
	Dictionary<int,Class30> m_dictionary;

public:
	explicit AccountDataManagerPrivate(const Framework& framework);
	virtual ~AccountDataManagerPrivate();

public:
	AccountDataSnapshot getSnapshot(unsigned char providerId, unsigned char route);
	AccountDataSnapshot getSnapshots();
	virtual AccountDataManagerPrivate* clone() Q_DECL_OVERRIDE { return new AccountDataManagerPrivate(*this); }
//private:
	Class30 method_2(unsigned char byte_0, unsigned char byte_1, bool bool);
	void method_3(const AccountDataFieldList& accountDataFieldList_0, const AccountDataFieldList& accountDataFieldList_1);
	void method_4(const AccountDataFieldList& accountDataFieldList_0, const AccountDataFieldList& accountDataFieldList_1);
};

} // namepsace QuantKit


using namespace QuantKit;

AccountDataManagerPrivate::AccountDataManagerPrivate(const Framework& framework)
	: m_framework(framework)
	, m_dictionary(new Dictionary<int, Class30>())
{
}

AccountDataManagerPrivate::~AccountDataManagerPrivate ()
{
}

AccountDataSnapshot AccountDataManagerPrivate::getSnapshot(unsigned char providerId, unsigned char route)
{
	Class30 @class = method_2(providerId, route, false);
	if (@class == null)
	{
		return new AccountDataSnapshot(new AccountDataEntry[0]);
	}
	AccountDataSnapshot result;
	lock (@class)
	{
		List<AccountDataEntry> list = new List<AccountDataEntry>();
		foreach (string current in @class.method_0().Keys)
		{
			Class31 class2 = @class.method_0()[current];
			AccountData accountData = new AccountData(m_framework.clock().dateTime(), AccountDataType.AccountValue, current, providerId, route);
			method_4(class2.method_0(), accountData.fields());
			List<AccountData> list2 = new List<AccountData>();
			foreach (AccountDataFieldList current2 in class2.method_2().Values)
			{
				AccountData accountData2 = new AccountData(m_framework.clock().dateTime(), AccountDataType.Position, current, providerId, route);
				method_4(current2, accountData2.fields());
				list2.Add(accountData2);
			}
			List<AccountData> list3 = new List<AccountData>();
			foreach (AccountDataFieldList current3 in class2.method_4().Values)
			{
				AccountData accountData3 = new AccountData(m_framework.clock().dateTime(), AccountDataType.Order, current, providerId, route);
				method_4(current3, accountData3.fields());
				list3.Add(accountData3);
			}
			list.Add(new AccountDataEntry(current, accountData, list2.ToArray(), list3.ToArray()));
		}
		result = new AccountDataSnapshot(list.ToArray());
	}
	return result;
}

AccountDataSnapshot AccountDataManagerPrivate::getSnapshots()
{
	List<AccountDataSnapshot> list = new List<AccountDataSnapshot>();
	lock (m_dictionary)
	{
		foreach (int current in m_dictionary.Keys)
		{
			byte providerId = (byte)(current / 256);
			byte route = (byte)(current % 256);
			list.Add(GetSnapshot(providerId, route));
		}
	}
	return list.ToArray();
}

Class30 AccountDataManagerPrivate::method_2(unsigned char byte_0, unsigned char byte_1, bool bool)
{
	int key = (int)byte_0 * 256 + (int)byte_1;
	Class30 @class;
	lock (m_dictionary)
	{
		if (!m_dictionary.TryGetValue(key, out @class))
		{
			if (@bool)
			{
				@class = new Class30();
				m_dictionary.Add(key, @class);
			}
			else
			{
				@class = null;
			}
		}
	}
	return @class;
}

void AccountDataManagerPrivate::method_3(const AccountDataFieldList& accountDataFieldList_0, const AccountDataFieldList& accountDataFieldList_1)
{
	foreach (AccountDataField accountDataField in accountDataFieldList_0)
	{
		accountDataFieldList_1[accountDataField.name(), accountDataField.currency()] = accountDataField.value();
	}
}

void AccountDataManagerPrivate::method_4(const AccountDataFieldList& accountDataFieldList_0, const AccountDataFieldList& accountDataFieldList_1)
{
	foreach (AccountDataField accountDataField in accountDataFieldList_0)
	{
		accountDataFieldList_1.Add(accountDataField.name(), accountDataField.currency(), accountDataField.value());
	}
}


// Pubic API 

AccountDataManager::AccountDataManager(const Framework& framework)
	: d_ptr(new AccountDataManagerPrivate(framework))
{
}

AccountDataManager::~AccountDataManager()
{
}

AccountDataManager::AccountDataManager (const AccountDataManager &other)
	: d_ptr(other.d_ptr)
{
}

AccountDataManager& AccountDataManager::operator=(const AccountDataManager &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool AccountDataManager::operator==(const AccountDataManager &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

AccountDataSnapshot AccountDataManager::getSnapshot(unsigned char providerId, unsigned char route)
{
	return d_ptr->getSnapshot(providerId, route);
}

AccountDataSnapshot AccountDataManager::getSnapshots()
{
	return d_ptr->getSnapshots();
}

QDebug operator<<(QDebug dbg, const AccountDataManager& accountdatamanager)
{
	return dbg << accountdatamanager.toString();
}

