#include <QuantKit/Transaction.h>

#include <QuantKit/Event/Fill.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/Event/Order.h>

namespace QuantKit {

class TransactionPrivate : public QSharedData
{
public:
	QList<Fill> m_text;
	double m_qty;
	double m_price;
	double m_cashFlow;
	bool m_isDone;

public:
	TransactionPrivate();
	explicit TransactionPrivate(const Fill& fill) { Add(fill); }
	virtual ~TransactionPrivate();

public:
	QList<Fill> fills() const { return m_text; }
	Instrument instrument() const { return m_text[0].instrument(); }
	Order order() const { return m_text[0].text(); }
	OrderSide side() const { return m_text[0].side(); }
	QString text() const
	{
		return m_text[0].text().text();
	}

	double price() const { return m_price; }
	double qty() const { return m_qty; }
	double commission() const { return m_cashFlow; }
	bool isDone() const { return m_isDone; }
	double amount() const;
	virtual double value() const Q_DECL_OVERRIDE;
	virtual double netCashFlow() const Q_DECL_OVERRIDE;
	virtual double cashFlow() const Q_DECL_OVERRIDE
	{
		return netCashFlow() - m_cashFlow;
	}

	void add(const Fill& fill);
	virtual QString toString() const Q_DECL_OVERRIDE { return "Transaction"; }
	virtual TransactionPrivate* clone() Q_DECL_OVERRIDE { return new TransactionPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

TransactionPrivate::TransactionPrivate()
	: m_text(new QList<Fill>())
{
}

TransactionPrivate::~TransactionPrivate ()
{
}

double TransactionPrivate::amount() const
{
	switch (m_side)
	{
		case OrderSide.Buy:
			return m_qty;
		case OrderSide.Sell:
			return -m_qty;
		default:
			throw new NotSupportedException("Transaction.Value Side is not spported : " + m_side);
	}
}

double TransactionPrivate::value() const
{
	if (m_instrument.factor() != 0.0)
	{
		return m_price * m_qty * m_instrument.factor();
	}
	return m_price * m_qty;
}

double TransactionPrivate::netCashFlow() const
{
	if (m_instrument.factor() != 0.0)
	{
		return -(amount() * m_price * m_instrument.factor());
	}
	return -(amount() * m_price);
}

void TransactionPrivate::add(const Fill& fill)
{
	m_text.Add(fill);
	m_qty += fill.entryQty();
	m_cashFlow += fill.commission();
	if (m_text.Count == 1)
	{
		m_price = fill.entryPrice();
		return;
	}
	m_price = 0.0;
	foreach (Fill current in m_text)
	{
		m_price += current.entryPrice() * current.entryQty();
	}
	m_price /= m_qty;
}


// Pubic API 

Transaction::Transaction()
	: d_ptr(new TransactionPrivate)
{
}

Transaction::Transaction(const Fill& fill)
	: d_ptr(new TransactionPrivate(fill))
{
}

Transaction::~Transaction()
{
}

Transaction::Transaction (const Transaction &other)
	: d_ptr(other.d_ptr)
{
}

Transaction& Transaction::operator=(const Transaction &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Transaction::operator==(const Transaction &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QList<Fill> Transaction::fills() const
{
	return d_ptr->fills();
}

Instrument Transaction::instrument() const
{
	return d_ptr->instrument();
}

Order Transaction::order() const
{
	return d_ptr->order();
}

OrderSide Transaction::side() const
{
	return d_ptr->side();
}

QString Transaction::text() const
{
	return d_ptr->text();
}

double Transaction::price() const
{
	return d_ptr->price();
}

double Transaction::qty() const
{
	return d_ptr->qty();
}

double Transaction::commission() const
{
	return d_ptr->commission();
}

bool Transaction::isDone() const
{
	return d_ptr->isDone();
}

double Transaction::amount() const
{
	return d_ptr->amount();
}

double Transaction::value() const
{
	return d_ptr->value();
}

double Transaction::netCashFlow() const
{
	return d_ptr->netCashFlow();
}

double Transaction::cashFlow() const
{
	return d_ptr->cashFlow();
}

void Transaction::add(const Fill& fill)
{
	d_ptr->add(fill);
}

QString Transaction::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const Transaction& transaction)
{
	return dbg << transaction.toString();
}

