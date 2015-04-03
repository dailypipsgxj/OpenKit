#include <QuantKit/Account.h>

#include <QHash>

#include <QuantKit/AccountPosition.h>
#include <QuantKit/AccountTransaction.h>
#include <QuantKit/Framework.h>
#include <QuantKit/Event/Fill.h>

namespace QuantKit {

class AccountPrivate Q_DECL_FINAL : public QSharedData
{
public:
    Framework m_framework;
	unsigned char m_currencyId;
    QHash<unsigned char, AccountPosition> m_idTable;
	QList<AccountPosition> m_positions;
	QList<AccountTransaction> m_transactions;
    Account *m_parent;

public:
	explicit AccountPrivate(const Framework& framework);
    ~AccountPrivate();

public:
	unsigned char currencyId() const { return m_currencyId; }
	void setCurrencyId(unsigned char value) { m_currencyId = value; }
	QList<AccountPosition> positions() const { return m_positions; }
	QList<AccountTransaction> transactions() const { return m_transactions; }
	double value() const;
    Account* parent() const { return m_parent; }
    void setParent(Account* parent) { m_parent = parent; }

	void add(const AccountTransaction& transaction, bool updateParent);

	void add(const Fill& fill, bool updateParent)
	{
        AccountTransaction transaction(fill);
        add(transaction, updateParent);
	}

	void add(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
        AccountTransaction transaction(dateTime, value, currencyId, text);
        add(transaction, updateParent);
	}

	void add(double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
        AccountTransaction transaction(m_framework.clock().dateTime(), value, currencyId, text);
        add(transaction, updateParent);
	}

	void deposit(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
        add(dateTime, value, currencyId, text, updateParent);
	}

	void deposit(double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
        add(value, currencyId, text, updateParent);
	}

	void withdraw(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
        add(dateTime, -value, currencyId, text, updateParent);
	}

	void withdraw(double value, unsigned char currencyId, const QString& text, bool updateParent)
	{
        add(-value, currencyId, text, updateParent);
	}

    //virtual AccountPrivate* clone() Q_DECL_OVERRIDE { return new AccountPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AccountPrivate::AccountPrivate(const Framework& framework)
    : QSharedData()
    , m_framework(framework)
	, m_currencyId(CurrencyId::USD)
{
}

AccountPrivate::~AccountPrivate ()
{
}

double AccountPrivate::value() const
{
	double num = 0.0;
    /*for (int i = 0; i < m_positions.count(); i++)
	{
        num += m_framework.currencyConverter().Convert(m_positions[i].value(), m_positions[i].currencyId(), m_currencyId);
    }*/
	return num;
}

void AccountPrivate::add(const AccountTransaction& transaction, bool updateParent)
{
    QHash<unsigned char, AccountPosition>::iterator iter = m_idTable.find(transaction.currencyId());

    if (iter == m_idTable.end()) {
        AccountPosition accountPosition(transaction);
        m_idTable.insert(transaction.currencyId(), accountPosition);
        m_positions.append(accountPosition);
    }
    else {
        iter.value().add(transaction);
    }
    m_transactions.append(transaction);
    if(m_parent != 0 && updateParent)
    {
        m_parent->add(transaction, true);
    }
}


// Pubic API 

Account::Account(const Framework& framework)
    : d(new AccountPrivate(framework))
{
}

Account::~Account()
{
}

Account::Account (const Account &other)
    : d(other.d)
{
}

Account& Account::operator=(const Account &other)
{
    d = other.d;
	return *this;
}

bool Account::operator==(const Account &other) const
{
    return (d==other.d);
}

unsigned char Account::currencyId() const
{
    return d->currencyId();
}

void Account::setCurrencyId(unsigned char value)
{
    d->setCurrencyId(value);
}

QList<AccountPosition> Account::positions() const
{
    return d->positions();
}

QList<AccountTransaction> Account::transactions() const
{
    return d->transactions();
}

double Account::value() const
{
    return d->value();
}

Account* Account::parent() const
{
    return d->parent();
}

void Account::setParent(Account *parent)
{
    d->setParent(parent);
}

void Account::add(const AccountTransaction& transaction, bool updateParent)
{
    d->add(transaction, updateParent);
}

void Account::add(const Fill& fill, bool updateParent)
{
    d->add(fill, updateParent);
}

void Account::add(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text, bool updateParent)
{
    d->add(dateTime, value, currencyId, text, updateParent);
}

void Account::add(double value, unsigned char currencyId, const QString& text, bool updateParent)
{
    d->add(value, currencyId, text, updateParent);
}

void Account::deposit(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text, bool updateParent)
{
    d->deposit(dateTime, value, currencyId, text, updateParent);
}

void Account::deposit(double value, unsigned char currencyId, const QString& text, bool updateParent)
{
    d->deposit(value, currencyId, text, updateParent);
}

void Account::withdraw(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text, bool updateParent)
{
    d->withdraw(dateTime, value, currencyId, text, updateParent);
}

void Account::withdraw(double value, unsigned char currencyId, const QString& text, bool updateParent)
{
    d->withdraw(value, currencyId, text, updateParent);
}

QDebug operator<<(QDebug dbg, const Account& account)
{
    return dbg;
    //return dbg << account.toString();
}

