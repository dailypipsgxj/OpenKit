#include <QuantKit/Event/OnFill.h>

#include <QuantKit/Event/Fill.h>
#include <QuantKit/Portfolio.h>

#include "Event_p.h"
#include <QuantKit/EventType.h>

namespace QuantKit {

class OnFillPrivate : public EventPrivate
{
public:
	Fill m_fill;
	Portfolio m_portfolio;

public:
	OnFillPrivate(const Portfolio& portfolio, const Fill& fill);
	virtual ~OnFillPrivate();

public:
	Fill fill() const { return m_fill; }
	Portfolio portfolio() const { return m_portfolio; }
	virtual unsigned char typeId() const Q_DECL_OVERRIDE { return EventType::OnFill; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "OnFill"; }
	virtual OnFillPrivate* clone() Q_DECL_OVERRIDE { return new OnFillPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

OnFillPrivate::OnFillPrivate(const Portfolio& portfolio, const Fill& fill)
	: m_fill(fill)
	, m_portfolio(portfolio)
{
}

OnFillPrivate::~OnFillPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(OnFill)

OnFill::OnFill(const Portfolio& portfolio, const Fill& fill)
	: Event(*new OnFillPrivate(portfolio, fill))
{
}

OnFill::~OnFill()
{
}

Fill OnFill::fill() const
{
	Q_D(const OnFill);
	return d->fill();
}

Portfolio OnFill::portfolio() const
{
	Q_D(const OnFill);
	return d->portfolio();
}


