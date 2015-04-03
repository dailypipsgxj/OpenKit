#include <QuantKit/PerformanceStrategy.h>

#include <QuantKit/Framework.h>
#include <QuantKit/Instrument.h>
#include <QuantKit/Event/Trade.h>
#include "InstrumentStrategy_p.h"

namespace QuantKit {

class PerformanceStrategyPrivate : public InstrumentStrategyPrivate
{
public:
	Stopwatch stopwatch_0;

public:
	explicit PerformanceStrategyPrivate(const Framework& framework);
	virtual ~PerformanceStrategyPrivate();

};

} // namepsace QuantKit


using namespace QuantKit;

PerformanceStrategyPrivate::PerformanceStrategyPrivate(const Framework& framework)
	: InstrumentStrategyPrivate (framework, "PerformanceStrategy")
	, stopwatch_0(new Stopwatch())
{
}

PerformanceStrategyPrivate::~PerformanceStrategyPrivate ()
{
}


// Pubic API 

QK_IMPLEMENTATION_PRIVATE(PerformanceStrategy)

PerformanceStrategy::PerformanceStrategy(const Framework& framework)
	: InstrumentStrategy(*new PerformanceStrategyPrivate(framework))
{
}

PerformanceStrategy::~PerformanceStrategy()
{
}


