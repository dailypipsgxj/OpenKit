#include <QuantKit/InstrumentDefinitionRequest.h>


namespace QuantKit {

class InstrumentDefinitionRequestPrivate : public QSharedData
{
public:
	QString m_id;
	Nullable`1<InstrumentType> m_filterType;
	QString m_filterSymbol;
	QString m_filterExchange;

public:
	InstrumentDefinitionRequestPrivate();
	virtual ~InstrumentDefinitionRequestPrivate();

public:
	QString id() const { return m_id; }
	void setId(const QString& value) { m_id = value; }
	Nullable`1<InstrumentType> filterType() const { return m_filterType; }
	void setFilterType(const Nullable`1<InstrumentType>& value) { m_filterType = value; }
	QString filterSymbol() const { return m_filterSymbol; }
	void setFilterSymbol(const QString& value) { m_filterSymbol = value; }
	QString filterExchange() const { return m_filterExchange; }
	void setFilterExchange(const QString& value) { m_filterExchange = value; }
	virtual InstrumentDefinitionRequestPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentDefinitionRequestPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentDefinitionRequestPrivate::InstrumentDefinitionRequestPrivate()
{
}

InstrumentDefinitionRequestPrivate::~InstrumentDefinitionRequestPrivate ()
{
}


// Pubic API 

InstrumentDefinitionRequest::InstrumentDefinitionRequest()
	: d_ptr(new InstrumentDefinitionRequestPrivate)
{
}

InstrumentDefinitionRequest::~InstrumentDefinitionRequest()
{
}

InstrumentDefinitionRequest::InstrumentDefinitionRequest (const InstrumentDefinitionRequest &other)
	: d_ptr(other.d_ptr)
{
}

InstrumentDefinitionRequest& InstrumentDefinitionRequest::operator=(const InstrumentDefinitionRequest &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool InstrumentDefinitionRequest::operator==(const InstrumentDefinitionRequest &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString InstrumentDefinitionRequest::id() const
{
	return d_ptr->id();
}

void InstrumentDefinitionRequest::setId(const QString& value)
{
	d_ptr->setId(value);
}

Nullable`1<InstrumentType> InstrumentDefinitionRequest::filterType() const
{
	return d_ptr->filterType();
}

void InstrumentDefinitionRequest::setFilterType(const Nullable`1<InstrumentType>& value)
{
	d_ptr->setFilterType(value);
}

QString InstrumentDefinitionRequest::filterSymbol() const
{
	return d_ptr->filterSymbol();
}

void InstrumentDefinitionRequest::setFilterSymbol(const QString& value)
{
	d_ptr->setFilterSymbol(value);
}

QString InstrumentDefinitionRequest::filterExchange() const
{
	return d_ptr->filterExchange();
}

void InstrumentDefinitionRequest::setFilterExchange(const QString& value)
{
	d_ptr->setFilterExchange(value);
}

QDebug operator<<(QDebug dbg, const InstrumentDefinitionRequest& instrumentdefinitionrequest)
{
	return dbg << instrumentdefinitionrequest.toString();
}

