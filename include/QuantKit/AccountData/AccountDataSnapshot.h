#ifndef __QUANTKIT_ACCOUNTDATASNAPSHOT_H__
#define __QUANTKIT_ACCOUNTDATASNAPSHOT_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class AccountDataSnapshotPrivate;

class AccountDataEntry;

class QUANTKIT_EXPORT AccountDataSnapshot
{
public:
	explicit AccountDataSnapshot(const AccountDataEntry& entries);
	~AccountDataSnapshot();

	AccountDataSnapshot(const AccountDataSnapshot &other);
	AccountDataSnapshot& operator=(const AccountDataSnapshot &other);
	bool operator==(const AccountDataSnapshot &other) const;
	inline bool operator!=(const AccountDataSnapshot &other) const { return !(this->operator==(other));  }
public:
	AccountDataEntry entries() const;

private:
	QSharedDataPointer<AccountDataSnapshotPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const AccountDataSnapshot& accountdatasnapshot);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const AccountDataSnapshot& accountdatasnapshot);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AccountDataSnapshot)

#endif // __QUANTKIT_ACCOUNTDATASNAPSHOT_H__
