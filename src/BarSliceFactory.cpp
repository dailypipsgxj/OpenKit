#include <QuantKit/BarSliceFactory.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Event/Bar.h>

namespace QuantKit {

class BarSliceFactoryPrivate : public QSharedData
{
public:
	Framework m_framework;
	IdArray<Class28> m_idArray;

public:
	explicit BarSliceFactoryPrivate(const Framework& framework);
	virtual ~BarSliceFactoryPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

BarSliceFactoryPrivate::BarSliceFactoryPrivate(const Framework& framework)
	: m_framework(framework)
	, m_idArray(new IdArray<Class28>(86400))
{
}

BarSliceFactoryPrivate::~BarSliceFactoryPrivate ()
{
}


// Pubic API 

BarSliceFactory::BarSliceFactory(const Framework& framework)
	: d_ptr(new BarSliceFactoryPrivate(framework))
{
}

BarSliceFactory::~BarSliceFactory()
{
}

BarSliceFactory::BarSliceFactory (const BarSliceFactory &other)
	: d_ptr(other.d_ptr)
{
}

BarSliceFactory& BarSliceFactory::operator=(const BarSliceFactory &other)
{
	d_ptr = other.d_ptr;
	return *this;
}

bool BarSliceFactory::operator==(const BarSliceFactory &other) const
{
	if(d_ptr && other.d_ptr)
		return (*d_ptr == *other.d_ptr);
	else
		return (d_ptr==other.d_ptr);
}

QDebug operator<<(QDebug dbg, const BarSliceFactory& barslicefactory)
{
	return dbg << barslicefactory.toString();
}

