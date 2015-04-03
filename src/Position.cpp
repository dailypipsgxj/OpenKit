#include <QuantKit/Position.h>

#include <QuantKit/Portfolio.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/Event/Fill.h>

namespace QuantKit {

class PositionPrivate : public QSharedData
{
public:
	Portfolio m_value;
	Instrument m_instrument;
	int m_portfolioId;
	int m_instrumentId;
	double m_qty;
	double m_qtyBought;
	double m_qtySold;
	QList<Fill> m_fills;
	Fill m_entryQty;

public:
	PositionPrivate();
	PositionPrivate(const Portfolio& portfolio, const Instrument& instrument);
	virtual ~PositionPrivate();

public:
	Portfolio portfolio() const { return m_value; }
	Instrument instrument() const { return m_instrument; }
	int portfolioId() const { return m_portfolioId; }
	int instrumentId() const { return m_instrumentId; }
	QList<Fill> fills() const { return m_fills; }
	double amount() const { return m_qty; }
	double qty() const { return Math.Abs(m_qty); }
	double qtyBought() const { return m_qtyBought; }
	double qtySold() const { return m_qtySold; }
	PositionSide side() const;
	double price() const
	{
		return m_value.pricer().GetPrice(this);
	}

	double value() const
	{
		return m_value.pricer().GetValue(this);
	}

	double entryPrice() const
	{
		return m_entryQty.entryPrice();
	}

	QDateTime entryDate() const { return m_entryQty.entryDate(); }
	double entryQty() const { return m_entryQty.entryQty(); }
	void add(const Fill& fill);
	QString getSideAsString();
	virtual QString toString() const Q_DECL_OVERRIDE { return "Position"; }
	virtual PositionPrivate* clone() Q_DECL_OVERRIDE { return new PositionPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

PositionPrivate::PositionPrivate()
	: m_portfolioId(-1)
	, m_instrumentId(-1)
	, m_fills(new QList<Fill>())
{
}

PositionPrivate::PositionPrivate(const Portfolio& portfolio, const Instrument& instrument)
	: m_value(portfolio)
	, m_instrument(instrument)
	, m_portfolioId(-1)
	, m_portfolioId(portfolio.id())
	, m_instrumentId(-1)
	, m_instrumentId(instrument.id())
	, m_fills(new QList<Fill>())
{
}

PositionPrivate::~PositionPrivate ()
{
}

PositionSide PositionPrivate::side() const
{
	if (m_qty < 0.0)
	{
		return PositionSide.Short;
	}
	return PositionSide.Long;
}

void PositionPrivate::add(const Fill& fill)
{
	m_fills.Add(fill);
	if (m_qty == 0.0)
	{
		m_entryQty = fill;
	}
	if (fill.side() == OrderSide.Buy)
	{
		m_qtyBought += fill.entryQty();
	}
	else
	{
		m_qtySold += fill.entryQty();
	}
	m_qty = m_qtyBought - m_qtySold;
}

QString PositionPrivate::getSideAsString()
{
	switch (side())
	{
		case PositionSide.Long:
			return "Long";
		case PositionSide.Short:
			return "Short";
		default:
			return "Undefined";
	}
}


// Pubic API 

Position::Position()
	: d_ptr(new PositionPrivate)
{
}

Position::Position(const Portfolio& portfolio, const Instrument& instrument)
	: d_ptr(new PositionPrivate(portfolio, instrument))
{
}

Position::~Position()
{
}

Position::Position (const Position &other)
	: d_ptr(other.d_ptr)
{
}

Position& Position::operator=(const Position &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Position::operator==(const Position &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Portfolio Position::portfolio() const
{
	return d_ptr->portfolio();
}

Instrument Position::instrument() const
{
	return d_ptr->instrument();
}

int Position::portfolioId() const
{
	return d_ptr->portfolioId();
}

int Position::instrumentId() const
{
	return d_ptr->instrumentId();
}

QList<Fill> Position::fills() const
{
	return d_ptr->fills();
}

double Position::amount() const
{
	return d_ptr->amount();
}

double Position::qty() const
{
	return d_ptr->qty();
}

double Position::qtyBought() const
{
	return d_ptr->qtyBought();
}

double Position::qtySold() const
{
	return d_ptr->qtySold();
}

PositionSide Position::side() const
{
	return d_ptr->side();
}

double Position::price() const
{
	return d_ptr->price();
}

double Position::value() const
{
	return d_ptr->value();
}

double Position::entryPrice() const
{
	return d_ptr->entryPrice();
}

QDateTime Position::entryDate() const
{
	return d_ptr->entryDate();
}

double Position::entryQty() const
{
	return d_ptr->entryQty();
}

void Position::add(const Fill& fill)
{
	d_ptr->add(fill);
}

QString Position::getSideAsString()
{
	return d_ptr->getSideAsString();
}

QString Position::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const Position& position)
{
	return dbg << position.toString();
}

