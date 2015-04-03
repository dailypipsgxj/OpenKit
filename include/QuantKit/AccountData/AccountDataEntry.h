#ifndef __QUANTKIT_ACCOUNTDATAENTRY_H__
#define __QUANTKIT_ACCOUNTDATAENTRY_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QSharedDataPointer>

namespace QuantKit {

class AccountDataEntryPrivate;

class AccountData;

class QUANTKIT_EXPORT AccountDataEntry Q_DECL_FINAL
{
public:
	AccountDataEntry(const QString& account, const AccountData& values, const AccountData& positions, const AccountData& orders);
	~AccountDataEntry();

	AccountDataEntry(const AccountDataEntry &other);
	AccountDataEntry& operator=(const AccountDataEntry &other);
#ifdef Q_COMPILER_RVALUE_REFS
    AccountDataEntry &operator=(AccountDataEntry &&other) { swap(other); return *this; }
#endif

    void swap(AccountDataEntry& other) { d.swap(other.d); }


	bool operator==(const AccountDataEntry &other) const;
	inline bool operator!=(const AccountDataEntry &other) const { return !(this->operator==(other));  }
public:
	QString account() const;
    QList<AccountData> values() const;
    QList<AccountData> positions() const;
    QList<AccountData> orders() const;

private:
    QSharedDataPointer<AccountDataEntryPrivate> d;

	friend QDebug operator<<(QDebug dbg, const AccountDataEntry& accountdataentry);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const AccountDataEntry& accountdataentry);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AccountDataEntry)

#endif // __QUANTKIT_ACCOUNTDATAENTRY_H__
