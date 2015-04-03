#include <QuantKit/Parameter.h>


namespace QuantKit {

class ParameterPrivate : public QSharedData
{
public:
	QString m_name;
	QVariant m_value;
	Attribute m_attributes;

public:
	ParameterPrivate(const QString& name, const QVariant& value);
	ParameterPrivate(const QString& name, const QVariant& value, const Attribute& attributes);
	virtual ~ParameterPrivate();

public:
	QString name() const { return m_name; }
	QVariant value() const { return m_value; }
	Attribute attributes() const { return m_attributes; }
	virtual QString toString() const Q_DECL_OVERRIDE { return "Parameter"; }
	virtual ParameterPrivate* clone() Q_DECL_OVERRIDE { return new ParameterPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

ParameterPrivate::ParameterPrivate(const QString& name, const QVariant& value)
	: m_name(name)
	, m_value(value)
	, m_attributes(new Attribute[0])
{
}

ParameterPrivate::ParameterPrivate(const QString& name, const QVariant& value, Attribute attributes)
	: m_name(name)
	, m_value(value)
	, m_attributes(attributes)
{
}

ParameterPrivate::~ParameterPrivate ()
{
}


// Pubic API 

Parameter::Parameter(const QString& name, const QVariant& value)
	: d_ptr(new ParameterPrivate(name, value))
{
}

Parameter::Parameter(const QString& name, const QVariant& value, Attribute attributes)
	: d_ptr(new ParameterPrivate(name, value, attributes))
{
}

Parameter::~Parameter()
{
}

Parameter::Parameter (const Parameter &other)
	: d_ptr(other.d_ptr)
{
}

Parameter& Parameter::operator=(const Parameter &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool Parameter::operator==(const Parameter &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QString Parameter::name() const
{
	return d_ptr->name();
}

QVariant Parameter::value() const
{
	return d_ptr->value();
}

Attribute Parameter::attributes() const
{
	return d_ptr->attributes();
}

QString Parameter::toString() const
{
	return d_ptr->toString();
}

QDebug operator<<(QDebug dbg, const Parameter& parameter)
{
	return dbg << parameter.toString();
}

