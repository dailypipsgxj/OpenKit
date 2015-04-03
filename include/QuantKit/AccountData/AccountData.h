#ifndef __QUANTKIT_ACCOUNTDATA_H__
#define __QUANTKIT_ACCOUNTDATA_H__

#include <QuantKit/quantkit_global.h>
#include <QDateTime>
#include <QString>

#include <QuantKit/DataObject.h>

namespace QuantKit {

class AccountDataPrivate;

class AccountDataFieldList;

enum class AccountDataType : unsigned char
{
    AccountValue,
    Position,
    Order
};

class QUANTKIT_EXPORT AccountData Q_DECL_FINAL : public DataObject
{
public:
	AccountData(const QDateTime& datetime, AccountDataType type, const QString& account, unsigned char providerId, unsigned char route);
	~AccountData();

public:
	AccountDataType type() const;
	QString account() const;
	unsigned char providerId() const;
	unsigned char route() const;
	AccountDataFieldList fields() const;

private:
	QK_DECLARE_PRIVATE(AccountData)

};

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::AccountData)

#endif // __QUANTKIT_ACCOUNTDATA_H__
