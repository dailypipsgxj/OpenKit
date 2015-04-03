#include <QuantKit/StrategyMethodAttribute.h>


namespace QuantKit {

class StrategyMethodAttributePrivate : public QSharedData
{
public:
	StrategyMethodAttributePrivate();
	virtual ~StrategyMethodAttributePrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

StrategyMethodAttributePrivate::StrategyMethodAttributePrivate()
{
}

StrategyMethodAttributePrivate::~StrategyMethodAttributePrivate ()
{
}


// Pubic API 

StrategyMethodAttribute::StrategyMethodAttribute()
	: d_ptr(new StrategyMethodAttributePrivate)
{
}

StrategyMethodAttribute::~StrategyMethodAttribute()
{
}

StrategyMethodAttribute::StrategyMethodAttribute (const StrategyMethodAttribute &other)
	: d_ptr(other.d_ptr)
{
}

StrategyMethodAttribute& StrategyMethodAttribute::operator=(const StrategyMethodAttribute &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool StrategyMethodAttribute::operator==(const StrategyMethodAttribute &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const StrategyMethodAttribute& strategymethodattribute)
{
	return dbg << strategymethodattribute.toString();
}

