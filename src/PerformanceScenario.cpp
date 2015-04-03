#include <QuantKit/PerformanceScenario.h>

#include <QuantKit/Framework.h>
#include "Scenario_p.h"

namespace QuantKit {

class PerformanceScenarioPrivate : public ScenarioPrivate
{
public:
	explicit PerformanceScenarioPrivate(const Framework& framework);
	virtual ~PerformanceScenarioPrivate();

public:
	virtual void run() Q_DECL_OVERRIDE;
	virtual PerformanceScenarioPrivate* clone() Q_DECL_OVERRIDE { return new PerformanceScenarioPrivate(*this); }
};

} // namepsace QuantKit


using namespace QuantKit;

PerformanceScenarioPrivate::PerformanceScenarioPrivate(const Framework& framework)
	: ScenarioPrivate (framework)
{
}

PerformanceScenarioPrivate::~PerformanceScenarioPrivate ()
{
}

void PerformanceScenarioPrivate::run()
{
	strategy = new PerformanceStrategy(m_dataFileManager);
	Provider provider = new PerformanceProvider(m_dataFileManager);
	strategy.setDataProvider() = (provider as IDataProvider);
	strategy.setExecutionProvider() = (provider as IExecutionProvider);
	base.StartStrategy(StrategyMode.Live);
}


// Pubic API 

PerformanceScenario::PerformanceScenario(const Framework& framework)
	: Scenario(*new PerformanceScenarioPrivate(framework))
{
}

PerformanceScenario::~PerformanceScenario()
{
}


