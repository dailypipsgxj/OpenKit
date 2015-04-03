#include <QuantKit/Event/OnPositionChanged.h>

#include <QuantKit/Portfolio.h>
#include <QuantKit/Position.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnPositionChangedPrivate : public EventPrivate
{
public:
	Portfolio m_portfolio;
	Position m_position;

public:
	OnPositionChangedPrivate(const Portfolio& portfolio, const Position& position);
	virtual ~OnPositionChangedPrivate();

public:
	Portfolio getPortfolio() const;

	Position getPosition() const;
	virtual unsigned char typeId() const Q_DECL_OVERRIDE
	{
		return EventType::OnPositionChanged;
	}

	virtual QString toString() const Q_DECL_OVERRIDE { return "OnPositionChanged"; }
	virtual OnPositionChangedPrivate* clone() Q_DECL_OVERRIDE { return new OnPositionChangedPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnPositionChangedPrivate::OnPositionChangedPrivate(const Portfolio& portfolio, const Position& position)
	: m_portfolio(portfolio)
	, m_position(position)
{
}

OnPositionChangedPrivate::~OnPositionChangedPrivate ()
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

QK_IMPLEMENTATION_PRIVATE(OnPositionChanged)

OnPositionChanged::OnPositionChanged(const Portfolio& portfolio, const Position& position)
	: Event(*new OnPositionChangedPrivate(portfolio, position))
{
}

OnPositionChanged::~OnPositionChanged()
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


