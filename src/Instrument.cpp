#include <QuantKit/Instrument.h>

#include <QuantKit/ObjectTable.h>
#include <QuantKit/AltIdList.h>
#include <QuantKit/Leg.h>
#include <QuantKit/Event/Bid.h>
#include <QuantKit/Event/Ask.h>
#include <QuantKit/Event/Trade.h>
#include <QuantKit/Event/Bar.h>
#include <QuantKit/Framework.h>

namespace QuantKit {

class InstrumentPrivate : public QSharedData
{
public:
	Framework m_framework;
	int m_id;
	InstrumentType m_type;
	QString m_symbol;
	QString m_description;
	QString m_exchange;
	unsigned char m_currencyId;
	unsigned char m_CCY1;
	unsigned char m_CCY2;
	double m_tickSize;
	QDateTime m_maturity;
	double m_factor;
	double m_strike;
	PutCall m_putCall;
	double m_margin;
	QString m_priceFormat;
	QString m_formula;
	AltIdList m_altId;
	QList<Leg> m_legs;
	ObjectTable m_fields;
	Trade m_trade;
	Ask m_ask;
	Bid m_bid;
	Bar m_bar;
	Instrument m_parent;
	IDataProvider m_dataProvider;
	IExecutionProvider m_executionProvider;
	bool bool_0;
	bool bool_1;

public:
	InstrumentPrivate();
	InstrumentPrivate(InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId);
	InstrumentPrivate(int id, InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId);
	InstrumentPrivate(int id, InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId, const QString& exchange);
	virtual ~InstrumentPrivate();

public:
	bool getBool_0() const;
	void setBool_0(bool value);

