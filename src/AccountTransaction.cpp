#include <QuantKit/AccountTransaction.h>

#include <QuantKit/Event/Fill.h>

namespace QuantKit {

class AccountTransactionPrivate : public QSharedData
{
public:
	QDateTime m_dateTime;
	double m_value;
	unsigned char m_currencyId;
	QString m_text;

public:
	explicit AccountTransactionPrivate(const Fill& fill);
	AccountTransactionPrivate(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text);
	virtual ~AccountTransactionPrivate();

public:
	QDateTime dateTime() const { return m_dateTime; }
	double value() const { return m_value; }
	unsigned char currencyId() const { return m_currencyId; }
	QString text() const { return m_text; }
	virtual AccountTransactionPrivate* clone() Q_DECL_OVERRIDE { return new AccountTransactionPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AccountTransactionPrivate::AccountTransactionPrivate(const Fill& fill)
	: m_dateTime(fill.entryDate())
	, m_value(fill.cashFlow())
	, m_currencyId(fill.currencyId())
	, m_text(fill.text())
{
}

AccountTransactionPrivate::AccountTransactionPrivate(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text)
	: m_dateTime(dateTime)
	, m_value(value)
	, m_currencyId(currencyId)
	, m_text(text)
{
}

AccountTransactionPrivate::~AccountTransactionPrivate ()
{
}


// Pubic API 

AccountTransaction::AccountTransaction(const Fill& fill)
	: d_ptr(new AccountTransactionPrivate(fill))
{
}

AccountTransaction::AccountTransaction(const QDateTime& dateTime, double value, unsigned char currencyId, const QString& text)
	: d_ptr(new AccountTransactionPrivate(dateTime, value, currencyId, text))
{
}

AccountTransaction::~AccountTransaction()
{
}

AccountTransaction::AccountTransaction (const AccountTransaction &other)
	: d_ptr(other.d_ptr)
{
}

AccountTransaction& AccountTransaction::operator=(const AccountTransaction &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool AccountTransaction::operator==(const AccountTransaction &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDateTime AccountTransaction::dateTime() const
{
	return d_ptr->dateTime();
}

double AccountTransaction::value() const
{
	return d_ptr->value();
}

unsigned char AccountTransaction::currencyId() const
{
	return d_ptr->currencyId();
}

QString AccountTransaction::text() const
{
	return d_ptr->text();
}

QDebug operator<<(QDebug dbg, const AccountTransaction& accounttransaction)
{
	return dbg << accounttransaction.toString();
}

