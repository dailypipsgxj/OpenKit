#ifndef __QUANTKIT_ACCOUNTDATAFIELDLIST_H__
#define __QUANTKIT_ACCOUNTDATAFIELDLIST_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QSharedDataPointer>

namespace QuantKit {

class AccountDataFieldListPrivate;

class AccountDataField;

class QUANTKIT_EXPORT AccountDataFieldList
{
public:
	AccountDataFieldList();
	~AccountDataFieldList();

	AccountDataFieldList(const AccountDataFieldList &other);
	AccountDataFieldList& operator=(const AccountDataFieldList &other);
	bool operator==(const AccountDataFieldList &other) const;
	inline bool operator!=(const AccountDataFieldList &other) const { return !(this->operator==(other));  }
public:
	QVariant item(const QString& name, const QString& currency) const;
	QVariant item(const QString& name) const;
	void add(const QString& name, const QString& currency, const QVariant& value);
	void add(const QString& name, const QVariant& value);
	void clear();
	AccountDataField toArray();

private:
	QSharedDataPointer<AccountDataFieldListPrivate> d_ptr;

	friend QDebug operator<<(QDebug dbg, const AccountDataFieldList& accountdatafieldlist);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const AccountDataFieldList& accountdatafieldlist);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AccountDataFieldList)

#endif // __QUANTKIT_ACCOUNTDATAFIELDLIST_H__