	bool getBool_1() const;
	void setBool_1(bool value);
	Framework getFramework() const;
	ObjectTable fields() const;
	Instrument parent() const { return m_parent; }
	void setParent(const Instrument& value) { m_parent = value; }
	int id() const { return m_id; }
	InstrumentType type() const { return m_type; }
	QString symbol() const { return m_symbol; }
	QString description() const { return m_description; }
	void setDescription(const QString& value) { m_description = value; }
	QString exchange() const { return m_exchange; }
	void setExchange(const QString& value) { m_exchange = value; }
	unsigned char currencyId() const { return m_currencyId; }
	void setCurrencyId(unsigned char value) { m_currencyId = value; }
	unsigned char CCY1() const { return m_CCY1; }
	void setCCY1(unsigned char value) { m_CCY1 = value; }
	unsigned char CCY2() const { return m_CCY2; }
	void setCCY2(unsigned char value) { m_CCY2 = value; }
	double tickSize() const { return m_tickSize; }
	void setTickSize(double value) { m_tickSize = value; }
	QDateTime maturity() const { return m_maturity; }
	void setMaturity(const QDateTime& value) { m_maturity = value; }
	double factor() const { return m_factor; }
	void setFactor(double value) { m_factor = value; }
	double strike() const { return m_strike; }
	void setStrike(double value) { m_strike = value; }
	PutCall putCall() const { return m_putCall; }
	void setPutCall(PutCall value) { m_putCall = value; }
	double margin() const { return m_margin; }
	void setMargin(double value) { m_margin = value; }
	QString priceFormat() const { return m_priceFormat; }
	void setPriceFormat(const QString& value) { m_priceFormat = value; }
	QString formula() const { return m_formula; }
	void setFormula(const QString& value) { m_formula = value; }
	AltIdList altId() const { return m_altId; }
	QList<Leg> legs() const { return m_legs; }
	Bid bid() const { return m_bid; }
	Ask ask() const { return m_ask; }
	Trade trade() const { return m_trade; }
	Bar bar() const { return m_bar; }
	IDataProvider dataProvider() const { return m_dataProvider; }
	void setDataProvider(const IDataProvider& value) { m_dataProvider = value; }
	IExecutionProvider executionProvider() const { return m_executionProvider; }
	void setExecutionProvider(const IExecutionProvider& value) { m_executionProvider = value; }
	Instrument clone(const QString& symbol);
	QString getExchange(unsigned char providerId);
	QString getSymbol(unsigned char providerId);
	virtual QString toString() const Q_DECL_OVERRIDE { return "Instrument"; }
	virtual InstrumentPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentPrivate::InstrumentPrivate()
	: m_exchange("")
	, m_priceFormat("F2")
	, m_formula("")
	, m_altId(new AltIdList())
	, m_legs(new QList<Leg>())
	, m_fields(new ObjectTable())
{
}

InstrumentPrivate::InstrumentPrivate(InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId)
	: m_type(type)
	, m_symbol(symbol)
	, m_description(description)
	, m_exchange("")
	, m_currencyId(currencyId)
	, m_priceFormat("F2")
	, m_formula("")
	, m_altId(new AltIdList())
	, m_legs(new QList<Leg>())
	, m_fields(new ObjectTable())
{
}

InstrumentPrivate::InstrumentPrivate(int id, InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId)
	: m_id(id)
	, m_type(type)
	, m_symbol(symbol)
	, m_description(description)
	, m_exchange("")
	, m_currencyId(currencyId)
	, m_priceFormat("F2")
	, m_formula("")
	, m_altId(new AltIdList())
	, m_legs(new QList<Leg>())
	, m_fields(new ObjectTable())
{
}

InstrumentPrivate::InstrumentPrivate(int id, InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId, QString exchange)
	: m_id(id)
	, m_type(type)
	, m_symbol(symbol)
	, m_description(description)
	, m_exchange("")
	, m_exchange(exchange)
	, m_currencyId(currencyId)
	, m_priceFormat("F2")
	, m_formula("")
	, m_altId(new AltIdList())
	, m_legs(new QList<Leg>())
	, m_fields(new ObjectTable())
{
}

InstrumentPrivate::~InstrumentPrivate ()
{
}

bool getBool_0() const
{
	return false;
}
void setBool_0(bool value)
{
}

bool getBool_1() const
{
	return false;
}
void setBool_1(bool value)
{
}

Framework getFramework() const
{
	return null;
}
ObjectTable InstrumentPrivate::fields() const
{
	if (m_fields == null)
	{
		m_fields = new ObjectTable();
	}
	return m_fields;
}

Instrument InstrumentPrivate::clone(QString symbol)
{
	Instrument instrument = new Instrument(this);
	if (symbol != null)
	{
		instrument.setSymbol() = symbol;
	}
	return instrument;
}

QString InstrumentPrivate::getExchange(unsigned char providerId)
{
	AltId altId = m_altId.Get(providerId);
	if (altId != null && !string.IsNullOrEmpty(altId.exchange()))
	{
		return altId.exchange();
	}
	return m_exchange;
}

QString InstrumentPrivate::getSymbol(unsigned char providerId)
{
	AltId altId = m_altId.Get(providerId);
	if (altId != null && !string.IsNullOrEmpty(altId.symbol()))
	{
		return altId.symbol();
	}
	return m_symbol;
}


// Pubic API 

Instrument::Instrument()
	: d_ptr(new InstrumentPrivate)
{
}

Instrument::Instrument(InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId)
	: d_ptr(new InstrumentPrivate(type, symbol, description, currencyId))
{
}

Instrument::Instrument(int id, InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId)
	: d_ptr(new InstrumentPrivate(id, type, symbol, description, currencyId))
{
}

Instrument::Instrument(int id, InstrumentType type, const QString& symbol, const QString& description, unsigned char currencyId, QString exchange)
	: d_ptr(new InstrumentPrivate(id, type, symbol, description, currencyId, exchange))
{
}

Instrument::~Instrument()
{
}

Instrument::Instrument (const Instrument &other)
	: d_ptr(other.d_ptr)
{
}

Instrument& Instrument::operator=(const Instrument &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Instrument::operator==(const Instrument &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

bool bool_0() const
{
	return d_ptr->
	setBool_0()
}

void setBool_0(bool value)
{
	d_ptr->bool_0(value);
}

bool bool_1() const
{
	return d_ptr->
	setBool_1()
}

void setBool_1(bool value)
{
	d_ptr->bool_1(value);
}

Framework framework() const
{
	return d_ptr->
	setFramework()
}

ObjectTable Instrument::fields() const
{
	return d_ptr->fields();
}

Instrument Instrument::parent() const
{
	return d_ptr->parent();
}

void Instrument::setParent(const Instrument& value)
{
	d_ptr->setParent(value);
}

int Instrument::id() const
{
	return d_ptr->id();
}

InstrumentType Instrument::type() const
{
	return d_ptr->type();
}

QString Instrument::symbol() const
{
	return d_ptr->symbol();
}

QString Instrument::description() const
{
	return d_ptr->description();
}

void Instrument::setDescription(const QString& value)
{
	d_ptr->setDescription(value);
}

QString Instrument::exchange() const
{
	return d_ptr->exchange();
}

void Instrument::setExchange(const QString& value)
{
	d_ptr->setExchange(value);
}

unsigned char Instrument::currencyId() const
{
	return d_ptr->currencyId();
}

void Instrument::setCurrencyId(unsigned char value)
{
	d_ptr->setCurrencyId(value);
}

unsigned char Instrument::CCY1() const
{
	return d_ptr->CCY1();
}

void Instrument::setCCY1(unsigned char value)
{
	d_ptr->setCCY1(value);
}

unsigned char Instrument::CCY2() const
{
	return d_ptr->CCY2();
}

void Instrument::setCCY2(unsigned char value)
{
	d_ptr->setCCY2(value);
}

double Instrument::tickSize() const
{
	return d_ptr->tickSize();
}

void Instrument::setTickSize(double value)
{
	d_ptr->setTickSize(value);
}

QDateTime Instrument::maturity() const
{
	return d_ptr->maturity();
}

void Instrument::setMaturity(const QDateTime& value)
{
	d_ptr->setMaturity(value);
}

double Instrument::factor() const
{
	return d_ptr->factor();
}

void Instrument::setFactor(double value)
{
	d_ptr->setFactor(value);
}

double Instrument::strike() const
{
	return d_ptr->strike();
}

void Instrument::setStrike(double value)
{
	d_ptr->setStrike(value);
}

PutCall Instrument::putCall() const
{
	return d_ptr->putCall();
}

void Instrument::setPutCall(PutCall value)
{
	d_ptr->setPutCall(value);
}

double Instrument::margin() const
{
	return d_ptr->margin();
}

void Instrument::setMargin(double value)
{
	d_ptr->setMargin(value);
}

QString Instrument::priceFormat() const
{
	return d_ptr->priceFormat();
}

void Instrument::setPriceFormat(const QString& value)
{
	d_ptr->setPriceFormat(value);
}

QString Instrument::formula() const
{
	return d_ptr->formula();
}

void Instrument::setFormula(const QString& value)
{
	d_ptr->setFormula(value);
}

AltIdList Instrument::altId() const
{
	return d_ptr->altId();
}

QList<Leg> Instrument::legs() const
{
	return d_ptr->legs();
}

Bid Instrument::bid() const
{
	return d_ptr->bid();
}

Ask Instrument::ask() const
{
	return d_ptr->ask();
}

Trade Instrument::trade() const
{
	return d_ptr->trade();
}

Bar Instrument::bar() const
{
	return d_ptr->bar();
}

IDataProvider Instrument::dataProvider() const
{
	return d_ptr->dataProvider();
}

void Instrument::setDataProvider(const IDataProvider& value)
{
	d_ptr->setDataProvider(value);
}

IExecutionProvider Instrument::executionProvider() const
{
	return d_ptr->executionProvider();
}

void Instrument::setExecutionProvider(const IExecutionProvider& value)
{
	d_ptr->setExecutionProvider(value);
}

Instrument Instrument::clone(QString symbol)
{
	return d_ptr->clone(symbol);
}

QString Instrument::getExchange(unsigned char providerId)
{
	return d_ptr->getExchange(providerId);
}

QString Instrument::getSymbol(unsigned char providerId)
{
	return d_ptr->getSymbol(providerId);
}

QString Instrument::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const Instrument& instrument)
{
	return dbg << instrument.toString();
}

