#include <QuantKit/Event/OnTransaction.h>

#include <QuantKit/Transaction.h>
#include <QuantKit/Portfolio.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnTransactionPrivate : public EventPrivate
{
public:
	Transaction m_transaction;
	Portfolio m_portfolio;

public:
	OnTransactionPrivate(const Portfolio& portfolio, const Transaction& transaction);
	virtual ~OnTransactionPrivate();

public:
	Transaction transaction() const { return m_transaction; }
	Portfolio portfolio() const { return m_portfolio; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnTransaction;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnTransaction"; }
	virtual OnTransactionPrivate* clone() Q_DECL_OVERRIDE { return new OnTransactionPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnTransactionPrivate::OnTransactionPrivate(const Portfolio& portfolio, const Transaction& transaction)
	: m_transaction(transaction)
	, m_portfolio(portfolio)
{
}

OnTransactionPrivate::~OnTransactionPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnTransaction)

OnTransaction::OnTransaction(const Portfolio& portfolio, const Transaction& transaction)
	: Event(*new OnTransactionPrivate(portfolio, transaction))
{
}

OnTransaction::~OnTransaction()
{
}

Transaction OnTransaction::transaction() const
{
	Q_D(const OnTransaction);
	return d->transaction();
}

Portfolio OnTransaction::portfolio() const
{
	Q_D(const OnTransaction);
	return d->portfolio();
}


