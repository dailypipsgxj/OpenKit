#include <QuantKit/InstrumentDefinitionEnd.h>


namespace QuantKit {

class InstrumentDefinitionEndPrivate : public QSharedData
{
public:
	QString m_requestId;
	RequestResult m_result;
	QString m_text;

public:
	InstrumentDefinitionEndPrivate();
	virtual ~InstrumentDefinitionEndPrivate();

public:
	QString requestId() const { return m_requestId; }
	void setRequestId(const QString& value) { m_requestId = value; }
	RequestResult result() const { return m_result; }
	void setResult(RequestResult value) { m_result = value; }
	QString text() const { return m_text; }
	void setText(const QString& value) { m_text = value; }
	virtual InstrumentDefinitionEndPrivate* clone() Q_DECL_OVERRIDE { return new InstrumentDefinitionEndPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

InstrumentDefinitionEndPrivate::InstrumentDefinitionEndPrivate()
{
}

InstrumentDefinitionEndPrivate::~InstrumentDefinitionEndPrivate ()
{
}


// Pubic API 

InstrumentDefinitionEnd::InstrumentDefinitionEnd()
	: d_ptr(new InstrumentDefinitionEndPrivate)
{
}

InstrumentDefinitionEnd::~InstrumentDefinitionEnd()
{
}

InstrumentDefinitionEnd::InstrumentDefinitionEnd (const InstrumentDefinitionEnd &other)
	: d_ptr(other.d_ptr)
{
}

InstrumentDefinitionEnd& InstrumentDefinitionEnd::operator=(const InstrumentDefinitionEnd &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool InstrumentDefinitionEnd::operator==(const InstrumentDefinitionEnd &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString InstrumentDefinitionEnd::requestId() const
{
	return d_ptr->requestId();
}

void InstrumentDefinitionEnd::setRequestId(const QString& value)
{
	d_ptr->setRequestId(value);
}

RequestResult InstrumentDefinitionEnd::result() const
{
	return d_ptr->result();
}

void InstrumentDefinitionEnd::setResult(RequestResult value)
{
	d_ptr->setResult(value);
}

QString InstrumentDefinitionEnd::text() const
{
	return d_ptr->text();
}

void InstrumentDefinitionEnd::setText(const QString& value)
{
	d_ptr->setText(value);
}

QDebug operator<<(QDebug dbg, const InstrumentDefinitionEnd& instrumentdefinitionend)
{
	return dbg << instrumentdefinitionend.toString();
}

