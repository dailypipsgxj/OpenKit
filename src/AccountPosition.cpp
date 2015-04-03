#include <QuantKit/AccountPosition.h>

#include <QuantKit/AccountTransaction.h>

namespace QuantKit {

class AccountPositionPrivate : public QSharedData
{
public:
	unsigned char m_currencyId;
	double m_value;

public:
	explicit AccountPositionPrivate(const AccountTransaction& transaction);
	AccountPositionPrivate(unsigned char currencyId, double value);
	virtual ~AccountPositionPrivate();

public:
	unsigned char currencyId() const { return m_currencyId; }
	double value() const { return m_value; }
	void add(const AccountTransaction& transaction)
	{
		m_value += transaction.value();
	}

	virtual AccountPositionPrivate* clone() Q_DECL_OVERRIDE { return new AccountPositionPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AccountPositionPrivate::AccountPositionPrivate(const AccountTransaction& transaction)
    : QSharedData()
    , m_currencyId(transaction.currencyId())
	, m_value(transaction.value())
{
}

AccountPositionPrivate::AccountPositionPrivate(unsigned char currencyId, double value)
    : QSharedData()
    , m_currencyId(currencyId)
	, m_value(value)
{
}

AccountPositionPrivate::~AccountPositionPrivate ()
{
}


// Pubic API 

AccountPosition::AccountPosition(const AccountTransaction& transaction)
	: d_ptr(new AccountPositionPrivate(transaction))
{
}

AccountPosition::AccountPosition(unsigned char currencyId, double value)
	: d_ptr(new AccountPositionPrivate(currencyId, value))
{
}

AccountPosition::~AccountPosition()
{
}

AccountPosition::AccountPosition (const AccountPosition &other)
	: d_ptr(other.d_ptr)
{
}

AccountPosition& AccountPosition::operator=(const AccountPosition &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool AccountPosition::operator==(const AccountPosition &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

unsigned char AccountPosition::currencyId() const
{
	return d_ptr->currencyId();
}

double AccountPosition::value() const
{
	return d_ptr->value();
}

void AccountPosition::add(const AccountTransaction& transaction)
{
	d_ptr->add(transaction);
}

QDebug operator<<(QDebug dbg, const AccountPosition& accountposition)
{
	return dbg << accountposition.toString();
}

