#include <QuantKit/Event/OnPortfolioDeleted.h>

#include <QuantKit/Portfolio.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnPortfolioDeletedPrivate : public EventPrivate
{
public:
	Portfolio m_portfolio;

public:
	explicit OnPortfolioDeletedPrivate(const Portfolio& portfolio);
	virtual ~OnPortfolioDeletedPrivate();

public:
	Portfolio portfolio() const { return m_portfolio; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnPortfolioDeleted;
	}

	virtual OnPortfolioDeletedPrivate* clone() Q_DECL_OVERRIDE { return new OnPortfolioDeletedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnPortfolioDeletedPrivate::OnPortfolioDeletedPrivate(const Portfolio& portfolio)
	: m_portfolio(portfolio)
{
}

OnPortfolioDeletedPrivate::~OnPortfolioDeletedPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnPortfolioDeleted)

OnPortfolioDeleted::OnPortfolioDeleted(const Portfolio& portfolio)
	: Event(*new OnPortfolioDeletedPrivate(portfolio))
{
}

OnPortfolioDeleted::~OnPortfolioDeleted()
{
}

Portfolio OnPortfolioDeleted::portfolio() const
{
	Q_D(const OnPortfolioDeleted);
	return d->portfolio();
}


