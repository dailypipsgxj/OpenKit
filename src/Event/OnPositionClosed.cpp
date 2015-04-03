#include <QuantKit/Event/OnPositionClosed.h>

#include <QuantKit/Portfolio.h>
#include <QuantKit/Position.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnPositionClosedPrivate : public EventPrivate
{
public:
	Portfolio m_portfolio;
	Position m_position;

public:
	OnPositionClosedPrivate(const Portfolio& portfolio, const Position& position);
	virtual ~OnPositionClosedPrivate();

public:
	Portfolio getPortfolio() const;

	Position getPosition() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnPositionClosed;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnPositionClosed"; }
	virtual OnPositionClosedPrivate* clone() Q_DECL_OVERRIDE { return new OnPositionClosedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnPositionClosedPrivate::OnPositionClosedPrivate(const Portfolio& portfolio, const Position& position)
	: m_portfolio(portfolio)
	, m_position(position)
{
}

OnPositionClosedPrivate::~OnPositionClosedPrivate ()
{
}

Portfolio getPortfolio() const
{
	return null;
}

Position getPosition() const
{
	return null;
}

// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnPositionClosed)

OnPositionClosed::OnPositionClosed(const Portfolio& portfolio, const Position& position)
	: Event(*new OnPositionClosedPrivate(portfolio, position))
{
}

OnPositionClosed::~OnPositionClosed()
{
}

Portfolio portfolio() const
{
	return d_ptr->
	setPortfolio()
}

Position position() const
{
	return d_ptr->
	setPosition()
}


