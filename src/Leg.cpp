#include <QuantKit/Leg.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Instrument.h>

namespace QuantKit {

class LegPrivate : public QSharedData
{
public:
	Framework m_framework;
	int m_symbol;
	Instrument m_symbol;
	double m_weight;

public:
	LegPrivate();
	explicit LegPrivate(const Framework& framework);
	LegPrivate(const Instrument& instrument, double weight);
	virtual ~LegPrivate();

public:
	Instrument instrument() const { return m_symbol; }
	void setInstrument(const Instrument& value);
	QString symbol() const;
	void setSymbol(const QString& value);
	double weight() const { return m_weight; }
	void setWeight(double value) { m_weight = value; }
	virtual LegPrivate* clone() Q_DECL_OVERRIDE { return new LegPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

LegPrivate::LegPrivate()
{
}

LegPrivate::LegPrivate(const Framework& framework)
	: m_framework(framework)
{
}

LegPrivate::LegPrivate(const Instrument& instrument, double weight)
	: m_framework(instrument.framework())
	, m_symbol(instrument)
	, m_symbol(instrument.id())
	, m_weight(weight)
{
}

LegPrivate::~LegPrivate ()
{
}

void LegPrivate::setInstrument(const Instrument& value)
{
	m_symbol = value;
	m_symbol = m_symbol.id();
}

QString LegPrivate::symbol() const
{
	if (m_symbol != null)
	{
		return m_symbol.symbol();
	}
	return null;
}

void LegPrivate::setSymbol(const QString& value)
{
	Instrument instrument = m_framework.instrumentManager()[value];
	if (instrument != null)
	{
		m_symbol = instrument;
		m_symbol = instrument.id();
		return;
	}
	Console.WriteLine("Leg::Symbol Can not find instrument with such symbol in the framework instrument manager. Symbol = " + m_symbol);
}


// Pubic API 

Leg::Leg()
	: d_ptr(new LegPrivate)
{
}

Leg::Leg(const Framework& framework)
	: d_ptr(new LegPrivate(framework))
{
}

Leg::Leg(const Instrument& instrument, double weight)
	: d_ptr(new LegPrivate(instrument, weight))
{
}

Leg::~Leg()
{
}

Leg::Leg (const Leg &other)
	: d_ptr(other.d_ptr)
{
}

Leg& Leg::operator=(const Leg &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Leg::operator==(const Leg &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

Instrument Leg::instrument() const
{
	return d_ptr->instrument();
}

void Leg::setInstrument(const Instrument& value)
{
	d_ptr->setInstrument(value);
}

QString Leg::symbol() const
{
	return d_ptr->symbol();
}

void Leg::setSymbol(const QString& value)
{
	d_ptr->setSymbol(value);
}

double Leg::weight() const
{
	return d_ptr->weight();
}

void Leg::setWeight(double value)
{
	d_ptr->setWeight(value);
}

QDebug operator<<(QDebug dbg, const Leg& leg)
{
	return dbg << leg.toString();
}

