#include <QuantKit/Event/OnPortfolioParentChanged.h>

#include <QuantKit/Portfolio.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnPortfolioParentChangedPrivate : public EventPrivate
{
public:
	Portfolio m_portfolio;

public:
	explicit OnPortfolioParentChangedPrivate(const Portfolio& portfolio);
	virtual ~OnPortfolioParentChangedPrivate();

public:
	Portfolio portfolio() const { return m_portfolio; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnPortfolioParentChanged;
	}

	virtual OnPortfolioParentChangedPrivate* clone() Q_DECL_OVERRIDE { return new OnPortfolioParentChangedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnPortfolioParentChangedPrivate::OnPortfolioParentChangedPrivate(const Portfolio& portfolio)
	: m_portfolio(portfolio)
{
}

OnPortfolioParentChangedPrivate::~OnPortfolioParentChangedPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnPortfolioParentChanged)

OnPortfolioParentChanged::OnPortfolioParentChanged(const Portfolio& portfolio)
	: Event(*new OnPortfolioParentChangedPrivate(portfolio))
{
}

OnPortfolioParentChanged::~OnPortfolioParentChanged()
{
}

Portfolio OnPortfolioParentChanged::portfolio() const
{
	Q_D(const OnPortfolioParentChanged);
	return d->portfolio();
}


