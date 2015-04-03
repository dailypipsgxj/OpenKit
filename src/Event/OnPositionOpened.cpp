#include <QuantKit/Event/OnPositionOpened.h>

#include <QuantKit/Portfolio.h>
#include <QuantKit/Position.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnPositionOpenedPrivate : public EventPrivate
{
public:
	Portfolio m_portfolio;
	Position m_position;

public:
	OnPositionOpenedPrivate(const Portfolio& portfolio, const Position& position);
	virtual ~OnPositionOpenedPrivate();

public:
	Portfolio getPortfolio() const;

	Position getPosition() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnPositionOpened;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnPositionOpened"; }
	virtual OnPositionOpenedPrivate* clone() Q_DECL_OVERRIDE { return new OnPositionOpenedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnPositionOpenedPrivate::OnPositionOpenedPrivate(const Portfolio& portfolio, const Position& position)
	: m_portfolio(portfolio)
	, m_position(position)
{
}

OnPositionOpenedPrivate::~OnPositionOpenedPrivate ()
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

QK_IMPLEMENTATION_PRIVATE(OnPositionOpened)

OnPositionOpened::OnPositionOpened(const Portfolio& portfolio, const Position& position)
	: Event(*new OnPositionOpenedPrivate(portfolio, position))
{
}

OnPositionOpened::~OnPositionOpened()
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


