#include <QuantKit/ParameterAttribute.h>


namespace QuantKit {

class ParameterAttributePrivate : public QSharedData
{
public:
	ParameterAttributePrivate();
	virtual ~ParameterAttributePrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

ParameterAttributePrivate::ParameterAttributePrivate()
{
}

ParameterAttributePrivate::~ParameterAttributePrivate ()
{
}


// Pubic API 

ParameterAttribute::ParameterAttribute()
	: d_ptr(new ParameterAttributePrivate)
{
}

ParameterAttribute::~ParameterAttribute()
{
}

ParameterAttribute::ParameterAttribute (const ParameterAttribute &other)
	: d_ptr(other.d_ptr)
{
}

ParameterAttribute& ParameterAttribute::operator=(const ParameterAttribute &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool ParameterAttribute::operator==(const ParameterAttribute &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const ParameterAttribute& parameterattribute)
{
	return dbg << parameterattribute.toString();
}

