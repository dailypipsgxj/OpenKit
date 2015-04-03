#include <QuantKit/Event/OnPortfolioAdded.h>

#include <QuantKit/Portfolio.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnPortfolioAddedPrivate : public EventPrivate
{
public:
	Portfolio m_portfolio;

public:
	explicit OnPortfolioAddedPrivate(const Portfolio& portfolio);
	virtual ~OnPortfolioAddedPrivate();

public:
	Portfolio portfolio() const { return m_portfolio; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnPortfolioAdded;
	}

	virtual OnPortfolioAddedPrivate* clone() Q_DECL_OVERRIDE { return new OnPortfolioAddedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnPortfolioAddedPrivate::OnPortfolioAddedPrivate(const Portfolio& portfolio)
	: m_portfolio(portfolio)
{
}

OnPortfolioAddedPrivate::~OnPortfolioAddedPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnPortfolioAdded)

OnPortfolioAdded::OnPortfolioAdded(const Portfolio& portfolio)
	: Event(*new OnPortfolioAddedPrivate(portfolio))
{
}

OnPortfolioAdded::~OnPortfolioAdded()
{
}

Portfolio OnPortfolioAdded::portfolio() const
{
	Q_D(const OnPortfolioAdded);
	return d->portfolio();
}


