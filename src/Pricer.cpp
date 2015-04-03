#include <QuantKit/Pricer.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Position.h>

namespace QuantKit {

class PricerPrivate : public QSharedData
{
public:
	Framework m_framework;

public:
	explicit PricerPrivate(const Framework& framework);
	virtual ~PricerPrivate();

public:
	virtual double getPrice(const Position& position) Q_DECL_OVERRIDE;
	virtual double getValue(const Position& position) Q_DECL_OVERRIDE;
	virtual PricerPrivate* clone() Q_DECL_OVERRIDE { return new PricerPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

PricerPrivate::PricerPrivate(const Framework& framework)
	: m_framework(framework)
{
}

PricerPrivate::~PricerPrivate ()
{
}

double PricerPrivate::getPrice(const Position& position)
{
	if (position.side() == PositionSide.Long)
	{
		Bid bid = position.instrument().bid();
		if (bid != null)
		{
			return bid.price();
		}
	}
	else
	{
		Ask ask = position.instrument().ask();
		if (ask != null)
		{
			return ask.price();
		}
	}
	Trade trade = position.instrument().trade();
	if (trade != null)
	{
		return trade.price();
	}
	Bar bar = position.instrument().bar();
	if (bar != null)
	{
		return bar.close();
	}
	return 0.0;
}

double PricerPrivate::getValue(const Position& position)
{
	if (position.instrument().factor() != 0.0)
	{
		return position.price() * position.qty() * position.instrument().factor();
	}
	return position.price() * position.qty();
}


// Pubic API 

Pricer::Pricer(const Framework& framework)
	: d_ptr(new PricerPrivate(framework))
{
}

Pricer::~Pricer()
{
}

Pricer::Pricer (const Pricer &other)
	: d_ptr(other.d_ptr)
{
}

Pricer& Pricer::operator=(const Pricer &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Pricer::operator==(const Pricer &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

double Pricer::getPrice(const Position& position)
{
	return d_ptr->getPrice(position);
}

double Pricer::getValue(const Position& position)
{
	return d_ptr->getValue(position);
}

QDebug operator<<(QDebug dbg, const Pricer& pricer)
{
	return dbg << pricer.toString();
}

