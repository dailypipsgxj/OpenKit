#include <QuantKit/PerformanceProvider.h>

#include <QuantKit/Framework.h>
#include "Provider_p.h"

namespace QuantKit {

class PerformanceProviderPrivate : public ProviderPrivate
{
public:
	explicit PerformanceProviderPrivate(const Framework& framework);
	virtual ~PerformanceProviderPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

PerformanceProviderPrivate::PerformanceProviderPrivate(const Framework& framework)
	: ProviderPrivate (framework)
{
}

PerformanceProviderPrivate::~PerformanceProviderPrivate ()
{
}


// Pubic API 

PerformanceProvider::PerformanceProvider(const Framework& framework)
	: Provider(*new PerformanceProviderPrivate(framework))
{
}

PerformanceProvider::~PerformanceProvider()
{
}


