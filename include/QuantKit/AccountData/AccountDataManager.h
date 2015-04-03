#ifndef __QUANTKIT_ACCOUNTDATAMANAGER_H__
#define __QUANTKIT_ACCOUNTDATAMANAGER_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QSharedDataPointer>

namespace QuantKit {

class AccountDataManagerPrivate;

class Framework;
class AccountData;
class AccountDataSnapshot;
class AccountDataFieldList;

class QUANTKIT_EXPORT AccountDataManager
{
public:
	explicit AccountDataManager(const Framework& framework);
	~AccountDataManager();

	AccountDataManager(const AccountDataManager &other);
	AccountDataManager& operator=(const AccountDataManager &other);
	bool operator==(const AccountDataManager &other) const;
	inline bool operator!=(const AccountDataManager &other) const { return !(this->operator==(other));  }
public:
	AccountDataSnapshot getSnapshot(unsigned char providerId, unsigned char route);
	AccountDataSnapshot getSnapshots();

private:
	QSharedDataPointer<AccountDataManagerPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const AccountDataManager& accountdatamanager);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const AccountDataManager& accountdatamanager);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AccountDataManager)

#endif // __QUANTKIT_ACCOUNTDATAMANAGER_H__
