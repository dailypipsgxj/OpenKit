#include <QuantKit/PositionEventArgs.h>

#include <QuantKit/Portfolio.h>
#include <QuantKit/Position.h>
#include "PortfolioEventArgs_p.h"

namespace QuantKit {

class PositionEventArgsPrivate : public PortfolioEventArgsPrivate
{
public:
	Position m_position;

public:
	PositionEventArgsPrivate(const Portfolio& portfolio, const Position& position);
	virtual ~PositionEventArgsPrivate();

public:
	Position position() const { return m_position; }
	virtual PositionEventArgsPrivate* clone() Q_DECL_OVERRIDE { return new PositionEventArgsPrivate(*this); }
//private:
	void setPosition(const Position& value) { m_position = value; }
};

} // namepsace QuantKit


using namespace QuantKit;

PositionEventArgsPrivate::PositionEventArgsPrivate(const Portfolio& portfolio, const Position& position)
	: PortfolioEventArgsPrivate (portfolio)
	, m_position(position)
{
}

PositionEventArgsPrivate::~PositionEventArgsPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(PositionEventArgs)

PositionEventArgs::PositionEventArgs(const Portfolio& portfolio, const Position& position)
	: PortfolioEventArgs(*new PositionEventArgsPrivate(portfolio, position))
{
}

PositionEventArgs::~PositionEventArgs()
{
}

Position PositionEventArgs::position() const
{
	Q_D(const PositionEventArgs);
	return d->position();
}


