#include <QuantKit/AccountDataSnapshot.h>

#include <QuantKit/AccountDataEntry.h>

namespace QuantKit {

class AccountDataSnapshotPrivate : public QSharedData
{
public:
	AccountDataEntry m_entries;

public:
	explicit AccountDataSnapshotPrivate(const AccountDataEntry& entries);
	virtual ~AccountDataSnapshotPrivate();

public:
	AccountDataEntry entries() const { return m_entries; }
	virtual AccountDataSnapshotPrivate* clone() Q_DECL_OVERRIDE { return new AccountDataSnapshotPrivate(*this); }
//private:
	void setEntries(const AccountDataEntry& value) { m_entries = value; }
};

} // namepsace QuantKit


using namespace QuantKit;

AccountDataSnapshotPrivate::AccountDataSnapshotPrivate(AccountDataEntry entries)
	: m_entries(entries)
{
}

AccountDataSnapshotPrivate::~AccountDataSnapshotPrivate ()
{
}


// Pubic API 

AccountDataSnapshot::AccountDataSnapshot(AccountDataEntry entries)
	: d_ptr(new AccountDataSnapshotPrivate(entries))
{
}

AccountDataSnapshot::~AccountDataSnapshot()
{
}

AccountDataSnapshot::AccountDataSnapshot (const AccountDataSnapshot &other)
	: d_ptr(other.d_ptr)
{
}

AccountDataSnapshot& AccountDataSnapshot::operator=(const AccountDataSnapshot &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool AccountDataSnapshot::operator==(const AccountDataSnapshot &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

AccountDataEntry AccountDataSnapshot::entries() const
{
	return d_ptr->entries();
}

QDebug operator<<(QDebug dbg, const AccountDataSnapshot& accountdatasnapshot)
{
	return dbg << accountdatasnapshot.toString();
}

