#include <QuantKit/AccountDataEntry.h>

#include <QuantKit/Event/AccountData.h>

namespace QuantKit {

class AccountDataEntryPrivate : public QSharedData
{
public:
	QString m_account;
	AccountData m_values;
	AccountData m_positions;
	AccountData m_orders;

public:
	AccountDataEntryPrivate(const QString& account, const AccountData& values, const AccountData& positions, const AccountData& orders);
	virtual ~AccountDataEntryPrivate();

public:
	QString account() const { return m_account; }
	AccountData values() const { return m_values; }
	AccountData positions() const { return m_positions; }
	AccountData orders() const { return m_orders; }
    //virtual AccountDataEntryPrivate* clone() Q_DECL_OVERRIDE { return new AccountDataEntryPrivate(*this); }
//private:
	void setAccount(const QString& value) { m_account = value; }
	void setValues(const AccountData& value) { m_values = value; }
	void setPositions(const AccountData& value) { m_positions = value; }
	void setOrders(const AccountData& value) { m_orders = value; }
};

} // namepsace QuantKit


using namespace QuantKit;

AccountDataEntryPrivate::AccountDataEntryPrivate(const QString& account, const AccountData& values, AccountData positions, AccountData orders)
    : QSharedData()
    , m_account(account)
	, m_values(values)
	, m_positions(positions)
	, m_orders(orders)
{
}

AccountDataEntryPrivate::~AccountDataEntryPrivate ()
{
}


// Pubic API 

AccountDataEntry::AccountDataEntry(const QString& account, const AccountData& values, AccountData positions, AccountData orders)
    : d(new AccountDataEntryPrivate(account, values, positions, orders))
{
}

AccountDataEntry::~AccountDataEntry()
{
}

AccountDataEntry::AccountDataEntry (const AccountDataEntry &other)
    : d(other.d)
{
}

AccountDataEntry& AccountDataEntry::operator=(const AccountDataEntry &other)
{
    d = other.d;
	return *this;
}

bool AccountDataEntry::operator==(const AccountDataEntry &other) const
{
    return (d==other.d);
}

QString AccountDataEntry::account() const
{
    return d->account();
}

QList<AccountData> AccountDataEntry::values() const
{
    return d->values();
}

QList<AccountData> AccountDataEntry::positions() const
{
    return d->positions();
}

QList<AccountData> AccountDataEntry::orders() const
{
    return d->orders();
}

QDebug operator<<(QDebug dbg, const AccountDataEntry& accountdataentry)
{
	return dbg << accountdataentry.toString();
}

