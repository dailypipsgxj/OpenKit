#include <QuantKit/AltId.h>


namespace QuantKit {

class AltIdPrivate : public QSharedData
{
public:
	unsigned char m_providerId;
	QString m_symbol;
	QString m_exchange;

public:
	AltIdPrivate();
	AltIdPrivate(unsigned char providerId, const QString& symbol, const QString& exchange);
	virtual ~AltIdPrivate();

public:
	unsigned char providerId() const { return m_providerId; }
	void setProviderId(unsigned char value) { m_providerId = value; }
	QString symbol() const { return m_symbol; }
	void setSymbol(const QString& value) { m_symbol = value; }
	QString exchange() const { return m_exchange; }
	void setExchange(const QString& value) { m_exchange = value; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "AltId"; }
	virtual AltIdPrivate* clone() Q_DECL_OVERRIDE { return new AltIdPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

AltIdPrivate::AltIdPrivate()
{
}

AltIdPrivate::AltIdPrivate(unsigned char providerId, const QString& symbol, const QString& exchange)
	: m_providerId(providerId)
	, m_symbol(symbol)
	, m_exchange(exchange)
{
}

AltIdPrivate::~AltIdPrivate ()
{
}


// Pubic API 

AltId::AltId()
	: d_ptr(new AltIdPrivate)
{
}

AltId::AltId(unsigned char providerId, const QString& symbol, const QString& exchange)
	: d_ptr(new AltIdPrivate(providerId, symbol, exchange))
{
}

AltId::~AltId()
{
}

AltId::AltId (const AltId &other)
	: d_ptr(other.d_ptr)
{
}

AltId& AltId::operator=(const AltId &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool AltId::operator==(const AltId &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

unsigned char AltId::providerId() const
{
	return d_ptr->providerId();
}

void AltId::setProviderId(unsigned char value)
{
	d_ptr->setProviderId(value);
}

QString AltId::symbol() const
{
	return d_ptr->symbol();
}

void AltId::setSymbol(const QString& value)
{
	d_ptr->setSymbol(value);
}

QString AltId::exchange() const
{
	return d_ptr->exchange();
}

void AltId::setExchange(const QString& value)
{
	d_ptr->setExchange(value);
}

QString AltId::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const AltId& altid)
{
	return dbg << altid.toString();
}

