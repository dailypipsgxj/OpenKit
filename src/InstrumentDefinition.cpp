#include <QuantKit/InstrumentDefinition.h>

#include <QuantKit/Instrument.h>

namespace QuantKit {

class InstrumentDefinitionPrivate : public QSharedData
{
public:
	QString m_requestId;
	unsigned char m_providerId;
	int m_totalNum;
	Instrument m_instruments;

public:
	InstrumentDefinitionPrivate();
	virtual ~InstrumentDefinitionPrivate();

public:
	QString requestId() const { return m_requestId; }
	void setRequestId(const QString& value) { m_requestId = value; }
	unsigned char providerId() const { return m_providerId; }
	void setProviderId(unsigned char value) { m_providerId = value; }
	int totalNum() const { return m_totalNum; }
	void setTotalNum(int value) { m_totalNum = value; }
	Instrument instruments() const { return m_instruments; }
	void setInstruments(const Instrument& value) { m_instruments = value; }
	virtual InstrumentDefinitionPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentDefinitionPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentDefinitionPrivate::InstrumentDefinitionPrivate()
{
}

InstrumentDefinitionPrivate::~InstrumentDefinitionPrivate ()
{
}


// Pubic API 

InstrumentDefinition::InstrumentDefinition()
	: d_ptr(new InstrumentDefinitionPrivate)
{
}

InstrumentDefinition::~InstrumentDefinition()
{
}

InstrumentDefinition::InstrumentDefinition (const InstrumentDefinition &other)
	: d_ptr(other.d_ptr)
{
}

InstrumentDefinition& InstrumentDefinition::operator=(const InstrumentDefinition &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool InstrumentDefinition::operator==(const InstrumentDefinition &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString InstrumentDefinition::requestId() const
{
	return d_ptr->requestId();
}

void InstrumentDefinition::setRequestId(const QString& value)
{
	d_ptr->setRequestId(value);
}

unsigned char InstrumentDefinition::providerId() const
{
	return d_ptr->providerId();
}

void InstrumentDefinition::setProviderId(unsigned char value)
{
	d_ptr->setProviderId(value);
}

int InstrumentDefinition::totalNum() const
{
	return d_ptr->totalNum();
}

void InstrumentDefinition::setTotalNum(int value)
{
	d_ptr->setTotalNum(value);
}

Instrument InstrumentDefinition::instruments() const
{
	return d_ptr->instruments();
}

void InstrumentDefinition::setInstruments(Instrument value)
{
	d_ptr->setInstruments(value);
}

QDebug operator<<(QDebug dbg, const InstrumentDefinition& instrumentdefinition)
{
	return dbg << instrumentdefinition.toString();
}

