#ifndef __QUANTKIT_ACCOUNT_H__
#define __QUANTKIT_ACCOUNT_H__

#include <QuantKit/quantkit_global.h>
#include <QDebug>
#include <QList>
#include <QDateTime>
#include <QString>
#include <QSharedDataPointer>

#include <QuantKit/CurrencyId.h>

namespace QuantKit {

class AccountPrivate;

class AccountPosition;
class AccountTransaction;
class Framework;
class Fill;

class QUANTKIT_EXPORT Account
{
public:
    Account();
	explicit Account(const Framework& framework);

    Account(const Account &other);

    ~Account();

    Account& operator=(const Account &other);

#ifdef Q_COMPILER_RVALUE_REFS
    Account &operator=(Account &&other) { swap(other); return *this; }
#endif

    void swap(Account& other) { d.swap(other.d); }

    bool operator==(const Account &other) const;
    inline bool operator!=(const Account &other) const { return !(this->operator==(other));  }

public:
	unsigned char currencyId() const;
	void setCurrencyId(unsigned char value);
	QList<AccountPosition> positions() const;
	QList<AccountTransaction> transactions() const;
	double value() const;
    Account parent() const;
    void setParent(Account* parent);
	void add(const AccountTransaction& transaction, bool updateParent = true);
	void add(const Fill& fill, bool updateParent = true);
	void add(const QDateTime& dateTime, double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);
	void add(double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);
	void deposit(const QDateTime& dateTime, double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);
	void deposit(double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);
	void withdraw(const QDateTime& dateTime, double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);
	void withdraw(double value, unsigned char currencyId = CurrencyId::USD, const QString& text = "", bool updateParent = true);

private:
    QSharedDataPointer<AccountPrivate> d;

	friend QDebug operator<<(QDebug dbg, const Account& account);
};

QUANTKIT_EXPORT QDebug operator<<(QDebug dbg, const Account& account);

} // namespace QuantKit

Q_DECLARE_SHARED(QuantKit::Account)

#endif // __QUANTKIT_ACCOUNT_H__
